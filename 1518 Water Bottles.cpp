class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int newBottles, emptyBottles = numBottles, ans =  numBottles;
        while(emptyBottles >= numExchange) {
          newBottles = emptyBottles / numExchange;
          ans += newBottles;
          emptyBottles = newBottles + emptyBottles % numExchange;
        } 
        return ans;
    }
};