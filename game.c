#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include "game.h"

static void random_mines(struct game *g){

	int random_col;
	int random_row;
	int l_i;
	srand((unsigned)time(NULL)); // Inicializa a função rand(); unsigned - variavel sem sinal
	
	for (l_i = 0; l_i < g->mines; l_i++){
		random_col = rand() % g->field.cols;
		random_row = rand() % g->field.rows;
		
		g->field.cells[random_col][random_row].mine = 1;
	
	}	

}

static void field_init(struct field *f, int rows, int cols){

	int l_i;
	
	struct cell **cells;

	cells = malloc(cols * sizeof(struct cell *));
	
	if(cells == NULL){
		exit(1);
	}
	
	for( l_i = 0; l_i < cols; l_i++){
		
		cells[l_i] = malloc(rows * sizeof(struct cell));
		if(cells[l_i] == NULL){
			exit(1);
		}
	}
	
	f->cells = cells;

}

static void field_destroy(struct field *f){

	free(f->cells);

}

void game_create(struct game *g, int level){
	
	if(level == GAME_LEVEL_EASY){
		g->field.rows = LEVEL_EASY_ROWS;
		g->field.cols = LEVEL_EASY_COLS;
		g->mines = LEVEL_EASY_MINES; 
	
	} else if(level == GAME_LEVEL_MEDIUM){
		g->field.rows = LEVEL_MEDIUM_ROWS;
		g->field.cols = LEVEL_MEDIUM_COLS;
		g->mines = LEVEL_MEDIUM_MINES; 
	
	} else if(level == GAME_LEVEL_HARD){
		g->field.rows = LEVEL_HARD_ROWS;
		g->field.cols = LEVEL_HARD_COLS;
		g->mines = LEVEL_HARD_MINES; 
		
	}	
	
	field_init(&g->field, g->field.rows, g->field.cols);
	    
    random_mines(g);

}

void game_destroy(struct game *g){

	field_destroy(&g->field);
	g->mines = 0;
	g->flags = 0;
	g->level = 0;

}

