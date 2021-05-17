/* Cracking the coding interview 6
 * Problem 3.3 : Stack of Plates
 * You have an infinite number of stacks arranged in a row and numbered (left to right) from 0, 
 * each of the stacks has the same maximum capacity
 * 
 * int popAtStack(int index) Returns the value at the top of the stack with the given index and 
 * removes it from that stack, and returns -1 if the stack with that given index is empty.
 * 
 * Problem Link : https://leetcode.com/problems/dinner-plate-stacks/
 * 
 * Push : O(N)
 * Pop : O(N)
 * popAtIndex : O(N)
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class DinnerPlates {
private:
    int capacity;
public:
    map<int, vector<int> > mp;
    set<int> available;
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    void push(int val) {
        if(available.empty())
            available.insert(mp.size());
        mp[*available.begin()].push_back(val);
        if(mp[*available.begin()].size() == capacity)
            available.erase(available.begin());
    }
    
    int pop() {
        while(mp.size() and mp.rbegin()->second.empty()){
            mp.erase(mp.rbegin()->first);
        }
        if(mp.empty()) return -1;
        return popAtStack(mp.rbegin()->first);
    }
    
    int popAtStack(int index) {
        if(mp[index].empty())
            return -1;
        int res = mp[index].back();
        mp[index].pop_back();
        available.insert(index);
        if(mp[index].empty())
            mp.erase(index);
        return res;
    }
};