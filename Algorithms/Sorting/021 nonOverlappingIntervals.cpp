// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });

        int i=0;
        int count = 0;
        while(i<intervals.size()){
            int currentInterval = i;
            int j = i+1;
            while(j<intervals.size()){
                if(intervals[j][0]<intervals[currentInterval][1])
                    count++;
                else break;
                j++;

            }
            i = j;
        }

        return count;

    }
};
