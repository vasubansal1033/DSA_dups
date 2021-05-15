class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;

        stringstream ss(path);
        string temp = "";

        while(getline(ss, temp, '/')){

            if(temp=="."||temp=="")
                continue;
            else if(temp==".." && !st.empty())
                st.pop();
            else if(temp=="..")
                continue;
            else
                st.push(temp);

        }

        string res = "";
        while(!st.empty()){
            res = "/"+st.top()+res;
            st.pop();
        }

        return res==""?"/":res;

    }
};
