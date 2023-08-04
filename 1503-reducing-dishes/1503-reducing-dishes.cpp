class Solution {
public:
    int maxSatisfaction(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(arr[n-1]<0)
        {
            return 0;
        }
        else if(arr[0]>=0)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=arr[i-1]*i;
            }
            return ans;
        }
        else
        {
            int ans=INT_MIN;
            int start=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)
                {
                    start++;
                }
                else
                {
                    break;
                }
            }
            start--;
            while(start>=0)
            {
                int temp_ans=0;
                int d=1;
                for(int i=start;i<n;i++)
                {
                    temp_ans+=(d*arr[i]);
                    d++;
                }
                ans=max(temp_ans,ans);
                start--;
            }
            return ans;
        }
    }
};