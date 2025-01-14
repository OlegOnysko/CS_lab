﻿#include "systemc.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "display.h"
#include "numgen.h"
#define NS * 1e-9
int sc_main(int ac, char* av[])
{
	//Signals
	sc_signal<double> in1;
	sc_signal<double> in2;
	sc_signal<double> power;
	sc_signal<double> f1;
	sc_signal<double> r1;
	sc_signal<double> r2;
	sc_signal<double> sum;
	sc_signal<double> diff;
	sc_signal<double> prod;
	sc_signal<double> quot;
	sc_signal<double> powr;
	sc_signal<bool> clk;
	//Clock
	//<TRACE>
	//</TRACE>
	numgen N("numgen");               //instance of `numgen' module
	N(in1, in2, clk);                //Positional port binding
	stage0 S0("stage0");              //instance of `stage1' module
	//Named port binding
	S0.in1(in1);
	S0.in2(in2);
	S0.power(power);
	S0.f1(f1);
	S0.clk(clk);

	sc_trace_file* wf = sc_create_vcd_trace_file("signals");
	wf->set_time_unit(1, SC_NS);
	sc_trace(wf, clk, "CLK");
	sc_trace(wf, prod, "Prod");


	stage1 S1("stage1");              //instance of `stage2' module
	S1(power, f1, r1, r2, clk);
	stage2 S2("stage2");              //instance of `stage2' module
	S2(r1, r2, sum, diff, clk);
	stage3 S3("stage3");              //instance of `stage2' module
	S3(sum, diff, prod, quot, clk);  //Positional port binding
	stage4 S4("stage4");              //instance of `stage3' module
	S4(prod, quot, powr, clk);       //Positional port binding
	display D("display");            //instance of `display' module
	D(powr, clk);                       //Positional port binding
	//<TRACE>

	//</TRACE>
	//<TRACE>
	sc_start(0, SC_NS);
	for (int i = 0; i < 50; i++)
	{
		clk.write(0);
		sc_start(10, SC_NS);
		clk.write(1);
		sc_start(10, SC_NS);
	}
	sc_close_vcd_trace_file(wf);
	//</TRACE>
	return 0;
}
