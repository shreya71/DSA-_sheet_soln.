/*********************************************************************************
QUESTION: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
          You must do it in place.
          
APPROACH: Definig a temporary 2d vector using the assign operator, and making changes in temporary. 
          At last assign values of temp to the original vector matrix.
          
***********************************************************************************/        

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { 
        vector<vector<int>> temp = matrix;
        for(int i = 0 ; i < matrix.size(); i++)
            {
                for(int j = 0; j< matrix[i].size(); j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        for(int x = 0; x<matrix.size(); x++)
                        {
                            temp[x][j] = 0;
                        }
                        for(int x = 0; x<matrix[i].size(); x++)
                        {
                            temp[i][x] = 0;
                        }
                    }
                }
            }
        matrix = temp ;
        temp.clear();
    }
};
