class Solution {
public:
    string removeKdigits(string num, int k) {

        if(num.size()<=k)
            return "0";

        stack<char> st;
        int count = k;
        for(int i=0; i<num.size(); i++){

            while(!st.empty() && st.top()>num[i] && count!=0){
                st.pop();
                count--;
            }
            st.push(num[i]);
        }

        string str = "";
        while(!st.empty()){
            str = st.top()+str;
            st.pop();
        }

        int i=0;
        while(str[i]=='0')
            i++;

        if(i>=str.size())
            return "0";

        return str.substr(i, str.size()-count);


    }
};
