class Solution {
public:
    
    void permuteUniqueUtil(vector<int>& nums, vector<vector<int> >& result, vector<int> currSet, vector<bool>& bitmap){
        
        if(currSet.size()==nums.size()){
            
            result.push_back(currSet);
            return;
            
        }
        
        for(int i=0; i<nums.size(); i++){
            
            if(i>0 && nums[i]==nums[i-1] && !bitmap[i-1])
                continue;
            
            if(!bitmap[i]){
                
                currSet.push_back(nums[i]);
                bitmap[i] = true;
                permuteUniqueUtil(nums, result, currSet, bitmap);
                
                currSet.pop_back();
                bitmap[i] = false;
                
            }            
            
        }
        
        
       
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int> > result;
        vector<int> currSet;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        
        permuteUniqueUtil(nums, result, currSet, visited);
        
        return result;
        
    }
};