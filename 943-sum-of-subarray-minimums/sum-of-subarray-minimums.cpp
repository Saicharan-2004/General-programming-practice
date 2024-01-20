class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int counter=1;
        int n=arr.size();
        vector<long long>right(n);
        vector<long long>left(n);
        stack<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            while(!temp.empty() && temp.top().first>=arr[i])
            {
                counter+=temp.top().second;
                temp.pop();
            }
            temp.push({arr[i],counter});
            left[i]=counter;
            counter=1;
        }
        while(!temp.empty())
        {
            temp.pop();
        }
        // reverse(arr.begin(),arr.end());
        counter=1;
        for(int i=n-1;i>=0;i--)
        {
            while(!temp.empty() && temp.top().first>arr[i])
            {
                counter+=temp.top().second;
                temp.pop();
            }
            temp.push({arr[i],counter});
            right[i]=counter;
            counter=1;
        }
        // long ans=0;
        int modu=1e9+7;
        long long result = 0;
        for (int i = 0; i < n; i++) 
        {
            result = (result + (arr[i] * left[i] * right[i])%modu) % modu;
        }
        return (int)result;
    }
};