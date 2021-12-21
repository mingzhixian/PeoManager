#define Max 100
 struct edges
   {
   int bv,tv,w;
   }g[Max];
int select(int s[],int v)
 {int i=v;
   while(s[i]>0)i=s[i];
  return i;
  }
  kruskal(struct edges g[],int n,int e)
  { int s[Max],v1,v2,i,j;
  for(i=1;i<=n;i++) s[i]=0;
  i=1;
  j=1;
 while(j<n &&i<=e)
 { v1=select(s,g[i].bv);
  v2=select(s,g[i].tv);
   if(v1!=v2)
  { printf("(%d,%d)--> %d\n",g[i].bv,g[i].tv,g[i].w);
   s[v1]=v2;
   j++;
  }
  i++;
  }
  }
 main()
 {struct edges g[Max]={{0,0,0},{1,3,1},{4,6,2},{2,5,3},{3,6,4},{1,4,5},{2,3,5},{3,4,5},
  {3,5,6},{1,2,6},{5,6,6}};
  int i,n,e;
  n=6;
  e=10;

/*  for(i=1;i<=10;i++)
  scanf("%d,%d,%d",&g[i].bv,&g[i].tv,&g[i].w);*/
  kruskal(g,n,e);
  }