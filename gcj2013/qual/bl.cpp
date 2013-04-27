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
int a[100][100];
set<int> aa;

string solve(){
    set<int>::iterator it=aa.begin();
    cout << aa.size() << endl;
    for (; it!=aa.end();++it) {
    
    for (int n=0;n<N;++n) {
        bool chk=true;
        for (int m=0;m<M;++m) {
            if (a[n][m]>*it) {chk=false;break;}
        }
        if (chk) {
            for (int m=0;m<M;++m) {
                if (a[n][m]==*it) a[n][m]=0;
            }
        }
    }
    for (int m=0;m<M;++m) {
        bool chk=true;
        for (int n=0;n<N;++n) {
            if (a[n][m]>*it) {chk=false;break;}
        }
        if (chk) {
            for (int n=0;n<N;++n) {
                if (a[n][m]==*it) a[n][m]=0;
            }
        }
    }
    }
    bool chk=true;
    for (int n=0;n<N;++n) {
        for (int m=0;m<M;++m) {
            if (a[n][m]) {chk=false;break;}
        }
    }
    
    return (chk)?"YES":"NO";
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>M;
        aa.clear();
        for (int n=0;n<N;++n) {
            for (int m=0;m<M;++m) {
                int x;
                cin>>x;
                a[n][m]=x;
                aa.insert(x);
            }
        }
                
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
	return 0;
}
