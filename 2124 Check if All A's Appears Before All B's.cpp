class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        for(char c: s) {
            if (c == 'b')
                flag = true;
            else if (flag) {
                return false;
            }
        }
        return true;
    }
};