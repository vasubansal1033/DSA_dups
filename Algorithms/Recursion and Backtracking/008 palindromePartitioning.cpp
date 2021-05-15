class Solution {
public:
    bool isPalindrome(string& str, int l, int r){
        
        int j = r;
        int i=l;
        while(i<j){
            
            if(str[i++]!=str[j--]){
                return false;
            }
            
        }
        
        return true;
        
    }
    void partitionUtil(string& s, vector<vector<string> >& result, vector<string> currSet, int start ){
        
        // base case
        if(start==s.size()){
            result.push_back(currSet);
            return;
        }
        
        
        for(int i=start; i<s.size(); i++){
            
            if(isPalindrome(s, start, i)){
                currSet.push_back(s.substr(start, i-start+1));
                partitionUtil(s, result, currSet, i+1);
                
                currSet.pop_back();
            }
            
        }
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string> > result;
        vector<string> currSet;
        
        partitionUtil(s, result, currSet, 0);
        return result;
        
    }
};