    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    using namespace std;
     
     
    int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
        int t;
        int n;
        cin >> t;
        int i,j,k;
        char in[1005];
        while(t--){
            cin >> n;
            getchar();
            int mina = 10000;
            int minb = 10000;
            for(i=0;i<n;i++){
                gets(in);
                int len = strlen(in);
                k=0;
                for(j=0;j<len;j++){
                    if(in[j]=='a')
                        k++;
                }
                mina = min(mina, k);
                minb = min(minb,len-k);
            }
            cout << min(mina,minb) << endl;
        }
        return 0;
    }
     
