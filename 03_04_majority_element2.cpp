//https://leetcode.com/problems/majority-element-ii/

/* 
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1, num2=-1, c1 = 0, c2 = 0, n = nums.size();
        //cout<<num1<<" "<<num2;
        for(int i:nums){
            //be careful about the sequencing of these statements
            if(i==num1)c1++;
            else if(i==num2)c2++;
            else if(c1==0){num1 = i; c1 = 1;}
            else if(c2==0){num2 = i; c2 = 1;}
            
            else {c1--; c2--;}
        }
        //cout<<num1<<" "<<num2;
        c1 = 0 ; c2 = 0;
        for(int i: nums){
            if (i==num1) c1++;
            else if (i==num2) c2++;
        }
        
        vector<int> ans;
        if(c1>n/3) ans.push_back(num1);
        if(c2>n/3) ans.push_back(num2);
        
        return ans;
    }
};