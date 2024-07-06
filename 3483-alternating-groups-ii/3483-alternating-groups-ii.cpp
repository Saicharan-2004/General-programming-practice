class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>newColors(colors);
        for(int i=0;i<k-1;i++)
        {
            newColors.push_back(colors[i]);
        }
        int n = newColors.size();
        int count = 1;
        int finAns = 0;
        for(int i=0;i<n-1;i++)
        {
            if(newColors[i]!=newColors[i+1])
            {
                count++;
            }
            else
            {
                // cout<<count<<endl;
                finAns += max(0,count+1-k);
                count=1;
            }
        }
        finAns += max(0,count+1-k);
        return finAns;
    }   
};