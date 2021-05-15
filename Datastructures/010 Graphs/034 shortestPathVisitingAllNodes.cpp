struct Tuple {
    int bitMask;
    int curr;
    int cost;

    Tuple(int bit, int n, int c) {
        bitMask = bit;
        curr = n;
        cost = c;
    }

    bool equals(const Tuple& p) const {
        return bitMask == p.bitMask && curr == p.curr && cost == p.cost;
    }

    int hashCode() const {
        return 1331 * bitMask + 7193 * curr + 727 * cost;
    }
};

struct Hash {
    size_t operator() (const Tuple &p) const {
        return p.hashCode();
    }
};

static bool operator==(const Tuple& lhs, const Tuple& rhs) {
    return lhs.equals(rhs);
}

class Solution {
public:
     int shortestPathLength(vector<vector<int>>& graph) {

        int N = graph.size();

        queue<Tuple> q;
        unordered_set<Tuple, Hash> visited;

        for (int i = 0; i < N; i++) {
            int tmp = (1 << i);
            visited.emplace(Tuple(tmp, i, 0));
            q.emplace(Tuple(tmp, i, 1));
        }

        while (!q.empty()) {
            Tuple curr = q.front();
            q.pop();

            if (curr.bitMask == (1 << N) - 1) {
                return curr.cost - 1;
            }
            else {
                auto& neighbors = graph[curr.curr];

                for (int v : neighbors) {
                    int bitMask = curr.bitMask;
                    bitMask |= (1 << v);

                    Tuple t(bitMask, v, 0);
                    if (!visited.count(t)) {
                        q.emplace(Tuple(bitMask, v, curr.cost + 1));
                        visited.emplace(t);
                    }
                }
            }
        }
        return -1;
    }
};
