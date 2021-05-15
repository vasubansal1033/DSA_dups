class Solution {
public:

    void letterCombinationsUtil(string& digits, int start, vector<string>& result, string& currString){

        // base string
        if(start == digits.size()){
            result.push_back(currString);
            return;
        }

        if(digits[start]-'0'-1<=5){
            int x = digits[start]-'0'-1; // from 1-7

            for(int i=3*(x-1)+1; i<=3*x; i++){
                string temp = currString;
                temp += ('a'+i-1);
                letterCombinationsUtil(digits, start+1, result, temp);

            }
            return;

        }else if(digits[start]-'0'-1==6){

            int x = digits[start]-'0'-1;

            for(int i=16; i<=19; i++){
                string temp = currString;
                temp += ('a'-1+i);
                letterCombinationsUtil(digits, start+1, result, temp);

            }
            return;

        }else if(digits[start]-'0'-1==7){

            int x = digits[start]-'0'-1;

            for(int i=20; i<=22; i++){
                string temp = currString;
                temp += ('a'-1+i);
                letterCombinationsUtil(digits, start+1, result, temp);

            }
            return;

        }else if(digits[start]-'0'-1==8){

            int x = digits[start]-'0'-1;

            for(int i=23; i<=26; i++){
                string temp = currString;
                temp += ('a'-1+i);
                letterCombinationsUtil(digits, start+1, result, temp);

            }
            return;

        }



        return;
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)
            return {};
        vector<string> result;
        string currString;
        letterCombinationsUtil(digits, 0, result, currString);

        return result;

    }
};
