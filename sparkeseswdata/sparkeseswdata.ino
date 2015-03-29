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

float resistanceSolar = 330.0;
float resistanceCharging = 330.0;
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

    float sensor1Read = analogRead( pinSolar );
    float voltageSolar = (5.0 / 1023.0)* sensor1Read; //solar power now in volts
    float solarNow = ( voltageSolar * voltageSolar ) / resistanceSolar; //solar power now in watts
    
    float sensor2Read = analogRead( pinCharging );
    float voltageCharging = (5.0 / 1023.0) * sensor2Read; //charging power now in volts
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
    request.hostname = "cryptic-brook-4182.herokuapp.com";
    request.port = 80;
    request.path = "/from-corey";
    
    request.hostname = "cryptic--brook--4182-herokuapp-com-jepr9wbaiu7b.runscope.net";
    request.port = 80;
    request.path = "/from-corey";
    request.body = "solarNow=" + String(solarNow) + "&chargingNow=" + String(chargingNow);

    // The library also supports sending a body with your request:
    //request.body = "{\"key\":\"value\"}";

    http.post(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);


    //delay(1000);
    
    
}


