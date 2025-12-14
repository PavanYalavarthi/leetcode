/*
Problem credits: https://leetcode.com/problems/count-and-say/description/

Given a positive integer n, return the nth element of the count-and-say sequence.

Solution: 
    Get count and respective element and keep appending to the string and assign it to ans at every step
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++) {
            int count = 1;
            string temp = "";
            for(int j = 1; j < ans.size(); j++) {
                if (ans[j] == ans[j-1]) count++;
                else {
                    temp += to_string(count) + ans[j-1];
                    count = 1;
                }
            }
            ans = temp + to_string(count) + ans.back();
        }
        return ans;
    }
};