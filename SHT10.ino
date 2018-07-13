

#include "SHT11.h"

esl::SHT11 sht11( 0 /*data*/, 2 /*clk*/ );

void setup() {
  Serial.begin( 115200 );
}

char sbuf[30];

void loop() {
  float val;
  if ( sht11.readTemperature(val) ) {
    int16_t t = (int16_t)(100*val);
    sprintf( sbuf, "%d.%02d deg.C, ", t/100, abs(t%100) );
    Serial.print( sbuf );
  } else {
    Serial.println( "Sensor Reading Failed! " );
  }
  delay(50);
  if ( sht11.readHumidity(val) ) {
    int16_t t = (int16_t)(100*val);
    sprintf( sbuf, "%d.%02d%c RH", t/100, t%100, '%' );
    Serial.println( sbuf );
  } else {
    Serial.println( "Sensor Reading Failed! " );
  }
  delay(5000);
}

/////////////////////////////////////////////////////////////////////////////////

