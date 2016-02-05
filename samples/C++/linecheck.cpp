#include "dropblox_ai.h"

int linecheck(const Board &board)
{
    int rows_removed;
    for (int i = ROWS - 1; i >= 0; i--) 
    {
        bool full = true;
        for (int j = 0; j < COLS; j++) 
        {
            if (!board.bitmap[i][j]) 
            {
                full = false;
                break;
            }
        }
        if (full) 
        {
            rows_removed += 1;
        }
    }
    
    return rows_removed;
}


