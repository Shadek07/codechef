
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
    char in1[100002];
    while(t--)
    {
        scanf("%d",&type);
        getchar();
        gets(in);
        strcpy(in1,in);
        unsigned long long int ans=1,tmp;
        forl(i,1,63)
        {
            ans *= (unsigned long long int)2;
        }
        //vector<int>, greater<int>
        priority_queue<int, vector<int>, greater<int> > pqb, pqg;
        //cout << ans << endl;
        int b = 0;
        int g = 0;
        int st;
        n = strlen(in);
        b_ind.clear();
        g_ind.clear();
        forl(i,0,n)
        {
            if(in[i] == 'B')
            {
                b++;            
            }                
            else
            {
                 g++;
            }               
        }
        
        if(n&1)
        {
            if(!(b == g-1 || g == b-1))
            {
                cout << -1 << endl; 
                continue;              
            }
            else
            {
                tmp = 0;
                if(type == 0)
                {
                    for(i=0;i<n;i+=2)
                    {                  
                        if(b > g && in[i] == 'G')
                            tmp++;
                         else if(g>b && in[i] == 'B')
                            tmp++;
                    }
                    cout << tmp << endl;
                    continue;
                }               
                else if(type == 1)
                {
                    j =0;
                    for(i=0;i<n;i++)
                    {                  
                        if(b > g && !(i&1) && in[i] == 'B')
                            continue;
                        if(b > g && (i&1) && in[i] == 'G')
                            continue;
                        if(g>b && !(i&1) && in[i] == 'G')
                            continue;
                        if(g>b && (i&1) && in[i] == 'B')
                            continue;
                        if(in[i] == 'B')
                            b_ind.push_back(i);
                        else
                            g_ind.pb(i);
                         j++;
                    }
                    j /= 2;
                    forl(i,0,j)
                    {
                        if(type == 1)
                            tmp += abs(b_ind[i]-g_ind[i]);
                        else
                            tmp += abs(b_ind[i]-g_ind[i])*abs(b_ind[i]-g_ind[i]);
                    }
                    ans = min(ans,tmp);
                    cout << ans << endl;
                    continue;
                }
                else
                {
                    tmp = 0;
                    for(i=1;i<n;i++)
                    {
                        if(in[i] == 'B')
                        {
                            pqb.push(i);
                        }
                        else
                        {
                            pqg.push(i);
                        }
                    }
                    if(b>g)
                    {
                        forl(i,0,n)
                        {
                            if((i&1) && in[i] == 'B')
                            {
                                j = pqg.top();
                                tmp += (j-i)*(j-i);
                                in[j] = 'B';
                                pqg.pop();
                                pqb.push(j);
                                while(!pqb.empty() && pqb.top() < j)
                                    pqb.pop();
                                continue;
                            }
                            if(!(i&1) && in[i] == 'G')
                            {
                                j = pqb.top();
                                tmp += (j-i)*(j-i);
                                in[j] = 'G';
                                pqb.pop();
                                pqg.push(j);
                                while(!pqg.empty() && pqg.top() < j)
                                    pqg.pop();
                                continue;
                            }
                        }
                    }
                    else
                    {
                        forl(i,0,n)
                        {
                            if((i&1) && in[i] == 'G')
                            {
                                j = pqb.top();
                                tmp += (j-i)*(j-i);
                                in[j] = 'G';
                                pqb.pop();
                                pqg.push(j);
                                while(!pqg.empty() && pqg.top() < j)
                                    pqg.pop();
                                continue;
                            }
                            if(!(i&1) && in[i] == 'B')
                            {
                                j = pqg.top();
                                tmp += (j-i)*(j-i);
                                in[j] = 'B';
                                pqg.pop();
                                pqb.push(j);
                                while(!pqb.empty() && pqb.top() < j)
                                    pqb.pop();
                                continue;
                            }
                        }
                    }
                    ans = min(ans,tmp);
                    cout << ans << endl;
                    continue;
                }                
            }                       
        }
        else
        {
            if(b != g)
            {
                 cout << -1 << endl;
                 continue;
            }           
        }
        
        tmp = 0;
        if(type == 0)
        {
            for(i=0;i<n;i+=2)
            {
                if(in[i] == 'G')
                    tmp++;
            }
            ans = min(ans,tmp);
            tmp = 0;
            for(i=0;i<n;i+=2)
            {
                if(in[i] == 'B')
                    tmp++;
            }
            ans = min(ans,tmp);
        }
        else if(type == 1)
        {
            j = 0;
            for(i=0;i<n;i++)
            {
                if(!(i&1) && in[i] == 'B')
                    continue;
                if((i&1) && in[i] == 'G')
                    continue;
                if(in[i] == 'B')
                    b_ind.push_back(i);
                else
                    g_ind.pb(i);
                 j++;
            }
            j /= 2;
            forl(i,0,j)
            {
                if(type == 1)
                    tmp += abs(b_ind[i]-g_ind[i]);
                else
                    tmp += abs(b_ind[i]-g_ind[i])*abs(b_ind[i]-g_ind[i]);
            }
            ans = min(ans,tmp);
            tmp = 0;
            j=0;
            b_ind.clear();
            g_ind.clear();
            for(i=0;i<n;i++)
            {
                if(!(i&1) && in[i] == 'G')
                    continue;
                if((i&1) && in[i] == 'B')
                    continue;
                if(in[i] == 'B')
                    b_ind.push_back(i);
                else
                    g_ind.pb(i);
                 j++;
            }
            j /= 2;
            forl(i,0,j)
            {
                if(type == 1)
                    tmp += abs(b_ind[i]-g_ind[i]);
                else
                    tmp += abs(b_ind[i]-g_ind[i])*abs(b_ind[i]-g_ind[i]);
            }
            ans = min(ans,tmp);
        }
        else
        {
            tmp = 0;
            for(i=1;i<n;i++)
            {
                if(in[i] == 'B')
                {
                    pqb.push(i);
                }
                else
                {
                    pqg.push(i);
                }
            }
            
            forl(i,0,n)
            {
                if((i&1) && in[i] == 'B')
                {
                    j = pqg.top();
                    tmp += (j-i)*(j-i);
                    in[j] = 'B';
                    pqg.pop();
                    pqb.push(j);
                    while(!pqb.empty() && pqb.top() < j)
                        pqb.pop();
                    continue;
                }
                if(!(i&1) && in[i] == 'G')
                {
                    j = pqb.top();
                    tmp += (j-i)*(j-i);
                    in[j] = 'G';
                    pqb.pop();
                    pqg.push(j);
                    while(!pqg.empty() && pqg.top() < j)
                        pqg.pop();
                    continue;
                }
                int ch = pqb.top();
                int ch1 = pqg.top();
                while(!pqb.empty() && pqb.top() <= i && in[i] == 'B')
                    pqb.pop();
                while(!pqg.empty() && pqg.top() <= i && in[i] == 'G')
                    pqg.pop();
            }
            ans = min(ans,tmp);
            while(!pqb.empty())
                pqb.pop();
            while(!pqg.empty())
                pqg.empty();
            tmp = 0;
            strcpy(in,in1);
            for(i=1;i<n;i++)
            {
                if(in[i] == 'B')
                {
                    pqb.push(i);
                }
                else
                {
                    pqg.push(i);
                }
            }
            
            forl(i,0,n)
            {
                if((i&1) && in[i] == 'G')
                {
                    j = pqg.top();
                    tmp += (j-i)*(j-i);
                    in[j] = 'G';
                    pqg.pop();
                    pqb.push(j);
                    while(!pqb.empty() && pqb.top() < j)
                        pqb.pop();
                    continue;
                }
                if(!(i&1) && in[i] == 'B')
                {
                    j = pqb.top();
                    tmp += (j-i)*(j-i);
                    in[j] = 'B';
                    pqb.pop();
                    pqg.push(j);
                    while(!pqg.empty() &&pqg.top() < j)
                        pqg.pop();
                    continue;
                }
                int ch = pqb.top();
                int ch1 = pqg.top();
                while(!pqb.empty() && pqb.top() <= i && in[i] == 'B')
                    pqb.pop();
                while(!pqg.empty() && pqg.top() <= i && in[i] == 'G')
                    pqg.pop();
            }
            ans = min(ans,tmp);
            
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
