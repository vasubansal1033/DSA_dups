
class Solution {
public:
    vector<vector<int> > getSkyline(vector<vector<int>>& buildings) {

        pair<int,int> curr({0,0});
        vector<vector<int> > result;
        multiset<pair<int,int>> seq;

        for(auto p:buildings){
            seq.emplace(make_pair(p[0], -p[2]));
            seq.emplace(make_pair(p[1], p[2]));
        }

        multiset<int> height({0});

        for(auto p:seq){

            // if it is a starting point, insert the height
            // otherwise, remove the height
            if(p.second<0)
                height.emplace(-p.second);
            else
                height.erase(height.find(p.second));

            // if maximum height changes, after insertion/deletion
            // insert the point
            if(*height.rbegin()!=curr.second){

                curr.first = p.first;
                curr.second = *height.rbegin();
                result.push_back({curr.first, curr.second});

            }

        }

        return result;

    }
};


// Just manages to pass
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        if(buildings.size()==0) return {};

        vector<vector<int> > points;
        for(int i=0; i<buildings.size(); i++){

            // insert starting point
            points.push_back({buildings[i][0], buildings[i][2], 0});

            // insert ending point
            // if consecutive buildings of same height are placed then merge them into one building
            while(i<buildings.size()-1 && buildings[i][2]==buildings[i+1][2]){
                i++;
            }

            points.push_back({buildings[i][1], buildings[i][2], 1});


        }

        sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b){

            // if points are clashing (x coordinates are same)
            if(a[0]==b[0]){

                // if start of one point coincides with end of another, then start point must be looked at first
                // otherwise the end point will also come in starline
                if(a[2]!=b[2]){

                    if(a[2]==0)
                        return true;
                    else if(b[2]==0)
                        return false;

                }

                // if two points have same starting, place the point with larger height first
                // otherwise the smaller point will also come in skyline
                else if(a[2]==0 && b[2]==0){
                    return a[1]>b[1];
                }

                // if two points have same ending, place the point with smaller height first
                // otherwise it will also come in skyline
                else if(a[2]==1 && b[2]==1){
                    return a[1]<b[1];
                }


            }

            return a[0]<b[0];

        });


        // if there are any points s.t. a building of height ends another building of same height starts, then remove those
        // instead of removing from vector, we can ignore these points wihle iterating

//         for(int i=0; i<points.size()-1; i++){

//             if(points[i][0]==points[i+1][0] && points[i][1]==points[i+1][1] && points[i][2]!=points[i+1][2]){
//                 points.erase(points.begin()+i, points.begin()+i+2);
//             }

//         }

        vector<vector<int> > res;
        set<int, greater<int> > s;
        s.insert(0);

        for(int i=0; i<points.size(); i++){

            // ignoring those points as mentioned above
            if(i<points.size()-1 && points[i][0]==points[i+1][0] && points[i][1]==points[i+1][1] && points[i][2]!=points[i+1][2]){
                i++;
                continue;
            }

            int sMax = *s.begin(); // minimum height in set

            // If we encounter a start, insert the y-coord
            if(points[i][2]==0){

                if(s.find(points[i][1])!=s.end()) continue;

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

                if(*s.begin()<sMax){
                    res.push_back({points[i][0], *s.begin()});
                }

            }

        }

        return res;

    }
};
