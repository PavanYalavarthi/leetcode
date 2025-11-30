class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return n - 1;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int step = -1;
        while(!q.empty()) {
            step++;
            for(int i = q.size(); i > 0; i--){
                int j = q.front();
                if (j == n - 1) return step;
                q.pop();
                for(int newIdx : mp[arr[j]]) {
                    if (newIdx != j) q.push(newIdx);
                }
                mp.erase(arr[j]);
                if (j + 1 < n && mp.count(arr[j+1]) != 0) q.push(j+1);
                if (j - 1 >= 0 && mp.count(arr[j-1]) != 0) q.push(j - 1);
            }
        }
        return step;
    }
};