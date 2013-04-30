#include <iostream>
using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

typedef long long ll;

int T;
int N,M;

ll a[100];
ll aa[100];
int A[100];
ll b[100];
ll bb[100];
int B[100];

ll DP[100][100];

ll solve(int i, int j){
    if (i==N || j==M) return 0;
    if (a[i]==aa[i] && b[j]==bb[j] && DP[i][j]>=0) return DP[i][j];
    
    if (A[i]==B[j]) {
        if (a[i]==b[j]) {
            ll r=a[i]+solve(i+1,j+1);
            if (a[i]==aa[i]&&b[j]==bb[j]) DP[i][j]=r;
            return r;
        }
        if (a[i]>b[j]) {
            a[i] -= b[j];
            ll ans = b[j] + solve(i,j+1);
            a[i] += b[j];
            if (a[i]==aa[i]&&b[j]==bb[j]) DP[i][j]=ans;
            return ans;
        }
        if (a[i]<b[j]) {
            b[j] -= a[i];
            ll ans = a[i] + solve(i+1,j);
            b[j] += a[i];
            if (a[i]==aa[i]&&b[j]==bb[j]) DP[i][j]=ans;
            return ans;
        }
    }
    ll r =std::max(solve(i+1,j), solve(i,j+1));
    if (a[i]==aa[i]&&b[j]==bb[j]) DP[i][j]=r;
    return r;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>M;
        rep(i,0,N) {cin>>a[i]>>A[i]; aa[i]=a[i];}
        rep(i,0,M) {cin>>b[i]>>B[i]; bb[i]=b[i]; }
        rep(i,0,N)rep(j,0,M)DP[i][j]=-1;
        
        cout<<"Case #"<<t<<": "<<solve(0,0)<<endl;
    }
    return 0;
}
