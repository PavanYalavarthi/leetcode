#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> orderedSet; 
        long long invCnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < k ; i++) {
            orderedSet.insert({-nums[i], i});
            invCnt += orderedSet.order_of_key({-nums[i], -1});
        }
        // cout << invCnt << endl;
        long long ans = invCnt;
        for(int i = k; i < n; i++) {
            invCnt = invCnt -  k + orderedSet.order_of_key({-nums[i-k], n});
            orderedSet.erase({-nums[i-k], i- k});
            orderedSet.insert({-nums[i], i});
            invCnt += orderedSet.order_of_key({-nums[i], -1});
            // cout<< i << " " << invCnt << endl;
            ans = min(ans, invCnt);
        }
        return ans;
    }
};