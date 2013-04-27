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

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin >> R >> L;
        ll ans = 0;
        do {
            ll need = 2*R+1;
            if (L < need) break;
            ++ans;
            L -= need;
            R += 2;
        } while (1);
        
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
