bool canAttendMeetings(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    });

    int i=0;
    while(i<intervals.size()){

        int currentInterval = i;
        int j = i+1;
        while(j<intervals.size()){

            if(intervals[j][0]<intervals[currentInterval][1])
                return false;
            else break;
            j++;

        }

        i = j;

    }

    return true;


}

// other solution
bool canAttendMeetings(vector<vector<int>>& intervals) {

    int m = intervals.size(), i, count = 0;
    vector<pair<int, int>> intervalSpace;
    for(i = 0; i<m; i++){
        // 0 for start
        intervalSpace.push_back(make_pair(intervals[i][0], 0));
        // 1 for end
        intervalSpace.push_back(make_pair(intervals[i][1], 1));
    }
    sort(intervalSpace.begin(), intervalSpace.end(), [=](pair<int, int> &a, pair<int, int> &b){
       if(a.first == b.first){
           return a.second > b.second;
       }
        return a.first < b.first;
    });
    for(i = 0; i<intervalSpace.size(); i++){
        if(count > 1) return false;
        if(intervalSpace[i].second == 0)
            count++;
        else
            count--;
    }
    return true;
}
