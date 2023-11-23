class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool>ans;
        for(int i=0;i<l.size();i++)
        {
            int left=l[i];
            int right=r[i];
            vector<int>temp;
            for(int j=left;j<=right;j++)
            {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            if(temp.size()==1||temp.size()==2)
            {
                ans.push_back(true);
                continue;
            }
            int diff=temp[1]-temp[0];
            
            for(int j=2;j<temp.size();j++)
            {
                if(temp[j]-temp[j-1]!=diff)
                {
                    ans.push_back(false);
                    diff=temp[j]-temp[j-1];
                    break;
                }
            }
            if(diff==temp[1]-temp[0])
            {
                ans.push_back(true);
            }
        }
        return ans;
    }
};