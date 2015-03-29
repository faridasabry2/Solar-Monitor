// This #include statement was automatically added by the Spark IDE.
//#include "SparkTime/SparkTime.h"


//Pin connected to solar panel    
int pinSolar = A0; 
//pin monitoring power out
int pinCharging = A1;

float resistanceSolar = 100.0;
float resistanceCharging = 100.0;
float sumSolar = 0.0;
float sumCharging = 0.0;
int minutesNow = 0;
int minute = 60000;



void setup() {
  
    pinMode( pinSolar, INPUT );
    pinMode( pinCharging, INPUT );

}

void loop() {
    
    float voltageSolar = analogRead(pinSolar ); //solar power now in volts
    float solarNow = ( voltageSolar * voltageSolar ) / resistanceSolar; //solar power now in watts
    
    float voltageCharging = analogRead( pinCharging ); //charging power now in volts
    float chargingNow = ( voltageCharging * voltageCharging ) / resistanceCharging; //solar power now in watts
    
    sumSolar +=  solarNow;
    sumCharging  += chargingNow;
    
    delay( minute );
    minutesNow += minute;
    
    if (minutesNow == 24 * minutes) {
        
        
    }
    
    
    
    
        //write this to cloud 
    
    }
    
    //look at pin solar, write to file 

}
