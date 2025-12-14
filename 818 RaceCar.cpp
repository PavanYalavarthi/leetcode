/*
Problem credits: https://leetcode.com/problems/race-car/

Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

Solution:
    Assume ceil(log(n +1)) is k

    We can stop just before target ie.  k -1, do reverse (+1), make j steps (j < k -1)  and revrse(+1) => #moves = k-1+1+j+1 => k + j+ 
    And distance is target - (1 << (k-1)) + (1 << j)

    Or

    we can jump ahead and then reverse
        #moves = k + 1 (for reverse)
        and distance is (1 << k) - target
*/
class Solution {
    unordered_map<int,int> mp;
public:
    int racecar(int target) {
        if (mp.find(target) != mp.end()) return mp[target];
        int & ans = mp[target]= INT_MAX;
        int k = 32 - __builtin_clz(target);
        if ((target & (target + 1)) == 0) return ans = k;
        for ( int j = 0; j < k - 1; j++)
            ans = min(ans, k + j + 1 + racecar(target - (1 << (k - 1)) + (1 << j)));
        return ans = min(ans, k + 1 + racecar((1 << k) - 1 - target));
    }
};


/*
BFS solution:

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        set<pair<int, int>>s;
        q.push({0, 1, 0});
        while(!q.empty()) {
            auto v= q.front();
            int pos = v[0], speed = v[1], steps = v[2];
            q.pop();
            if (pos == target)
                return steps;
            if (s.contains({pos, speed})) continue;
            s.insert({pos, speed});
            int nextPos = pos + speed;
            if (nextPos < 2 * target && nextPos >= 0)
                q.push({nextPos, speed << 1, steps + 1});
            if (nextPos > target && speed > 0) {
                q.push({pos, -1, steps+1});
            } else if (nextPos < target && speed < 0) {
                q.push({pos, 1, steps+1});
            } 
        }
        return 0;
    }
};
*/