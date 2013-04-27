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
ll A,B;

ll ans;
// map<int,vector<ll> > psum;

bool chkp(ll n) {
    ll k=0;
    ll d=1;
    while ((n/d)) {
        ++k;
        d*=10;
    }
    
    ll d1=1;
    ll d2=d/10;
    for (int i=0; i<(k/2+1); ++i) {
        if ( (n%(d1*10))/d1 != (n%(d2*10))/d2) {
            /*cout << "no"<<endl; */
            return false;
        }
        d1*=10;
        d2/=10;
    }
//    cout <<"yes"<<endl;
    return true;
}

void chka(ll b) {

    ll bb = b*b;
    ll k=0;
    ll d=1;
    while ((b/d)) {
        ++k;
        d*=10;
    }
//        cout << "pain:" << k <<"," << b << endl;
//    psum[k].push_back(b);

    if (bb>=A && bb<=B && chkp(bb)) {
//        cout << b << "," << bb << endl;
        ++ans;
    }
}

void chk(int b) {
    int bs = (b+1)/2;
    int bk = b/2;

    ll ba = 1;
    for (int i=0; i<bs; ++i) ba*=10;
    
    for (ll a=ba/10; a< ba; ++a) {
        stringstream ss;
        ss << a;
        string sa = ss.str();
        for (int i=bk-1; i>=0; --i) {
            sa += sa[i];
        }
        ll p;
        stringstream so;
        so << sa;
        so >> p;
        if (p*p > B) break;
        chka(p);
    }
}

int solve() {
    ans=0;
    for (int i=1; i<=7; ++i) chk(i);
/*
    ll sum=0;
    map<int,vector<ll> >::iterator it=psum.begin();
    for (; it!=psum.end();++it) {
        sum += (*it).second.size();
        cout << (*it).first << ":" << (*it).second.size() << ":" << sum << endl;
        for (int i=0; i<(*it).second.size() && i < 20; ++i) {
            cout << (*it).second[i] << ",";
        }
        cout << endl;
    }
*/
    return ans;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>A>>B;
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
	return 0;
}
