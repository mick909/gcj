#include <iostream>
#include <map>
using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

typedef long long ll;
typedef pair<int,int> key_t;

int T;
int N,M;

ll a[100];
int A[100];
ll b[100];
int B[100];

map<key_t,ll> DP[100][100];

ll solve(int i, int j){
    if (i==N || j==M) return 0;
    if (DP[i][j].find(make_pair(a[i],b[j])) != DP[i][j].end()) return DP[i][j][make_pair(a[i],b[j])];
    
    if (A[i]==B[j]) {
        if (a[i]==b[j]) {
            ll r=a[i]+solve(i+1,j+1);
            DP[i][j][make_pair(a[i],b[j])] = r;
            return r;
        }
        if (a[i]>b[j]) {
            a[i] -= b[j];
            ll ans = b[j] + solve(i,j+1);
            a[i] += b[j];
            DP[i][j][make_pair(a[i],b[j])] = ans;
            return ans;
        }
        if (a[i]<b[j]) {
            b[j] -= a[i];
            ll ans = a[i] + solve(i+1,j);
            b[j] += a[i];
            DP[i][j][make_pair(a[i],b[j])] = ans;
            return ans;
        }
    }
    ll r =std::max(solve(i+1,j), solve(i,j+1));
    DP[i][j][make_pair(a[i],b[j])] = r;
    return r;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>M;
        rep(i,0,N) {cin>>a[i]>>A[i];}
        rep(i,0,M) {cin>>b[i]>>B[i];}
        rep(i,0,N)rep(j,0,M)DP[i][j].clear();
        
        cout<<"Case #"<<t<<": "<<solve(0,0)<<endl;
    }
    return 0;
}
