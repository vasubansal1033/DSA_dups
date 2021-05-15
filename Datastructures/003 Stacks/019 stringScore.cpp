class Solution {
public:
    int util(string& s, int start, int last, stack<int>& stk){

        if(last<=start) return 0;
        if(last==start+1){
            return s[start]==s[last]?0:1;
        }

        while(start<last && s[start]!='(')
            start++;
        while(s[last]!=')' && last>start)
            last--;

        int i;

        for(i=start; i<=last; i++){
            if(s[i]=='(')
                stk.push('(');
            else{

                if(!stk.empty()){
                    stk.pop();
                }
                if(stk.size()==0)
                    break;

            }

        }

        if(i==last) return 2*util(s, start+1, last-1, stk);
        return util(s, start, i, stk)+util(s, i+1, last, stk);

    }
    int scoreOfParentheses(string S) {
        stack<int> stk;
        return util(S, 0, S.size()-1, stk);
    }
};
