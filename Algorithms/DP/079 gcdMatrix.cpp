#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 5;

int a[N], b[N];
int ca[N], cb[N];
long long cnt[N];

int main() {
    int n, m, q;
    cin>>n>>m>>q;

    for (int i = 0; i < n; ++i)
        cin>>a[i];

    for (int i = 0; i < m; ++i)
        cin>>b[i];

    for (int it = 0; it < q; ++it) {
        int a, b, c, d; cin>>a>>b>>c>>d;
        ++a, ++b, ++c, ++d;

        // ca and cb store counts of numbers in arrays a and b
        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        for (int i = a - 1; i < c; ++i)
            ca[::a[i]]++; // global scope resolution operator
        for (int i = b - 1; i < d; ++i)
            cb[::b[i]]++;


        for (int i = 1; i < N; ++i)
            for (int j = i + i; j < N; j += i) {
                ca[i] += ca[j];
                cb[i] += cb[j];
            }
        int res = 0;
        for (int i = N - 1; i >= 1; --i) {
            cnt[i] = ca[i] * 1ll * cb[i];
            for (int j = i + i; j < N; j += i)
                cnt[i] -= cnt[j];
            if (cnt[i])
                res++;
        }
        cout<<res<<'\n';
    }
    return 0;
}
