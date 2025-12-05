class Solution {
public:
    int pivotInteger(int n) {
        int leftsum = n * (n + 1) / 2, rightsum = n;
        while(leftsum > rightsum) {
            leftsum -= n;
            n--;
            rightsum += n;
        }
        return (leftsum == rightsum) ? n : -1;
    }
};