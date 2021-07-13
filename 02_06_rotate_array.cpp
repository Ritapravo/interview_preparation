//https://leetcode.com/problems/rotate-image/

/* 
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Example 3:

Input: matrix = [[1]]
Output: [[1]]

Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

*/

class Solution {
public:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=1; i<n; i++)
            for(int j = 0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};