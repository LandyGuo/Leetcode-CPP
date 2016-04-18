/*
130. Surrounded Regions   
Difficulty: Medium
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
/*2nd pass
注意：构造函数里面不要去初始化neighbors，否则会反复调构造函数，直至栈溢出
*/
 struct seed
 {
	 int row, col;
	 seed(int row, int col) :row(row), col(col){};//注意：不要在构造函数里面调构造函数
	 vector<seed> getNeighbors()
	 {
		 vector<seed> neighbors;
		 neighbors.push_back(seed(row - 1, col));
		 neighbors.push_back(seed(row, col - 1));
		 neighbors.push_back(seed(row + 1, col));
		 neighbors.push_back(seed(row, col + 1));
		 return neighbors;
	 }
 };


 class Solution {
 public:
	 void solve(vector<vector<char>>& board) {
		 //环绕一周找到出口处，修改标记为"*"
		 if (board.empty())
			 return;
		 int rows = board.size(), cols = board[0].size();
		 //先从边界开始初始化种子(可以到达出口的种子)，初始化后注意修改标记(为避免重复加入)
		 queue<seed> seeds;
		 for (int i = 0; i < rows; i++)
		 {
			 if (board[i][0] == 'O' )
			 {
				 seeds.push(seed(i, 0));
				 board[i][0] = '*';
			 }
			 if (board[i][cols - 1] == 'O')
			 {
				 seeds.push(seed(i, cols-1));
				 board[i][cols-1] = '*';
			 }
		 }
		for (int j = 0; j < cols; j++)
		{
			if (board[0][j] == 'O')
			{
				seeds.push(seed(0, j));
				board[0][j] = '*';
			}
			if (board[rows - 1][j] == 'O')
			{
				seeds.push(seed(rows - 1, j));
				board[rows - 1][j] = '*';
			}
		}
		//采用bfs方法加入所有能和已有种子相连的种子,由于已经修改标记，所以这里不会重复加入
		 while (!seeds.empty())
		 {
			 seed curSeed = seeds.front();
			 seeds.pop();
			 for (seed  s : curSeed.getNeighbors())
			 {
				 if (isSeedValid(s, rows, cols) && board[s.row][s.col] == 'O')
				 {
					 board[s.row][s.col] = '*';
					 seeds.push(s);
				 }
			 }
		 }
		 //更新所有的表示，能到达出口的种子都已经标识为"*",剩下的都是不能到达出口的种子
		 for (int i = 0; i < rows; i++)
		 {
			 for (int j = 0; j < cols; j++)
			 {
				 if (board[i][j] != '*')
					 board[i][j] = 'X';
				 else
					 board[i][j] = 'O';
			 }
		 }

	 };
    //检测种子是否在合法的范围里面
	 bool isSeedValid(seed const& s, int board_size_row, int board_size_col)
	 {
		 return (s.row >= 0 && s.row < board_size_row&&s.col >= 0 && s.col < board_size_col) ? true : false;
	 };
 };
