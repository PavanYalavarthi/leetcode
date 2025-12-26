/*
problem credits: https://leetcode.com/problems/count-mentions-per-user/description/

You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
This event indicates that a set of users was mentioned in a message at timestampi.
The mentions_stringi string can contain one of the following tokens:
id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
ALL: mentions all users.
HERE: mentions all online users.
Offline Event: ["OFFLINE", "timestampi", "idi"]
This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.


Solution:
    Sort even ts based on time, if it is same, offline needed to be first

    And rest is simulation
*/

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto&b) {
            int t1 = stoi(a[1]), t2 = stoi(b[1]);
            return ((t1 == t2) ? (a[0][0] > b[0][0]) : (t1 < t2));
        });
        
        vector<int>mentions(numberOfUsers, 0);
        vector<int>offline(numberOfUsers, 0);
        int all = 0;
        for(auto& event: events) {
            if (event[0][0] == 'O') {
                int t = stoi(event[1]), user = stoi(event[2]);
                offline[user] = t + 60;
            } else {
                int t = stoi(event[1]);
                string s = event[2];
                int n = s.size();
                for(int i = 0; i < n; ) {
                    if (s[i] == 'A') {
                        all++;
                        i += 3;
                    } else if (s[i] == 'H') {
                        for(int i = 0; i < numberOfUsers; i++) {
                            if (offline[i] <= t) {
                                mentions[i]++;
                            }
                        }
                        i += 4;
                    } else {
                        i += 2;
                        int user = 0;
                        cout << i << " " << s[i] << endl;
                        while(i < n && s[i] != ' ') {
                            user = user * 10 + (s[i] - '0');
                            i++;
                        }
                        i++;
                        mentions[user]++;
                    }
                }
            }
        }
        if (all != 0) {
            for(int& val: mentions) {
                val += all;
            }
        }
        return mentions;
    }
};