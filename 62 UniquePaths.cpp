class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        int num = m + n - 2;
        unsigned long long ans = 1;
        for(int i = 1; i < m; i++) {
            ans = ans * num / i;
            num--;
        }
        return (int)ans;
    }
};