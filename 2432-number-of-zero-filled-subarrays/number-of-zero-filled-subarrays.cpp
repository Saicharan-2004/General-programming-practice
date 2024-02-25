class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) 
    {
        vector<long long int>temp;
        int start=0;
        int end=0;
        int n=arr.size();
        while(end<n && start<n)
        {
            if(end < n && arr[start]!=0 && arr[end]!=0)
            {
                start++;
                end++;
            }
            if(end<n && arr[end]==0)
            {
                end++;
            }
            if(end<n && arr[start]==0 && arr[end]!=0)
            {
                temp.push_back(end-start);
                start=end;
            }
        }
        temp.push_back(end-start);
        long long int sum=0;
        for(auto it:temp)
        {
            sum+=(long long int)(((it)*(it+1))/2);
        }
        return sum;
    }
};