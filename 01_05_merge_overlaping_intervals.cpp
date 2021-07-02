//https://leetcode.com/problems/merge-intervals/

/* 
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if(intervals.size()==0)return merged;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(auto it: intervals){
            if(it[0]<=temp[1]) temp[1] = max(temp[1], it[1]);
            else{
                merged.push_back(temp);
                temp = it;
            }
        }
        merged.push_back(temp);
        return merged;
    }
};