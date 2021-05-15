#include <bits/stdc++.h>
using namespace std;

int maxNormalSubstring(string& P, string& Q, int K, int N){

    if (K == 0) return 0;

    // keeps count of normal characters
    int cnt = 0, left = 0, right = 0;
    int ans = 0;

    while (right < N) {

        while (right < N && count <= K) {

            // get position of character
            int pos = P[right] - 'a';

            // check if current character is normal
            if (Q[pos] == '0') {
                // check if normal characters count exceeds K
                if (cnt + 1 > K) break;
                else cnt++;
            }
            right++;
            // update answer with substring length
            if (cnt <= K)
                ans = max(ans, right - left);
        }

        while (left < right) {
            // get position of character
            int pos = P[left] - 'a';
            left++;
            // check if character is
            // normal then decrement count
            if (Q[pos] == '0') cnt--;
            if (cnt < K) break;
        }
    }
    return ans;
}

// Driver code
int main()
{
    // initialise the string
    string P = "giraffe", Q = "01111001111111111011111111";
    int K = 2;
    int N = P.length();
    cout << maxNormalSubstring(P, Q, K, N);
    return 0;
}
