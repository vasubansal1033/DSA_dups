class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int front = q.front(); q.pop();
            if(arr[front]==0) return true;

            visited[front] = true;

            if(front+arr[front]<arr.size() && !visited[front+arr[front]])
                q.push(front+arr[front]);
            if(front-arr[front]>=0 && !visited[front-arr[front]])
                q.push(front-arr[front]);

        }

        return false;

    }
};
