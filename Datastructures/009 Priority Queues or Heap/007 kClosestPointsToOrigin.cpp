#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> distPoint;
// avoid square because returning as int and also unnecessary calculations
int distance(p p1){
    return pow(p1.first, 2)+pow(p1.second, 2);
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

    priority_queue<distPoint> maxHeap;
    for(int i=0; i<points.size(); i++){

        int dist = distance({points[i][0], points[i][1]});
        p p_ = {points[i][0], points[i][1]};
        maxHeap.push({dist, p_});

        if(maxHeap.size()>K)
            maxHeap.pop();

    }
    vector<vector<int> > ans;
    while(!maxHeap.empty()){

        p p_ = maxHeap.top().second;
        vector<int> v = {p_.first, p_.second};
        ans.push_back(v);
        maxHeap.pop();

    }
    return ans;

}
int main(){

    int n, k; cin>>n>>k;
    vector<vector<int> > points(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin>>points[i][0]>>points[i][1];
    }
    vector<vector<int> > ansV = kClosest(points, k);
    for(int i=0; i<ansV.size(); i++)
        cout<<ansV[i][0]<<" "<<ansV[i][1]<<endl;


return 0;
}
