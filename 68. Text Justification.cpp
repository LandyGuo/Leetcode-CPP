/*
68. Text Justification  
Difficulty: Hard
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/
//2nd pass
/*
思路：
1)如何判断当前单词是否应该加入当前行？求当前行中所有单词的最小占用长度，如果加上当前单词后的最小占用长度>L，当前行就不包括当前单词
（先生成一行后，再加入当前单词）
2)怎么判断最后一行？如果到最后一个单词，那么最后一个单词所在的行就是最后一行
3)怎么加空格？加空格要根据当前行的【单词数目】还有【行数】来定：
【单词数目】：如果只有一个单词，那么就直接在这个单词后面补空格；如果多于1个单词的情况，就在单词中间补空格(最后一个单词后面不添加空格)
【行数】：最后一行，单词之间不添加空格，在最后一个单词之后添加空格
*/
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ret;
		vector<string> curLine;
		int line_length_of_words = 0;
		for (int cnt = 0; cnt<words.size(); cnt++)
		{
			string word = words[cnt];
			int lineLength = curLine.size() - 1 + line_length_of_words;//当前单词最少要占用的长度
			if (lineLength <= maxWidth&&lineLength + word.length() + 1>maxWidth)//不加当前单词，构成一行
			{
			    string line;
			    if(curLine.size()==1)//只有一个单词，所有空格都加在后面
			    {
			        line+=curLine[0];
			        line +=string(maxWidth-line.length(),' ');//注意这里：只有一个单词的情况，要在后面补空格
			    }
			    //多个单词，空格加在中间
			    else
			    {
			        int left_spaces = maxWidth - line_length_of_words;
    				int empty_spaces = curLine.size()-1;//多个单词时，最后一个单词之后不加空格
    				vector<string> addLine;
    				for (int i = 0; i < curLine.size(); i++)
    				{
    					addLine.push_back(curLine[i]);
    					if(i!=curLine.size()-1)
    					{
    					 	int spaces =ceil((double)left_spaces / empty_spaces);
    						left_spaces -= spaces, empty_spaces--;
    						addLine.push_back(string(spaces, ' '));   
    					}
    				}
    				for (string s : addLine)
					    line += s;
			    }
				ret.push_back(line);
				curLine.clear();
				//处理完当前行后，再加上当前单词
				curLine.push_back(word);
				line_length_of_words = word.length();
			}
			else
			{
				line_length_of_words += word.length();
				curLine.push_back(word);
			}
			if (cnt == words.size() - 1)//最后一个单词，意味着最后一行
			{
				string line;
				for (int i = 0; i < curLine.size(); i++)
				{
					line += curLine[i];
					if (i != curLine.size() - 1)
						line += " ";
				}
				line +=string(maxWidth-line.length(),' ');//在后面补空格
				ret.push_back(line);
			}
		}
		return ret;
	}
};
