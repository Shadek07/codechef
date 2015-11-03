
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
#include <fstream>
#include<ctime>
#include<iterator>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
set<string> st;
map<string,int> mp;

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    int i,j,k,K,n;
    int given[MAX];
    int dest[MAX];
    //cout << char(1+'0');
    while(t--){
        scanf("%d %d",&n,&K);
        forl(i,0,n){
            scanf("%d",&given[i]);
        }
        forl(i,0,n){
            scanf("%d",&dest[i]);
        }
        bool ok=true;
        if(K == n){
            forl(i,0,n){
                if(given[i] == dest[0]){
                    j = i;
                }
            }
            forl(i,0,n){
                k = (j+i)%n;
                if(given[k] != dest[i]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cout << dest[0] << endl;
            }
            else{
                cout << -1 << endl;
            }
        }else if(n <= 5){
            mp.clear();
            st.clear();
            queue<string> pq;
            string s = "";
            string s1,s2;
            forl(i,0,n){
                s += char(given[i]+'0');
            }
            pq.push(s);
            st.insert(s);
            mp[s] = 1;
            while(!pq.empty()){
                s = pq.front();
                pq.pop();
                forl(i,0,n-K+1){
                    s1 = s;
                    char c = s[i+K-1];
                    for(j=i+K-2;j>=i;j--){
                        s1[j+1] = s1[j];
                    }
                    s1[i] = c;
                    if(!mp[s1]){
                        st.insert(s1);
                        pq.push(s1);
                        mp[s1] = 1;
                    }
                }
            }
            s = "";
            forl(i,0,n){
                s += char(dest[i]+'0');
            }
            set<string>::iterator it = st.find(s);
            
            if(it != st.end()){
                cout << distance(st.begin(),it) + 1<< endl;
            }
            else{
                cout << -1 << endl;
            }
            //for(it = st.begin();it != st.end();it++){
                //cout << *it << endl;
            //}
            
        }
         else{
            cout << -1 << endl;
        }
        
    }
    return 0;
}
