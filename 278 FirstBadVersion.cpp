// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
 * Time complexity : O(log n)
 * Space complexity : O(1)
 * Using binary search to get first bad version
*/

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};