#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "numgen.h"

// definition of the `generate' method
void numgen::generate()
{
	static double a = 75.00;
	static double b = 66.00;
	a -= 1;
	b -= 2;
	out1.write(a);
	out2.write(b);

} // end of `generate' method
