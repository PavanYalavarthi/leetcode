class Solution {
    public int passThePillow(int n, int time) {
       n--;
       int chunks = time / n, p = time % n;
       return 1 + ((chunks & 1) == 0 ? p : n - p);
    }
}