#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "utils.h"
#include "gfx.h"
#include "game.h"
#include "screens.h"

int screen_game(struct game *g){

	int k;
	int c,l,p_c, p_l;

	clear_screen();

    draw_field(&g->field);
    
    cursor_move(3, 8);

    c = 0;
    l = 0;
    
    p_c = 3;
    p_l = 8;
    

	while(1){
		switch (k = get_key()) 
		{
		case KEY_UP:
			if(l - 1 >= 0)
			{
				cursor_move_up(2);
				p_l = p_l - 2;
				l--;
			}
			break;

		case KEY_DOWN:
			if(l + 1 < g->field.rows)
			{
				cursor_move_down(2);
				p_l = p_l + 2;
				l++;
			}
			break;

		case KEY_RIGHT:
			if(c + 1 < g->field.cols)
			{
				cursor_move_right(4);
				p_c = p_c + 4;
				c++;
			}
	 		break;
	 
		case KEY_LEFT:
			if(c - 1 >=0)
			{
				cursor_move_left(4);
				p_c = p_c - 4;
				c--;
			}
			break;
			
		case KEY_SPACE:
			printf("\u2691");
			cursor_move(p_c, p_l);
			break;
			
		case KEY_ESCAPE:
			game_destroy(&g);
			exit(0);
			break;
		}
		
	}

	return 0;

}
