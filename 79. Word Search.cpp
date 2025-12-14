/*
Problem credits: https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

Solution: 
    Basic dfs
*/
class Solution {
public:
    int dir[5] = {0 , 1 , 0, -1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(checkCell(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool checkCell(vector<vector<char>>& board, string word, int i, int j, int k){
        if( k == word.size()) return true;
        if( i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k] ) return false;
        board[i][j] = '\0';
        for(int l = 0; l < 4; l++ )
            if(checkCell(board, word, i+ dir[l], j + dir[l+1], k+1))
                return true;
        board[i][j] = word[k];
        return false;
    }
};