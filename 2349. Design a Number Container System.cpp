/*
Problem credits: https://leetcode.com/problems/design-a-number-container-system/description/

Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

Solution:
    Use priority queue for index retrival and map for storing umber at givemn index to make every operation at o(1)
*/
class NumberContainers {
    unordered_map<int, int> mp;
    unordered_map<int, priority_queue<int>> heap;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (mp.count(index)) {
            int prev = mp[index];
            if (prev == number) return;
        }
        mp[index] = number;
        heap[number].push(-index);
    }
    
    int find(int number) {
        auto& indexHeap = heap[number];
        while(!indexHeap.empty() && mp[-indexHeap.top()] != number) indexHeap.pop();
        return indexHeap.empty() ? -1 : -indexHeap.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */