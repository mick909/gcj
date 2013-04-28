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

int F[10][10];
int C[10][10];
int W[2][10][10];
int T[10][10];

typedef pair<int,int> pos_t;

int main(int argc, char *argv[]) {
    cin>>TC;
    for(int t=1;t<=TC;++t) {
        cin>>H>>N>>M;
        
        rep(i,0,N) {
            rep(j,0,M) {
                cin>>C[i][j];
                T[i][j] = -1;
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                cin>>F[i][j];
            }
        }
        
        rep(i,0,N) {
            rep(j,0,M-1) {
                if (C[i][j] < F[i][j+1]+50
                    || C[i][j+1] < std::max(F[i][j],F[i][j+1]+50))
                {
                    W[0][i][j] = INF;
                }
                else
                if (C[i][j+1] >= H+50)
                {
                    W[0][i][j] = 0;
                }
                else
                {
                    W[0][i][j] = H-C[i][j+1]+50;
                }
            }
        }
        rep(i,0,N-1) {
            rep(j,0,M) {
                if (C[i][j] < F[i+1][j]+50
                    || C[i+1][j] < std::max(F[i][j],F[i+1][j]+50))
                {
                    W[1][i][j] = INF;
                }
                else
                if (C[i+1][j] >= H+50)
                {
                    W[1][i][j] = 0;
                }
                else
                {
                    W[1][i][j] = H-C[i+1][j]+50;
                }
            }
        }
        
        T[0][0] = 0;
        pos_t st(0,0);
        
        deque<pos_t> Q;
        Q.push_back(st);
        
        int NF[4][5] = { {-1, 0, 1, -1, 0}, {0, -1, 0, 0, -1}, {1, 0, 1, 0, 0}, {0, 1, 0, 0, 0} };

        while (!Q.empty()) {
            pos_t p = Q.front(); Q.pop_front();
            
            int a=p.first;
            int b=p.second;
            rep(i,0,4) {
                if (a+NF[i][0] < 0 || a+NF[i][0] > N-1
                 || b+NF[i][1] < 0 || b+NF[i][1] > M-1) {
                continue;
                }

                int na=a+NF[i][0];
                int nb=b+NF[i][1];
                int nw = W[NF[i][2]][a+NF[i][3]][b+NF[i][4]];
                cout << "(" << na << "," << nb <<") :"<<nw<<endl;
                if (nw == INF) {
                    continue;
                }

                if (T[a][b]==0 && nw==0)
                {
                    if (T[na][nb] < 0) {
                        T[na][nb] = 0;
                        Q.push_back(make_pair(na,nb));
                    }
                }
                else
                {
                    int n = std::max(nw, T[a][b]);
                    int m = (H-n-max(F[a][b],F[na][nb]) >= 20)?10:100;
                    if (T[na][nb]<0 || T[na][nb] > n+m) {
                        T[na][nb] = n+m;
                        Q.push_back(make_pair(na,nb));
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": "<<(T[N-1][M-1]/10)<<"."<<(T[N-1][M-1]%10)<<endl;


        rep(i,0,N) {
            cout << T[i][0];
            rep(j,1,M) {
                cout << " <" << W[0][i][j-1] << "> " << T[i][j];
            }
            cout << endl;
            if (i<N-1) {
                rep(j,0,M) {
                    cout << "<" << W[1][i][j] << ">   ";
                }
            cout << endl;
            }
        }
        cout << "----" << endl;


    }
    return 0;
}
