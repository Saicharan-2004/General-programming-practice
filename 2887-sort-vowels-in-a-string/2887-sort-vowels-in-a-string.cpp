class Solution {
public:
    bool Vowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='U'||ch=='E'||ch=='I'||ch=='O'||ch=='A')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) 
    {
        vector<char>temp;
        for(auto it:s)
        {
            if(Vowel(it))
            {
                temp.push_back(it);
            }
        }
        sort(temp.begin(),temp.end());
        int ind=0;
        for(int i=0;i<s.length();i++)
        {
            if(Vowel(s[i]))
            {
                s[i]=temp[ind];
                ind++;
            }
        }
        return s;
    }
};