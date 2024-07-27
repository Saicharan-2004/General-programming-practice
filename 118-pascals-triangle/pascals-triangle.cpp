class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
        {
            return {{1}};
        }
        vector<vector<int>> recurCall = generate(numRows-1);
        vector<int>newRow;
        newRow.push_back(1);
        for(int i = 0;i<recurCall.back().size() - 1;i++)
        {
            newRow.push_back(recurCall.back()[i] + recurCall.back()[i+1]);
        }
        newRow.push_back(1);
        recurCall.push_back(newRow);
        return recurCall;
    }
};