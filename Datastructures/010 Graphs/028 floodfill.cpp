class Solution {
public:
    bool isValid(vector<vector<int> >& image, int& oldColor, int x, int y){

        if(x<0 || y<0 || x>=image.size() || x>=image[0].size()|| image[x][y]!=oldColor)
            return false;
        return true;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        queue<pair<int, int> > q;

        int oldColor = image[sr][sc];
        if(oldColor==newColor) return image;

        q.push({sr, sc});


        while(!q.empty()){

            pair<int, int> front = q.front(); q.pop();
            int x = front.first; int y = front.second;

            image[x][y] = newColor;

            if(isValid(image, oldColor, x+1, y))
                q.push({x+1, y});
            if(isValid(image, oldColor, x-1, y))
                q.push({x-1, y});
            if(isValid(image, oldColor, x, y+1))
                q.push({x, y+1});
            if(isValid(image, oldColor, x, y-1))
                q.push({x, y-1});

        }

        return image;

    }
};
