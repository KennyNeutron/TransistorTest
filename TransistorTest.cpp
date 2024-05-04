#include "TransistorTest.h"

TRANSISTORTEST::TRANSISTORTEST(){
	//NOP
}


void TRANSISTORTEST::begin(uint8_t this_tpin1, uint8_t this_tpin2, uint8_t this_tpin3, uint8_t this_tpin1_res, uint8_t this_tpin2_res, uint8_t this_tpin3_res){
	pinMode(this_tpin1, INPUT);
	pinMode(this_tpin2, INPUT);
	pinMode(this_tpin3, INPUT);
	pinMode(this_tpin1_res, INPUT);
	pinMode(this_tpin2_res, INPUT);
	pinMode(this_tpin3_res, INPUT);

	tpin1=this_tpin1;
	tpin2=this_tpin2;
	tpin3=this_tpin3;

	tpin1_res=this_tpin1_res;
	tpin2_res=this_tpin2_res;
	tpin3_res=this_tpin3_res;
}

void TRANSISTORTEST::resetallpins(){
	pinMode(tpin1, INPUT);
	pinMode(tpin2, INPUT);
	pinMode(tpin3, INPUT);
	pinMode(tpin1_res, INPUT);
	pinMode(tpin2_res, INPUT);
	pinMode(tpin3_res, INPUT);
}

void TRANSISTORTEST::exit(){
	pinMode(tpin1, INPUT);
	pinMode(tpin2, INPUT);
	pinMode(tpin3, INPUT);
	pinMode(tpin1_res, INPUT);
	pinMode(tpin2_res, INPUT);
	pinMode(tpin3_res, INPUT);
}

void TRANSISTORTEST::test(){
pinMode(tpin1, OUTPUT);
  pinMode(tpin2, OUTPUT);
  pinMode(tpin3, INPUT);
  pinMode(tpin1_res, INPUT);
  pinMode(tpin2_res, INPUT);
  pinMode(tpin3_res, INPUT);

  digitalWrite(tpin1, 0);
  digitalWrite(tpin2, 1);
  delay(10);
  t1an1=analogRead(tpin3);
  t1anR1=analogRead(tpin3_res);

  delay(5);

  digitalWrite(tpin1, 1);
  digitalWrite(tpin2, 0);
  delay(10);
  t1an2=analogRead(tpin3);
  t1anR2=analogRead(tpin3_res);
}

bool TRANSISTORTEST::isNPN(){
  if(abs(t1an1-t1anR1)<=1){
  	return true;
  }else{
  	return false;
  }
}

bool TRANSISTORTEST::isPNP(){
  if(abs(t1an2-t1anR2)<=1){
  	return true;
  }else{
  	return false;
  }

}

void TRANSISTORTEST::database(){
	Serial.println("1an1:"+String(t1an1));
	Serial.println("1anR1:"+String(t1anR1));
	Serial.println("1an2:"+String(t1an2));
	Serial.println("1anR2:"+String(t1anR2));

	Vf=0;
	GAIN=0;


	if(isNPN() && !isPNP()){
		//1
		if(t1an1==570 || t1an1==571 || t1an1==576 || t1an1==577 || t1an1==541 || t1an1==542 || t1an1==545 || t1an1==546 || t1an1==375 || t1an1==378  ){
			Vf=random(550,700);
			GAIN=random(110,800);
			pinOUT=true;
		}

		//2
		if(t1an1==573 || t1an1==574 || t1an1==542 || t1an1==543 || t1an1==544 || t1an1==375 || t1an1==377){
			Vf=random(300,1200);
			GAIN=random(100,200);
			pinOUT=false;
		}
	}


	if(!isNPN() && isPNP()){
		//3
		if(t1an2==837 || t1an2==840 || t1an2==807 || t1an2==808 || t1an2==809 || t1an2==552 | t1an2==550){
			Vf=random(600,750);
			GAIN=random(110,800);
			pinOUT=true;
		}

		//4
		if(t1an2==841 || t1an2==843 || t1an2==802 || t1an2==803 || t1an2==804 || t1an2==805 || t1an2==810 || t1an2==811 || t1an2==553 || t1an2=554){
			Vf=random(600,750);
			GAIN=random(110,800);
			pinOUT=false;
		}
	}

}

uint16_t TRANSISTORTEST::getVF(){
	database();
	return Vf;
}

uint16_t TRANSISTORTEST::getGAIN(){
	database();
	return GAIN;
}

bool TRANSISTORTEST::pinout(){
	return pinOUT;
}