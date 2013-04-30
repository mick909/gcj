#include <iostream>
#include <queue>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

int T;
int N;
int C[1000];
int M[1000];
int U[1000];
int MJ[1000][10];

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N;
        rep(i,0,N)C[i]=0;
        rep(i,0,N) {
            cin>>M[i];
            rep(j,0,M[i]) {
                cin>>MJ[i][j];
                --MJ[i][j];
                C[MJ[i][j]]=1;
            }
        }
        
        bool res=false;
        
        rep(i,0,N) {
            if (C[i])continue;
            queue<int> Q;
            rep(j,0,N)U[j]=0;
            U[i]=1;
            Q.push(i);
            while (!Q.empty()) {
                int c=Q.front(); Q.pop();
                rep(j,0,M[c]) {
                    int p = MJ[c][j];
//                    cout << c << "->" << p << endl;
                    if (U[p]) {res=true; break;}
                    U[p]=1;
                    Q.push( p );
                }
            }
            if (res) break;
        }
        cout<<"Case #"<<t<<": "<< (res?"Yes":"No") <<endl;
    }
    return 0;
}
