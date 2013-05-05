#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

typedef long long ll;

int T;
ll A;
int N;
int V[100];
int C[100];

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>A>>N;
        rep(i,0,N)cin>>V[i];
        sort(V,V+N);

        // A==1のときはどれも食えないので、N個全部削除が答え
        if (A==1) {
            cout<<"Case #"<<t<<": "<<N<<endl;
            continue;
        }
        int n=0;
        int tmp=0;
        // 何回、x-1を食わせればV[n]が食えるかを各nについて調べる
        // ただし、残りの数(=N-n)を超えたら、N-n削除して終了
        while(n<N){
            tmp=0;
            while(tmp<N-n && A<=V[n]){A+=A-1;++tmp;}
            A+=V[n];
            C[n]=tmp;
            ++n;
        }
        // 前方に遡って食わせた回数を加算する
        // 食わせた回数よりもN-n削除したほうが実は良かったかを判定する
        int res=C[n-1];
        n-=2;
        while(n>=0){
            res=min(N-n, res+C[n]);
            --n;
        }
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}
