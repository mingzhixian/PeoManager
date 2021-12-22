#include <stdio.h>
void disp(int a[])
{
  int i;
  for (i = 0; i < 10; ++i)
    printf("%4d", a[i]);
  printf("\n\n");
}
int partition(int a[], int l, int h)
{
  int i, p, t;
  i = l + 1;
  p = h - 1;
  while (i < p)
  {
    while (a[l] >= a[i])
      i++;
    while (a[l] <= a[p])
      p--;
    if (i < p)
      t = a[i], a[i] = a[p], a[p] = t;
  }
  //if(p<i)
  t = a[l], a[l] = a[p], a[p] = t;
  printf("\n%d\n", p);
  disp(a);
  return p;
}
void quicksort(int a[], int l, int h)
{
  int p;
  if (l < h)
  {
    p = partition(a, l, h);
    quicksort(a, l, p);
    quicksort(a, p + 1, h);
  }
}
main()
{
  int a[] = {3 ,4 ,2, 89, 446, 0, -88, -3, 446, -87};
  int l, h, p;
  l = 0;
  h = 10;

  //clrscr();
  disp(a);
  quicksort(a, l, h);
  disp(a);
}