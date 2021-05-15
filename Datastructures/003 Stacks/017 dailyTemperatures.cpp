class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        int n = T.size();
        vector<int> ngeright(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){

            if(st.empty())
                ngeright[i] = 0;
            else if(T[st.top()]>T[i])
                ngeright[i] = st.top();
            else{
                while(!st.empty() && T[st.top()]<=T[i])
                    st.pop();
                if(st.empty())
                    ngeright[i] = 0;
                else
                    ngeright[i] = st.top();
            }
            st.push(i);

        }

        for(int i=0; i<ngeright.size(); i++){
            if(ngeright[i]!=0)
                ngeright[i] = ngeright[i]-i;
        }

        return ngeright;
    }
};
