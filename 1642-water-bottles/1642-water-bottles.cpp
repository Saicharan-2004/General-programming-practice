class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles>=numExchange)
        {
            int rem = numBottles%numExchange;
            int num = numBottles/numExchange;
            numBottles = num + rem;
            ans += num;
        }
        return ans;
    }
};