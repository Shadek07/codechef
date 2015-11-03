
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


#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }
int MAX;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

void reverse1(char *from, char *to ){ 
int len=strlen(from); 
int l; 
for(l=0;l<len;l++) 
 to[l]=from[len-l-1];  to[len]='\0'; 
} 

void call_sum(char *first, char *sec, char *result){ 
 char F[MAX], S[MAX], Res[MAX];  int f,s,sum,extra,now; 
f=strlen(first); 
s=strlen(sec); 
reverse1(first,F); 
reverse1(sec,S); 
 for(now=0,extra=0;(now<f && now<s);now++){    sum=(F[now]-'0') + (S[now]-'0') + extra;   Res[now]=sum%10 +'0';   extra= sum/10;  } 
for(;now<f;now++){ 
  sum=F[now] + extra-'0';   Res[now]=sum%10 +'0';   extra=sum/10;  } 
for(;now<s;now++){ 
  sum=F[now] + extra-'0';   Res[now]=sum%10 +'0';   extra=sum/10;  } 
if(extra!=0) Res[now++]=extra+'0'; 
Res[now]='\0'; 
if(strlen(Res)==0) strcpy(Res,"0"); 
reverse1(Res,result);}

/******************************************************************/ 
void call_mult(char *first,char *sec,char *result)
{ 
char F[MAX],S[MAX],temp[MAX]; 
int f_len,s_len,f,s,r,t_len,hold,res; 
f_len=strlen(first); 
s_len=strlen(sec); 
reverse1(first,F); 
reverse1(sec,S); 
t_len=f_len+s_len; 
r=-1; 
for(f=0;f<=t_len;f++) 
 temp[f]='0';  temp[f]='\0'; 
for(s=0;s<s_len;s++){ 
 hold=0;   for(f=0;f<f_len;f++){  res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0'); 
temp[f+s]=res%10+'0'; 
hold=res/10; 
if(f+s>r) r=f+s; 
 }   while(hold!=0){  res=hold+temp[f+s]-'0'; 
hold=res/10; 
temp[f+s]=res%10+'0'; 
if(r<f+s) r=f+s; 
f++; 
 }  } 
 for(;r>0 && temp[r]=='0';r--);  temp[r+1]='\0'; 
reverse1(temp,result); 
}

int char_match(char fir[2005], char sec[2005])
{
	int len1, len2;
	int i,j;
	len1 = strlen(fir);
	len2 = strlen(sec);
	sort(fir,fir+len1);
	sort(sec,sec+len2);
	int cnt=0;
	for(i = '1'; i<= '9'; i++)
	{
		int b,c;
		b = c = 0;
		forl(j,0,len1)
		{
			if(fir[j] > i)
				break;
			if(fir[j] == i)
				b++;
		}
		forl(j,0,len2)
		{
			if(sec[j] > i)
				break;
			if(sec[j] == i)
				c++;
		}
		cnt += min(b,c);
	}
	return cnt;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    char in[1002];
    int lcm;
    int b[101];
    int n;
    int i,j,k;
    cin >> t;
    getchar();
    int a;
    while(t--)
	{
	    gets(in);
	    MAX = strlen(in)+2;
	    int len = strlen(in);
	    cin >> n;
	    lcm = 1;
	    forl(i,0,n)
	    {
	    	cin >> a;
	    	lcm = lcm * (a / gcd(lcm,a));
	    }
	    getchar();
	    string st = to_string(lcm);
	    char out[2002];
	    char one[2];
	    char multip[2000];
	    multip[0] = '1';
	    multip[1] = '\0';
	    
	    one[0] = '1';
	    one[1] = '\0';
	    strcpy(out, st.c_str());
	    
	    char ans[1005];
	    int mx_match = 0;
	    /*while(strlen(out) <= len)
		{
			char res[2005];
			call_mult(out,multip,res);
			strcpy(out, res);
			
			int mt = char_match(out,in);
			if(mt > mx_match)
			{
				mx_match = max(mx_match, mt);
				strcpy(ans,out);
			}
			
			//increment multiple
			call_sum(multip, one, res);
			strcpy(multip,res);
		}*/
		
		char res[2005];
		char tos[1005];
		strcpy(tos,to_string(len-1).c_str() );
		call_mult(out,tos,res);
		strcpy(out, res);
			
		int mt = char_match(out,in);
		if(mt > mx_match)
		{
			mx_match = max(mx_match, mt);
			strcpy(ans,out);
		}
		//cout << out << endl;
		//cout << ans << endl;
		//cout << mx_match << endl;
		reverse(ans,ans+strlen(ans));
		k = strlen(ans);
		char show[1005];
		bool ch[1005];
		ms(ch,false);
		int i1;
		for(k = len-1,j=0;j < mx_match;k--,j++)
		{
			
			for(i1 = 0; i1 < len;i1++)
			{
				if(ch[i1] == false && in[i1] == ans[j])
				{
					ch[i1] = true;
					show[k] = ans[j];
					break;
				}
			}
			
		}
		
		for(;k>=0;k--)
		{
			
			for(i1 = 0; i1 < len;i1++)
			{
				if(ch[i1] == false)
				{
					ch[i1] = true;
					show[k] = in[i1];
					break;
				}
			}
			
		}
		
		show[len] = '\0';
		cout << show << endl;				
	}
    return 0;
}

