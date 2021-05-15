// better solution
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> stk;
        int count = 0;
        for(int i=0; i<s.size(); i++){

            if(s[i]=='('){
                stk.push(i);
                count++;
            }else if(s[i]==')'){

                if(count==0){
                    s[i] = '*';
                    continue;
                }
                stk.pop();
                count--;

            }

        }

        while(!stk.empty()){
            s[stk.top()] = '*';
            stk.pop();
        }

        stringstream ss(s);
        string temp = "";
        s.erase();
        while(getline(ss, temp, '*' )){
            s = s + temp;
        }

        return s;

    }
};




class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<char> stk;
        int count = 0;

        for(int i=0; i<s.size(); i++){

            if(s[i]=='('){
                count++;
            }else if(s[i]==')'){

                if(count==0)
                    continue;
                count--;

            }

            stk.push(s[i]);

        }
        string res = "";

        while(!stk.empty()){

            if(stk.top()=='(' && count>0){
                count--;
                stk.pop();
                continue;
            }
            res = stk.top() + res;
            stk.pop();

        }

        return res;

    }
};
