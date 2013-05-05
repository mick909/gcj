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

double PP[10001];

int main(int argc, char *argv[]) {
            // 残りの落ちてくるダイヤの数
            ll nl = 5;
            ll h = 6;
            X=6;

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

// 右端 = Px[i+1][X] = Px[i][X] + (1-Px[i][X])*0.5
// 途中 = Px[i+1][x] = Px[i][x] + (Px[i][x+1]-Px[i][x])*0.5
// Px[i][1]が0でなくなったら、Px[i+1][X]は1になる
// 以降は順次、Px[i+1][X-a]が1になっていく
            rep(j,0,d+1) PP[j]=0.0;
            PP[d] = 0.5;
            rep(i,1,min(d,nl)){
                rep(j,1,d) {
                    PP[j] = PP[j] + (PP[j+1]-PP[j])*0.5;
                }
                PP[d] = PP[d] + (1-PP[d])*0.5;
            }
            rep(i,d,nl){
                rep(j,1,d-(i-d)) {
                    PP[j] = PP[j] + (PP[j+1]-PP[j])*0.5;
                }
                rep(j,d-(i-d),d+1) {
                    PP[j] = 1.0;
                }
            }
            ans = PP[abs(X)];
        }
        cout<<"Case #"<<t<<": "<<fixed << setprecision(6)<<ans<<endl;
    }
    return 0;
}
