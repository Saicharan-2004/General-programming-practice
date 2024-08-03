#include<bits/stdc++.h>
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>tp;
        for(auto it:target)
        {
            tp[it]++;
        }
        for(auto it:arr)
        {
            tp[it]--;
        }
        for(auto it:tp)
        {
            if(it.second < 0)
            {
                return false;
            }
        }
        return true;
    }
};