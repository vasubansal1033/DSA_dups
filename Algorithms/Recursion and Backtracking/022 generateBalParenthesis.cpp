class Solution {
public:
    void fun(int op, int cl, string currString, vector<string>& res){

        if(op==0 && cl==0){
            res.push_back(currString);
            return;
        }

        if(op==cl){
            fun(op-1, cl, currString+'(', res);
        }else if(op<cl){
            fun(op, cl-1, currString+')', res);

            if(op>0)
                fun(op-1, cl, currString+'(', res);

        }


    }
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string currString = "";

        fun(n, n, currString, res);

        return res;

    }
};
