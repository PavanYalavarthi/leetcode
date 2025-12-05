class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0;i<n;i++){
            if(citations[i] >= i + 1) h = i+1;
            else return h;
        }
        return h;
    }
};