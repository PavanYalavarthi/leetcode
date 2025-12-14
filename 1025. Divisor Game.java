/*
Problem credits: https://leetcode.com/problems/divisor-game/

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any integer x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

Solution: 
    If it is even, make it odd such that we can make them face 1 and there will be no option.
*/
class Solution {
    public boolean divisorGame(int n) {
        return (n & 1) == 0;
    }
}