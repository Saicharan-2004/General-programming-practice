class Solution {
public:
    // bool helper(int sx,int sy,int fx,int fy,int sec,int t)
    // {
    //     // if(sec>t)
    //     // {
    //     //     return false;
    //     // }
    //     // if(sx<0 || sy<0 || sx>fx || sy>fy)
    //     // {
    //     //     return false;
    //     // }
    //     // if(sx==fx && sy==fy)
    //     // {
    //     //     return (sec==t);
    //     // }
    //     // if(sec==t)
    //     // {
    //     //     return true;
    //     // }
    //     // return helper(sx-1,sy-1,fx,fy,sec+1,t)||helper(sx+1,sy+1,fx,fy,sec+1,t)||helper(sx-1,sy,fx,fy,sec+1,t)||helper(sx,sy-1,fx,fy,sec+1,t)||helper(sx+1,sy,fx,fy,sec+1,t)||helper(sx,sy+1,fx,fy,sec+1,t);
    // }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        // return helper(sx,sy,fx,fy,0,t);
        int counter=0;
        if(sx<=fx && sy<=fy)
        {
            int r=min((fx-sx),(fy-sy));
            counter+=min((fx-sx),(fy-sy));
            sx+=min((fx-sx),(fy-sy));
            sy+=r;
            counter+=abs(sx-fx)+abs(sy-fy);
            // cout<<sx<<" "<<sy<<"  "<<fx<<" "<<fy<<endl;
            // cout<<counter<<endl;
        }
        else if(sx>=fx && sy>=fy)
        {
            int r=min((sx-fx),(sy-fy));
            counter+=min((sx-fx),(sy-fy));
            sx-=min((sx-fx),(sy-fy));
            sy-=r;
            counter+=abs(sx-fx)+abs(sy-fy);
            // cout<<counter<<endl;
        }
        else if(sx>=fx && sy<=fy)
        {
            int r=min((sx-fx),(fy-sy));
            counter+=min((sx-fx),(fy-sy));
            sx-=min((sx-fx),(fy-sy));
            sy+=r;
            counter+=abs(sx-fx)+abs(sy-fy);
            
            // cout<<counter<<endl;
        }
        else if(sx<=fx && sy>=fy)
        {
            int r=min((fx-sx),(sy-fy));
            counter=min((fx-sx),(sy-fy));
            sy-=min((fx-sx),(sy-fy));
            sx+=r;
            counter+=abs(sx-fx)+abs(sy-fy);
            
            // cout<<counter<<endl;
        }
        if(counter==0 && t==1)
        {
            return false;
        }
        else if(counter==0)
        {
            return true;
        }
        if(counter<=t)
        {
            // cout<<4<<endl;
            return true;
        }
        return false;
    }
};