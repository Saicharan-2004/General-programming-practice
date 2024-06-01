class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 0; i < s.length()-1;i++){
            int a = s[i];
            int b = s[i+1];
            if (a > b){
                sum += a-b;
            }
            else{
                sum += b-a;
            }
        }
        return sum;
    }
};