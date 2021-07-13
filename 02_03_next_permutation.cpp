//https://leetcode.com/problems/next-permutation/submissions/

class Solution {
public:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1, j = n-1;
        while((i--)>0 && nums[i]>=nums[i+1]);
        if(i!=-1){
            while(j>0 && nums[j]<=nums[i])j--;
            swap(nums[i],nums[j]);
            j = n-1; 
        }
        i++;
        while(i<j)
            swap(nums[i++], nums[j--]);
    }
};