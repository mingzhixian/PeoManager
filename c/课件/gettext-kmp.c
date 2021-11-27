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
getnext1()
{int i=1,j=0,m;
 m=strlen(s);
 next[1]=0;
 for(i=2;i<m;i++)
	{j=next[i-1];
     while(j>0)
	 if(s[i-1]==s[j])
		{next[i]=j+1;
		 break;
		}
		else
		j=next[j];
	if(j==0)next[i]=1;
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
    getnext1();
      disp(next);
    i=kmp(s1,s);
    printf("\n%s\n%s\n",s1,s);
    printf("\npos=%d\n",i+1);
    }
