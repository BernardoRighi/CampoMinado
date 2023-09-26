#ifndef UTILS_H
#define UTILS_H

#define KEY_UP                  0x01F0
#define KEY_DOWN                0x01F1
#define KEY_LEFT                0x02F0
#define KEY_RIGHT               0x02F1
#define KEY_SPACE               0x0020
#define KEY_ESCAPE              0x001B

/*
 * Retorna um número inteiro que indica a tecla pressionada pelo usuário sem
 * que seja necessária a confirmação utilizando o 'enter'.
 */
extern int get_key();

/*
 * Retorna a largura e altura da tela de comandos em número de elementos.
 *
 *  int *h          altura da tela.
 *  int *w          largura da tela.
 */
extern void screen_size(int *h, int *w);

/*
 * Limpa a tela de comandos.
 */
extern void clear_screen(void);

/*
 * Habilita ou não a exibição do cursor na tela de comandos.
 *
 *  int visible     0: desabilitado; 1: habilitado.
 */
extern void cursor_show(int visible);

/*
 * Movimenta o cursor para a posição indicada.
 *
 *  int x           posição da coluna.
 *  int y           posição da linha.
 */
extern void cursor_move(int x, int y);

/*
 * Move o cursor n posições acima.
 *
 *  int n           número de posições a serem deslocadas.
 */
extern void cursor_move_up(int n);

/*
 * Move o cursor n posições abaixo.
 *
 *  int n           número de posições a serem deslocadas.
 */
extern void cursor_move_down(int n);

/*
 * Move o cursor n posições à direita.
 *
 *  int n           número de posições a serem deslocadas.
 */
extern void cursor_move_right(int n);

/*
 * Move o cursor n posições à esquerda.
 *
 *  int n           número de posições a serem deslocadas.
 */
extern void cursor_move_left(int n);

#endif // UTILS_H

