class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) 
    {
        int n=arr.size();
        stack<int>temp;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!temp.empty() && arr[temp.top()]<=arr[i])
            {
                temp.pop();
            }
            if(temp.empty())
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=temp.top()-i;
            }
            temp.push(i);
        }
        return ans;
    }
};