// greedy method will not work here
// As the jobs can have arbitrary weights which may lead to wrong choice
// second code is greedy method which is wrong
// this one is dp (ON2)

// optimal solution
// dont know the correctness
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){

        int n = endTime.size();

        // Created an array of indices to store the order of endtimes instead of creating a vector of pairs
        vector<int> idx(n, 0);
        for (int i = 0; i < n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [&endTime](int i, int j) { return endTime[i] < endTime[j]; });


        auto latestNonConflict = [&idx, &startTime, &endTime](int i) {

            int start = startTime[idx[i]], left = 0, right = i;

            while (left < right){
                int mid = left + (right - left) / 2;
                if (endTime[idx[mid]] <= start)
                    left = mid + 1;
                else
                    right = mid;
            }
            return right == 0 ? -1 : right - 1;
        };
        vector<int> dp(n, 0);
        dp[0] = profit[idx[0]];

        for (int i = 1; i < n; ++i){

            int curr = profit[idx[i]];
            int prev = latestNonConflict(i);
            if (prev != -1) curr += dp[prev];
            dp[i] = max(curr, dp[i - 1]);

        }
        return dp[n - 1];
    }
};

class Solution {
public:
    bool isIntersection(int& a, int& b, int& m, int& n){

        if(b>m) return true;
        else return false;

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        // Step 1 -> sort according to endTimes

        // jobs[i] = endTime, startTime, profit
        vector<pair<int, pair<int, int> > > jobs;
        for(int i=0; i<profit.size(); i++){
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }

        sort(jobs.begin(), jobs.end());

        // Step 2 -> Create maxProfits array which will store the maximum profit considering it as the last job done
        vector<int> maxProfits(profit.size());
        for(int i=0; i<profit.size(); i++){
            maxProfits[i] = jobs[i].second.second;
        }

        // Step 3 -> For job i, check every job j from 0 to i-1. If jth job can be done with ith job
        // take the maximum of all (maximum profit at j + profit of doing job i)
        int res = INT_MIN;
        for(int i=1; i<profit.size(); i++){

            int startTimeCurr = jobs[i].second.first;
            int endTimeCurr = jobs[i].first;
            for(int j=0; j<i; j++){

                int startTimePrev = jobs[j].second.first;
                int endTimePrev = jobs[j].first;

                if(!isIntersection(startTimePrev, endTimePrev, startTimeCurr, endTimeCurr)){
                    maxProfits[i] = max(maxProfits[i], maxProfits[j]+jobs[i].second.second);
                }

            }
            res = max(res, maxProfits[i]);


        }

        return res;

    }
};






class Solution {
public:
    bool isIntersection(int a, int b, int c, int d){

        // check if intervals [a, b] and [c, d] intersect
        // b and c can be equal

        if(b<=c || d<=a) return false;
        else return true;

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<pair<double, int> > profitPerUnitTime;
        for(int i=0; i<profit.size(); i++){

            double perUnitProfit = (profit[i]*1.0)/(endTime[i]-startTime[i]);
            profitPerUnitTime.push_back({perUnitProfit, i});

        }
        sort(profitPerUnitTime.begin(), profitPerUnitTime.end(), [&]( pair<double, int> a, pair<double, int> b){

            if(a.first==b.first) return endTime[a.second]<=endTime[b.second];
            return a.first<b.first;

        });

        vector<pair<int, int> > bookedIntervals;
        int totProfit = 0;
        for(int i = profit.size()-1; i>=0; i--){

            int currIdx = profitPerUnitTime[i].second; // index in given arrays

            bool flag = false;
            for(pair<int, int> p: bookedIntervals){

                if(isIntersection(p.first, p.second, startTime[currIdx], endTime[currIdx])){
                    flag = true;
                    break;
                }

            }
            if(flag) continue;
            bookedIntervals.push_back({startTime[currIdx], endTime[currIdx]});
            // cout<<currIdx<<" ";
            totProfit += profit[currIdx];

        }

        return totProfit;

    }
};
