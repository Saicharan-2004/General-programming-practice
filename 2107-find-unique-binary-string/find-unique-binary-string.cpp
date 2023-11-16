class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n=nums.size();
        unordered_set<int>r;
        for(auto it:nums)
        {
            r.insert(stoi(it,0,2));
        }
        for(int i=0;i<=pow(2,n);i++)
        {
            if(r.find(i)==r.end())
            {
                string er=bitset<16>(i).to_string();
                return er.substr(16-n);
            }
        }
        return " ";
    }
};