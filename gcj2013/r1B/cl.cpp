#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <fstream>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef long long ll;

static const int INF = (1<<30)-1;
int T;

string S;
int L;
map<char, vector<string> > DM;

/*
 * pos文字目(0オリジン)からstrと比較する
 * 直前までにml文字が一致している
 * 4文字以上の長さ一致していたら一致していない文字があっても良い
 * 一致しなかった文字数と、最後に一致していた長さを返す
 * 一致していない文字間に4文字以上の一致がない場合は(-1,-1)を返す
 */
pair<int,int> cmpd(int pos, int ml, const string& str) {
    int l=str.length();
    if (L-pos < l) return mp(-1,-1);

    int dif=0;
    int i=0;
    while (i<l) {
        if (S[pos] == str[i]) {++i; ++pos; ++ml; continue;}
        if (ml < 4) return mp(-1,-1);
        ++i; ++pos;
        ml=0;
        ++dif;
    }
    return mp(dif, min(4,ml));
}

/*
 * メモ
 * [pos文字目以降について][直前までに一致していた文字数(max:4)]の、
 * 異なる文字数の最小値
 * 初期値:-1
 * 条件に合うか一致がない場合はINF (2^30-1)
 */
int MD[4000][5];


/*
 * pos文字目(0オリジン)以降について、直前までにml文字が一致していたときの
 * 以降の文字列で異なる文字数の最小値を求める
 * 条件に合うか一致がない場合はINF (2^30-1)
 */
int mindif(const int pos, const int ml) {
    if (pos==L) return 0;
    if (MD[pos][ml] >= 0) return MD[pos][ml];

    int res=INF;
    for (auto it=DM.begin(); it!=DM.end(); ++it) {
        // 直前までに4文字一致していない場合は一文字目の一致が必須となる
        // これで比較すべき語数を枝狩りできる
        // ml=3,2,1,0の場合にもそれぞれ2,3,4,5文字目の一致が必須になる条件で
        // 刈れるけれどそこまではやってない
        if (ml<4 && (*it).first != S[pos]) continue;

        rep(i,0,(*it).second.size()){
            pair<int,int> c = cmpd(pos, ml, (*it).second[i]);
            if (c.first < 0) continue;
            res = min(res, c.first + mindif(pos+(*it).second[i].size(), c.second));
            if (res == 0) break;
        }
        if (res == 0) break;
    }

    return (MD[pos][ml] = res);
}

int main(int argc, char *argv[]) {
    // 辞書作成
    // 先頭文字でグループ化しておく
    ifstream ifs("garbled_email_dictionary.txt");
    string s;
    while( ifs>>s ) {
        DM[s[0]].pb(s);
    }

    cin>>T;
    for(int t=1;t<=T;++t) {
        rep(i,0,4000)rep(j,0,5) MD[i][j]=-1;
        cin>>S;
        L=S.length();

        cout<<"Case #"<<t<<": "<<mindif(0,4)<<endl;
    }
    return 0;
}
