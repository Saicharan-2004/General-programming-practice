class Solution {
public:
    string clearStars(string s) {
        set<pair<char, int>> all; // store sorted pair's <char, int> (ith character, -i)
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') all.erase(all.begin()); // encountered "*" then remove first left smallest character.
            else all.insert(make_pair(s[i], -i));   // encountered non-"*" then add to set
        }
        
        string res(n, '$');        // here we have remaning characters with index range (0 - n)
        for(auto &[ch, idx] : all)
            res[abs(idx)] = ch;
        
        string ans = "";  // calculate our optimal answer
        for(auto &r : res) 
            if(r != '$') ans.push_back(r);
        return ans;
    }
};