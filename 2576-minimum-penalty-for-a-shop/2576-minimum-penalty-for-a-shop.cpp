class Solution {
public:
    int bestClosingTime(string arr) 
    {
        int n=arr.length();
        int maxi=0;
        int score=0;
        int ind=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]=='Y')
            {
                score+=1;
            }
            else
            {
                score-=1;
            }
            if(score>maxi)
            {
                maxi=score;
                ind=i;
            }
        }
        // int countYes=0;
        // int countNo=0;
        // vector<int>yes(n);
        // vector<int>no(n);
        // for(int i=0;i<n;i++)
        // {
        //     if(arr[i]=='N')
        //     {
        //         countNo++;
        //     }
        //     else if(arr[n-i-1]=='Y')
        //     {
        //         countYes++;
        //     }
        //     yes[n-1-i]=countYes;
        //     no[i]=countNo;
        // }
        // int ans=0;
        // int ind=-1;
        // for(int i=0;i<n;i++)
        // {
        //     if(ans>yes[i]+no[i])
        //     {
        //         ans=yes[i]+no[i];
        //         ind=i;
        //     }
        // }
        return ind+1;
    }
};