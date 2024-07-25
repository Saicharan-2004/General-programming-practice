class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        // int n  = potions.size();
        sort(potions.begin(),potions.end());
        for(auto it:spells)
        {
            double gif = success%it == 0 ? success/it : success/it + 1;
            int num = lower_bound(potions.begin(),potions.end(),gif)-potions.begin();
            ans.push_back(potions.size()-num);
        }
        return ans;
    }
};