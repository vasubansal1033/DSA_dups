// naive solution
//class Solution {
//public:
//
//          int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//
//        vector<pair<int, int>> jobs;
//
//        int N = profit.size(), res = 0, i = 0, best = INT_MIN;
//
//        for (int j = 0; j < N; ++j)
//            jobs.push_back({difficulty[j], profit[j]});
//
//        sort(jobs.begin(), jobs.end());
//        sort(worker.begin(), worker.end());
//
//        for (int & ability : worker) {
//
//            while (i < N && ability >= jobs[i].first)
//                best = max(jobs[i++].second, best);
//            res += best;
//        }
//        return res;
//    }
//
//
//
//};


// dp solution
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int* difficultyProfitMap = new int[100001];
        for(int i=0; i<100001; i++)
            difficultyProfitMap[i] = 0;

        // incase two work with same difficulty are present, consider the one with maximum profit
        for(int i=0; i<difficulty.size(); i++)
            difficultyProfitMap[difficulty[i]] = max(difficultyProfitMap[difficulty[i]], profit[i]);

        for(int i=1; i<100001; i++)
            difficultyProfitMap[i] = max(difficultyProfitMap[i-1], difficultyProfitMap[i]);

        int total = 0;
        for(auto i:worker)
            total+=difficultyProfitMap[i];

        return total;
    }
};
