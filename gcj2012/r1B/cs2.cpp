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

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N;
        vector<int> S(N);
        map<int, vector<int> > M;
        
        rep(i,0,N) {cin>>S[i];}
        
        int sum=0;
        vector<int> SB;
        rep(i,1,1<<N) {
            SB.clear();
            rep(j,0,N) {
                if (i & (1<<j)) {SB.pb(S[j]); sum+=S[j];}
            }
            if (M.find(sum) != M.end()) {break;}
            M[sum]=SB;
            sum=0;
        }
        cout<<"Case #"<<t<<":"<<endl;
        if (sum) {
            cout << M[sum][0];
            rep(i,1,M[sum].size()) cout << " " << M[sum][i];
            cout <<endl;
            cout << SB[0];
            rep(i,1,SB.size()) cout << " " << SB[i];
            cout <<endl;
        } else {
            cout << "Impossible"<<endl;
        }
    }
    return 0;
}
