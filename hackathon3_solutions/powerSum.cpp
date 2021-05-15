#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
void powerSumUtil(int x, int n, int& count, int start){
    
    // base case
    if(x<0)
        return;
    if(x==0)
        count++;
    
    
    for(int i=start; pow(i, n)<=x; i++){
        
        // ith number is minimum
        powerSumUtil(x-pow(i, n), n, count, i+1);
        
    }
    
}
int powerSum(int X, int N) {

    int count = 0;
    powerSumUtil(X, N, count, 1); 
    
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
