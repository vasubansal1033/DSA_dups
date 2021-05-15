#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

void ans(vector<int>& s, vector<int>& e){

    vector<pair<int, int> > timings;
    unordered_map<string, int> m;

    loop(i, s.size()){
        timings.push_back({s[i], e[i]});
        string str = to_string(s[i])+" "+to_string(e[i]);
        m[str] = i+1;
    }
    sort(timings.begin(), timings.end(),[&](pair<int, int> a, pair<int, int> b){
        return a.second<b.second;
    });

    int prev;
    loop(i, timings.size()){

        if(i==0){
            string str = to_string(timings[0].first)+" "+to_string(timings[0].second);
            cout<<m[str]<<" ";
            prev = 0;
            continue;
        }else{

            if(timings[i].first>=timings[prev].second){
                string str = to_string(timings[i].first)+" "+to_string(timings[i].second);
                cout<<m[str]<<" ";
                prev = i;
            }

        }


    }
    cout<<endl;

}
int main()
 {
	//code
	int t; cin>>t;
	loop(i, t){
	    int n; cin>>n; vector<int> s(n), e(n);
	    loop(j, n)
	        cin>>s[j];
	    loop(j, n)
	        cin>>e[j];

	    ans(s, e);
	}

	return 0;
}
