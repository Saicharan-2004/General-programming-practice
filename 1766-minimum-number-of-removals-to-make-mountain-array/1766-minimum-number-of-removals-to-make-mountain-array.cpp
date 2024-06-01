class Solution {
public:
    vector<int> findlis(vector<int> &nums)
    {
        vector<int> lis(nums.size(),0);
        vector<int> vec;
        vec.push_back(nums[0]); 
        lis[0] = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] > vec.back())    
                vec.push_back(nums[i]);
            else
            {
                int idx = lower_bound(vec.begin() , vec.end() , nums[i]) - vec.begin();
                vec[idx] = nums[i];
            }
            lis[i] = vec.size();
        }
        return lis;
    }
    int mysol(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>lis(n);
        vector<int>lds(n);
        for(int i=0;i<n;i++)
        {
            lis[i]=1;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i] = max(lis[i],1 + lis[j]);
                }
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            lds[i]=1;
            for(int j = i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    lds[i] = max(lds[i],1 + lds[j]);
                }
            }
        }
        int ans = -1;
        for(auto it : lis)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it :lds)
        {
            cout<<it<<" ";
        }
        for(int i = 0;i<n;i++)
        {
            if(lis[i]>1 && lds[i] >1)
                ans = max (ans , (lis[i] + lds[i] - 1));
        }
        return n-ans;
    }
    int minimumMountainRemovals(vector<int>& nums) 
    {
        vector<int> frontlis = findlis(nums);
        reverse(nums.begin() , nums.end());
        vector<int> revlis = findlis(nums);
        reverse(revlis.begin() , revlis.end());
        int maxlen = 0;
        for(int i = 0 ; i < frontlis.size() ; i++)
        {
            if(frontlis[i] == 1 || revlis[i] == 1)  
                continue;
            maxlen = max(maxlen , frontlis[i] + revlis[i] - 1);
        }
        return nums.size() - maxlen;
    }
};