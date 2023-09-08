class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows==1)
        {
            vector<vector<int>> final;
            final.push_back({1});
            return final;
        }
        vector<vector<int>> final=generate(numRows-1);
        vector<int>temp=final[final.size()-1];
        vector<int> ToPush;
        ToPush.push_back(1);
        for(int i=1;i<temp.size();i++)
        {
            ToPush.push_back(temp[i]+temp[i-1]);
        }
        ToPush.push_back(1);
        final.push_back(ToPush);
        return final;
    }
};