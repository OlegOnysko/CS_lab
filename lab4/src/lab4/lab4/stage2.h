#ifndef STAGE2_H
#define STAGE2_H

struct stage1 : sc_module {

	sc_in<double> power;   //input 1
	sc_in<double> f1;   //input 2
	sc_out<double> r1;  //output 1
	sc_out<double> r2; //output 2
	sc_in<bool>    clk;  //clock

	void factadd();       //method implementing functionality

						 //Counstructor
	SC_CTOR(stage1) {
		SC_METHOD(factadd);   //Declare addsub as SC_METHOD and  
		sensitive_pos << clk;  //make it sensitive to positive clock edge
	}

public:

};
#endif 
