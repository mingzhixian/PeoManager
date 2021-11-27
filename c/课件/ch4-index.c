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
main()
{char s[]="abcabc123";
 char t[]="1cab";
 printf("find:%d\n",index(s,t));
}