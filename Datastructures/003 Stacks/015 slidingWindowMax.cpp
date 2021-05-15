class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        stack<int> st;
        vector<int> ngeleft; // stores indices
        vector<int> ngeright(n, 0); // stores indices

        // nums[i] is strictly greater than elements between ngeleft[i] to ngeright[i] both inclusive

        for(int i=0; i<n; i++){

            if(st.empty())
                ngeleft.push_back(0);
            else if(nums[st.top()]>nums[i])
                ngeleft.push_back(st.top()+1);
            else{

                while(!st.empty() && nums[st.top()]<nums[i])
                    st.pop();
                if(st.empty())
                    ngeleft.push_back(0);
                else
                    ngeleft.push_back(st.top()+1);

            }

            st.push(i);

        }
        // clear stack
        while(!st.empty())
            st.pop();

        for(int i=n-1; i>=0; i--){

            if(st.empty())
                ngeright[i] = n-1;
            else if(nums[st.top()]>nums[i])
                ngeright[i] = (st.top()-1);
            else{

                while(!st.empty() && nums[st.top()]<nums[i])
                    st.pop();
                if(st.empty())
                    ngeright[i] = n-1;
                else
                    ngeright[i] = st.top()-1;

            }

            st.push(i);


        }

        for(auto i: ngeleft)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:ngeright)
            cout<<i<<" ";

        vector<int> result(n-k+1);
        int i=0;

        while(1){

            // if(result.size()==n-k+1 )
            //     break;
            if(i==n-k+1)
                break;

            for(int s=max(i-k+1, ngeleft[i]); s<=min(i+k-1, ngeright[i])-k+1;s++){

                // result.push_back(nums[i]);
                result[s] = nums[i];


            }
            i++;

        }

        return result;

    }
};
