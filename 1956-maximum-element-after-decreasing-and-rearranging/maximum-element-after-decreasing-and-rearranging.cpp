class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++)
        {
            if(abs(arr[i]-arr[i-1])<=1)
            {
                continue;
            }
            else
            {
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
        // int n=arr.size();
        // unordered_map<int,int>tp;
        // for(auto it:arr)
        //     tp[it]++;
        // int maxOccr=0;
        // int req=-1;
        // for(auto it:tp)
        // {
        //     if(it.second>maxOccr)
        //     {
        //         maxOccr=it.second;
        //         req=it.first;
        //     }
        // }
        // return min(req,n);
    }
};