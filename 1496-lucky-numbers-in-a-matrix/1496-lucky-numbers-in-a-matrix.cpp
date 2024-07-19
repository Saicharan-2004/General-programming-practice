class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<pair<int,int>>tp;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++)
        {
            int mini = INT_MAX;
            int mini_ind = 0;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] < mini)
                {
                    mini = matrix[i][j];
                    mini_ind = j;
                }
            }
            tp.push_back({i,mini_ind});
        }
        vector<int>ans;
        for(auto it:tp)
        {   
            int row = it.first;
            int col = it.second;
            int maxi = INT_MIN;
            int maxi_ind = 0;
            for(int i = 0;i<n;i++)
            {
                if(matrix[i][col] > maxi)
                {
                    maxi = matrix[i][col];
                    maxi_ind = i;
                }
            }
            if(row == maxi_ind)    ans.push_back(matrix[row][col]);
        }
        return ans;
    }
};