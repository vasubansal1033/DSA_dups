int dist(int x, int y, int a, int b){
    return max(abs(a-x), abs(b-y));
}
int Solution::coverPoints(vector<int> &A, vector<int> &B) {

    int cnt = 0;
    int prevX = A[0];
    int prevY = B[0];

    for(int i=1; i<A.size(); i++){

        cnt+=dist(A[i], B[i], A[i-1], B[i-1]);

    }

    return cnt;

}
