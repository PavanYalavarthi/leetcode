class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long>prefix(n+1, 0), suffix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i-1] + (s[i-1] == 'L');
        }
        for(int i = n-1; i >= 0; i--) {
            suffix[i] += suffix[i+1] + (s[i] == 'T');
        }
        long long ans = 0, bestWithC = 0, resWithL = 0, resWithT = 0, resWithC = 0;
        for(int i =0; i< n; i++) {
            if (s[i] == 'C') {
                resWithL += (prefix[i] + 1) * suffix[i];
                resWithT += prefix[i] * (suffix[i] + 1);
                resWithC += prefix[i] * suffix[i];
            } else {
                bestWithC = max(bestWithC, prefix[i] * suffix[i]);
            }
        }
        resWithC += bestWithC;
        return max({resWithL, resWithT, resWithC});
    }
};