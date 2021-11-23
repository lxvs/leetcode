#if DEBUG
#include "lib/debug.h"
#endif

#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][9] = {0};
    int col[9][9] = {0};
    int rec[9][9] = {0};

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;
            if (row[i][board[i][j] - '1']
                    || col[j][board[i][j] - '1']
                    || rec[(i / 3) * 3 + j / 3][board[i][j] - '1']) {
#if DEBUG
                dbg("i = %d, j = %d\n", i, j);
                dbg("row[%d][%d] = %d\n", i, board[i][j] - '1', row[i][board[i][j] - '1']);
                dbg("col[%d][%d] = %d\n", j, board[i][j] - '1', col[j][board[i][j] - '1']);
                dbg("rec[%d][%d] = %d\n", (i / 3) * 3 + j / 3, board[i][j] - '1',
                        rec[(i / 3) * 3 + j / 3][board[i][j] - '1']);
#endif
                return false;
            } else {
                row[i][board[i][j] - '1']++;
                col[j][board[i][j] - '1']++;
                rec[(i / 3) * 3 + j / 3][board[i][j] - '1']++;
            }
        }
    return true;
}
