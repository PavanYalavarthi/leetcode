class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), j = n, sum =0;
        for(int i = 0; i< n/3;i++){
            sum += piles[j-=2];
        }
        return sum;
    }
};