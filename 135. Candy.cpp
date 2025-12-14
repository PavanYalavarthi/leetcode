/*
problem credits: https://leetcode.com/problems/candy/

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Solution:
    Number of candies you give seeing from right and left

    Now, pick maximum for each index
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>right(n,1);
        for(int i=n-2;i>=0;i--)
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1] +1;
        int candy = right[0];
        for(int i=1, left = 1;i<n;i++){
            if(ratings[i] > ratings[i-1]) left++;
            else left =1;
            candy += max(left,right[i]);
        }
        return candy;
    }
};