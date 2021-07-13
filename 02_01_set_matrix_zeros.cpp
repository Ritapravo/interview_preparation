//https://leetcode.com/problems/set-matrix-zeroes

/* 
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
Input: matrix = [[1,1,1],
                 [1,0,1],
                 [1,1,1]]
Output: [[1,0,1],
         [0,0,0],
         [1,0,1]]

Input: matrix = [[0,1,2,0],
                 [3,4,5,2],
                 [1,3,1,5]]
Output: [[0,0,0,0],
         [0,4,5,0],
         [0,3,1,0]]
*/



//space complexity O(m+n) solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int a[m], b[n];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]==0){
                    a[i] = 1;
                    b[j] = 1;
                }
            }
        }
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(a[i]==1 || b[j]==1)
                    matrix[i][j]=0;
                
        
    }
};


//space complexity O(1) time complexity O(m*n) solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int c = 1;
        
        for(int i = 0; i<m; i++){
            if (matrix[i][0]==0)c=0;
            for(int j = 1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=1; j--)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            if(c==0)matrix[i][0]=0;
        }
    }
};
/* 
Here, we use the 0th row and 0th column as the extra space required
We can see that matrix[0][0] is used twice, so we take the a variable 'c' 
which takes value 0 whenever any element of 0th column is 0.
*/