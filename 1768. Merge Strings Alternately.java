class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        StringBuilder sb = new StringBuilder(m + n );
        for(int i = 0; i < Math.min(m, n); i++) {
            sb.append(word1.charAt(i));
            sb.append(word2.charAt(i));
        }
        for(int i = Math.min(m, n); i < m; i++) {
            sb.append(word1.charAt(i));
        }
        for(int i = Math.min(m, n); i < n; i++) {
            sb.append(word2.charAt(i));
        }
        return sb.toString();

    }
}