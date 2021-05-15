#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
// O(nlogn)


// calculates distance between two points
float dist(p p1, p p2){
    return pow(pow(p1.first-p2.first, 2)+pow(p1.second-p2.second, 2), 0.5);
}
// bruteforce to find minimum distance. Used for less than 3 points
float bruteForce(vector<p> points){

    float mini = INT_MAX;
    for(int i=0; i<points.size()-1; i++){
        float d = dist(points[i], points[i+1]);
        if(mini>d)
            mini = d;
    }
    return mini;
}

// Helps in sorting Px and Py using STL sort
bool sortbyX(p p1, p p2){
    return p1.first<p2.first;
}
bool sortbyY(p p1, p p2){
    return p1.second<p2.second;
}

// Finds the minimum distance in strip. Then minimum with d. According to geometric calculations
// the inner loop wont for more than 7 times. Thus instead of n2 it is O(n)
float stripClosest(vector<p> strip, float d){

    float mini = d;
    for(int i=0; i<strip.size(); i++){

        for(int j=i+1; j<strip.size() && (strip[j].second-strip[i].second)<mini; j++){

            float di = dist(strip[i], strip[j]);
            if(di<mini)
                mini = d;

        }

    }
    return mini;

}
float closestDistanceUtil(vector<p> Px, vector<p> Py){

    if(Px.size()<=3)
        return bruteForce(Px);

    int mid = Px.size()/2;

    p midPoint = Px[mid];

    vector<p> Qx, Qy, Rx, Ry;
    for(int i=0; i<=mid; i++){
        Qx.push_back(Px[i]);
    }
    for(int i=mid+1; i<Px.size(); i++){
        Rx.push_back(Px[i]);
    }
    for(int i=0; i<Px.size(); i++){
        if(Py[i].first<=midPoint.first)
            Qy.push_back(Py[i]);
        else
            Ry.push_back(Py[i]);
    }

    float dl = closestDistanceUtil(Qx, Qy);
    float dr = closestDistanceUtil(Rx, Ry);
    float d = min(dl, dr);

    vector<p> strip;

    for(int i=0; i<Py.size(); i++){
        if(abs(Py[i].first-midPoint.first)<d)
            strip.push_back(Py[i]);
    }

    return stripClosest(strip, d);


}
float closestDistance(vector<p> points){

    vector<p> Px(points), Py(points);

    // Sort Px w.r.t. x and Py w.r.t. y
    sort(Px.begin(), Px.end(), sortbyX);
    sort(Py.begin(), Py.end(), sortbyY);

    return closestDistanceUtil(Px, Py);
}
int main(){

    vector<p> points;
    points.push_back({2, 3});
    points.push_back({12, 30});
    points.push_back({40, 50});
    points.push_back({5, 1});
    points.push_back({12, 10});
    points.push_back({3, 4});

    cout<<closestDistance(points)<<endl;

return 0;
}
