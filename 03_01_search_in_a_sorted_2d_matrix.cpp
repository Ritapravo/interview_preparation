//https://leetcode.com/problems/search-a-2d-matrix/

/* 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:

Input: matrix = [[1,3,5,7],
                 [10,11,16,20],
                 [23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1, 3, 5, 7 ],
                 [10,11,16,20],
                 [23,30,34,60]], target = 13
Output: false

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m-1;
        if(target<matrix[0][0])return false;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(target>matrix[mid][0])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        int x = high;
        low = 0; high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[x][mid]==target)
                return true;
            else if(target>matrix[x][mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        
        return false;
    }
};