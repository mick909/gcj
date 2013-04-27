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
int A,B;

bool chk(int n) {
    int sn = (int)sqrt(n);
    if (sn*sn != n) return false;
    {
        stringstream ss;
         ss << n;
        string strn = ss.str();
        string strr = strn;
        reverse(strr.begin(),strr.end());
        if (strn != strr) {
            return false;
        }
    }
    {
        stringstream ss;
         ss << sn;
        string strn = ss.str();
        string strr = strn;
        reverse(strr.begin(),strr.end());
        if (strn != strr) {
            return false;
        }
    }
    return true;
}

int solve(){
    int ans=0;
    for (int i=A;i<=B;++i) {
        if (chk(i)) ++ans;
    }
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
