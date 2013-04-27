#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef long long ll;

int T;
ll R,L;

bool check(int128_t m) {
    int128_t need = (int128_t)2 * m * m + ((int128_t)2 * R-1) * m;
    if ((int128_t)L >= need) return true;
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
