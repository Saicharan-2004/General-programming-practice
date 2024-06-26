class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        // unordered_set<int>temp;
        int n = meetings.size();
        // int ans = 0;
        sort(meetings.begin(),meetings.end());
        // int beg=meetings[0][0];
        // int end=meetings[0][1];
        // vector<pair<int,int>>tp;
        // for(int i = 1;i<n;i++)
        // {
        //     if(meetings[i][0] <= end + 1)
        //     {
        //         end = max(end,meetings[i][1]);
        //     }
        //     else
        //     {
        //         tp.push_back({beg,end});
        //         beg = meetings[i][0];
        //         end = meetings[i][1];
        //     }
        // }
        // tp.push_back({beg,end});
        // int avail = 0;
        for(auto it:meetings)
        {
            cout<<it[0]<<" "<<it[1]<<":";
        }
        cout<<endl;
        int ans = 0;
        int prev = 1;
        for(int i = 0;i<n;i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            if(start > prev)
            {
                if(i == 0)
                {
                    ans += start - prev;
                }
                else
                {
                    ans += start - prev - 1;
                }
            }
            prev = max(prev,end);
        }
        if(days > prev)
        {
            ans +=days-prev;
        }
        return ans;
        // if(tp[0].first != 1)
        // {
        //     avail +=tp[0].first - 1;
        // }
        // for(int i = 1;i<tp.size();i++)
        // {
        //     avail +=  tp[i].first - tp[i-1].second - 1;
        // }
        // if(tp[tp.size() - 1].second < days)
        // {
        //     avail += days - tp[tp.size() - 1].second;
        // }
        // return avail;
    }
};