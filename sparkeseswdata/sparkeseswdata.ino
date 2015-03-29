   

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
int use[100] = {0}, generated[100] = {0}, i=0, j = 0;

void loop() {
    
    float voltageSolar = analogRead( pinSolar ); //solar power now in volts
    float solarNow = ( voltageSolar * voltageSolar ) / resistanceSolar; //solar power now in watts
    
    float voltageCharging = analogRead( pinCharging ); //charging power now in volts
    float chargingNow = ( voltageCharging * voltageCharging ) / resistanceCharging; //solar power now in watts
    
    use[i] = solarNow;
    generated[j] = chargingNow;
    
    
    sumSolar +=  solarNow;
    sumCharging  += chargingNow;
    
    delay( minute );
    minutesNow += minute;
    i++;
    j++;
    
    
    
    if (minutesNow == 60* minutes) {
        for (x = 0, x < 100, x++) {
            float totalUse += use[x];
            float totalGenerated += generated[x];
        }
        minutesNow = 0;
        
    }
    
    
    
    
        //write this to cloud 
    
    }
    
    //look at pin solar, write to file 

}
