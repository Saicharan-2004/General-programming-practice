class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>temp;
        for(auto it:s)
        {
            temp[it]++;
        }
        vector<pair<int,int>>ans;
        for(auto it:s)
        {
            ans.push_back({temp[it],it});
        }
        sort(ans.begin(),ans.end());
        string answer="";
        unordered_set<char>r;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(r.find(ans[i].second)==r.end())
            {
                while(ans[i].first!=0)
                {
                    answer+=ans[i].second;
                    ans[i].first--;
                }
            }
            r.insert(ans[i].second);
        }
        return answer;
    }
};