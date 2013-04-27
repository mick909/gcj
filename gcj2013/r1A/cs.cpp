#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define pb push_back

typedef long long ll;

int T;

int solve(){
    return 0;
}

ll pow(int a, int b) {
    ll s=0,k=0;
    while(b){s<<=1;s|=b&1;b>>=1;++k;}
    ll ans=1;
    while(k-->0){ans*=ans;if(s&1)ans*=a;s>>=1;}
    return ans;
}

int R,M,N,K;

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>R>>N>>M>>K;
            cout << "Case #" << t << ":"<<endl;
        for (int r=0; r<R; ++r) {
            vector<ll> KN;
            for (int i=0; i<K; ++i) {
                ll kn;
                cin >> kn;
                KN.pb(kn);
            }
            
            
            int ma=0;
            int mb=0;
            int mc=0;
            int d=0;
            
            for (int k=0; k<K; ++k) {
            int a=0;
            int b=0;
            int c=0;
                while (KN[k]%5 == 0) { KN[k]/=5; ++a; }
                while (KN[k]%3 == 0) { KN[k]/=3; ++b; }
                while (KN[k]%2 == 0) { KN[k]/=2; ++c; }
                ma = max(ma,a);
                mb = max(mb,b);
                mc = max(mc,c);
            }
            int tw = N-ma-mb;
            while (tw <= mc) {
                ++d;
                mc -= 2;
            }
            
            int cnt=0;
            for (int i=0; cnt<N && i<ma; ++i,++cnt) cout << "5";
            for (int i=0; cnt<N && i<mb; ++i,++cnt) cout << "3";
            for (int i=0; cnt<N && i<d; ++i,++cnt) cout << "4";
            for (int i=0; cnt<N && i<mc; ++i,++cnt) cout << "2";
            
            for (int i=0; cnt<N && i<(N-(ma+mb+d+mc)); ++i,++cnt) {
                cout << "2";
            }
            cout << endl;
        }
    }
    return 0;
}
