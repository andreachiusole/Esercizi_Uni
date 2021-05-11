#include <stdio.h>

int abs_val( int num )
{
    if(num >= 0)
    {
        return num;
    }
    else
    {
        return -num;
    }
}

int abs_sum( int v[], int dim )
{
  int sum = 0;
  for(int i=0; i<dim; i++)
  {
    sum += abs_val(v[i]);
  }
  return sum;
}

int max_abs( int v[], int dim )
{
  int max = v[0];
  for(int i=1; i<dim; i++)
  {
    if(abs_val(v[i]) > max)
    {
        max = abs_val(v[i]);
    }
  }
  return max;
}

void divide( int v[], int dim, int res[] )
{
    for(int i=0; i<dim; i++)
    {
        if(v[2*i] == 0)
        {
            res[i] = 2;
            return;
        }
        else if(v[2*i+1] % v[2*i] == 0)
        {
            res[i] = 1;
        }
        else
        {
            res[i] = 0;
        }
    }
}


/* Programma di testing non modificare! */

int main()
{
  int    dim = 3;
  int    v[100];
  int    w[100];
  int    res;

  // legge il vettore
  /*scanf("%d",&dim);
  for ( int i = 0; i < dim; ++i ) scanf("%d",&v[i]);
  */
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  res = abs_sum( v, dim );
  printf("abs_sum: %d\n",res);

  res = max_abs( v, dim );
  printf("max_abs: %d\n",res);

  divide( v, dim, w );
  for ( int i = 0; i < dim/2; ++i )
  {
    printf("w[%d]: %d\n",i,w[i]);
  }
  
  printf("All done folks!\n");
  return 0;
}
