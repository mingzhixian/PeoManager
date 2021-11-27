#define N  10
#include "stdlib.h"

char *s="-abaabcac";
    int next[N]={0};
getnext()
{int i=1,j=0,m;
 m=strlen(s);
 next[1]=0;
 while (i<m-1)
 {if(j==0 || s[i]==s[j])
     {i++,j++;
     next[i]=j;
         }
  else
   j=next[j];
 }
  }
 disp(int next[])
    {int i;
     for(i=1;i<strlen(s);++i)
       printf("%3d",next[i]);
     printf("\n");
    }
kmp(char *s,char *t)
{int i,j;
 i=1,j=1;
 while(i<strlen(s) && j<strlen(t))
   if(j==0 || s[i]==t[j])
      {++i,++j;}
    else
     j=next[j];
     if(j==strlen(t))
      return i-strlen(t);
     else
      return 0;
   }


  main()
  {char *s1="-aababaabaabcac";
    int i;
   // clrscr();
    getnext();
      disp(next);
    i=kmp(s1,s);
    printf("\n%s\n%s\n",s1,s);
    printf("\npos=%d\n",i+1);
    }
