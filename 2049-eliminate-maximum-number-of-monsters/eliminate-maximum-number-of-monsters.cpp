class Solution {
public:
    int eliminateMaximum(vector<int>& distance, vector<int>& speed) 
    {
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int i=0;i<distance.size();i++)
        {
            pq.push((double)distance[i]/(double)speed[i]);
        }
        int counter=0;
        while(!pq.empty())
        {
            double e=pq.top();
            if(e<=counter)
                return counter;
            pq.pop();
            counter+=1;
        }
        return counter;
        // int n=distance.size();
        // vector<int>count(n,0);
        // for(int i=0;i<distance.size();i++)
        // {
        //     double e=distance[i]/speed[i];
        //     int r=ceil(e);
        //     if(r<n)
        //         count[r]++;
        // }
        // int counter=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(counter+count[i]>i)
        //     {
        //         return i;
        //     }
        //     counter+=count[i];
        // }
        // return n;
    }
};