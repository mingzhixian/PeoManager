#include <stdio.h>
#define N 5
int c[N][N] = {
    {000, 007, 100, 100, 003},
    {007, 000, 006, 002, 001},
    {100, 006, 000, 003, 010},
    {100, 002, 003, 000, 004},
    {003, 001, 010, 004, 000},
};
int f[N], d[N];
int p[N][N];
int min()
{
  int i;
  int m = 32767, k = -1;
  for (i = 0; i < N; ++i)
  {
    if (d[i] < m && f[i] == 0)
    {
      k = i, m = d[i];
    }
  }
  f[k] = 1;
  return k;
}
void change(int k)
{
  int i, j;
  for (i = 0; i < N; ++i)
    if (d[k] + c[k][i] < d[i] && f[i] == 0)
    {
      d[i] = d[k] + c[k][i];
      j = 0;
      while (p[k][j] > 0)
      {
        p[i][j] = p[k][j];
        j++;
      }
      p[i][j] = k + 1;
    }
}
void disp(int p[N], int k)
{
  int i = 0;
  while (p[i])
  {
    printf("%d   ", p[i]);
    i++;
  }
  printf("%d   ", k + 1);
}
int main(int argc, char const *argv[])
{
  int k;
  int i = 0;
  for (i = 0; i < N; ++i)
  {
    d[i] = c[0][i];
    p[i][0] = 1;
  }
  f[0] = 1;
  for (i = 1; i < N; ++i)
  {
    k = min();
    disp(p[k], k);
    printf("   dist=%d\n", d[k]);
    change(k);
  }
}