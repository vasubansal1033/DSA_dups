int minMeetingRooms(vector<vector<int>>& intervals) {

    if(intervals.size()==0)
        return 0;

    vector<pair<int, int> > intervalSpace;
    for(int i=0; i<intervals.size(); i++){
        intervalSpace.push_back({intervals[i][0], 0});
        intervalSpace.push_back({intervals[i][1], 1});
    }

    sort(intervalSpace.begin(), intervalSpace.end(), [](pair<int, int>& a, pair<int, int>& b){
        // smartness. if same number is opening and closing in two intervals
        // then we'd first decrement count and then increase. otherwise
        // our maxCount will store 1 more
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    });


    int count = 0;
    int maxCount = 0;
    for(auto p:intervalSpace){
        if(p.second==0){
            count++;
            maxCount = max(maxCount, count);
        }else count--;


    }

    return maxCount;
}
