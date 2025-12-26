/*
problem credits: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Solution:
    Construct dag based on dependencies and find topo sort and push the items
*/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> s(supplies.begin(), supplies.end());

        vector<int>inDegree(n, 0);
        vector<vector<int>>gr(n);
        for(int i = 0; i < n; i++) {
            for(string ingredient: ingredients[i]) {
                if (s.count(ingredient) == 0) {
                    inDegree[i]++;
                    auto it = find(recipes.begin(), recipes.end(), ingredient);
                    if (it == recipes.end()) break;
                    gr[it - recipes.begin()].push_back(i);
                }
            }
        }
        queue<int>q;
        for(int i = 0; i < n ; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<string> ans;
        while(!q.empty()) {
            int ingredient = q.front();
            ans.push_back(recipes[ingredient]);
            q.pop();
            for(int child: gr[ingredient]) {
                inDegree[child]--;
                if (inDegree[child] == 0)
                    q.push(child);
            }
        }
        return ans;
    }
};