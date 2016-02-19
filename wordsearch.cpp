/*
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
class Solution {  
public:  
    bool exist(vector<vector<char> > &board, string word) {  
        for(int i=0;i<board.size();i++)  
        {  
            for(int j =0;j<board[i].size();j++)  
            {  
                if(existWord(board,word,i,j,0))  
                {  
                    return true;  
                }  
            }  
        }  
        return false;  
    }  
      
    bool existWord(vector<vector<char>> &board, string word, int i, int j, int n)  
    {  
        if(i >= board.size() || i<0)  
        {  
            return false;  
        }  
        else if(j >= board[0].size() || j < 0)  
        {  
            return false;  
        }  
        else  
        {  
            if(board[i][j] == word[n])  
            {  
                if(n==word.size()-1)  
                {  
                    return true;  
                }  
                board[i][j] = '.';  
                if(existWord(board,word,i-1,j,n+1))  
                {  
                    return true;  
                }  
                else if(existWord(board,word,i,j-1,n+1))  
                {  
                    return true;  
                }  
                else if(existWord(board,word,i+1,j,n+1))  
                {  
                    return true;  
                }  
                else if(existWord(board,word,i,j+1,n+1))  
                {  
                    return true;  
                }  
                board[i][j] = word[n];  
                return false;  
            }  
            return false;  
        }  
    }  
}; 
