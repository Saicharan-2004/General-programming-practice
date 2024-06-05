class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>>tp;
        int n = words.size();
        vector<unordered_map<char,int>>r;
        unordered_map<char,int>top;
        for(auto it:words[0])
        {
            top[it]++;
        }
        r.push_back(top);
        for(int i = 1;i<n;i++)
        {
            unordered_map<char,int>tp;
            for(auto it:words[i])
            {
                if(top.find(it) != top.end())
                {
                    tp[it]++;
                }
            }
            r.push_back(tp);
        }
        vector<string>ans;
        for(auto it:top)
        {
            int count = it.second;
            for(int i = 1;i<n;i++)
            {
                if(r[i].find(it.first) != r[i].end())
                {
                    int qwer = r[i][it.first];
                    count=min(count,qwer);
                }
                else
                {
                    count=0;
                    break;
                }
            }
            string an="";
            an +=it.first;
            while(count>0)
            {
                ans.push_back(an);
                count--;
            }
        }
        return ans;
    }
};