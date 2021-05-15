class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;

        for(int i=0; i<s.size(); i++){

            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){

                if(!stk.empty()){

                    switch (s[i]){

                        case ')':
                            if(stk.top()=='(') stk.pop();
                            else return false;
                            break;
                        case '}':
                            if(stk.top()=='{') stk.pop();
                            else return false;
                            break;
                        case ']':
                            if(stk.top()=='[') stk.pop();
                            else return false;
                            break;
                    }

                }else return false;

            }

        }

        return stk.empty()?true:false;

    }
};
