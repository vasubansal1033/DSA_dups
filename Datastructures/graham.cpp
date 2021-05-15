class Solution {
public:
    // A utility function to return square of distance
    // between p1 and p2
    static int distSq(Point p1, Point p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }

    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are colinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    static int orientation(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) {
            return 0;  // colinear
        }
        return (val > 0) ? 1 : 2; // clock or counterclock wise
    }

    // A comparison function object using specified reference point
    struct pointsComparator {
        Point p0;
        bool operator() (const Point& p1, const Point& p2) {

            // Find orientation
            int o = orientation(p0, p1, p2);
            if (o == 0) {
                return distSq(p0, p2) >= distSq(p0, p1);
            }
            return o == 2;
        }
        pointsComparator(Point p) : p0(p) {}
    };

    // Prints convex hull of a set of n points.
    vector<Point> outerTrees(vector<Point> points) {
        int n = points.size();
        if (n <= 3) {
            return points;
        }
        // Find the bottommost point
        int ymin = points[0].y, min = 0;
        for (int i = 1; i < n; i++) {
            int y = points[i].y;
            // Pick the bottom-most or chose the left most point in case of tie
            if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
                ymin = points[i].y, min = i;
            }
        }

        // Place the bottom-most point at first position
        Point temp = points[0];
        points[0] = points[min];
        points[min] = temp;

        // Sort n-1 points with respect to the first point.
        // A point p1 comes before p2 in sorted ouput
        // if p2 has larger polar angle (in counterclockwise direction) than p1
        // In the tied case, the one has smaller distance from p0 comes first
        Point p0 = points[0];
        sort(points.begin(), points.end(), pointsComparator(p0));
        //As we need to output all the vertices instead of extreme points
        //We need to sort the points with the same largest polar angle w.r.p. p0 in another way to break tie
        //Closer one comes last
        Point pn = points.back();
        if (orientation(p0, points[1], pn) != 0) {
            int idx = n-1;
            while (orientation(p0, points[idx], pn) == 0) {
                idx--;
            }
            reverse(points.begin() + idx + 1, points.end());
        }

        // Create an empty stack and push first three points to it.
        vector<Point> vertices;
        vertices.push_back(points[0]);
        vertices.push_back(points[1]);
        vertices.push_back(points[2]);
        // Process remaining n-3 points
        for (int i = 3; i < n; i++) {
            // Keep removing top while the angle formed by
            // points next-to-top, top, and points[i] makes a right (in clockwise) turn
            while (orientation(vertices[vertices.size() - 2], vertices.back(), points[i]) == 1) {
                vertices.pop_back();
            }
            vertices.push_back(points[i]);
        }
        return vertices;
    }
};
