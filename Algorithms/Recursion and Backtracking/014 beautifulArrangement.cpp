class Solution {
public:

    void countArrangementUtil(int& n, vector<bool>& visited, int start, int& count){
        // base case
        if(start>=n){
            count++;
            return;
        }

        for(int i=1; i<=n; i++){

            if(!visited[i-1] && (i%(start+1)==0 || ((start+1)%i==0))){

                visited[i-1] = true;
                countArrangementUtil(n, visited, start+1, count);
                visited[i-1] = false;

            }

        }

        return;


    }
    int countArrangement(int N) {

        if(N==0)
            return 0;

        vector<bool> visited(N, false);
        int count = 0;
        countArrangementUtil(N, visited, 1, count);

        return count;

    }
};
