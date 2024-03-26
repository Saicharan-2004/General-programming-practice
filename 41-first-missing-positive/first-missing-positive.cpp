class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>temp;
        for(auto it:nums)
        {
            temp.insert(it);
        }
        for(int i=1;i<=1e5;i++)
        {
            if(temp.find(i)==temp.end())
            {
                return i;
            }
        }
        return 1e5+1;
    }
};