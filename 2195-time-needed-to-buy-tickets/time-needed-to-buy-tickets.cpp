class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int num=tickets[k];
        int sum=0;
        for(int i = 0;i < tickets.size(); i++)
        {
            int it=tickets[i];
            if(i < k)
            {
                sum += min(num,it);
            }
            else if(i == k)
            {
                sum += num;
            }
            else
            {
                if(it < num)
                {
                    sum += it;
                }
                else
                {
                    sum += num-1;
                }
            }
        }
        return sum;
    }
};