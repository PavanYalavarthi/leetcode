/*
Problem credits: https://leetcode.com/problems/range-sum-query-immutable/

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Solution:
    Use prefix sum
*/
/*Using prefixSum*/
class NumArray {
    vector<int>prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.assign(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
 
 
 /*

Below is fenwick tree implementation for the same

struct BIT {
    vector<int>BIA;
    public:
        void build(vector<int>& nums) {
            BIA.assign(nums.size() + 1, 0);
            for(int i =0; i< nums.size(); i++)
                update(i, nums[i]);
        }

        void update(int index, int val) {
            index++;
            while(index < BIA.size()){
                BIA[index] += val;
                index += (index & -index);
            } 
        }

        int query(int index) {
            index++;
            int sum = 0;
            while(index > 0) {
                sum += BIA[index];
                index -= (index & -index);
            }
            return sum;
        }
};

class NumArray {
    struct BIT bit;
public:
    NumArray(vector<int>& nums) {
        bit.build(nums);
    }
    
    int sumRange(int left, int right) {
        return bit.query(right) - bit.query(left - 1);
    }
};

*/