class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        for(int t = n1 + n2, left = 0, right = n1, mid1, mid2, l1, l2, r1, r2; left <= right; ){
            mid1 = (left + right) >> 1;
            mid2 = t / 2 - mid1;
            l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if (l1 > r2) right = mid1 - 1;
            else if (l2 > r1) left = mid1 + 1;
            else return (t & 1) ? min(r1, r2) : (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        return 0;
    }
};