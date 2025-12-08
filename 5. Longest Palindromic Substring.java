class Solution {
    public String longestPalindrome(String t) {
        int n = t.length(), m = 2*n +1,mx =0;
        String s = "#";
        for(int i=0;i<n;i++){
            s += t.charAt(i) + "#";
        }
        int []dp = new int[m];
        int center = 0, right = 0;
        for(int i =0;i<m;i++){
            if(i < right) dp[i] = Math.min(right - i, dp[2*center - i]);
            while(i > dp[i] && i + dp[i] + 1 < m && s.charAt(i-dp[i] - 1) == s.charAt(i + dp[i] + 1)) dp[i]++;
            if(i + dp[i] > right) {
                center =i;
                right = i + dp[i];
            }
            if(dp[i] > dp[mx]) mx = i; 
        }
        return s.substring(mx - dp[mx] , mx + dp[mx] + 1).replaceAll("#","");
    }
};