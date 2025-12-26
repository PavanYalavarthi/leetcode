/*
Problem credits: https://leetcode.com/problems/pass-the-pillow/description/

There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

Solution:
    For each round we need n-1 hops. So we see #cycles we completed and remaining

    If #cycles is odd, then its rem from left else from right
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int cycles = time / (n - 1), rem = time % (n - 1);
        return (cycles & 1) == 0 ? 1 + rem : n - rem;
    }
};