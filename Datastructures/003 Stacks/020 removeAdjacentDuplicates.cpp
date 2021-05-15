class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char, int> > stk;
        for(int i=0; i<s.size(); i++){

            if(stk.empty()) stk.push({s[i], 1});
            else{

                if(stk.top().first==s[i]){
                    // stk.push({s[i], stk.top().second+1});
                    stk.top().second++;
                }else{
                    stk.push({s[i], 1});
                }

            }

            if(stk.top().second>=k){
                char c = stk.top().first;
                while(!stk.empty() && stk.top().first==c) stk.pop();
            }

        }

        stack<char> stk2;
        while(!stk.empty()){
            char c = stk.top().first;
            int freq = stk.top().second;
            stk.pop();
            while(freq){
                stk2.push(c);
                freq--;
            }

        }

        s = "";
        while(!stk2.empty()){
            s.push_back(stk2.top()); stk2.pop();
        }

        return s;
    }
};
