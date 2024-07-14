class Solution {
public:
    int helper(int n,int m,vector<int>hori,vector<int>verti)
    {
        int vertiCount = 1;
        int horiCount = 1;
        sort(verti.begin(),verti.end());
        sort(hori.begin(),hori.end());
        int i = m-2;
        int j = n-2;
        int ans = 0;
        while(i>=0 && j>=0)
        {
            if(hori[i]>verti[j])
            {
                ans+=hori[i]*horiCount;
                vertiCount++;
                i--;
            }
            else
            {
                ans+=verti[j]*vertiCount;
                horiCount++;
                j--;
            }
        }
        while(i>=0)
        {
            ans+=hori[i]*horiCount;
            vertiCount++;
            i--;
        }
        while(j>=0)
        {
            ans+=verti[j]*vertiCount;
            horiCount++;
            j--;
        }
        return ans;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) 
    {
        return helper(n,m,horizontalCut,verticalCut);
    }
};