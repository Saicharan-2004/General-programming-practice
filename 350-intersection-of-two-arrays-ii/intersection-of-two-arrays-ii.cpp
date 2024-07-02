class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>tp;
        for(auto it:nums1)
        {
            tp[it]++;
        }
        vector<int>ans;
        for(auto it:nums2)
        {
            if(tp[it]>0)
            {
                tp[it]--;
                ans.push_back(it);
            }
        }
        return ans;
    }
};