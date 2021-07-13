//https://leetcode.com/problems/pascals-triangle

/* 
Input: numRows = 5
Output: [[1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]]
 */

//Approach: ans[i][j] = (i)C(j) = (i)*(i-1)*(i-2)*...(j times)/(j!)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            int r = 1;
            for(int j=0; j<=i; j++){
                ans[i][j] = r;
                r *= i-j;
                r /= j+1;
            }
        }
        return ans;
    }
};

//Approach: ans[i][j] = ans[i-1][j-1] + ans[i-1][j];

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int>temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            for(int j = 1; j<i; j++){
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};



