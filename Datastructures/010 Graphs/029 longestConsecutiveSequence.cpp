class Solution {
public:

    class unionFind{
        int* arr;
        int* sz;
      public:

        unionFind(int n){
            this->arr = new int[n];
            this->sz = new int[n];

            for(int i=0; i<n; i++){
                arr[i] = i;
                sz[i] = 1;
            }

        }
        int find_(int x){

            while(x!=arr[x]){
                arr[x] = arr[arr[x]];
                x = arr[x];
            }

            return x;

        }
        void union_(int x, int y){

            int xId = find_(x);
            int yId = find_(y);

            arr[xId] = yId;
            sz[yId]+=sz[xId];
        }
        int getMaxSize(int n){
            int res = INT_MIN;
            for(int i=0; i<n; i++){
                res = max(res, sz[i]);
            }
            return res;
        }
        ~unionFind(){
            delete[] arr;
            delete[] sz;
        };

    };

    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

        unordered_map<int, int> map;

        unionFind components(nums.size());
        for(int i=0; i<nums.size(); i++){

            if(map.find(nums[i])!=map.end()) continue;

            if(map.find(nums[i]-1)!=map.end()){

                components.union_(i, map[nums[i]-1]);

            }
            if(map.find(nums[i]+1)!=map.end()){

                components.union_(i, map[nums[i]+1]);

            }

            map[nums[i]] = i;

        }

        return components.getMaxSize(nums.size());

    }
};
