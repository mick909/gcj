#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()

int T;
int E;
int R;
int N;
vector<int> V;

int solve(int p, int e){
    int ans = 0;
    
    if (p == N-1) {
        return V[p]*e;
    }
    
    for (int i=0; i<=e; ++i) {
        int g = V[p]*i;
        ans = std::max( ans, g + solve(p+1, std::min(E, e-i+R)) );
    }
    
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
        
        cout<<"Case #"<<t<<": "<<solve(0, E)<<endl;
    }
    return 0;
}
