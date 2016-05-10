/*
37. Sudoku Solver   
Difficulty: Hard
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
//2nd pass
/*
思路：
1.用三个数组分别保存 行，列 和cell的约束
2.刚开始就需要初始化这3个约束，因为填每个格子都需要受到全局约束
3.如果当前只有一个分支，直接返回分支结果；如果有多个分支,则用回溯法从中返回能走通的一条路
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()) return;
        int rows = board.size(),cols = board[0].size();
        assert(rows==cols);
        int row_use[9][9]={0},col_use[9][9]={0},cell_use[9][9]={0};
        //特别注意：这里需要进行初始化！！！，不能通过回溯来填，因为当前格子所有的可能是受全局棋盘的约束的
        for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
			    if(board[i][j]=='.') continue;
				int cur = board[i][j] - '0' -1;
				row_use[i][cur] = 1;
				col_use[j][cur] = 1;
				cell_use[i / 3 * 3 + j / 3][cur] = 1;
			}
		}
        if(solve(board,0,0,row_use,col_use,cell_use))
            return;
    }
    
    bool solve(vector<vector<char>>& board,int cur_row,int cur_col,int (&row_use)[9][9],int (&col_use)[9][9],int (&cell_use)[9][9])
    {
        if(cur_row>=9)
            return true;
        int next_row = cur_col==8?cur_row+1:cur_row,next_col = cur_col==8?0:cur_col+1;
        //当前格子里面有数
        if(board[cur_row][cur_col]!='.')//当前只有一种选择，单个分支，直接返回单个分支的结果
            return solve(board,next_row,next_col,row_use,col_use,cell_use);
        else//有多个分支时，回溯法遍历多个分支，从中返回有解的结果
        {
            //求解当前格子的数
            for(int i=0;i<9;i++)
            {
                if(row_use[cur_row][i]==0&&col_use[cur_col][i]==0&&cell_use[cur_row/3*3+cur_col/3][i]==0)//同时满足行列和cell约束
                {
                    board[cur_row][cur_col] = '0'+i+1;//填数
                    //修改行列和cell约束条件
                    row_use[cur_row][i]=1,col_use[cur_col][i]=1,cell_use[cur_row/3*3+cur_col/3][i]=1;
                    //继续求解下一个cell
                    if(solve(board,next_row,next_col,row_use,col_use,cell_use))
                        return true;
                    //回溯
                    board[cur_row][cur_col] ='.';
                    row_use[cur_row][i]=0,col_use[cur_col][i]=0,cell_use[cur_row/3*3+cur_col/3][i]=0;
                }
            }
        }
        return false;
    }
};
