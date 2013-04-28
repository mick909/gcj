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

#define INF (1<<31 - 1)

int TC;
int H,N,M;

int C[100][100];
int F[100][100];
int T[100][100];

typedef pair<int,int> pos_t;
typedef pair<int, pos_t> node_t;

int NF[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main(int argc, char *argv[]) {
    cin>>TC;
    for(int t=1;t<=TC;++t) {
        cin>>H>>N>>M;
        
        rep(i,0,N) {
            rep(j,0,M) {
                cin>>C[i][j];
                T[i][j] = -INF;
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                cin>>F[i][j];
            }
        }
        
        priority_queue<node_t> PQ;
        {
            deque<pos_t> Q;
            T[0][0] = H;
            Q.push_back(make_pair(0,0));
            PQ.push(make_pair(H, make_pair(0,0)));
            while (!Q.empty()) {
                pos_t p=Q.front(); Q.pop_front();
                int i=p.first;
                int j=p.second;
                rep(f,0,4) {
                    int ni=i+NF[f][0];
                    int nj=j+NF[f][1];
                    if (ni<0 || nj<0 || ni>N-1 || nj>M-1) continue;
                    if (C[i][j] < F[ni][nj]+50
                     || C[ni][nj] < std::max(H, std::max(F[i][j],F[ni][nj]))+50) continue;
                    if (T[ni][nj]==H) continue;
                    T[ni][nj] = H;
                    Q.push_back(make_pair(ni,nj));
                    PQ.push(make_pair(H, make_pair(ni,nj)));
                }
            }
        }
        
        while (!PQ.empty()) {
            node_t n = PQ.top(); PQ.pop();
            int i = n.second.first;
            int j = n.second.second;
            int h = n.first;
            if (T[i][j] > h) continue;
            rep(f,0,4) {
                int ni=i+NF[f][0];
                int nj=j+NF[f][1];
                if (ni<0||nj<0||ni>N-1||nj>M-1) continue;
                if (C[i][j] < F[ni][nj]+50) continue;
                if (C[ni][nj] < std::max(F[i][j],F[ni][nj])+50) continue;
                
                int nh=std::min(h, C[ni][nj]-50);
                int nv=nh - ((nh>=F[i][j]+20) ? 10:100);
                if (T[ni][nj]<nv) {
                    T[ni][nj]=nv;
                    PQ.push(make_pair(nv, make_pair(ni,nj)));
                }
            }
        }
        /*
        rep(i,0,N) {
        rep(j,0,M) {
            cout<<" "<<T[i][j];
        }
        cout<<endl;
        }
        */
        int a=H-T[N-1][M-1];
        cout<<"Case #"<<t<<": "<<(a/10)<<"."<<(a%10)<<endl;
    }
    return 0;
}
