class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>right(n,1);
        for(int i=n-2;i>=0;i--)
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1] +1;
        int candy = right[0];
        for(int i=1, left = 1;i<n;i++){
            if(ratings[i] > ratings[i-1]) left++;
            else left =1;
            candy += max(left,right[i]);
        }
        return candy;
    }
};