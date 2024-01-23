class Solution {
public:
int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        
        for (const string& s : arr) {
            int a = 0, dup = 0;
            for (char c : s) {
                dup |= a & (1 << (c - 'a'));
                a |= 1 << (c - 'a');
            }
            
            if (dup > 0)
                continue;
            
            for (int i = dp.size() - 1; i >= 0; i--) {
                if ((dp[i] & a) > 0)
                    continue;
                dp.push_back(dp[i] | a);
                res = max(res, __builtin_popcount(dp[i] | a));
            }
        }
        
        return res;
    }
    // struct hash_pair 
    // {
    //     template <class T1, class T2>
    //     size_t operator()(const pair<T1, T2>& p) const
    //     {
    //         auto hash1 = hash<T1>{}(p.first);
    //         auto hash2 = hash<T2>{}(p.second);
    
    //         if (hash1 != hash2) {
    //             return hash1 ^ hash2;              
    //         }
            
    //         // If hash1 == hash2, their XOR is zero.
    //         return hash1;
    //     }
    // };
    // int helper(vector<string>arr,int ind,string uptillnow,unordered_map<pair<string,int>,int,hash_pair>&dp)
    // {
    //     if(ind==arr.size())
    //     {
    //         return 0;
    //     }
    //     if(dp.find({uptillnow,ind})!=dp.end())
    //     {
    //         return dp[{uptillnow,ind}];
    //     }
    //     int nottake=helper(arr,ind+1,uptillnow,dp);
    //     int take=INT_MIN;
    //     unordered_map<char,int>temp;
    //     unordered_set<char>temp1;
    //     bool check=false;
    //     for(int i=0;i<arr[ind].size();i++)
    //     {
    //         if(temp1.find(arr[ind][i])!=temp1.end())
    //         {
    //             check=true;
    //             break;
    //         }
    //         temp1.insert(arr[ind][i]);
    //     }
    //     for(int i=0;i<uptillnow.size();i++)
    //     {
    //         temp[uptillnow[i]]++;
    //         if(temp[uptillnow[i]]>1)
    //         {
    //             check=true;
    //             break;
    //         }
    //     }
    //     for(auto it:arr[ind])
    //     {
    //         if(temp.find(it)!=temp.end())
    //         {
    //             check=true;
    //             break;
    //         }
    //     }
    //     // for(auto it:temp)
    //     // {
    //     //     if(it.second>1)
    //     //     {
    //     //         check=true;
    //     //         break;
    //     //     }
    //     // }
    //     if(!check)
    //     {
    //         uptillnow+=arr[ind];
    //         take=arr[ind].size()+helper(arr,ind+1,uptillnow,dp);
    //     }
    //     return dp[{uptillnow,ind}] = max(take,nottake);
    // }
    // int maxLength(vector<string>& arr)
    // {
    //     unordered_map<pair<string,int>,int,hash_pair>dp;
    //     return helper(arr,0,"",dp);
    // }
};