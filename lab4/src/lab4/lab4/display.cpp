#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "display.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
//Definition of print_result method 
void display::print()
{
	printf("Result = %f\n", in.read());

} // end of print method
