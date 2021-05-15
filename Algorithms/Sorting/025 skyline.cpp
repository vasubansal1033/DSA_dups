class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<vector<int> > points;
        for(int i=0; i<buildings.size(); i++){

            // insert starting point
            points.push_back({buildings[i][0], buildings[i][2], 0});
            // insert ending point
            points.push_back({buildings[i][1], buildings[i][2], 1});

        }

        // multiset<int, greater<int> > s;
        set<int, greater<int> > s;
        s.insert(0);

        sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b){

            // if points are clashing
            if(a[0]==b[0]){

                // if two points have same starting, place the point with larger height first
                if(a[2]==b[2]==0){
                    return a[1]>b[1];
                }
                // if start of one point coincides with end of another, then start point must be looked at first
                else if(a[2]!=b[2] && a[0]==b[0]){

                    if(a[2]==0)
                        return true;
                    else if(b[2]==0)
                        return false;

                }
                // if two points have same ending, place the point with smaller height first
                else if(a[2]==b[2]==1 && a[0]==b[0]){
                    return a[1]<b[1];
                }


            }

            return a[0]<b[0];

        });

        vector<vector<int> > res;
        for(int i=0; i<points.size(); i++){

            int sMax = *s.begin();
            cout<<points[i][0]<<" "<<points[i][1]<<" "<<points[i][2]<<'\n';

            // If we encounter start, insert the y-coord
            if(points[i][2]==0){

                s.insert(points[i][1]);
                // if it changes max, output in res
                if(*s.begin()>sMax){
                    res.push_back({points[i][0], *s.begin()});
                }

            }else{

                // If we encounter end, remove the y-coord
                // It could happen that set can have duplicate heights
                // So have to use multisets
                // But then how to identify which point to remove?

                s.erase(points[i][1]);
                // s.erase(s.lower_bound(points[i][1]));

                if(*s.begin()<sMax){
                    res.push_back({points[i][0], *s.begin()});
                }

            }

        }

        return res;

    }
};
