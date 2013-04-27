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

int T;

int bd[4][4];
int dt;

string solve(){
    for (int i=0; i<4; ++i) {
        int ox1=3;
        int ox2=3;
        for (int j=0; j<4; ++j) {
            ox1 &= bd[i][j]; 
            ox2 &= bd[j][i];
        }
        if ((ox1 & 1) || (ox2 & 1)) return "X won";
        if ((ox1 & 2) || (ox2 & 2)) return "O won";
    }
    int ox1=3;
    int ox2=3;
    for (int i=0; i<4; ++i) {
        ox1 &= bd[i][i];
        ox2 &= bd[i][3-i];
    }
    if ((ox1 & 1) || (ox2 & 1)) return "X won";
    if ((ox1 & 2) || (ox2 & 2)) return "O won";
    
    if (dt) return "Game has not completed";
    return "Draw";
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        dt = 0;
        for (int i=0;i<4;++i) {
            for (int j=0; j<4; ++j) {
                char ch;
                cin>>ch;
                switch(ch) {
                case '.': bd[i][j]=0;++dt;break;
                case 'T': bd[i][j]=3;break;
                case 'X': bd[i][j]=1;break;
                case 'O': bd[i][j]=2;break;
                }
            }
        }
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
	return 0;
}
