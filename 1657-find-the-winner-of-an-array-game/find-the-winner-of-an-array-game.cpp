class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int maxi=-1;
        for(int i=0;i<n;i++)
            maxi=max(maxi,arr[i]);
        if(k>=n)
            return maxi;
        int curr=arr[0];
        int consecutive=0;
        for(int i=1;i<n;i++)
        {
            if(curr>arr[i])
            {
                consecutive++;
            }
            else
            {
                consecutive=1;
                curr=arr[i];
            }
            if(consecutive==k)
                return curr;
        }
        return curr;
    }
};