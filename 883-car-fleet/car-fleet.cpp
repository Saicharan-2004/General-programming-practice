#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<float,float>>arr;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        // reverse(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            arr[i].second=(target-arr[i].first)/arr[i].second;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i].second<<" ";
        // }
        // cout<<endl;
        stack<float>prevGreater;
        // unordered_set<double>temp;
        for(int i=0;i<n;i++)
        {
            while(!prevGreater.empty() && prevGreater.top()<=arr[i].second)
            {
                prevGreater.pop();
            }
            prevGreater.push(arr[i].second);
        }
        return prevGreater.size();
    }
};