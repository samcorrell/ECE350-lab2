#include "fir.h"

void fir(ap_int<8> in, ap_int<10>* out, ap_int<8> shift_reg[N]){
#pragma HLS PIPELINE
	//taps can be smaller than int size
	ap_int<8> taps[N] = {1, 2, 0, -3, 0, 4, -5, 0, 1, -2, 0, -3, 0, 4, -5, 0};
#pragma HLS ARRAY_PARTITION dim=1 type=complete variable=taps
#pragma HLS ARRAY_PARTITION dim=1 type=complete variable=shift_reg
 //shift reg starts with all 0's
	ap_int<10> acc = 0;
		acc = 0;
		SHIFT_LOOP:
		for(int j = N - 1; j>0; j--){
#pragma HLS UNROLL factor=16
			shift_reg[j] = shift_reg[j-1];
		}
		shift_reg[0] = in;

		ACC_LOOP:
		for(int j = N - 1; j>=0; j--){
#pragma HLS UNROLL factor=16
			acc+=shift_reg[j]*taps[j];
		}

		*out = acc;
}
