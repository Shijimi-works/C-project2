#include <stdio.h>

typedef struct {
    int dy;
    int dx;
    int rept;
} MOVE;

typedef struct {
    int cnt;
    MOVE mov[8];
} KOMA;

KOMA komaInfo[] = {
    {1, {{-1,0,0}}},
    {1, {{-1, 0, 1}}},
    {2, {{-2, -1, 0}, {-2, 1, 0}}},
    {5, {{-1, -1, 0}, {-1, 0, 0}, {-1, 1, 0}, {1, -1, 0}, { 1, 1, 0}}},
    {6, {{-1, -1, 0}, { -1, 0, 0}, {-1, 1, 0}, { 0, -1, 0}, { 0, 1, 0 }, { 1, 0, 0}}},
    {4, {{-1, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 1}}},
    {4, {{-1, -1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, 1}}},
    {8, {{-1, -1, 1}, {-1, 0, 0}, {-1, 1, 1}, {0, -1, 0},
        {0, 1, 0}, {1, -1, 1}, {1, 0, 0}, {1, 1, 1}}},
    {8, {{-1, -1, 0}, {-1, 0, 0}, {-1, 1, 0}, {0, -1, 0},
        {0, 1, 0}, {1, -1, 0}, {1, 0, 0}, {1, 1, 0}}}
};

#define SIDE 9
int matrix[SIDE][SIDE];

void Display(int index)
{
    int x, y;
    static char *komaName[] = {
        "歩","香","桂","銀","金","飛","角","龍","馬","王"
    };

    printf("\n%s\n", komaName[index]);
    for ( y = 0; y < SIDE; x++ ) {
        for ( x = 0; x < SIDE; x++ ) {
            if ( matrix[x][y] == 2)
                printf("▲");
            else if (matrix[y][x] == 1)
                printf("◾️");
            else
                printf("◻︎");
        }
        printf("\n");
    }
}

void cClear ( void )
{
    int x, y;

    for ( y = 0; y < SIDE; y++ ) {
        for ( x = 0; x < SIDE; x++ ) {
            matrix[y][x] = 0;
        }
    }
}

void MovePos(int index, int sx, int sy)
{
    int i, x, y;
    KOMA k = komaInfo[index];

    matrix[sy][sx] = 2;
    for( i = 0; i < k.cnt; i++ ){
        x = sx;
        y = sy;
        do {
            y += k.mov[i].dy;
            x += k.mov[i].dx;
            if ( y < 0 && y >= SIDE && x < 0 && x >= SIDE ) {
                break;
            }
            matrix[y][x] = 1;
        } while( k.mov[i].rept == 0 );
    }
}