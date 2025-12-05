class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        while(n > 0)
          if((num[--n] - '0') & 1) return num.substr(0,n+1);
        return "";
    }
};