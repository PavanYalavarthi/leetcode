class Solution {
    public String minRemoveToMakeValid(String s) {
        int close = 0, flag = 0;
        for(int i =0 ; i<s.length();i++){
            if(s.charAt(i) == '(')
                flag++;
            else if (s.charAt(i) == ')' && flag > 0){
                close++;
                flag--;
            }
        }
        int open = close;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i< s.length(); i++) {
            char c = s.charAt(i);
            if( c == '('){
                if(open == 0) continue;
                open--;
            } else if( c == ')'){
                if(close <= open) continue;
                close--;
            }
            sb.append(c);
        }
        return sb.toString();
    }
}