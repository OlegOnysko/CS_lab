#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage3.h"
//Definition of addsub method
void stage2::addsub()
{
	double a;
	double b;
	a = r1.read();
	b = r2.read();
	sum.write(a + b);
	diff.write(a - b);
} // end of addsub method
