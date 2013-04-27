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
int KN;
int CN;

typedef pair<int, vector<int> > ch_t;
typedef vector<ch_t> chs_t;
chs_t CHS;

typedef pair<vi, map<int,int> > st_t;
typedef pair<st_t, int> sv_t;

typedef map<int, map<int,int> > us_t;
us_t used;

sv_t dfs(sv_t sv) {
    st_t st=sv.first;
    int v = sv.second;
    
    bool upd=true;
    if (used.find(v) != used.end()) {
        upd=false;
        for (map<int,int>::iterator it=st.second.begin(); it!=st.second.end(); ++it) {
            if (used[v].find((*it).first) == used[v].end()
                || used[v][(*it).first] < (*it).second) {
                upd=true;
                break;
            }
        }
    }
    if (!upd) return sv_t();
    used[v] = st.second;
    
/*
    cout << "st: [";
    for (int i=0; i<st.first.size(); ++i) cout << " " << st.first[i];
    cout <<"],[";
    for (map<int,int>::iterator it=st.second.begin(); it!=st.second.end(); ++it) cout << " (" << (*it).first << ","<< (*it).second <<")";
    cout <<"]"<<endl;
*/
    if (st.first.size() == CN) return sv;

    vector<st_t> nxs;
    
    // chests which can open
    set<int> cds;
    for (int ki=0; ki<st.second.size(); ++ki) {
        for (int ci=1; ci<=CN; ++ci) {
            // not opened
            if (v & (1<<(ci-1))) continue;
            // have key
            if (st.second.find(CHS[ci-1].first) == st.second.end()) continue;
            if (st.second[CHS[ci-1].first] == 0) continue;
            cds.insert(ci);
        }
    }
/*
    cout << "cds: [";
    for (set<int>::iterator it=cds.begin(); it!=cds.end(); ++it) cout << " " << *it;
    cout << "]"<<endl;
 */   
    // next state
    for (set<int>::iterator it=cds.begin(); it!=cds.end(); ++it) {
        st.first.pb( (*it) );
        v |= (1<<((*it)-1));

        // remove used key
        --st.second[CHS[(*it)-1].first];
/*
    cout << "nx: [";
    for (int i=0; i<od.size(); ++i) cout << " " << od[i];
    cout <<"] "<< od.size() << "<?>" << CN << endl;
*/
        // all chest is opened, complete (nk is dummy)
        if (st.first.size() == CN) return make_pair(st, v);

        // add new key
        for (int i=0; i<CHS[(*it)-1].second.size(); ++i) {
            ++st.second[CHS[(*it)-1].second[i]];
        }

        // deep first search
        sv_t res = dfs(make_pair(st,v));
        // all chest is opened, complete (nk is dummy)
        if (res.first.first.size() == CN) return res;
        
        // restore
        st.first.pop_back();
        v &= ~(1<<((*it)-1));
        ++st.second[CHS[(*it)-1].first];
        for (int i=0; i<CHS[(*it)-1].second.size(); ++i) {
            --st.second[CHS[(*it)-1].second[i]];
        }
//        cout << "Track Back"<<endl;
    }
    
    // impossible
    return sv_t();
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        map<int,int> ks;
        CHS.clear();
        used.clear();
        cin>>KN>>CN;
//        cout<<KN<<" "<<CN<<endl;
        for (int i=0; i<KN; ++i) {
            int k;
            cin>>k;
//            cout<<k<<" ";
            ks[k]++;
        }
//        cout<<endl;
        for (int i=0; i<CN; ++i) {
            int k,ikn,ik;
            cin>>k>>ikn;
//            cout<<k<<" "<<ikn<<" ";
            vi iks;
            for (int j=0; j<ikn; ++j) {
                cin>>ik;
//                cout <<ik<<" ";
                iks.pb(ik);
            }
//            cout<<endl;
            CHS.pb(make_pair(k, iks));
        }

        st_t st=make_pair(vi(), ks);
        
        sv_t res=dfs(make_pair(st,0));
        
        cout<<"Case #"<<t<<":";
        if (res.first.first.size() == CN) {
            for (int i=0; i<res.first.first.size(); ++i) {
                cout<<" "<<res.first.first[i];
            }
            cout <<endl;
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }
	return 0;
}
