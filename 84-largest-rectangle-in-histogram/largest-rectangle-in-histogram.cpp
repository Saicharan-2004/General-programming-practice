class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        stack<int>temp;
        int n=arr.size();
        vector<int>prevSmaller(n,0);
        for(int i=0;i<n;i++)
        {
            while(!temp.empty() && arr[temp.top()] >= arr[i])
            {
                temp.pop();
            }
            if(temp.empty())
            {
                prevSmaller[i]=0;
            }
            else
            {
                prevSmaller[i]=temp.top()+1;
            }
            temp.push(i);
        }
        while(!temp.empty())
        {
            temp.pop();
        }
        vector<int>nextSmaller(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!temp.empty() && arr[temp.top()] >= arr[i])
            {
                temp.pop();
            }
            if(temp.empty())
            {
                nextSmaller[i]=n-1;
            }
            else
            {
                nextSmaller[i]=temp.top()-1;
            }
            temp.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i]);
            ans=max(ans,arr[i]*(nextSmaller[i]-prevSmaller[i]+1));
        }
        return ans;
    }
};