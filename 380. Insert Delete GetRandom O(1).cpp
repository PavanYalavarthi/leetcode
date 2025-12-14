/*
    Problem credits: https://leetcode.com/problems/insert-delete-getrandom-o1/

    Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.


Solution: As deletion needed to be O(1), we needed to use map to store indices at which element exists
And while deleting, swap it will last element and pop in back


*/
class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int> um;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(um.find(val) != um.end()) return false;
        v.push_back(val);
        um.insert({val,v.size()-1});
        return true;
    }
    
    bool remove(int val) {
        if(um.find(val) == um.end()) return false;
        int last = v.back();
        um[last] = um[val];
        v[um[val]] = last;
        v.pop_back();
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */