class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a = cost[0], b =cost[1], c;
        for(int i = 2; i < cost.length ;i++){
            c = cost[i] + Math.min(a,b);
            a = b;
            b = c;
        }
        return Math.min(a,b);
    }
}