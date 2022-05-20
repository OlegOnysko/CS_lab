#ifndef STAGE5_H
#define STAGE5_H
#include "systemc.h"
struct stage4 : sc_module {
	sc_in<double>  prod;     //input port 1
	sc_in<double>  quot;     //input port 2
	sc_out<double> powr;     //output port 1 
	sc_in<bool>    clk;      //clock
	void power();            //method implementing functionality
							 //Constructor
	SC_CTOR(stage4) {
		SC_METHOD(power);    //declare power as SC_METHOD and 
		sensitive_pos << clk;  //make it sensitive to positive clock edge 
	}
};
#endif 

