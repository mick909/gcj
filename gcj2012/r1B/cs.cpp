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
int N;

int solve(){
    return 0;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N;
        vector<int> S(N);
        rep(i,0,N) {cin>>S[i];}
        vector<int> A,B;
        bool fnd=false;
        rep(i,3,1<<N) {
            vector<int> SB;
            int sum=0;
            rep(j,0,N) {
                if (i & (1<<j)) {SB.pb(S[j]); sum+=S[j];}
            }
            if (sum%1) continue;
            rep(j,0,(1<<SB.size())) {
                int ss=0;
                rep(k,0,SB.size()) {
                    if (j & (1<<k)) ss+=SB[k];
                }
                if (ss+ss == sum) {
                    rep(k,0,SB.size()) {
                        if (j & (1<<k)) A.pb(SB[k]); else B.pb(SB[k]);
                    }
                    fnd=true;
                    break;
                }
            }
            if (fnd) break;
        }
        cout<<"Case #"<<t<<":"<<endl;
        if (fnd) {
            cout << A[0];
            rep(i,1,A.size()) cout << " " << A[i];
            cout <<endl;
            cout << B[0];
            rep(i,1,B.size()) cout << " " << B[i];
            cout <<endl;
        } else {
            cout << "Impossible"<<endl;
        }
    }
    return 0;
}
