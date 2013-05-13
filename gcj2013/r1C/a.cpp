/*
 * 提出版
 * N個連続の子音を探して、それを含む開始位置と終了位置のペアをsetに入れる
 * ややこしく考え過ぎ
 * 当然、LargeはTLEする
 */
#include <iostream>
#include <string>
#include <utility>
#include <set>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;

string VOL;
int T;
string S;
int N;
int L;
set<pii> SS;

int solve(){
    int res = 0;
    rep(i,0,L) {
        if(VOL.find(S[i]) != string::npos)continue;
        int cnt=1;
        rep(j,i+1,L) {
            if (cnt==N) break;
            if(VOL.find(S[j]) != string::npos)break;
            ++cnt;
        }
        if (cnt!=N)continue;
//        res += (i+1) * (L-(i+N)+1);
        for (int s =0 ; s<= i; ++s) {
            for (int len=i+N-s; len<=L-s; ++len) {
                SS.insert( mp(s,s+len) );
            }
        }
    }
    return SS.size();
//    return res; // SS.size();
}

int main(int argc, char *argv[]) {
    VOL="aeiou";
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>S>>N;
        L=S.size();
        SS.clear();
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
    return 0;
}
