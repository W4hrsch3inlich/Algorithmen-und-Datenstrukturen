int nextPrime(int a[], int len, int lp)
{
  for(int i = lp; i < len; i+=lp)
  {
    a[i] = -1;
  }
  while(a[lp] == -1)
  {
    lp += 1;
  }
  return lp;
}

int primfac(int a[], int s)
{
  int acount = 0;
  int sieb[s];
  int p = 2;
  while(s != 1)
  {
    while(s % p == 0)
    {
      s = s/p;
      a[acount] = p;
      acount++;
    }
    p = nextPrime(sieb, s, p);
  }
  return acount;
}
