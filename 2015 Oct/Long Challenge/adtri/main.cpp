    #include<stdio.h>
    #include<math.h>
    int a[5100001]={},i,j,k;
    int main()
    {
        for(i=1;i<=2237;i++)
        {
            for(j=i+1;j<=2237;j++)
            {
                for(k=1;k*(i*i+j*j)<=5000000;k++)
                {
                    a[k*(i*i+j*j)]=1;
                }
            }
        }
        int T;
        scanf("%d",&T);
        while(T--)
        {
            int S;
            scanf("%d",&S);
            if(a[S]) printf("YES\n");
            else printf("NO\n");
        }
        return 0;
    } 
