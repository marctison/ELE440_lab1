#include "resources.h"
#include <iostream>
#include <math.h>
#include "algo.h"

using namespace std;

#define NBELE 1000
#if 0
int main(void)
{
	int N[10];
	int R[4] = {100, 10000, 1000000, 100000000};
	int D[5] = {0,25,50,75,100};
	int E[10];
	int* t1;
	int n;
	int r;
	int d;
	int i;
	
	Lab1 lab1;

	for(i=1; i<=10; i++)
	{
		N[i] = (i*10) * 1000;
	}

	for(i=0; i<10; i++)
	{
		n = N[i];

		for(int j=0; j<4; j++)
		{
			r = R[i];
			
			for(int k=0; k<5; k++)
			{
				d = D[k];

				for(int m=0; m<10; m++)
				{
					t1 = generer_donnees(n, r, d);
					lab1.algo1(t1,n);
					E[m] = lab1.get_e();
				}
				sauvegarder(n,r,d,E,10,"algo.log");
			}
		}
	}
	return 0;
}


#endif

#if 1
int main(void)
{
	Lab1 lab1;
	int* t1;
	int i;


	t1 = generer_donnees(100, 100, 50);
	for(i=0; i<100; i++)
	{
		cout << t1[i] << endl;
	}
	
	cout << endl;

	lab1.algo1(t1,100);
	for(i=0; i<100; i++)
	{
		cout << t1[i] << endl;
	}

	return 0;
}
#endif
