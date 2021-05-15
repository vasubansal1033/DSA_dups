class Solution {
public:

    static int distSq(vector<int>  p1, vector<int>  p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are colinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    static int orientation(vector<int>  p, vector<int>  q, vector<int>  r) {
        int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) {
            return 0;  // colinear
        }
        return (val > 0) ? 1 : 2; // clock or counterclock wise
    }

    vector<vector<int> > outerTrees(vector<vector<int> > points) {

        if (points.size() <= 3) {
            return points;
        }
        // Find the bottommost and left-most point
        int y_min = points[0][1], idx = 0;
        for(int i=1; i<points.size(); i++){
            if(points[i][1]<y_min || (points[i][1]==y_min && points[i][0]<points[idx][0])){
                y_min = points[i][1];
                idx = i;
            }
        }

        // Place the bottom-most point at first position
        swap(points[0], points[idx]);

        // If the intermediate points on the boundary are not needed then minute changes required in sorting statements.

        // Sort the points in increasing order of polar angle w.r.t. points[0]
        // In tied case, the one having smaller distance from p0 comes first
        vector<int>  p0 = points[0];
        sort(points.begin(), points.end(), [&](vector<int>& p1, vector<int>& p2){

            // p0 should be at beginning
            if(p1==p0) return true;
            if(p2==p0) return false;

            int o = orientation(p0, p1, p2);
            // If points are collinear
            // If x coordinate is same, sort in decreasing order of y coordinate
            // else sort in increasing order of x coordinate
            if (o == 0) {

                if(p1[0]==p2[0])
                    return p1[1]>p2[1];
                else
                    return p1[0]<p2[0];

            }
            return (o == 2);
        });

        // If the first few points have same x coordinate, then sort them in increasing order of y
        int i=0;
        while(points[i][0]==points[i+1][0])
            i++;

        if(i>0)
            sort(points.begin(), points.begin()+i+1, [&](vector<int> p1, vector<int> p2){
                return p1[1]<p2[1];
            });

        // Create an empty stack and push first three points to it.
        vector<vector<int> > vertices;
        vertices.push_back(points[0]);
        vertices.push_back(points[1]);
        // Process remaining n-2 points
        for (int i = 2; i < points.size(); i++) {

            //Keep removing top, until the current top 2 points in stack and points[i] forms a clockwise turn
            while (orientation(vertices[vertices.size() - 2], vertices.back(), points[i]) == 1)
                vertices.pop_back();

            vertices.push_back(points[i]);
        }
        return vertices;
    }
};
