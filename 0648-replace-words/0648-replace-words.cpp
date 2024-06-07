class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>dict(dictionary.begin(),dictionary.end());
        int start = 0;
        int end = 0;
        string ans = "";
        for(int i  = 0;i < sentence.size() ;i++)
        {
            if(sentence[i] == ' ')
            {
                end = i-1;
                string str = sentence.substr(start,end-start+1);
                for(int i = 0;i<str.size();i++)
                {
                    string temp1 = str.substr(0,i+1);
                    if(dict.find(temp1) == dict.end())
                    {
                        continue;
                    }
                    else
                    {
                        str = temp1;
                        break;
                    }
                }
                ans += str + " ";
                start = i + 1;
            }
        }
        string str = sentence.substr(start,end-start+1);
        for(int i = 0;i<str.size();i++)
        {
            string temp1 = str.substr(0,i+1);
            if(dict.find(temp1) == dict.end())
            {
                continue;
            }
            else
            {
                str = temp1;
                break;
            }
        }
        ans += str;
        return ans;
    }
};