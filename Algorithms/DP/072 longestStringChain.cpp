class Solution {
public:
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), [&](string a, string b){

            return a.size()<b.size();

        });

        unordered_map<string, int> dp;
        int res = 0;
        for(auto& word:words){

            for(int i=0; i<word.size(); i++){

                string temp = word.substr(0, i).append(word.substr(i+1));
                if(dp.find(temp)!=dp.end())
                    dp[word] = max(dp[word], 1+dp[temp]);

                else dp[word] = max(dp[word], 1);
            }
            res = max(res, dp[word]);
        }

        return res;

    }
};


class Solution {
public:

    bool isDifferByOne(string &a, string &b){

        int i = 0, j = 0, counter = 0;
        while(i < a.size() and j < b.size()){

            if(a[i] == b[j]){
                i++; j++;
            }
            else{
                i++;
                counter++;
            }
        }

        return (counter <= 1);
    }

    int longestStrChain(vector<string>& words){

        int n = words.size();
        vector<int> dp(n, 1);
        int maxm = 0;

        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){

              if(words[i].size() == 1 + words[j].size() and isDifferByOne(words[i], words[j]) && dp[i] < dp[j] + 1 )
                dp[i] = dp[j] + 1;
            }
            maxm = max(maxm, dp[i]);
        }

        return maxm;
    }
};
