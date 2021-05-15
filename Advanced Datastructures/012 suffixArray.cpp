#include<bits/stdc++.h>
using namespace std;

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
int main(){

    string str = "missisippi";
    vector<int> suffixArray = getSA(str);

    for(int i=0; i<suffixArray.size(); i++)
        cout<<str.substr(suffixArray[i])<<'\n';

return 0;
}
