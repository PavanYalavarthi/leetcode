class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        if(n < 4) return arr[0];
        int q = n / 4;
        for(int i = q; i < n;i++)
            if(arr[i-q] == arr[i]) 
                return arr[i];
        return -1;
    }
}