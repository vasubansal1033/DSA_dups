// gives tle
class Solution {
public:

    int calculateGrundy(vector<int>& grundyNo, int n){

        // if stones are 0, player 1 will loose
        if(n==0) return grundyNo[0] = 0;

        if(grundyNo[n]!=-1)
            return grundyNo[n];

        unordered_set<int> grundy;
        for(int i=1; i*i<=n; i++){
            grundyNo[n-i*i] = calculateGrundy(grundyNo, n-i*i);
            grundy.insert(grundyNo[n-i*i]);
        }

        // calculate the mex of this set
        int mex = 0;
        while(grundy.find(mex)!=grundy.end())
            mex++;

        return grundyNo[n] = mex;

    }
    bool winnerSquareGame(int n) {

        vector<int> grundyNo(n, -1);

        unordered_set<int> v;
        for(int i=1; i*i<=n; i++)
            v.insert(calculateGrundy(grundyNo, n-i*i));

        // calculate the mex of this set
        int mex = 0;
        while(v.find(mex)!=v.end())
            mex++;

        return mex != 0;

    }
};
