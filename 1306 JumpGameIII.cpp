class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<bool>visited(arr.size(), false);
        q.push(start);
        while(!q.empty()) {
            int index = q.front();
            if (arr[index] == 0) return true;
            q.pop();
            if(arr[index] == -1) continue;
            if (index - arr[index] >= 0) q.push(index - arr[index]);
            if (index + arr[index] < n) q.push(index + arr[index]);
            arr[index] = -1;
        }
        return false;
    }
};