class Solution {
public:
    int canFormed(string word, vector<int> v){
        for(char c : word)
            if(!(v[c-'a']--))
                return 0;
        return word.length();
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        for(char c : chars)
            v[c - 'a']++;
        int c = 0;
        for(string word : words)
            c += canFormed(word, v);
        return c;
    }
};