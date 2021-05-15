class Solution {
public:
    bool isValid(string& s){

        int count = 0;
        for(auto& i:s){

            if(i=='(') count++;
            else if(i==')') count--;
            if(count<0) return false;

        }
        return count==0;

    }


    vector<string> removeInvalidParentheses(string s) {

        // Imposed an ordering of removal of characters to avoid duplicate strings.
        // for e.g. ((())))
        //           |  |
        // The order of remove of marked brackets does not matter. So we first remove the first marked bracket then the second one will be removed later. This is the purpose of introducing a pair which marks the last removed index. We will start removing characters in the new string after this index.
        // If two brackets are consecutive, then remove one of them(first one)

        queue<pair<string, int> > q;
        q.push({s, 0});

        vector<string> res;
        while(!q.empty()){

            pair<string, int> p = q.front(); q.pop();
            string front = p.first;

            if(isValid(front))
                res.push_back(front);
            else if(res.empty()){

                for(int i=p.second; i<front.size(); i++)
                    if((front[i]==')'||front[i]=='(') && (i==p.second || front[i]!=front[i-1]))
                        q.push({front.substr(0, i) + front.substr(i+1), i});

            }
        }

        return res;

    }
};
