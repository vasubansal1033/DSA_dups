class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<pair<int, int> > players(scores.size());
        for(int i=0; i<scores.size(); i++){
            players[i] = {scores[i], ages[i]};
        }

        // sort first by ages, if equal age then sort by score
        sort(players.begin(), players.end(), [&](pair<int, int> a, pair<int, int> b){

            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;

        });

        int res = 0;
        // Maximum sum of a longest increasing subsequence of scores
        int lis[scores.size()];
        for(int i=0; i<players.size(); i++){

            lis[i] = players[i].first;
            for(int j=i-1; j>=0; j--){

                if(players[i].first>=players[j].first)
                    lis[i] = max(lis[i], lis[j]+players[i].first);

            }
            res = max(res, lis[i]);

        }

        return res;

    }
};
