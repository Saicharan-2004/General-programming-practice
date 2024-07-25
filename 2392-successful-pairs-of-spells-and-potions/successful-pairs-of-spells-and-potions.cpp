class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int n  = potions.size();
        int m = spells.size();
        sort(potions.begin(),potions.end());
        for(auto it:spells)
        {
            int start = 0;
            int end = n-1;
            double gif = success%it == 0 ? success/it : success/it + 1;
            int num = lower_bound(potions.begin(),potions.end(),gif)-potions.begin();
            ans.push_back(n-num);
        }
        return ans;
    }
};