#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage1.h"
#include <math.h>
//Definition of addsub method
void stage0::adddif()
{
	double a;
	double b;
	a = in1.read();
	b = in2.read();
	f1.write(a + b);
	power.write(((int)a + (int)b) - int(a) << 1);

}
