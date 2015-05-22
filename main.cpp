#include <iostream>
#include "winpro.h"
#include <time.h>
using namespace std;
int main()
{
	clock_t start, end;
    start = clock();
	int b[2];
	int a[5];
	/*
	cin >> b[0];
	cin >> b[1];

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	*/
	b[0]=35;
	b[1]=30;
	a[0]=10;
	a[1]=32;
	a[2]=8;
	a[3]=22;
	a[4]=2;
	cout << winpro(b, a) << endl;
   end=clock();
   cout<<"Run time: "<<(double)(end - start) / CLOCKS_PER_SEC<<"S"<<endl;
  return 0;
}
