class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        vector<int>prefix;
        vector<int>suffix;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix.push_back(sum);
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            suffix.push_back(sum);
            sum+=nums[i];
        }
        // for(auto it:prefix)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        reverse(suffix.begin(),suffix.end());
        // for(auto it:suffix)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=(2*i+1-n)*nums[i]+suffix[i]-prefix[i];
        }
        // for(auto it:ans)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};