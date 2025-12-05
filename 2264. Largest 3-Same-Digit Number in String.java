class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";
        int count = 1;
        char prev = num.charAt(0);
        for(int i = 1;i<num.length();i++){
            if(num.charAt(i) == prev){
                count++;
                if(count == 3){
                    String tmp = num.substring(i-2,i+1);
                    if(ans.compareTo(tmp) < 0) ans = tmp;
                }
            } else {
                count = 1;
                prev = num.charAt(i);
            }
        }
        return ans;
    }
}