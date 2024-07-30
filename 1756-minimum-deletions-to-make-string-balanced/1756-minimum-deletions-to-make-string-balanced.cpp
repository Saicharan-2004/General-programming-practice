class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>tp;
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            char it = s[i];
            if(!tp.empty() && tp.top() =='b' && it == 'a')
            {
                count++;
                // cout<<it<<" ";  
                tp.pop();
            }
            else
            {
                tp.push(it);
            }
        }
        return count;
    }
};