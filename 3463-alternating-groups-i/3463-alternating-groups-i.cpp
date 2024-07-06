class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int n = colors.size();
        int ans=0;
        for(int i = 1;i<n-1;i++)
        {
            if(colors[i-1] == colors[i+1])
            {
                if(colors[i-1]!=colors[i])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};