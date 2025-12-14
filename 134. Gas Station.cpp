/*

Problem credits: https://leetcode.com/problems/gas-station/

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Solution:
    keep gas_til keeping + (gas[i] - cost[i]) and cur_gas + (gas[i] - cost[i]),
        If cur_gas < 0, then whatever we picked the start is not wring, so setting start to be i + 1
*/
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