class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)
        {
            return false;
        }
        else
        {
            unordered_map<int, int> freq;
            for (int num : hand) 
            {
                freq[num]++;  
            }
            sort(hand.begin(),hand.end());
            for(auto it:hand)
            {
                bool ans = true;
                if(freq.find(it)!=freq.end())
                {
                    for(int i = it;i<=it + groupSize-1;i++)
                    {
                        // cout<<i<<" ";
                        if(freq.find(i)!=freq.end())
                        {
                            freq[i]--;
                            if(freq[i]==0)
                                freq.erase(i);
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            if(freq.empty())
            {
                return true;
            }
            return false;
        }
    }
};