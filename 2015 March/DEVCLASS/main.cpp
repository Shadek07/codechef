
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

char in1[100002];
int n;
vector<int> b_ind;
vector<int> g_ind;
void start_with_b()
{
    ms(in1,'B');
    int i;
    for(i=1;i<n;i+=2)
        in1[i] = 'G';
}

void start_with_g()
{
    ms(in1,'G');
    int i;
    for(i=1;i<n;i+=2)
        in1[i] = 'B';
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,j1,k;
    int type;
    cin >> t;
    char in[100002];
    
    while(t--)
    {
        scanf("%d",&type);
        getchar();
        gets(in);
        unsigned long long int ans=1,tmp;
        forl(i,1,63)
        {
            ans *= (unsigned long long int)2;
        }
        //cout << ans << endl;
        int b = 0;
        int g = 0;
        int ind_b,ind_g;
        ind_b = ind_g = 0;
        int st;
        n = strlen(in);
        b_ind.clear();
        g_ind.clear();
        forl(i,0,n)
        {
            if(in[i] == 'B')
            {
                b++;
                b_ind.push_back(i);
            }
                
            else
            {
                 g++;
                 g_ind.pb(i);
            }
               
        }
        int szg,szb;
        szg = g_ind.size();
        szb = b_ind.size();
        if(n&1)
        {
            if(!(b == g-1 || g == b-1))
            {
                cout << -1 << endl;               
            }
            else
            {                               
                
                if(b>g)
                    start_with_b();
                else
                    start_with_g();
                tmp = 0;
                forl(i,0,n)
                {
                    if(in[i] != in1[i])
                    {
                        int sz;
                        if(in[i] == 'G')
                            sz = szg;
                         else
                            sz = szb;
                        
                        if(in[i] == 'B')
                        forl(j1,ind_b,sz)
                        {
                            j = b_ind[j1];
                            if(in1[j] == in[i] && in1[j] != in[j])
                            {
                                //tmp += pow((j-i)*1.0,type);
                                if(type == 0)
                                    tmp += 1;
                                swap(in1[i],in1[j]);
                                if(in1[j] == 'B')
                                    ind_b = j1+1;
                                else
                                    ind_g = j1+1;
                                
                                break;
                            }
                        }
                        else
                            forl(j,ind_g,sz)
                            {
                                if(in1[j] == in[i] && in1[j] != in[j])
                                {
                                    //tmp += pow((j-i)*1.0,type);
                                    if(type == 0)
                                    tmp += 1;
                                    swap(in1[i],in1[j]);
                                    if(in1[j] == 'B')
                                        ind_b = j1+1;
                                    else
                                        ind_g = j1+1;
                                    
                                    break;
                                }
                            }  
                    }
                }
                
                ans = min(ans,tmp);
                
                cout << ans << endl; 
                
            }
        }
        else
        {
            if(b != g)
            {
                 cout << -1 << endl;
            }
            else
            {
                forl(k,0,2)
                {
                    ind_b = ind_g = 1;
                    if(k == 0)
                    start_with_b();
                    else
                        start_with_g();
                    tmp = 0;
                    forl(i,0,n)
                    {
                        if(in[i] != in1[i])
                        {
                            int sz;
                        if(in[i] == 'G')
                            sz = szg;
                         else
                            sz = szb;
                        
                        if(in[i] == 'B')
                        forl(j1,ind_b,sz)
                        {
                            j = b_ind[j1];
                            if(in1[j] == in[i] && in1[j] != in[j])
                            {
                                //tmp += pow((j-i)*1.0,type);
                                if(type == 0)
                                    tmp += 1;
                                swap(in1[i],in1[j]);
                                if(in1[j] == 'B')
                                    ind_b = j1+1;
                                else
                                    ind_g = j1+1;
                                
                                break;
                            }
                        }
                        else
                            forl(j,ind_g,sz)
                            {
                                if(in1[j] == in[i] && in1[j] != in[j])
                                {
                                    //tmp += pow((j-i)*1.0,type);
                                    if(type == 0)
                                    tmp += 1;
                                    swap(in1[i],in1[j]);
                                    if(in1[j] == 'B')
                                        ind_b = j1+1;
                                    else
                                        ind_g = j1+1;
                                    
                                    break;
                                }
                            }
                        }
                    }
                    ans = min(ans,tmp);
                }
                cout << ans << endl; 
            }
        }
        
        
        
    }
    return 0;
}
