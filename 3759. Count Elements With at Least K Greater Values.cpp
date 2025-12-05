#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

class Solution {
   
public:
    int countElements(vector<int>& nums, int k) {
         tree < int ,  null_type ,  less_equal<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > os;
        for(int num: nums) {
            os.insert(num);
        }
        int ans = 0;
        for(int num: nums) {
            ans += (nums.size() - os.order_of_key(num + 1)) >= k ;
        }
        return ans;
    }
};