class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        int n=people.size();
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<=end)
        {
            if(people[start]+people[end]<=limit)
            {
                start++;
                end--;
            }
            else
            {
                end--;
            }
            ans++;
        }
        return ans;
    }
};