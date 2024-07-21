class Solution {
public:
    int maxOperations(string s) {
        int countOnes = 0;
        int ans = 0;
        int i = 0;
        int n = s.size();
        while(i<s.size())
        {
            int count = 0;
            while(s[i] == '1')
            {
                count++;
                i++;
            }
            while(i<n-1 && s[i+1] == '0')
            {
                i++;
            }
            if(i<n && s[i] == '0')
            {
                countOnes+=count;
                cout<<countOnes<<endl;
                ans+=countOnes;
                i++;    
            }
        }
        return ans;
    }
};