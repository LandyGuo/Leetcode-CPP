/*
36. Valid Sudoku   
Difficulty: Easy
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

//2nd pass
//采用bin的方法进行统计：按行的bin,按列划分的bin,还有按行和列进行划分的bin;每个Bin里都按数字值进行划分，如果已经用过了，那么就是invalid
//需要注意的是：board的size一定是9*9

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty())return false;
        int rows = board.size(),cols = board[0].size();
        assert(rows==9&&cols==9);
        int check_col[9][9] = {0},check_grid[9][9]={0};
        for(int i=0;i<9;i++)
        {
            int used[9]={0};
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                int cur = board[i][j]-'0'-1;
                if(used[cur]==0) used[cur]=1;//check row
                else return false;
                if(check_col[j][cur]==0) check_col[j][cur]=1;//check col
                else return false;
                if(check_grid[i/3*3+j/3][cur]==0) check_grid[i/3*3+j/3][cur]=1;//check grid
                else return false;
            }
        }
        return true;
    }
};
