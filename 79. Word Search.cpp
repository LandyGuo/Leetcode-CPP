/*
79. Word Search  
Difficulty: Medium
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
//2nd pass
//思路：回溯法+dfs
 struct cell
 {
	 char c;
	 bool isused;
	 cell(char c) :c(c), isused(false){};
	 cell() = default;
 };


 class Solution {
 public:
	 bool exist(vector<vector<char>>& board, string word) {
		 if (board.empty()) return false;
		 int rows = board.size(), cols = board[0].size();
		 vector<vector<cell>>cell_board(rows, vector<cell>(cols, cell()));
		 for (int i = 0; i < rows; i++)
		 {
			 for (int j = 0; j < cols; j++)
				 cell_board[i][j] = cell(board[i][j]);
		 }
		 for (int i = 0; i < rows; i++)
		 {
			 for (int j = 0; j < cols; j++)
			 {
				 if (cell_board[i][j].c == word[0])
				 {
				     cell_board[i][j].isused = true;
					 if (dfs(cell_board, 1, i, j, word))
						 return true;
					cell_board[i][j].isused = false;
				 }
			 }

		 }
		 return false;
	 }

	 bool dfs(vector<vector<cell>>&cell_board, int index, int cur_row, int cur_col, string& word)
	 {
		 if (index == word.size())
			 return true;
		 char cur_char = word[index];
		 int rows = cell_board.size(), cols = cell_board[0].size();
		 vector<pair<int, int>>neighbors = { { cur_row, cur_col + 1 }, { cur_row, cur_col - 1 }, 
		                                     { cur_row - 1, cur_col }, { cur_row + 1, cur_col } };
		 for (pair<int, int>neighbor : neighbors)
		 {
			 if (neighbor.first >= 0 && neighbor.first < rows&&neighbor.second >= 0 && neighbor.second < cols)
			 {
				 if (cell_board[neighbor.first][neighbor.second].c == cur_char&&cell_board[neighbor.first][neighbor.second].isused == false)
				 {
					 cell_board[neighbor.first][neighbor.second].isused = true;
					 if (dfs(cell_board, index + 1, neighbor.first, neighbor.second, word))
						 return true;
					 cell_board[neighbor.first][neighbor.second].isused = false;
				 }
			 }
		 }
		 return false;
	 }
 };
