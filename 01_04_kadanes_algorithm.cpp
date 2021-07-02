//https://leetcode.com/problems/maximum-subarray/
/* 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arr_max = nums[0], curr_max = nums[0];
        int n  = nums.size();
        for(int i = 1; i<n; i++){
            curr_max = max(nums[i], curr_max+nums[i]);
            arr_max = max(arr_max, curr_max);
        }
        return arr_max;
    }
};