#pragma once
#include "systemc.h"

SC_MODULE(s1_unit)
{
	sc_in<int> x_in, y_in;
	sc_out<int> sum_out, f1_out;

	void sum()
	{

		sum_out.write(17);
	}

	void F1()
	{
		sum();
		f1_out.write((x_in xor y_in) - (x_in << 1));

	}
	SC_CTOR(s1_unit)
	{
		SC_METHOD(F1);
		sensitive << x_in << y_in;
	}
};

	