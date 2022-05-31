/*************************************************************************************************************

QUESTION: Given an m x n matrix, return all elements of the matrix in spiral order.

APPROACH: four variables required, start_column, end_column, start_row, and end_row tp track the path in spiral order.
          The two if conditions* are bascically for rectangular matrices to get printed correctly.
          
****************************************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_column = 0, end_column =  matrix[0].size()-1, start_row = 0, end_row = matrix.size()-1;
        vector<int> v;
            while( start_column <= end_column && start_row <= end_row)
        {
            for(int i = start_column; i <= end_column; i++)
               v.push_back(matrix[start_row][i]);    
            start_row++;                               
            for(int i = start_row; i <= end_row; i++)
               v.push_back(matrix[i][end_column]);
            end_column--;
                if(start_row<=end_row)
            for(int i = end_column; i >=start_column; i--)
               v.push_back(matrix[end_row][i]);
            end_row--;
                if(start_column<=end_column)
             for(int i = end_row; i >= start_row; i--)
               v.push_back(matrix[i][start_column]);
            start_column++;
        }            
        return v;
    }
};
