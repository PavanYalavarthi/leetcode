class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--,n--;
        while( m>=0 && n>=0) {
            if(nums1[m] > nums2[n]) nums1[m + n + 2] = nums1[m--];
            else nums1[m + n + 2] = nums2[n--];
        }
        while(n >=0){
            nums1[m + n + 2] = nums2[n--];
        }
    }
};