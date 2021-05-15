#include<bits/stdc++.h>
using namespace std;

//https://cp-algorithms.com/string/suffix-array.html

class suffix{
public:
    int idx;
    vector<int> ranks;
    suffix(){
        ranks.resize(2);
    }

};
vector<int> getSA(string& str){

    vector<suffix> suffixes(str.size());
    for(int i=0; i<suffixes.size(); i++){
        suffixes[i].idx = i;
        suffixes[i].ranks[0] = str[i]-'a';
        suffixes[i].ranks[1] = i+1<str.size()?str[i+1]-'a':-1;
    }

    sort(suffixes.begin(), suffixes.end(), [&](suffix a, suffix b){

        if(a.ranks[0]==b.ranks[0]) return a.ranks[1]<b.ranks[1];
        return a.ranks[0]<b.ranks[0];

    });

    vector<int> idxMapping(str.size());
    for(int k = 2; k<str.size(); k*=2){

        int rnk = 0;
        int prev = suffixes[0].ranks[0];
        suffixes[0].ranks[0] = rnk; // assigned first rank suffix as 0
        idxMapping[suffixes[0].idx] = 0;

        // assigning primary ranks
        for(int i=1; i<str.size(); i++){


            if(suffixes[i].ranks[0]==prev && suffixes[i].ranks[1]==suffixes[i-1].ranks[1]){
                prev = suffixes[i].ranks[0];
                suffixes[i].ranks[0] = rnk;
            }else{
                prev = suffixes[i].ranks[0];
                suffixes[i].ranks[0] = ++rnk;
            }
            idxMapping[suffixes[i].idx] = i;

        }

        // assign secondary ranks
        for(int i=0; i<str.size(); i++){

            int nextIdx = suffixes[i].idx+k;
            suffixes[i].ranks[1] = nextIdx<str.size()?suffixes[idxMapping[nextIdx]].ranks[0]:-1;

        }

        sort(suffixes.begin(), suffixes.end(), [&](suffix a, suffix b){

            if(a.ranks[0]==b.ranks[0]) return a.ranks[1]<b.ranks[1];
            return a.ranks[0]<b.ranks[0];

        });


    }

    vector<int> suffixArray(str.size());
    for(int i=0; i<suffixArray.size(); i++)
        suffixArray[i] = suffixes[i].idx;

    return suffixArray;

}
/* To construct and return LCP */
vector<int> buildLCP(string& str, vector<int>& suffixArray)
{
    int n = suffixArray.size();
    vector<int> lcp(n, 0);

    // An auxiliary array to store inverse of suffix array
    vector<int> invSuff(n, 0);

    for (int i=0; i < n; i++) invSuff[suffixArray[i]] = i;

    int k = 0; // Initialize length of previous LCP

    for (int i=0; i<n; i++){
        // If the current suffix is at n-1, then we don’t have next substring to consider.
        if (invSuff[i] == n-1){
            k = 0;
            continue;
        }
        /* j contains index of the next substring to
           be considered  to compare with the present
           substring, i.e., next string in suffix array */
        int j = suffixArray[invSuff[i]+1];

        // Directly start matching from k'th index as
        // at-least k-1 characters will match
        while (i+k<n && j+k<n && str[i+k]==str[j+k]) k++;

        lcp[invSuff[i]] = k; // lcp for the present suffix.

        // Deleting the starting character from the string.
        if (k>0) k--;
    }

    // return the constructed lcp array
    return lcp;
}
int countDistinctSubstring(string& str){
    int n = str.size();
    vector<int> suffixArray = getSA(str);
    vector<int> lcp = buildLCP(str, suffixArray);

    // n - suffixArr[i] will be the length of suffix
    // at ith position in suffix array initializing
    // count with length of first suffix of sorted
    // suffixes
    int result = n - suffixArray[0];

    for (int i = 1; i < lcp.size(); i++)

        //  subtract lcp from the length of suffix
        result += (n - suffixArray[i]) - lcp[i - 1];

    result++;  // For empty string
    return result;
}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){
        string str; cin>>str;
        cout<<countDistinctSubstring(str)<<'\n';
    }

return 0;
}
