// This #include statement was automatically added by the Spark IDE.
#include "HttpClient/HttpClient.h"

HttpClient http;
#define VARIABLE_ID "string"
#define TOKEN "otherString"

//Headers need to be set to init
http_header_t headers[] = {
    {"Content-Type", "application/json" },
    {"X-Auth-Token", TOKEN },
    { NULL, NULL }
};

http_request_t request;
http_response_t response;

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
    
    request.hostname = "ourUrl"; //our server url
    request.port = 80; 
    //Serial.begin(9600);

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
    minutesNow += 1;
    i++;
    j++;
    
    
    
    int x;
    if (minutesNow == 60* minute) {
        for (x = 0; x < 100; x++) {
            float totalUse += use[x];
            float totalGenerated += generated[x];
        }
        minutesNow = 0;
        
    }
   
    char [][] myArray = {
        {"solarNow", String(solarNow) }, 
        {"chargingNow", String(chargingNow) }, 
        {"totalUse", String(totalUse)}, 
        {"totalGenerated", String(totalUse}
    };
    
    //Transmitting Data:
    request.path = "/api/v1.6/variables/"VARIABLE_ID"/values";
    request.body = "{\"value\":" + String(myArray) + "}";

    http.post(request, response, headers);

    //Serial.println(response.status);

    //Serial.println(response.body);

    //delay(1000);
    
    
}

