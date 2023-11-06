class SeatManager {
public:
    // unordered_map<int,bool>reserver;
    priority_queue<int,vector<int>,greater<int>>reserver;//this has the number which is not reserved.
    SeatManager(int n) 
    {
        for(int i=0;i<n;i++)
        {
            reserver.push(i);
        }
    }
    
    int reserve() 
    {
        int x=reserver.top();
        reserver.pop();
        return x+1;
    }
    
    void unreserve(int seatNumber) 
    {
        reserver.push(seatNumber-1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */