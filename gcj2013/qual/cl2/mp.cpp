#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// from www.programming-magic.com/20090123132035/
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
  BidirectionalIterator last1 ,
  BidirectionalIterator first2 ,
  BidirectionalIterator last2 )
{
  if (( first1 == last1 ) || ( first2 == last2 )) {
    return false ;
  }
  BidirectionalIterator m1 = last1 ;
  BidirectionalIterator m2 = last2 ; --m2;
  while (--m1 != first1 && !(* m1 < *m2 )){
  }
  bool result = (m1 == first1 ) && !(* first1 < *m2 );
  if (! result ) {
    while ( first2 != m2 && !(* m1 < * first2 )) {
      ++ first2 ;
    }
    first1 = m1;
    std :: iter_swap (first1 , first2 );
    ++ first1 ;
    ++ first2 ;
  }
  if (( first1 != last1 ) && ( first2 != last2 )) {
    m1 = last1 ; m2 = first2 ;
    while (( m1 != first1 ) && (m2 != last2 )) {
      std :: iter_swap (--m1 , m2 );
      ++ m2;
    }
    std :: reverse (first1 , m1 );
    std :: reverse (first1 , last1 );
    std :: reverse (m2 , last2 );
    std :: reverse (first2 , last2 );
  }
  return ! result ;
}
 
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
  BidirectionalIterator middle ,
  BidirectionalIterator last )
{
  return next_combination (first , middle , middle , last );
}

// 1 0*n  0*n 1
// 2 0*n  0*n) 2
//
// 1 [num(1)=1,2,3] [num(1)=1,2,3] 1
void n4p3(int n, vector<string>& ps) {
    string zs(n*2, '0');
    ps.push_back("1"+zs+"1");
    ps.push_back("2"+zs+"2");

    for (int r=1; r<=min(3,n); ++r) {
        vector<int> cmb;
        for (int j=0; j<n; ++j) cmb.push_back(j);
        do {
            string pat1(n,'0');
            string pat2(n,'0');
            for (int j=0; j<r; ++j) {
                pat1[cmb[j]] = '1';
                pat2[n-1-cmb[j]] = '1';
            }
            ps.push_back("1"+pat1+pat2+"1");
        } while (next_combination(cmb.begin(), cmb.begin()+r, cmb.end()));
    }
}

// 1 0*(n-1) 0 0*(n-1) 1
// 1 0*(n-1) 1 0*(n-1) 1
// 1 0*(n-1) 2 0*(n-1) 1
//
// 2 0*(n-1) 0 0*(n-1) 2
// 2 0*(n-1) 1 0*(n-1) 2
//
// 1 [num(1)=1,2,3] [0,1] [num(1)=1,2,3] 1
//
// 1 [num(1)=1] 2 [num(1)=1] 1
void n4p1(int n, vector<string>& ps) {
    string zs(n-1, '0');
    ps.push_back("1"+zs+"0"+zs+"1");
    ps.push_back("1"+zs+"1"+zs+"1");
    ps.push_back("1"+zs+"2"+zs+"1");
    ps.push_back("2"+zs+"0"+zs+"2");
    ps.push_back("2"+zs+"1"+zs+"2");
    
    for (int r=1; r<=min(3, n-1); ++r) {
        vector<int> cmb;
        for (int j=0; j<n-1; ++j) cmb.push_back(j);
        do {
            string pat1(n-1,'0');
            string pat2(n-1,'0');
            for (int j=0; j<r; ++j) {
                pat1[cmb[j]] = '1';
                pat2[n-2-cmb[j]] = '1';
            }
            ps.push_back("1"+pat1+"0"+pat2+"1");
            ps.push_back("1"+pat1+"1"+pat2+"1");
        } while (next_combination(cmb.begin(), cmb.begin()+r, cmb.end()));
    }

    {
        for (int i=0; i<n-1; ++i) {
            string pat1(n-1,'0');
            string pat2(n-1,'0');
            pat1[i] = '1';
            pat2[n-1-i-1] = '1';
            ps.push_back("1"+pat1+"2"+pat2+"1");
        }
    }
}

struct cmps {
    bool operator()(const string& l, const string& r) const {
        if (l.size() != r.size()) return (l.size() < r.size());
        return l<r;
    }
};

int main(int argc, char *argv[]) {
    vector<string> ps;

// Create candidates of fair and square numbers before execute solver :-p

    ps.push_back("1");
    ps.push_back("2");
    ps.push_back("3");
    ps.push_back("11");
    ps.push_back("22");
    ps.push_back("101");
    ps.push_back("111");
    ps.push_back("121");
    ps.push_back("202");
    ps.push_back("212");
    
    for (int n=2; n<25; ++n) {
        n4p1(n, ps);
    }

    for (int n=1; n<25; ++n) {
        n4p3(n,ps);
    }

    sort(ps.begin(), ps.end(), cmps());
    
    cout << ps.size() << endl;
    for (int j=0; j<ps.size(); ++j) {
        cout << ps[j] << endl;
    }
    return 0;
}