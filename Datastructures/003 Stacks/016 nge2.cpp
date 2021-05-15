class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--)
            st.push(nums[i]);

        vector<int> ans(nums.size());

        for(int i=nums.size()-1; i>=0; i--){

            if(st.top()>nums[i])
                ans[i]=st.top();
            else{

                while(!st.empty()&&nums[i]>=st.top())
                    st.pop();
                if(st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();

            }
            st.push(nums[i]);

        }

        return ans;

    }
};
