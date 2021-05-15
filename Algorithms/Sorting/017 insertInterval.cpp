 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<pair<int, int> > intervalSpace;
    // add the non overlapping intervals
    for(int i=0; i<intervals.size(); i++){
        intervalSpace.push_back({intervals[i][0], 0});
        intervalSpace.push_back({intervals[i][1], 1});
    }
    // add the new interval
    intervalSpace.push_back({newInterval[0], 0});
    intervalSpace.push_back({newInterval[1], 1});

    sort(intervalSpace.begin(), intervalSpace.end(), [](pair<int, int>& a, pair<int, int>& b){
        if(a.first==b.first)
            return a.second<b.second;// change sign if touched intervals are not to be merged

        return a.first<b.first;
    });

    int count = 0;
    intervals.clear();

    for(int i=0; i<intervalSpace.size(); i++){

        if(intervalSpace[i].second==0){
            count++;
            if(count==1){
                intervals.push_back({intervalSpace[i].first});
            }
        }else{
            count--;
            if(count==0){
                intervals[intervals.size()-1].push_back(intervalSpace[i].first);
            }
        }

    }

    return intervals;


}
