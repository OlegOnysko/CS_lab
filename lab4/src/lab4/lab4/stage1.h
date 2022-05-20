#ifndef STAGE0_H
#define STAGE0_H

struct stage0 : sc_module {

	sc_in<double> in1;   //input 1
	sc_in<double> in2;   //input 2
	sc_out<double> power;  //output 1
	sc_out<double> f1; //output 2
	sc_in<bool>    clk;  //clock

	void adddif();       //method implementing functionality

						 //Counstructor
	SC_CTOR(stage0) {
		SC_METHOD(adddif);   //Declare addsub as SC_METHOD and  
		sensitive_pos << clk;  //make it sensitive to positive clock edge
	}

public:

};

#endif
