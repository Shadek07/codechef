
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
map<long long int, int> mp;
bool doit(long long int n){
    long long int low = 1, high = n-1,mid;
    long long int a,b;
    bool ok=false;
    while(low <= high){
        mid = (low+high)/2;
        a = mid;
        a *= a;
        b = (mid+1);
        b *= b;
        if(a + b == n*n){
            ok = true;
            return ok;
        }
        else if(a+b > n*n){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        
       
    }
    return ok;
}
int main() {
  
  int t;
  cin >> t;
  int n;
  long long int a,b,i;
  //forl(i,1,5000000+1)
        //mp[i] = i*i;
  forl(i,1,5000001){
      mp[i*i] = 1;
  }
  while(t--){
      scanf("%d",&n);
      char ans[10] = "NO";
      double c;
      
      for(i=n-1;i>=1;i--){
          long long int d = n*n - i*i;
          double e = sqrt(d);
          e = (int)e;
          if(e*e == d){
            //ans = "YES";
            strcpy(ans,"YES");
            break;
          }
      }
      /*forl(i,1,2251){
          a = n*n - i*i;
          if(a > 0 && mp[a]){
            strcpy(ans,"YES");
            break;
          }
      }*/
      //if(doit(n))
        //ans = "YES";
      //cout << ans << endl;
      printf("%s\n",ans);
  }
 
  return 0;
}
