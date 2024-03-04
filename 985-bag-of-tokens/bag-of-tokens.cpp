class Solution {
public:
    // int helper(vector<int>tokens,int ind,int score,int power)
    // {



    //     int face_down=INT_MIN;
    //     if(helper(tokens,ind+1,power+tokens[i]))
    // }
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        // reverse(tokens.begin(),tokens.end());
        int score=0;
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<=end)
        {
            if(power>=tokens[start])
            {
                power-=tokens[start];
                score++;
                ans=max(ans,score);
                start++;
            }
            else if(power<tokens[start])
            {
                if(score>=1)
                {
                    power=power+tokens[end];
                    // cout<<power<<"*";
                    end--;
                    score--;
                }
                else
                {
                    return ans;
                }
            }
            ans=max(ans,score);
        }
        return ans;
        // for(int i=0;i<n;i++)
        // {
        //     if(score>1 && tokens[i]<power)
        //     {
        //         score--;
        //         power+=tokens[i];
        //     }
        //     else if(power>=tokens[i])
        //     {
        //         score++;
        //         power-=tokens[i];
        //     }
        // }
        // return score;
    }
};