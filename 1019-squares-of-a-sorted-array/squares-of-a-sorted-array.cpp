class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) 
    {
        int n=arr.size();
        int ind_neg=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=0)
            {
                ind_neg=i;
                break;
            }
        }
        vector<int>ans;
        if(ind_neg==-1)
        {
            ind_neg=n;
        }
        int ind=ind_neg-1;
        while(ind>=0 && ind_neg<n)
        {
            if(arr[ind]*arr[ind]<=arr[ind_neg]*arr[ind_neg])
            {
                ans.push_back(arr[ind]*arr[ind]);
                ind--;
            }
            else
            {
                ans.push_back(arr[ind_neg]*arr[ind_neg]);
                ind_neg++;
            }
        }
        while(ind>=0)
        {
            ans.push_back(arr[ind]*arr[ind]);
            ind--;
        }
        while(ind_neg<n)
        {
            ans.push_back(arr[ind_neg]*arr[ind_neg]);
            ind_neg++;
        }
        return ans;
    }
};