#include"stdio.h"
index(char *s,char *t)
{int m,n,i,j;
 n=strlen(s);
 m=strlen(t);
 for(i=0;i<n-m+1;i++)
 {j=0;
  while(j<m)
  {if(s[i+j]!=t[j])
    break;
   j++;
  }
  if(j==m)
	  return i;

 }
 return -1;
}
bfindex(char *s,char *t)
{int m,n,i,j;
 n=strlen(s);
 m=strlen(t);
 i=0;j=0;
 while(i<n-m+1&&j<m)
 {  if(s[i]==t[j])
    i++,j++;
    else
    i=i-j+1,j=0;
 }
if(j==m)
 return i-j;
else 
return -1;
}

main()
{char s[]="abcabc123";
 char t[]="bc1";
 printf("find:%d\n",bfindex(s,t));
}