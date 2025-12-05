static int MOD=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<long> memo={0},prefixSum={0}; // Dynamic lists to help discard values in the front (optimizations).
        for(int i=1;i<=n;i++) {
            // Same as previous section prefix sum optimization.
			// Here we add 1 as the contribution of ith day as we don't iniatilize memo with 1s
            memo.push_back((1+prefixSum[max(0,(int)prefixSum.size()-delay)]-prefixSum[max(0,(int)prefixSum.size()-forget)]+MOD)%MOD);
            prefixSum.push_back((prefixSum.back()+memo.back())%MOD); // Store the prefixSum for ith state of dp.
            if(memo.size()>forget+1)    // Optimization to discard non-required values
                memo.pop_front(),prefixSum.pop_front();
        }
        return (memo.back()-memo.front()+MOD)%MOD; // Subtract the people who found out by the `n-forget` day as observed.
    }
};