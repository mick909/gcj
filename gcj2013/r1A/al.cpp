#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int T;
ll R,L;

bool check(ll m) {
    double nd = 2.0L * m * m + (2.0L * R-1) * m;
    if  (nd > 2.0e18) return false;
    ll need = 2L * m * m + (2L * R-1) * m;
    if (L >= need) return true;
    return false;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin >> R >> L;
        
        ll l = 1;
        ll r = 1100000000L;
        
        while (l+1<r) {
            ll m = r - (r-l)/2L;
            if (check(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        
        cout<<"Case #"<<t<<": "<<l<<endl;
    }
    return 0;
}
