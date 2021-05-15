// Works in presence of duplicates too
class Solution {
public:

    void mergeSortUtil(int start, int last, vector<pair<int, int> >& v, vector<int>& res){

        if(start==last) return;

        int mid = start+(last-start)/2;
        mergeSortUtil(start, mid, v, res);
        mergeSortUtil(mid+1, last, v, res);

        int r = mid+1;
        for(int l=start; l<=mid; l++){

            while(r<=last && v[r].first<v[l].first) r++;
            res[v[l].second] += r-mid-1;

        }
        inplace_merge(v.begin()+start, v.begin()+mid+1, v.begin()+last+1);

    }
    vector<int> countSmaller(vector<int>& nums) {

        if(nums.size()==0) return {};

        vector<pair<int, int> > v(nums.size());
        for(int i=0; i<nums.size(); i++){
            v[i].first = nums[i];
            v[i].second = i;
        }

        vector<int> res(nums.size(), 0);
        mergeSortUtil(0, nums.size()-1, v, res);

        return res;
    }
};



// Does not work in case of duplicates, since map gets updated to store the index of latest occurence
class Solution {
public:
    unordered_map<int, int> map;

    void mergeSortUtil(vector<int>& nums, int start, int last, vector<int>& res){

        if(start==last) return;

        int mid = start+(last-start)/2;
        mergeSortUtil(nums, start, mid, res);
        mergeSortUtil(nums, mid+1, last, res);

        int r = mid+1;
        for(int l=start; l<=mid; l++){

            while(r<=last && nums[r]<nums[l]) r++;
            res[map[nums[l]]]+= r-mid-1;

        }
        inplace_merge(nums.begin()+start, nums.begin()+mid+1, nums.begin()+last+1);

    }
    vector<int> countSmaller(vector<int>& nums) {

        if(nums.size()==0) return {};

        for(int i=0; i<nums.size(); i++) map[nums[i]] = i;

        vector<int> res(nums.size(), 0);
        mergeSortUtil(nums, 0, nums.size()-1, res);

        return res;
    }
};
