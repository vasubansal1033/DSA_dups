vector<vector<int>> merge(vector<vector<int>>& intervals) {

    int n = intervals.size();
    vector<pair<int, int> > intervalSpace;

    // insert all numbers in the interval space
    // 0 if opening, 1 if closing side
    for(int i=0; i<n; i++){
        intervalSpace.push_back({intervals[i][0], 0});
        intervalSpace.push_back({intervals[i][1], 1});
    }

    sort(intervalSpace.begin(), intervalSpace.end(), [&](pair<int, int>& a, pair<int, int>& b){

        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;

    });

    // whenever we encounter count==1 after incrementing, itmeans an opening juncture
    // whenever we encounter count==0 after decrementing, itmeans an closing juncture
    vector<vector<int> > result;
    int count = 0;
    for(int i=0; i<intervalSpace.size(); i++){

        if(intervalSpace[i].second==0){
            count++;
            if(count==1){
                result.push_back({intervalSpace[i].first});
            }
        }else{
            count--;
            if(count==0){
                result[result.size()-1].push_back(intervalSpace[i].first);
            }
        }

    }

    return result;

}
