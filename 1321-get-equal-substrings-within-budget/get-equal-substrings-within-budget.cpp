class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.length();
        vector<int>temp(n);
        for(int i = 0 ; i < n ; i++)
        {
            temp[i] = abs(s[i]-t[i]);
            cout<<temp[i]<<" ";
        }
        int maxi = 0;
        int start = 0;
        int sum = 0;
        int end = 0;
        while(end < n)
        {
            sum+=temp[end];
            while(sum > maxCost)
            {
                sum -= temp[start];
                start++;
            }
            maxi = max(maxi, end - start + 1);
            end++;
        }
        return maxi;
    }
};