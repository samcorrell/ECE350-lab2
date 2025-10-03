#include "fir.h"
#include <cmath>

int main(){
	ap_int<8> in;
	ap_int<10> out;
	ap_int<8> shift_reg[N] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	double angle = (2.00* M_PI)/(SIZE/2);
	for(int i = 0; i<SIZE; i++){
		in = 63*std::sin(angle*(i));
		fir(in,&out, shift_reg);
		printf("output = %d\n", (int)out);
	}
	return 0;
}
