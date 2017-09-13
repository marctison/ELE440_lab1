#include "algo.h"



int Lab1::get_e(void)
{
	return this->e;
}

void Lab1::algo1(int* T, int N)
{
	int m;
	int* G;
	int* D;
	int i;

	if(N >= 2)
	{
		m = N/2;
		G = new int[m];
		D = new int[N-m];

		for(i=0; i<m; i++)
		{
			G[i] = T[i];
		}

		for(i=0; i<(N-m); i++)
		{
			D[i] = T[m+i];
		}

		this->algo1(G, m);
		this->algo1(D, N-m);
		this->algo2(T, G, m, D, N-m);

		delete [] G;
		delete [] D;
	}

}


void Lab1::algo2(int* T, int* G, int lengthG, int* D, int lengthD)
{
	int i=0;
	int j=0;
	int k=0;

	while ((i < lengthG) && (j < lengthD))
	{
		if(G[i] < D[j])
		{
			T[k] = G[i];
			i++;
		}
		else
		{
			T[k] = D[j];
			j++;
		}
		k++;
	}

	while(i < lengthG)
	{
		T[k] = G[i];
		i++;
		k++;
	}

	while (j < lengthD)
	{
		T[k] = D[j];
		j++;
		k++;
	}
}
