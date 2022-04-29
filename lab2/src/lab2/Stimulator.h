#pragma once
#include "systemc.h"

SC_MODULE(Stimulator)
{
	sc_out<int> X, Y;
	sc_in<bool> CLK;
	void Generator()
	{
		X.write(17);
		Y.write(75 + 66);
		wait();
	}

	SC_CTOR(Stimulator)
	{
		SC_THREAD(Generator);
		sensitive << CLK.pos();
	}
};
