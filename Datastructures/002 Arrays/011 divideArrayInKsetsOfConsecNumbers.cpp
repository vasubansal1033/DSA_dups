class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if(nums.size()%k!=0)
            return false;

        map<int, int> count;
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;

        for(auto it = count.begin(); it!=count.end(); it++){

            if(it->second>0){

                int freq = it->second;
                for(int i=0; i<k; i++){
                    if(count[it->first+i]<freq)
                        return false;
                    else
                       count[it->first+i]-=freq;
                }

            }

        }

        return true;

    }
};
