/*
Problem credits: https://leetcode.com/problems/minimum-number-of-people-to-teach/

On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the ith user knows, and
friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


Solution:
    Keep track of user and language flag in form of bitset. And if a and b doesnt have any common add them to needed and pick any language and see how many users needed to learn it. And pick min count

*/
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<bitset<501>>knownLang(m+1);
        for(int i = 1; i <= m; i++) {
            for(int lang: languages[i-1])
                knownLang[i][lang] = 1;
        }
        bitset<501>needed;
        for(auto& frndShip: friendships) {
            int a = frndShip[0], b = frndShip[1];
            if ((knownLang[a] & knownLang[b]).any()) continue;
            needed[a] = needed[b] = 1;
        }

        if (needed.count() == 0) return 0;

        int ans = INT_MAX;

        for(int lang = 1; lang <= n; lang++) {
            int toLearn = 0;
            for(int user = 1; user <= m; user++) {
                if (needed[user] && !knownLang[user][lang]) toLearn++;
            }
            ans = min(ans, toLearn);
        } 
        return ans;

    }
};