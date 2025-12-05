class Solution {
    public String makeGood(String s) {
        Stack<Character> st= new Stack<>();
        for(int i = 0 ; i < s.length(); i++){
            if(st.isEmpty() || Math.abs(st.peek() - s.charAt(i)) != 32)
                st.push(s.charAt(i));
            else
                st.pop();
        }
        String ans = "";
        for(Character c : st) {
            ans += c;
        }
        return ans;
    }
}