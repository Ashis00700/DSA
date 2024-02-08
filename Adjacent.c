#include<stdio.h>
#include<string.h>

int main()
{
	int t,c,i,l;
	char a[80];
    printf("Test value:\n");
	scanf("%d",&t);
	while(t>0)
	{
	    printf("Enter");
        getchar();
		fgets(a,sizeof(a),stdin);
		l=strlen(a);
		for(i=0;i<l-1;++i)
		{
			if((a[i]==0)&&(a[i+1]==0)) c++;
		}
		if(c==0) printf("No\n");
		else
        {
            printf("Yes\n");
            c=0;
        }
		--t;
	}
	return 0;
}