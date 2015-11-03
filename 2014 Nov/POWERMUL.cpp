#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include<fstream>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1001
#define LL unsigned long long
using namespace std;
 
bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];
 
 
long long int prnt[260][501];
long long int out[260];
long long int n,m;
int r;
map<pair<int,int>, int> mp;
 
void sieve ()
{
unsigned long int i,j;
 
memset (mark, true, sizeof (mark));
 
mark [0] = mark [1] = false;
 
for ( i = 4; i < N; i += 2 ) mark [i] = false;
 
for ( i = 3; i * i <= N; i += 2 ) {
if ( mark [i] ) {
for ( j = i * i; j < N; j += 2 * i ) mark [j] = false;
}
}
 
primeList.clear ();
primeList.push_back (2);
 
for ( i = 3; i < N; i += 2 )
{
if ( mark [i] ) primeList.push_back (i);
}
 
}
 
long long int square(long long int a)
{
return ((a%m)*(a%m))%m;
}
 
long long int mult(long long int b, long long int power)
{
if(power == 0)
return 1;
if(power == 1)
return b%m;
if(power%2 == 0)
return square(mult(b,power/2));
else
{
long long int tmp = mult(b,power-1);
tmp = tmp%m;
return ((b%m)*tmp)%m;
}
}
 
void doit(unsigned long n)
{
int i = 0,j,k;
unsigned long temp = n;
int sz = primeList.size();
unsigned long int pr;
unsigned long int n1 = n;
unsigned long int base;
int ch;
memset(prnt, 0, sizeof(prnt));
for(j = n; j>=(n/2); j--)
{
n1 = j;
//cout << j << endl;
if(j != n)
{
for(k = 2;k<=n;k++)
{
prnt[n-j][k] = prnt[n-j-1][k];
//if(j == 4 && k == 2)
//cout << "...." << k << " "<< prnt[n-j][k] << endl;
//if(j == 4 && k == 5)
//cout << "...." << k << " " << prnt[n-j][k] << endl;
}
}
i = 0;
while(i<sz && primeList[i]*primeList[i] <= n1)
{
pr = primeList[i];
int ch=0;
while(n1%pr == 0)
{
n1 /= pr;
ch++;
}
prnt[n-j][pr] += (ch*j);
//if(j == 4)
//cout << "###" << " " <<pr << " " << prnt[n-j][pr] << endl;
i++;
 
}
if(n1>1)//prime
{
prnt[n-j][n1] += (j);
}
//cout << j << " " << n-j << " " << prnt[n-j][n1] << endl;
n1 = n-j+1;
i = 0;
while(i<sz && primeList[i]*primeList[i] <= n1)
{
pr = primeList[i];
int ch=0;
while(n1%pr == 0)
{
n1 /= pr;
ch++;
}
prnt[n-j][pr] -= (ch*j);
i++;
 
}
if(n1>1)//prime
{
prnt[n-j][n1] -= (n-j+1);
}
//if(j == 4)
//cout << "###" << " " << 2 << " " << prnt[n-j][2] << endl;
long long int ans = 1;
for(i = 0;i<sz;i++)
{
if(prnt[n-j][primeList[i]] > 0)
{
	pair<int,int> p1;
	p1 = make_pair(primeList[i],prnt[n-j][primeList[i]]);
	long long int t1;
	if(mp[p1])
	t1 = mp[p1];
	else
	{
		t1 = mult(primeList[i],prnt[n-j][primeList[i]]);
		mp[p1] = t1;
	}
ans *= t1;
ans %= m;
//if(j == 4 && i == 2)
//cout << "ans:" << ans << endl;
//if(j == 4 && i == 5)
//cout << "ans:" << ans << endl;
}
}
out[n-j] = ans;
//cout << ans << endl;
}
}
 
int main(void)
{	
unsigned long int n,i,temp,q,a,b,n1;
sieve();
int t;
cin >> t;
int ca = 1;
//ofstream cout("2.txt");
while(t--)
{
cin >> n >> m >> q;
mp.clear();
if(n <= 500)
doit(n);
while(q--)
{
cin >> r;
if(n > 500)
{
cout << 0 << endl;
continue;
}
if(r > n-r)
{
cout << out[n-(n-r)-1] << endl;
}
else
{
cout << out[n-r-1] << endl;
}
}
 
 
}
return 0;
}
