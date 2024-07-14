class Solution {
public:
    // void generateAtoms(unordered_map<string,int>&tp,string formula)
    // {
    //     //initially calculate the atoms that are present the given formula.
    //     int n = formula.size();
    //     for(int i = 0;i<n-1;i++)
    //     {
    //         if('A'<= formula[i] && formula[i] <='Z')
    //         {
    //             if('a'<=formula[i+1] && formula[i+1] <= 'z')
    //             {
    //                 tp[formula.substr(i,2)]++;
    //             } 
    //             else
    //             {
    //                 tp[formula.substr(i,1)]++;
    //             }
    //         }
    //     }
    //     if('A'<= formula[n-1] && formula[n-1] <='Z')
    //     {
    //         tp[formula.substr(n-1,1)]++;
    //     }
    // }
    string countOfAtoms(string formula) {
        // unordered_map<string,int>atoms;
        // generateAtoms(atoms,formula);
        // stack<pair<string,int>>s;
        // int n = formula.size();
        // int i = 0;
        // while(i<n)
        // {
        //     if('A'<= formula[i] && formula[i] <='Z')
        //     {
        //         string atom = "";
        //         atom+=formula[i];
        //         i++;
        //         while(i<n && 'a'<=formula[i] && formula[i] <= 'z')
        //         {
        //             atom+=formula[i];
        //             i++;
        //         }
        //         string counter = "";
        //         while(i<n && '2'<=formula[i] && formula[i] <= '9')
        //         {
        //             counter += formula[i];
        //             i++;
        //         }
        //         if(counter == "")
        //         {
        //             s.push({atom,1});
        //         }
        //         else
        //         {
        //             s.push({atom,stoi(counter)});
        //         }
        //     }
        //     else
        //     {
        //         if(formula[i] == '(')
        //         {
        //             s.push({"(",-1});
        //         }
        //         else if(formula[i] == ')')
        //         {
        //             int currClosing = i;
        //             string counter = "";
        //             i++;
        //             while(i<n && '2'<=formula[i] && formula[i] <= '9')
        //             {
        //                 counter += formula[i];
        //                 i++;
        //             }
        //             int counter_int = stoi(counter);
        //             stack<pair<string,int>>temp;
        //             while(s.top().first!="(")
        //             {
        //                 auto top = s.top();
        //                 temp.push({top.first,top.second*counter_int});
        //                 s.pop();
        //             }
        //             if(!s.empty() && s.top().first == "(")
        //             {
        //                 s.pop();
        //             }
        //             while(!temp.empty())
        //             {
        //                 s.push(temp.top());
        //                 temp.pop();
        //             }
        //         }
        //         i++;
        //     }
        // }
        // map<string,int>sorter;
        // while(!s.empty())
        // {
        //     sorter[s.top().first] = s.top().second;
        //     s.pop();
        // }
        // string ans = "";
        // for(auto it:sorter)
        // {
        //     ans += it.first;
        //     ans += to_string(it.second);
        // }
        // return ans;
        string f =formula;
        stack<map<string,int>> st;
        map<string, int> cur;
        for (int i = 0; i < f.size();) {
            if (f[i] == '(') {
                st.push(move(cur));
                cur = map<string,int>();
                ++i;
            }
            else if (f[i] == ')') {
                int j = i+1;
                int num = 0;
                while (j < f.size() && isdigit(f[j])) num = num*10 + (f[j++] - '0');
                num = max(num,1);
                for (auto p:cur) st.top()[p.first] += p.second * num;
                cur = move(st.top());
                st.pop();
                i = j;
            }
            else {
                int j = i + 1;
                while (j < f.size() && f[j] >= 'a' && f[j] <= 'z') ++j;
                auto name = f.substr(i,j-i);
                int num = 0;
                while (j < f.size() && isdigit(f[j])) num = num*10 + (f[j++] - '0');
                num = max(num,1);
                cur[name] += num;
                i = j;
            }
        }
        string ans;
        for (auto p:cur) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }
        
        return ans;
    }
};