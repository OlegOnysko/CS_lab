#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage2.h"
//Definition of addsub method
void stage1::factadd()
{
	double a;
	double b;
	a = power.read();
	b = f1.read();

	r1.write((int)a + (int)b);

	r2.write(5);

} // end of addsub method
