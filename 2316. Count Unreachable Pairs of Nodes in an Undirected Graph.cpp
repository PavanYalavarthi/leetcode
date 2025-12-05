class Solution {
    vector<int>par, size;
    int find(int x) {
        while (par[x] != x) {
            x = par[par[x]];
        }
        return x;
    }
    void unite(int x, int y) {
        int parX = find(x), parY = find(y);
        if (parX != parY) {
            if (size[parY] > size[parX]) swap(parY, parX);
            par[parX] = parY;
            size[parY] += size[parX];
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        size.resize(n, 1);
        for(const auto&e : edges) unite(e[0], e[1]);
        long res = 0, total = 0;
        for(int i=0;i<n;i++) {
            if (par[i] == i) {
                res += size[i] * total;
                total += size[i];
            }
        }
        return res;
    }
};