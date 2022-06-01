/*********************************************************************************************************************************
QUESTION: Given an m x n grid of characters board and a string word, return true if word exists in the grid. The word can be constructed from letters 
          of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once. 
          
APPROACH: We stard traversing the 2D vector till we get 1st letter of string word. Then we go to check function to check whether further word is found in vector
          or not. we mark the letter found of a word temporarily as '*' so that a letter of vector is not taken twice. 

**********************************************************************************************************************************/

class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, int pos, string word)
    {
        if( pos == word.length())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[pos]) 
        return false;
        board[i][j] = '*' ;
        bool next = check(board, i+1, j, pos +1, word) || check(board, i-1, j, pos +1, word) ||check(board, i, j+1, pos +1, word) || check(board, i, j-1, pos +1, word) ;
        board[i][j] = word[pos];
        return next;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i< board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == word[0] && check(board, i, j, 0, word))
                return true;
        return false;
    }
};
