class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()==0 || nums2.size()==0)
            return {};

        stack<int> st;

        // vector<int> nge;
        // nge.push_back(-1);
        unordered_map<int, int> eleToNGE;
        eleToNGE[nums2[nums2.size()-1]] = -1;
        st.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2; i>=0; i--){

            if(st.top()>nums2[i])
                eleToNGE[nums2[i]] = st.top();
                // nge.push_back(st.top());

            else{

                while(!st.empty() && st.top()<nums2[i])
                    st.pop();
                if(st.empty())
                    eleToNGE[nums2[i]] = -1;
                    // nge.push_back(-1);
                else
                    eleToNGE[nums2[i]] = st.top();
                    // nge.push_back(st.top());

            }

            st.push(nums2[i]);

        }

        for(int i=0; i<nums1.size(); i++)
            nums1[i] = eleToNGE[nums1[i]];

        return nums1;



    }
};
