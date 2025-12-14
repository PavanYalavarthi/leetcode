/*
Problem credits: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

Solution: To track Each Element we are traverse Or Not [as They said That any element can occoure max Twice]
While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};