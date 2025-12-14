/*
Problem credits: https://leetcode.com/problems/multiply-strings/description/

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Solution: Basic multiplication, a[i]* a[j] => goes in ans[i+j+1]
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        string ans(m+n, '0');
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int num = (ans[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                ans[i+j+1] = num % 10 +'0';
                ans[i+j] += num/ 10; 
            }
        }
        int i = 0;
        while(ans[i] == '0') i++;
        return ans.substr(i);
    }
};