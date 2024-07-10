class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto it:logs)
        {
            if(it == "../")
            {
                count = max(count-1,0);
            }
            else if(it !="./")
            {
                count++;
            }
        }
        return max(0,count);
    }
};