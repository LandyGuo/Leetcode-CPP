/*
200. Number of Islands  
Difficulty: Medium
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
 struct seed
 {
	 int row, col;
	 seed(int row, int col) :row(row), col(col){};
	 vector<seed> getNeighbors()
	 {
		 vector<seed> neighbors;
		 neighbors.push_back(seed(row - 1, col));
		 neighbors.push_back(seed(row, col - 1));
		 neighbors.push_back(seed(row + 1, col));
		 neighbors.push_back(seed(row, col + 1));
		 return neighbors;
	 };

 };

class Solution {
 public:
	 int numIslands(vector<vector<char>>& grid) {
		 if (grid.empty())
			 return 0;
		 int rows = grid.size(), cols = grid[0].size();
		 //initialize
		 queue<seed> seeds;
		 int cnt = 0;
		 for (int i = 0; i < rows; i++)
		 {
			 for (int j = 0; j < cols; j++)
			 {
			     //每加入一个种子，总的计数就+1
				 if (grid[i][j] == '1')
				 {
					 grid[i][j] = '*';
					 seeds.push(seed(i, j));
					 cnt += 1;
				 }
				 //延伸修改与种子相邻的值
				 while (!seeds.empty())
				 {
					 seed curSeed = seeds.front();
					 seeds.pop();
					 for (seed s : curSeed.getNeighbors())
					 {
						 if (isSeedValid(s, rows, cols) && grid[s.row][s.col] == '1')
						 {
							 seeds.push(s);
							 grid[s.row][s.col] ='*';
						 }
					 }
				 }
			 }
		 }
		 return cnt;

	 };
     //判断种子是否跃出边界
	 inline bool isSeedValid(seed const& s, int board_size_row, int board_size_col)
	 {
		 return (s.row >= 0 && s.row < board_size_row&&s.col >= 0 && s.col < board_size_col) ? true : false;
	 };
 };
