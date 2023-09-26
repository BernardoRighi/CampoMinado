#ifndef GAME_H
#define GAME_H

#define GAME_LEVEL_EASY               0
#define GAME_LEVEL_MEDIUM             1
#define GAME_LEVEL_HARD               2
#define LEVEL_EASY_MINES              7 
#define LEVEL_MEDIUM_MINES            25  
#define LEVEL_HARD_MINES              50
#define LEVEL_EASY_ROWS               5
#define LEVEL_MEDIUM_ROWS             10
#define LEVEL_HARD_ROWS               10
#define LEVEL_EASY_COLS               5
#define LEVEL_MEDIUM_COLS             10
#define LEVEL_HARD_COLS               10 

struct cell {

	char mine;
	char flag;

};

struct field {
    int rows;
    int cols;
    struct cell **cells;
};

struct game {

	int mines;
	int flags;
	int level;
	struct field field;

};

extern void game_create(struct game *g, int level);

extern void game_destroy(struct game *g);

#endif // GAME_H

