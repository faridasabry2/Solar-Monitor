// This #include statement was automatically added by the Spark IDE.
#include "HttpClient/HttpClient.h"
HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    //  { "Content-Type", "application/json" },
    //  { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
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
int minute = 60000;



void setup() {
    Serial.begin(9600);
  
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
    i++;
    j++;
    
    
    
  
        

   
   // char dataArray[]= {solarNow, chargingNow, totalUse, totalGenerated
    //};
    
    
    Serial.println();
    Serial.println("Application>\tStart of Loop.");
    // Request path and body can be set at runtime or at setup.
    request.hostname = "localhost";
    request.port = 5000;
    request.path = "/to-app";
    
    request.hostname = "requestb.in";
    request.port = 80;
    request.path = "/pvnn45pv";
    
    request.body = "solarNow=" + String(solarNow) + "&chargingNow=" + String(chargingNow);

    // The library also supports sending a body with your request:
    //request.body = "{\"key\":\"value\"}";

    // Get request
    http.get(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);


    //delay(1000);
    
    
}

