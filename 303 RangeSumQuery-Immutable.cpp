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