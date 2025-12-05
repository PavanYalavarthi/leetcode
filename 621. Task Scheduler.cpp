class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(int i = 0; i< tasks.size() ; i++)
            v[tasks[i] - 'A']++;
        int maxFreq = *max_element(v.begin(), v.end());
        int maxCount = count(v.begin(), v.end(), maxFreq);
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
    }
};