class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        priority_queue<pair<long long, int>> pq;
        int n = technique1.size();
        for(int i = 0; i < n; i++) {
            pq.push({(long long)technique1[i] - technique2[i], i});
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int index = pq.top().second;
            pq.pop();
            if(i < k) {
                ans = ans + technique1[index];
            } else {
                ans = ans + max(technique1[index] , technique2[index]);
            }
        }
        return ans;
    }
};