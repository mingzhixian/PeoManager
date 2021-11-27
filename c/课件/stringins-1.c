#include"stdio.h"
len(char *s)
{char *p=s;
 while(*p)
	 p++;
 return p-s;
 }
insert(char *s,int i,char *t)
{int m,n,j;
 n=len(t);
 m=len(s);
 for(j=m-1;j>=i;j--)
	 s[j+n]=s[j];
 for(j=0;j<n-1;j++)
	 s[i+j]=t[j];

 
}
main()
{char s[100]="aslk3453dfj";
 int l;
 l=len(s);
 printf("%d\n",l);
 insert(s,5,"@#$%");
 printf("%s\n",s);
}