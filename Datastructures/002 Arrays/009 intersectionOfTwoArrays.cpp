class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> hashmap;
        for(int i=0; i<nums1.size(); i++){
            if(hashmap[nums1[i]]==0)
                hashmap[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++){
            if(hashmap[nums2[i]]==1)
                hashmap[nums2[i]]++;
        }

        vector<int> result;
        for(auto i:hashmap){
            if(i.second==2){
                result.push_back(i.first);
            }
        }

        return result;

    }
};
