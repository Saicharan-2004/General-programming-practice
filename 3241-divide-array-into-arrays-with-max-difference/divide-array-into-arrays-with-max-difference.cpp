class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) 
    {
        if(arr.size()%3!=0)
        {
            return {};
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<(n);i+=3)
        {
            int r=i;
            cout<<i<<" ";
            if(r+2<arr.size())
            {
                if(abs(arr[i + 2] - arr[i]) <= k)
                {
                    vector<int>temp={arr[r],arr[r+1],arr[r+2]};
                    ans.push_back(temp);
                }
                else
                {
                    return {};
                }
            }
        }
        return ans;
    }
};