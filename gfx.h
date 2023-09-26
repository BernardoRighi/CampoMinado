#ifndef GFX_H
#define GFX_H

#include "game.h"

/*
 * Desenha o tabuleiro do jogo conforme as propriedades da estrutura.
 *
 *  struct field *f         estrutura com as propriedades do tabuleiro.
 */
extern void draw_field(struct field *f);

#endif // GFX_H

