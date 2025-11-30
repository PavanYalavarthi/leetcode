class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long sum = 0, ans = 0;
        unordered_map<string, int> mp; 
        string prev = "#";
        for(int num: capacity) {
            ans += mp[{to_string(num) + "#" + to_string(sum - num)}];
            sum += num;
            mp[prev]++;
            prev = to_string(num) + "#" + to_string(sum); // adding prev after processing current to maintain window of 3
        }
        return ans;
    }
};