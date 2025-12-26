/*
Problem credits: https://leetcode.com/problems/water-bottles/

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

SOlution:
  Simulate the behaviour.
*/
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