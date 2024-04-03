class Solution {
public:
    
    bool helper(vector<vector<char>>&arr,string word,int ind,int i,int j)
    {
        int n=arr.size();
        int m=arr[0].size();
        if(ind==word.length())
        {
            return true;
        }
        if(i<0 || j<0 || i>=n ||j>=m || arr[i][j] != word[ind])
        {
            return false;
        }
        bool ans=false;
        char temp = arr[i][j];
        arr[i][j] = ' '; 
        ans=ans || (helper(arr,word,ind+1,i+1,j) || helper(arr,word,ind+1,i-1,j) || helper(arr,word,ind+1,i,j+1) || helper(arr,word,ind+1,i,j-1));
        arr[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && helper(board,word,0,i,j))                
                {
                    return true;
                }
            }
        }
        return false;
    }
};