/*
problem credits: https://leetcode.com/problems/minimum-deletions-to-make-alternating-substring/description/

You are given a string s of length n consisting only of the characters 'A' and 'B'.

You are also given a 2D integer array queries of length q, where each queries[i] is one of the following:

[1, j]: Flip the character at index j of s i.e. 'A' changes to 'B' (and vice versa). This operation mutates s and affects subsequent queries.
[2, l, r]: Compute the minimum number of character deletions required to make the substring s[l..r] alternating. This operation does not modify s; the length of s remains n.
A substring is alternating if no two adjacent characters are equal. A substring of length 1 is always alternating.

Return an integer array answer, where answer[i] is the result of the ith query of type [2, l, r].

 

Solution:
    Initially, updtae BIT with 1 at index i when s[i] == s[i-1]

    Later when char at particular index changes, it effcetsr left and right indices. Update BIT as required.
*/

struct BIT {
	vector<int>v;
	BIT(int n) {
		v.assign(n+1, 0);
	}
	void update(int index, int val) {
		for(; index < v.size(); index += index & -index)
			v[index] += val;
	}

	int query(int index) {
		int sum = 0;
		for(; index > 0; index -= index & -index)
			sum += v[index];
		return sum;
	}

    int range_query(int l, int r) {
        return query(r) - (l ? query(l-1) : 0);
    }
};
class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        BIT bit(n);
        for(int i = 1; i< n; i++) {
            if (s[i] == s[i-1])
                bit.update(i, 1);
        }
        vector<int> ans;
        for(auto& q: queries) {
            if (q[0] == 1) {
                int index = q[1];
                if (index > 0 && s[index] == s[index -1]) bit.update(index, -1);
                if (index + 1 < n && s[index] == s[index + 1]) bit.update(index + 1, -1);

                s[index] = (s[index] == 'A' ? 'B' : 'A');

                if (index > 0 && s[index] == s[index -1]) bit.update(index, 1);
                if (index + 1 < n && s[index] == s[index + 1]) bit.update(index + 1, 1);
                
            } else {
                int l = q[1], r = q[2];
                ans.push_back(bit.range_query(l+1, r));
            }
        }
        return ans;
    }
};