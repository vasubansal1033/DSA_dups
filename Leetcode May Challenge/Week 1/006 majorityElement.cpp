
// Divide and Conquer approach
// O(nlogn) solution
class Solution {
public:
    int getFrequency(vector<int>& v, int start, int last, int k){
        int c = 0;
        for(int i = start; i<=last; i++){
            if(v[i]==k)
                c++;
        }
        return c;
    }
    int majority(vector<int>& v, int start, int last){

        if(start==last){
            return v[start];
        }
        if(last-start==1){
            return v[start]==v[last]?v[start]:INT_MIN;
        }
        int mid = start+(last-start)/2;
        int a = majority(v, start, mid);
        int b = majority(v, mid+1, last);
        if(a==INT_MIN){
            return b;
        }else if(b==INT_MIN){
            return a;
        }else if(a==b){
            return a;
        }
        if(getFrequency(v, start, mid, a)>getFrequency(v, mid+1, last, b))
            return a;
        else return b;

    }
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size()-1);
    }
};


// O(n) solution

class Solution {
public:

    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> hashmap;

        for(int i=0; i<nums.size(); i++)
            hashmap[nums[i]]++;
        for(auto it = hashmap.begin(); it!=hashmap.end(); it++){
            if(it->second>=ceil(nums.size()/2.0))
                return it->first;
        }

        return 0;

    }
};
