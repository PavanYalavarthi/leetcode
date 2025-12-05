class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_til = 0, start = 0;
        for(int i =0, curr_gas = 0, dif ;i <gas.size();i++){
            dif = gas[i] - cost[i];
            curr_gas += dif;
            gas_til += dif;
            if(curr_gas < 0){
                start = i +1;
                curr_gas = 0;
            }
        }
        return (gas_til < 0 ? -1 : start);
        
    }
};