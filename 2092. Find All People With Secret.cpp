/*
problem credits: https://leetcode.com/problems/find-all-people-with-secret/description/

You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

Solution:
    Use dsu to create edges between persons and if they arte unble to get secret, remove them
*/

struct DSU {
    vector<int> par;

    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        int u = find(x), v = find(y);
        par[u] = v;
    }

    void reset(int x) {
        par[x] = x;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> meetingPerTime;
        for (auto& meeting : meetings) {
            int a = meeting[0], b = meeting[1], t = meeting[2];
            meetingPerTime[t].emplace_back(a, b);
        }

        DSU dsu(n);
        dsu.unite(firstPerson, 0);

        for (auto& [t, meetings] : meetingPerTime) {
            for (auto& [a, b] : meetings) {
                dsu.unite(a, b);
            }
            for (auto& [a, b] : meetings) {
                if (dsu.find(a) != dsu.find(0)) {
                    dsu.reset(a);
                    dsu.reset(b);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dsu.find(i) == dsu.find(0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};



