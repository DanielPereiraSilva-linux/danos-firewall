#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// --- Protótipos ---
void draw_layout(WINDOW **header_win, WINDOW **main_win, WINDOW **footer_win);
void display_rules(WINDOW *win, const char* table, const char* chain);
int main_menu(WINDOW *win);

// --- Função Principal ---
int main() {
    if (getuid() != 0) {
        fprintf(stderr, "Erro: Privilégios de root são necessários.\n");
        return 1;
    }

    // Inicialização do ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0); // Esconde o cursor
    start_color();
    keypad(stdscr, TRUE);

    // Define pares de cores que usaremos
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLUE); // Para o item selecionado

    WINDOW *header_win, *main_win, *footer_win;
    draw_layout(&header_win, &main_win, &footer_win);

    int choice;
    do {
        choice = main_menu(main_win);
        
        // Limpa a janela principal para a próxima ação
        werase(main_win);
        box(main_win, 0, 0);

        switch(choice) {
            case 0: // Gerenciar Tabela Filter
                display_rules(main_win, "filter", "INPUT");
                break;
            case 1: // Gerenciar Tabela NAT
                display_rules(main_win, "nat", "PREROUTING");
                break;
            // Adicionar outras opções aqui...
        }
        
        if (choice != -1) { // Se não foi 'q' para sair
            wattron(footer_win, COLOR_PAIR(3));
            mvwprintw(footer_win, 1, 2, "Pressione qualquer tecla para voltar ao menu...");
            wattroff(footer_win, COLOR_PAIR(3));
            wrefresh(footer_win);
            getch();
            draw_layout(&header_win, &main_win, &footer_win); // Redesenha tudo
        }

    } while (choice != -1);

    // Finaliza o ncurses
    endwin();
    return 0;
}


// --- Funções da Interface ncurses ---

void draw_layout(WINDOW **header_win, WINDOW **main_win, WINDOW **footer_win) {
    int parent_y, parent_x;
    getmaxyx(stdscr, parent_y, parent_x);

    // Janela do Cabeçalho
    *header_win = newwin(3, parent_x, 0, 0);
    box(*header_win, 0, 0);
    wbkgd(*header_win, COLOR_PAIR(1));
    mvwprintw(*header_win, 1, (parent_x - 32) / 2, "DANOS FIREWALL - LEGENDARY EDITION");
    
    // Janela do Rodapé
    *footer_win = newwin(3, parent_x, parent_y - 3, 0);
    box(*footer_win, 0, 0);
    wbkgd(*footer_win, COLOR_PAIR(1));
    mvwprintw(*footer_win, 1, 2, "Use as SETAS para navegar, ENTER para selecionar, 'q' para sair.");

    // Janela Principal
    *main_win = newwin(parent_y - 6, parent_x, 3, 0);
    box(*main_win, 0, 0);

    refresh();
    wrefresh(*header_win);
    wrefresh(*main_win);
    wrefresh(*footer_win);
}

// Menu principal interativo
int main_menu(WINDOW *win) {
    char *choices[] = {
        "Gerenciar Tabela 'filter'",
        "Gerenciar Tabela 'nat'",
        "Gerenciar Tabela 'mangle'",
        "Funções Rápidas de NAT"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 0;
    int choice = 0;
    int c;

    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 1, 2, "--- MENU PRINCIPAL ---");
    wattroff(win, COLOR_PAIR(3));

    while (1) {
        for (int i = 0; i < n_choices; ++i) {
            if (highlight == i) { // Destaca a opção atual
                wattron(win, A_REVERSE | COLOR_PAIR(4));
                mvwprintw(win, i + 3, 4, "> %s", choices[i]);
                wattroff(win, A_REVERSE | COLOR_PAIR(4));
            } else {
                mvwprintw(win, i + 3, 4, "  %s  ", choices[i]);
            }
        }
        wrefresh(win);

        c = getch();
        switch (c) {
            case KEY_UP:
                highlight = (highlight == 0) ? n_choices - 1 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == n_choices - 1) ? 0 : highlight + 1;
                break;
            case 10: // Tecla Enter
                choice = highlight;
                return choice;
            case 'q':
            case 'Q':
                return -1; // Sair
            default:
                break;
        }
    }
}


// Exibe a saída de um comando em uma janela com rolagem
void display_rules(WINDOW *win, const char* table, const char* chain) {
    char comando[512];
    snprintf(comando, sizeof(comando), "sudo iptables -t %s -L %s -v -n --line-numbers", table, chain);
    
    FILE* fp = popen(comando, "r");
    if (fp == NULL) {
        mvwprintw(win, 1, 2, "Erro ao executar o comando iptables.");
        wrefresh(win);
        return;
    }

    char buffer[512];
    int line = 1;
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, line++, 2, "Regras para: Tabela [%s] -> Chain [%s]", table, chain);
    wattroff(win, COLOR_PAIR(3));
    line++;
    
    // Lê e exibe a saída do comando na janela
    while (fgets(buffer, sizeof(buffer), fp) != NULL && line < getmaxy(win) - 1) {
        mvwprintw(win, line++, 2, "%s", buffer);
    }
    
    pclose(fp);
    wrefresh(win);
}
