#ifndef __LAB1__
#define __LAB1__ 

class Lab1 //divide and conquer
{
	public:
		int get_e(void);
		void algo1(int* T, int N); //divide and conquer

	private:

		int e; //nb d'execution (nb de fois passe par un barometre)
		void algo2(int* T, int* G, int a, int* D, int b); //merge sort
};
#endif
