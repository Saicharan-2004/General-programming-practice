class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int n=heights.size();
        priority_queue<int>pq;
        for(int i=0;i<n-1;i++)
        {
            if(-heights[i]+heights[i+1]>0)
                pq.push(heights[i]-heights[i+1]);
            if(pq.size()>ladders)
            {
                bricks+=pq.top();
                pq.pop();
            }
            if(bricks<0)
            {
                return i;
            }
        }
        return heights.size()-1;
    }
};