class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> st = new Stack<>();
        Stack<Integer> sr = new Stack<>();
        int count = 0;
        for(int i = 0; i< s.length(); i++){
            char c = s.charAt(i);
            if(c == '(')
                st.push(i);
            else if(c == '*')
                sr.push(i);
            else {
                if(st.isEmpty() && sr.isEmpty()) return false;
                else if(!st.isEmpty()) st.pop();
                else sr.pop();
            }
        }
        while(!st.isEmpty()){
            if(sr.isEmpty() || st.peek() > sr.peek()) return false;
            sr.pop();
            st.pop();
        }
        return true;
    }
}