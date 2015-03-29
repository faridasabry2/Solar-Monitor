void setup() {
    //Pin connected to solar panel    
    int pinSolar = D0; 
    //pin monitoring power out
    int pinCharging = D1;
    
    int resistanceSolar = 100;
    int resistanceCharging = 100;
    int sumSolar = 0;
    int sumCharging = 0;
    int days = 0;
    int min = 60000;
    int minutes = 0;
    bool flagloop = false;
    //flags
    pinMode(voltagePin, INPUT);

}

void loop() {
    int TimeBegining = millis(); //gets current time in milliseconds
        
    float solarNow = analogueRead( pinSolar ); //solar power in watts now
    float chargingNow = analogueRead( pinCharging ); //charging power in watts now
    float sumSolar = sumSolar +solarNow
    time = delay(1min - time)
    int TimeEnd = millis();
    if (flagloop != true) {
        changeTime = TimeEnd - TimeBegining;
    }
    else {
        changeTime = changeTime;
    }
    
    minutes = minutes + 1;
        
    if (minutes == 1440) {
        days = days + 1
    }
           
    flagloop = true;
    delay( min-changeTime );
    
    
        //write this to cloud 
    
    }
    
    //look at pin solar, write to file 

}