// O(n2)

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

// returns 0 if points are collinear
// 1 if clockwise
// 2 if counterclockwise
int orientation(p p1, p p2, p p3){

    // determinant of these points
    // area of triangle
    int val = (p2.second-p1.second)*(p3.first-p2.first)-
                (p2.first-p1.first)*(p3.second-p2.second);

    if(val==0) return 0;
    return val>0?1:2;

}

vector<p> convexHull(vector<p> points){

    int n = points.size();
    if(n<2)
        return {};

    vector<p> hull;

    // find the leftmost point
    int l=0;
    for(int i=1; i<n; i++){
        if(points[i].first<points[l].first)
            l=i;
    }

    // this point will definitely be in the convex hull
    int p=l, q;
    do{
        // add the current point
        hull.push_back(points[p]);

        q = (p+1)%n;
        // find q s.t. (p, x, q) is counterclockwise
        // i.e we want most counterclockwise/left-sided q, w.r.t p
        for(int i=0; i<n; i++){

            if(orientation(points[p], points[i], points[q])==2){
                q = i;
            }

        }

        // make the current point
        p=q;

    }while(p!=l); // while we don't come to the first point(which was the leftmost)

    return hull;
}

int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<p> points;
        for(int i=0; i<n; i++){
            int x, y; cin>>x>>y;
            points.push_back({x, y});
        }

        vector<p> v = convexHull(points);
        if(v.size()==0){
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++)
            if(i==v.size()-1)
                cout<<v[i].first<<" "<<v[i].second;
            else
                cout<<v[i].first<<" "<<v[i].second<<", ";
        cout<<endl;

    }


}
