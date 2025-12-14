/*
Problem credits: https://leetcode.com/problems/assign-cookies/description/

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

SOlution: Sort each and assign bigger to greater
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(),greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int j = 0, count = 0;
        for(int i=0;i<s.size();i++,j++){
            while(j<g.size() && g[j] > s[i]) j++;
            if(j == g.size()) break;
            count++;
        }
        return count;
    }
};