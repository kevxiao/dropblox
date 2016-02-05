#include "dropblox_ai.h"

int holecheck(const Board &board)
{
    int holecount = 0;
    int grid[ROWS][COLS];
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
        {
            if (board.bitmap[r][c] != 0)
                grid[r][c] = -1;
            else
            {
                grid[r][c] = 1;
                ++holecount;
            }
        }
    for (int r = 0; r < ROWS; ++r)
    {
        if (r == 0)
        {
            for (int c = 0; c < COLS; ++c)
            {
                grid[r][c] = 0;
                --holecount;
            }
        }
        else
        {
            for (int c = 0; c < COLS; ++c)
                if (grid[r-1][c] == 0)
                {
                    grid[r][c] = 0;
                    --holecount;
                }
        }
    }
    if (holecount < 0)
        holecount = 0;
    return holecount;
}
