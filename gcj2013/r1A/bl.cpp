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
ll E;
ll R;
ll N;

vector<ll> V;

ll solve(){
    vector<ll> e(N+1,-1);
    vector<ll> w(N,-1);
    vector<ll> u(N,-1);
    e[0] = E;
    w[N-1] = 0;
    
    ll ans = 0;
    
    for (int i=0; i<N; ++i) {
        int pb;
        ll vm=0;
        for (int j=N-1; j>=0; --j) {
            if (u[j]>=0) continue;
            if (V[j] > vm) { vm = V[j]; pb=j; }
        }

//        cout << "eval: " << pb << " " << V[pb];
        
        // 使えるエネルギーが確定する
        if (e[pb] < 0) {
            int pa=pb-1;
            while (e[pa]<0) --pa;
            e[pb] = std::min((ll)E, e[pa]+(pb-pa)*R);
        }
        
//        cout << " e=" << e[pb];
        
        int pw=pb;
        while (w[pw] < 0) {
            ++pw;
        }

        // 使っていいエネルギー
        ll us = e[pb];
        if (pw < N-1) {
            us = std::max(0LL, e[pb] - std::max(0LL, w[pw]-(pw-pb)*R));
        }
        u[pb] = us;

//        cout << " u=" << u[pb];
        
        // 後ろのエネルギー(確定)と予約を設定
        ans += us * V[pb];
        e[pb+1] = std::min((ll)E, R + e[pb]-us);
        if (pb > 0) w[pb-1] = e[pb]-R;
        
//        cout << endl;
    }
//    for(int i=0; i<N; ++i) cout << " " << e[i]; cout << endl;
//    for(int i=0; i<N; ++i) cout << " " << u[i]; cout << endl;
//    for(int i=0; i<N; ++i) cout << " " << w[i]; cout << endl;
    return ans;   
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin >> E >> R >> N;
        V.clear();
        for (int i=0; i<N; ++i) {
            int v;
            cin >> v;
            V.pb(v);
        }
        
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
    return 0;
}
