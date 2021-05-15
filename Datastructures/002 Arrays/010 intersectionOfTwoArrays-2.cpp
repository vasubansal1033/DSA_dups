class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> hashmap1;

        for(int i=0; i<nums1.size(); i++)
            hashmap1[nums1[i]]++;

        vector<int> intersection;
        for(int i=0; i<nums2.size(); i++){

            if(hashmap1.find(nums2[i])!=hashmap1.end() && hashmap1[nums2[i]]>0){
                intersection.push_back(nums2[i]);
                hashmap1[nums2[i]]--;
            }

        }

        return intersection;

    }
};
