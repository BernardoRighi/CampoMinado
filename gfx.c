#include <stdio.h>
#include "gfx.h"

/*
 * Desenha a linha superior do tabuleiro.
 *
 *  int cols                número de elementos a serem desenhados.
 */
static void top_line(int cols)
{
    printf("\u250C");
	for (int i=0;i<cols-1;i++)
	{
		printf("\u2500\u2500\u2500\u252C");
	}
	printf("\u2500\u2500\u2500\u2510\n");
}

/*
 * Desenha a linha entre os campos do tabuleiro.
 *
 *  int cols                número de elementos a serem desenhados.
 */
static void mid_line(int cols)
{
	printf("\u251C");
	for (int i=0;i<cols-1;i++)
	{
		printf("\u2500\u2500\u2500\u253C");
	}
	printf("\u2500\u2500\u2500\u2524\n");

}

/*
 * Desenha a linha inferior do tabuleiro.
 *
 *  int cols                número de elementos a serem desenhados.
 */
static void bot_line(int cols)
{
	
	printf("\u2514");
	for (int i=0;i<cols-1;i++)
	{
		printf("\u2500\u2500\u2500\u2534");
	}
	printf("\u2500\u2500\u2500\u2518");
	
}

/*
 * Desenha os espaços reservados para inserção de elementos no tabuleiro.
 *
 *  int cols                número de elementos a serem desenhados.
 */
static void row_data(int cols)
{
	for (int i=0;i<cols+1;i++)
	{
		printf("\u2502   ");
	}
	printf("\n");
}

void draw_field(struct field *f)
{
	top_line(f->cols);
	for(int i=0; i<f->rows-1;i++)
	{
		row_data(f->cols);
		mid_line(f->cols);
	}
    row_data(f->cols);
	bot_line(f->cols);
}

