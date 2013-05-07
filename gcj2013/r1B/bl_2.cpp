#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

typedef long long ll;

int T;
ll N;
int X,Y;

// doubleの精度だけどあとで2で割りまくるので大丈夫（？）
double cmb(int n, int r) {
    double ans=1;
    for(int i=0;i<r;++i)ans=(ans*(n-i))/(i+1);
    return ans;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>X>>Y;

        double ans=0.0;

        ll d=abs(X)+abs(Y);

        // 足りないので必ず0
        if (N <= (d*(d-1))/2) ans=0.0;

        // 充分にダイヤがあるので必ず1
        else if(N >= ((d+1)*(d+2))/2) ans=1.0;

        // 最外周の辺の場合は確率を計算
        else {
            // 残りの落ちてくるダイヤの数
            ll nl = N-(d*(d-1))/2;
            ll h = d/2+1;

            // 片側があふれた結果Yの位置まで必ず埋まるパターン
            if (nl-d > Y) ans = 1.0;

            // ここまで来た場合、中央には絶対に残らない
            else if (X == 0) ans = 0.0;

            // 片側にY以上貯まる場合の数の総数を振り分け方の総数で割る！
            else {
                ans=0;
                // Y+1〜nlまで、C(nl,k)を加算する
                // 整数で加算すると桁あふれするのでdoubleで
                for (ll k=Y+1; k<=nl; ++k) ans+=cmb(nl,k);
                // 総数 = 2^nlで割る
                for (ll k=0; k<nl; ++k) ans/=2;
            }
        }
        cout<<"Case #"<<t<<": "<<fixed << setprecision(6)<<ans<<endl;
    }
    return 0;
}
