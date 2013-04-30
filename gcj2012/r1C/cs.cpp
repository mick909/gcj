#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <memory>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

static const ll Zp = 1000000009;
static const double EPS = 1e-9;

int T;
int N,M;

ll a[100];
int A[100];
ll b[100];
int B[100];

ll solve(int i, int j){
    if (i==N || j==M) return 0;
    
    if (A[i]==B[j]) {
        if (a[i]==b[j]) {
            return a[i]+solve(i+1,j+1);
        }
        if (a[i]>b[j]) {
            a[i] -= b[j];
            ll ans = b[j] + solve(i,j+1);
            a[i] += b[j];
            return ans;
        }
        if (a[i]<b[j]) {
            b[j] -= a[i];
            ll ans = a[i] + solve(i+1,j);
            b[j] += a[i];
            return ans;
        }
    }
    return std::max(solve(i+1,j), solve(i,j+1));
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>M;
        rep(i,0,N) cin>>a[i]>>A[i];
        rep(i,0,M) cin>>b[i]>>B[i];
        
        cout<<"Case #"<<t<<": "<<solve(0,0)<<endl;
    }
    return 0;
}
