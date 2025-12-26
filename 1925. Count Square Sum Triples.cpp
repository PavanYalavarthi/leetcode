/*
Problem credits: https://leetcode.com/problems/count-square-sum-triples/description/

A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.


Solution: brute force
*/
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <=n; b++) {
                int c = sqrt(a*a + b*b);
                if (c > n) break;
                if (c * c == a*a + b*b){
                    ans++;
                }
            }
        }
        return ans;
    }
};