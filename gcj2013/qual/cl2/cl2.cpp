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
#include <fstream>

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
string A,B;

ll ans;

vector<string> mps;

struct cmps {
    bool operator()(const string& l, const string& r) const {
        if (l.size() != r.size()) return (l.size() < r.size());
        return l<r;
    }
};

int solve() {
    ans=0;
    int s=0;
    struct cmps cp;
    
    while (s<mps.size() && cp(mps[s],A)) ++s;
    while (s<mps.size() && !cp(B, mps[s])) ++s,++ans;
    return ans;
}

int main(int argc, char *argv[]) {
    ifstream ifs("mp.out");
    string str;
    while (getline(ifs, str)) {
        mps.push_back(str);
    }
    
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>A>>B;
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
	return 0;
}
