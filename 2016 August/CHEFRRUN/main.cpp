
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define MID(a, b) (a + ((b - a) >> 1))
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999

bool taken[MAX];
bool tmp[MAX];
bool notBeautiful[MAX];
int arr[MAX];
int n;
int ans;
int cycleNode;
void markAsNotBeautiful(int s, int stop);
void anotherCycle(int s);
bool doit(int s, bool ch){
    int a,i;
    if(ch){
        a = s;
        while(true){
            if(taken[a])
                break;
            taken[a]=true;
            ans++;
            a = (a+arr[a]+1)%n;
        }
        return true;
    }
    
    //ms(tmp,false);
    forl(i,0,n){
        tmp[i] = false;
    }
    a = s;
    tmp[a]=true;
    a = (a+arr[a]+1)%n;
    while(true){
       if(a==s)
            return true;
       if(tmp[a]){
            cycleNode = a;
            anotherCycle(a);
            markAsNotBeautiful(s,a);
            return false;
       }else if(taken[a]){
           cycleNode = a;
           anotherCycle(a);
           markAsNotBeautiful(s,a);
           return false;
       }     
       tmp[a]=true;
       a = (a+arr[a]+1)%n;
    }
}

void anotherCycle(int s){
    int a;
    a = s;
    if(!taken[a])
        ans++;
    taken[a]=true;
    a = (a+arr[a]+1)%n;
    while(true){
        if(a == s)
            break;
        if(!taken[a]){
            ans++;
            taken[a]=true;
        }  
        a = (a+arr[a]+1)%n;
    }
}

void markAsNotBeautiful(int s, int stop){    
    while(s != stop){
        notBeautiful[s] = true;
        //cout << s << endl;
        s = (s+arr[s]+1)%n;
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    freopen("3.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    int t;
    
      ifstream f1 ("1.txt");
      string line1,line2;
      if (f1.is_open())
      {
        
        while ( getline (f1,line1) )
        {
            ifstream f2("2.txt");
            if(f2.is_open()){
                bool found=false;
                while(getline(f2,line2)){
                    if(line1 == line2){
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout << line1 << endl;
                }
                f2.close();
            }
        }
        f1.close();
      }
      return 0;
      
    cin >> t;
    int i,j,k;
    while(t--){
        cin >> n;
        forl(i,0,n){
            cin >> arr[i];
        }
        ans=0;
        ms(taken,false);
        ms(notBeautiful,false);
        for(i=n-1;i>=0;i--){
            if(taken[i])
                continue;
            if(notBeautiful[i])
                continue;
            bool c = doit(i,false);
            if(c){
                c = doit(i,true);
            }else{
                //anotherCycle(cycleNode);
            } 
        }
        cout << ans << endl;
    }
    return 0;
}
