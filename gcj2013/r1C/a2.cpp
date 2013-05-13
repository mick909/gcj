/*
 * A-Large解
 * 開始位置に注目してループを回し、
 * 開始位置以降で母音が連続する位置をcs,ceに求める
 * ce-cs>=Nだったら、csから先頭N文字を使った部分文字列の組み合わせ
 *   = (cs-s+1) * (L-(cs+N)+1
 * 個がすべて有効な部分文字列の数となる
 * csまでの開始位置はすべて列挙したので、次の開始位置の候補をs = cs+1とし、
 * またcsも1進める
 * csを1進めてもce-cs>=Nなら同様に加算
 *
 * ce-cs<Nになったら、もうceまでの位置にN個連続する文字列は無いのでcs=ceにして
 * 再度cs,ceを探索する（これをやらないとTLEになる）
 *
 * 文字列を最初から最後まで一度しかナメないので、O(L)
 * のはずだけど、ceのうしろをcsが追っかけていくのでO(L)じゃないかも
 * （実行時間は0.3秒程度なので問題ない）
 */
#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

string V;
int T;
string S;
int N;
int L;

int main(int argc, char *argv[]) {
    V = "aeiou";
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>S>>N;
        L=S.size();
        ll res=0;
        int cs=0;
        int ce=0;
        int s=0;
        while (s<L) {
            while (cs<L && (ce-cs)<N) {
                while (cs < L && V.find(S[cs]) != string::npos) ++cs;
                ce=cs;
                while (ce < L && V.find(S[ce]) == string::npos) ++ce;
                if (ce-cs<N) cs=ce;
            }
            if (ce-cs<N) break;
//            cout << s <<" "<<cs<<" "<<ce<<endl;
            res += (ll)(cs-s+1) * (L-(cs+N)+1);
            s = ++cs;
        }
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}
