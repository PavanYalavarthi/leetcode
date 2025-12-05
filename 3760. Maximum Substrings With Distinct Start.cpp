class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>isProcessed(26, false);
        int count = 0;
        for(char c: s) {
            int ascii = c - 'a';
            if (!isProcessed[ascii]) {
                isProcessed[ascii] = true;
                count++;
            }
        }
        return count;
    }
};