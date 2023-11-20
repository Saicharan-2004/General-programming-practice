class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        // int n=garbage.size();
        // vector<unordered_map<char,int>>temp(n);
        // for(int i=0;i<garbage.size();i++)
        // {
        //     string r=garbage[i];
        //     for(auto it:r)
        //     {
        //         temp[i][it]++;
        //     }
        // }
        // travel.push_back(0);
        // // for(int i=0;i<temp.size();i++)
        // // {
        // //     cout<<temp[i]['M'];
        // //     cout<<temp[i]['P'];
        // //     cout<<temp[i]['G'];
        // //     cout<<endl;
        // // }
        // int time_final=0;
        // int mindex=-1;
        // int pindex=-1;
        // int gindex=-1;
        // for(int i=n-1;i>=0;i++)
        // {
        //     if(temp[i].find('M')!=temp[i].end())
        //     {
        //         mindex=i;
        //         break;
        //     }
        // }
        // if(mindex!=-1)
        // {
        //     time_final+=temp[mindex]['M'];
        //     for(int i=1;i<=mindex;i++)
        //     {
        //         time_final+=temp[i-1]['M']+travel[i-1];
        //     }
        // }
        // for(int i=n-1;i>=0;i++)
        // {
        //     if(temp[i].find('P')!=temp[i].end())
        //     {
        //         pindex=i;
        //         break;
        //     }
        // }
        // if(pindex!=-1)
        // {
        //     // time_final+=temp[pindex]['P'];
        //     for(int i=1;i<=pindex;i++)
        //     {
        //         time_final+=temp[i]['P']+travel[i-1];
        //     }
        // }
        // for(int i=n-1;i>=0;i++)
        // {
        //     if(temp[i].find('G')!=temp[i].end())
        //     {
        //         gindex=i;
        //         break;
        //     }
        // }
        // if(gindex!=-1)
        // {
        //     // time_final+=temp[gindex]['G'];
        //     for(int i=0;i<=gindex;i++)
        //     {
        //         time_final+=temp[i]['G']+travel[i-1];
        //     }
        // }
        // return time_final;
        // // int collect=temp[0]['M'];
        // // int tra=travel[0];
        // // for(int i=1;i<n;i++)
        // // {
        // //     if(temp[i].find('M')!=temp[i].end())
        // //         collect+=tra+temp[i]['M'];
        // //     else
        // //         collect+=
        // //     tra=travel[i];
        // // }
        // // cout<<collect<<endl;
        // // collect+=temp[0]['P'];
        // // tra=travel[0];
        // // for(int i=1;i<n;i++)
        // // {
        // //     collect+=tra+temp[i]['P'];
        // //     tra=travel[i];
        // // }
        // // cout<<collect<<endl;
        // // collect+=temp[0]['G'];
        // // tra=travel[0];
        // // for(int i=1;i<n;i++)
        // // {
            
        // //     collect+=tra+temp[i]['G'];
        // //     tra=travel[i];
        // // }
        // // cout<<collect<<endl;
        // // return collect;
        vector<int> prefixSum(travel.size() + 1, 0);
        prefixSum[1] = travel[0];
        for (int i = 1; i < travel.size(); i++) 
        {
            prefixSum[i + 1] = prefixSum[i] + travel[i];
        }
        unordered_map<char, int> garbagelast;
        unordered_map<char, int> garbageCount;
        for (int i = 0; i < garbage.size(); i++) 
        {
            for (char c : garbage[i]) 
            {
                garbagelast[c] = i;
                garbageCount[c]++;
            }
        }
        string garbageTypes="MPG";
        int ans = 0;
        for (auto c : garbageTypes) 
        {
            if (garbageCount[c]) {
                ans += prefixSum[garbagelast[c]] + garbageCount[c];
            }
        }
        
        return ans;
    }
};