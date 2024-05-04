#ifndef TRANSISTORTEST_H
#define TRANSISTORTEST_H

#include "Arduino.h"

class TRANSISTORTEST{
public:


	TRANSISTORTEST();
	void begin(uint8_t this_tpin1, uint8_t this_tpin2, uint8_t this_tpin3, uint8_t this_tpin1_res, uint8_t this_tpin2_res, uint8_t this_tpin3_res);
	void resetallpins();
	void exit();
	void test();
	bool isNPN();
	bool isPNP();
	bool pinout(); //true CBE false EBC


	uint16_t getVF();
	uint16_t getGAIN();

private:
	int tpin1, tpin2, tpin3, tpin1_res, tpin2_res, tpin3_res;
	uint16_t t1an1,t1anR1, t1an2, t1anR2;
	bool transistor_isNPN=false;
	bool transistor_isPNP=false;
	bool pinOUT=false;

	void database();
	uint16_t Vf=0.00;
	uint16_t GAIN=0; 

};

#endif