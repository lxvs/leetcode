#include "036-valid-sudoku.h"

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
                return false;
            } else {
                row[i][board[i][j] - '1']++;
                col[j][board[i][j] - '1']++;
                rec[(i / 3) * 3 + j / 3][board[i][j] - '1']++;
            }
        }
    return true;
}
