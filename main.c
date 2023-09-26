#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gfx.h"
#include "game.h"
#include "screens.h"

int main(void)
{

	int level;
	
	struct game g;
    
    printf("Level:\n 0 - Facil \n 1 - Médio \n 2 - Dificil \n Digite o Level: ");
    scanf("%d", &level); 

    game_create(&g, level);
    
    screen_game(&g);

    return 0;
}
