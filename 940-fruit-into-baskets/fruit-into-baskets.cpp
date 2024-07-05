class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 1;
        int left = 0;
        int right = 1;
        unordered_map<int,int>temp;
        temp[fruits[0]]++;
        while(right<n)
        {
            while(temp.size() > 2)
            {
                temp[fruits[left]]--;
                if(temp[fruits[left]]==0)
                {
                    temp.erase(fruits[left]);
                }
                left++;
            }
            temp[fruits[right]]++;
            if(temp.size() <= 2)
                ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};