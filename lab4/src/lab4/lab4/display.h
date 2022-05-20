
#ifndef DISPLAY_H
#define DISPLAY_H 
#include "stage4.h"	// Added by ClassView

struct display : sc_module {
	sc_in<double> in;        // input port 1
	sc_in<bool>   clk;       // clock
	void print();            // method 
	SC_CTOR(display) {
		SC_METHOD(print);    // declare print as SC_METHOD and 
		sensitive_pos << clk;  // make it sensitive to positive clock edge
	}

public:
};
#endif
