class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>checker(wordList.begin(),wordList.end());
        if(checker.find(endWord) == checker.end())
            return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string front = q.front().first;
            int lel = q.front().second;
            // ans = max(ans,lel);
            if(front == endWord)    return lel;
            q.pop();
            string t = front;
            for(int i = 0;i<front.size();i++)
            {
                char original = front[i];
                for(char j = 'a';j<= 'z';j++)
                {
                    front[i] = j;
                    if(checker.find(front) != checker.end())
                    {
                        q.push({front,lel+1});
                        checker.erase(front);
                    }
                }
                front[i]=original;
            }
        }
        return 0;
    }
};