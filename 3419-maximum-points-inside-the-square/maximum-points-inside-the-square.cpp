class Solution {
public:
    static bool compareBy(const pair<pair<int,int>,char>& p1, const pair<pair<int,int>,char>& p2) 
    { 
        return p1.first.second < p2.first.second; 
    }
    // int longestCommonSubsequence(string& text1, string& text2)
    // {
    //     int n = text1.size();
    //     int m = text2.size();

    //     // initializing 2 vectors of size m
    //     vector<int> prev(m + 1, 0), cur(m + 1, 0);

    //     for (int idx2 = 0; idx2 < m + 1; idx2++)
    //         cur[idx2] = 0;

    //     for (int idx1 = 1; idx1 < n + 1; idx1++) {
    //         for (int idx2 = 1; idx2 < m + 1; idx2++) {
    //             // if matching
    //             if (text1[idx1 - 1] == text2[idx2 - 1])
    //                 cur[idx2] = 1 + prev[idx2 - 1];

    //             // not matching
    //             else
    //                 cur[idx2]
    //                     = 0 + max(cur[idx2 - 1], prev[idx2]);
    //         }
    //         prev = cur;
    //     }

    //     return cur[m];
    // }
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // vector<pair<pair<int,int>,char>>tp;
        int n = points.size();
        // vector<unordered_set<int>>checker(26,0);
        vector<pair<int,char>>tp;
        int maxi = -1;
        for(int i = 0;i<n;i++)
        {
            int r = max(abs(points[i][0]),abs(points[i][1]));
            tp.push_back({r,s[i]});
        }
        sort(tp.begin(),tp.end());
        unordered_set<char>tillNow;
        int prevNumber = 0;
        for(int i = 0;i<tp.size();i++)
        {
            if(tillNow.find(tp[i].second) == tillNow.end())
            {
                tillNow.insert(tp[i].second);
            }
            else
            {
                if(tp[prevNumber].first == tp[i].first)
                {
                    return max(0,prevNumber);
                }
                else
                {
                    return prevNumber + 1;
                }
            }
            prevNumber = i;
        }
        return tp.size();
        // for(auto it:dist)
        // {

        // }
        // unordered_set<char>ans;
        
        // sort(tp.begin(),tp.end());
        // string str = "";
        // for(int i = 0;i<n;i++)
        // {
        //     str+=tp[i].second; 
        // }
        // string str2 = "";
        // sort(tp.begin(),tp.end(),compareBy);
        // for(int i = 0;i<n;i++)
        // {
        //     str2+=tp[i].second; 
        // }
        // cout<<str<<" "<<str2<<" ";
        // return longestCommonSubsequence(str,str2);
    }
};