class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        int maxi=-1;
        unordered_map<int,vector<int>>temp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                maxi=max(maxi,i+j);
                temp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<=maxi;i++)
        {
            for(auto it:temp[i])
            {
                ans.push_back(it);
            }
        }
        return ans;
    //     int m=nums.size();
    //     vector<int>ans;
    //     int n=-1;
    //     for(auto it:nums)
    //     {
    //         int r=it.size();x
    //         n=max(n,r);
    //     }
    //     set<pair<int,int>>checker;
    //     for(int j=0;j<n;j++)
    //     {
    //         for(int i=0;i<m;i++)
    //         {
    //             int t1=i;
    //             int t2=j;
    //             while(t1>=0 && t2<nums[t1].size())
    //             {
    //                 if(t2<nums[t1].size())
    //                 {
    //                     if(checker.find({t1,t2})==checker.end())
    //                         ans.push_back(nums[t1][t2]);
    //                 }
    //                 checker.insert({t1,t2});
    //                 t2++;
    //                 t1--;
    //             }
    //     }
    //     }
    //     return ans;
    }
};