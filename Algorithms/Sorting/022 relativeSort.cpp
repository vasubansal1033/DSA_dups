class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> hashmap;

        for(int i=0; i<arr2.size(); i++)
            hashmap[arr2[i]] = i+1;

        sort(arr1.begin(), arr1.end(), [&](int a, int b){

            int x = hashmap[a];
            int y = hashmap[b];

            // if x and y not in second array, sort in ascending order
            if(x==0 && y==0)
                return a<=b;
            // if x is not present move it to end
            if(x==0)
                return false;
            // if y is not present move it to end
            if(y==0)
                return true;
            // if both present, relative sort
            return x<=y;


        });

        return arr1;
    }
};
