class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) 
    {
        int start=0;
        int end=0;
        int n=arr.size();
        long long int sum=0;
        while(end<n && start<n)
        {
            if(end<n)
            {
                if(arr[end]!=0)
                {
                    if(arr[start]==0)
                    {
                        long long int it=end-start;
                        sum+=(long long int)(((it)*(it+1))/2);
                        start=end;
                    }
                    else
                    {
                        start++;
                        end++;
                    }
                }
                else
                {
                    end++;
                }
            }
        }
        long long int it=end-start;
        sum+=(long long int)(((it)*(it+1))/2);
        return sum;
    }
};