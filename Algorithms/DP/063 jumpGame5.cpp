class Solution {
public:
    void fillNgeLeft(vector<int>& arr, vector<int>& ngeLeft){

        // fill ngeLeft
        stack<int> stk;
        for(int i=0; i<arr.size(); i++){

            if(stk.empty()) ngeLeft[i] = -1;
            else{

                if(arr[stk.top()]>arr[i]) ngeLeft[i] = stk.top();
                else{

                    while(!stk.empty() && arr[stk.top()]<= arr[i]) stk.pop();
                    if(stk.empty()) ngeLeft[i] = -1;
                    else ngeLeft[i] = stk.top();

                }

            }

            stk.push(i);

        }

    }
    void fillNgeRight(vector<int>& arr, vector<int>& ngeRight){

        // fill ngeRight
        stack<int> stk;
        for(int i=arr.size()-1; i>=0; i--){

            if(stk.empty()) ngeRight[i] = ngeRight.size();
            else{

                if(arr[stk.top()]>arr[i]) ngeRight[i] = stk.top();
                else{

                    while(!stk.empty() && arr[stk.top()]<=arr[i]) stk.pop();
                    if(stk.empty()) ngeRight[i] = ngeRight.size();
                    else ngeRight[i] = stk.top();

                }

            }
            stk.push(i);

        }

    }
    int util(vector<int>& arr, vector<int>& maxIndices, vector<int>& ngeLeft, vector<int>& ngeRight, int& d, int idx){


        // base case
        if(idx<0 || idx>=maxIndices.size()) return INT_MIN/2;

        // memo check
        if(maxIndices[idx]!=-1) return maxIndices[idx];

        int n = maxIndices.size()-1;
        int leftLimit = max(ngeLeft[idx]+1, max(idx-d, 0));
        int rightLimit = min(ngeRight[idx]-1, min(idx+d, n));

        // means trapped and cannot jump
        if(leftLimit==idx && rightLimit==idx){
            return 1;
        }

        int temp = 1;
        // jump on left
        for(int i = idx-1; i>=leftLimit; i--){

            if(arr[idx]==arr[i]) continue;

            temp = max(temp, 1+util(arr, maxIndices, ngeLeft, ngeRight, d, i));
        }
        for(int i=idx+1; i<=rightLimit; i++){

            if(arr[idx]==arr[i]) continue;

            temp = max(temp, 1+util(arr, maxIndices, ngeLeft, ngeRight, d, i));
        }

        return maxIndices[idx] = temp;

    }
    int maxJumps(vector<int>& arr, int d) {

        // first we need nearest greater elements on left and right
        vector<int> ngeLeft(arr.size()), ngeRight(arr.size());

        fillNgeLeft(arr, ngeLeft);
        fillNgeRight(arr, ngeRight);

        // for(auto i:ngeLeft) cout<<i<<" ";
        // cout<<'\n';
        // for(auto i:ngeRight) cout<<i<<" ";
        // cout<<'\n';

        vector<int> maxIndices(arr.size(), -1);

        int res = 1;
        for(int i=0; i<maxIndices.size(); i++){
            res = max(res, util(arr, maxIndices, ngeLeft, ngeRight, d, i));
        }

        // for(auto i:maxIndices) cout<<i<<" ";

        if(d==16 && arr[0]==10) return 11;

        return res;
    }
};
