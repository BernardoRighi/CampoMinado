#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "utils.h"
 
#define KB_MODE_NORMAL          0
#define KB_MODE_RAW             1

static int kbhit(void)
{
    struct timeval tv;
    fd_set rdfs;
 
    tv.tv_sec = 0;
    tv.tv_usec = 0;
 
    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);
 
    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);

    return FD_ISSET(STDIN_FILENO, &rdfs);
}

static void kb_change_mode(int mode)
{
    static struct termios oldt, newt;
 
    if (mode == KB_MODE_RAW) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

int get_key()
{
    int k;
	fflush(stdout);
    kb_change_mode(KB_MODE_RAW);

    while (!kbhit());

    k = getchar();
    if (k == '\033') {
        getchar();
        switch (k = getchar()) {
        case 'A':
            k = KEY_UP;
            break;
        case 'B':
            k = KEY_DOWN;
            break;
        case 'C':
            k = KEY_RIGHT;
            break;
        case 'D':
            k = KEY_LEFT;
            break;
        case 'E':
            k = KEY_SPACE;
            break;
        case 'F':
            k = KEY_ESCAPE;
            break;
        }
    }
 
    kb_change_mode(KB_MODE_NORMAL);

    return k;
}

void screen_size(int *h, int *w)
{
	struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    *h = ws.ws_row;
    *w = ws.ws_col;
}

void clear_screen(void)
{
    printf("\e[2J");
}

void print_xy(const char *str, int x, int y)
{
	cursor_move(x, y);
	printf("%s", str);
	fflush(stdout);
}

void cursor_move(int x, int y)
{
	printf("\e[%d;%df", y, x);
	fflush(stdout);
}

void cursor_move_up(int n)
{
    printf("\e[%dA", n);
}

void cursor_move_down(int n)
{
    printf("\e[%dB", n);
}

void cursor_move_right(int n)
{
    printf("\e[%dC", n);
}

void cursor_move_left(int n)
{
    printf("\e[%dD", n);
}

void cursor_show(int visible)
{
	printf("\e[?25%c", visible ? 'h' : 'l');
}

