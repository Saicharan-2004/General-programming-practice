class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string>ans;
        unordered_set<int>temp;
        for(int i=0;i<target.size();i++)
        {
            temp.insert(target[i]);
        }
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(temp.find(i+1)!=temp.end())
            {
                ans.push_back("Push");
                counter++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(counter==target.size())
                break;
        }
        return ans;
    }
};