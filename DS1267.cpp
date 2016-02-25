//
//  DS1267.cpp
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <DS1267.h>

DS1267::DS1267(int _ICs, int _RST, int _CLK, int _DTQ, int _STK):ICs(_ICs),RST(_RST),CLK(_CLK),DTQ(_DTQ),STK(_STK){
 
 pinMode(RST,OUTPUT);
 pinMode(CLK,OUTPUT);
 pinMode(DTQ,OUTPUT );
 digitalWrite(RST,LOW);
 digitalWrite(CLK,LOW);
 digitalWrite(DTQ,LOW);
 
 for(int i=0;i<ICs*2;i++)
 POT+= char(0);
}

DS1267::DS1267(int _ICs, int _RST, int _CLK, int _DTQ):ICs(_ICs),RST(_RST),CLK(_CLK),DTQ(_DTQ){
    
    pinMode(RST,OUTPUT);
    pinMode(CLK,OUTPUT);
    pinMode(DTQ,OUTPUT );
    digitalWrite(RST,LOW);
    digitalWrite(CLK,LOW);
    digitalWrite(DTQ,LOW);
    
    for(int i=0;i<ICs*2;i++)
        POT+= char(0);
    
    STK = 0;
}

DS1267::DS1267(int _RST, int _CLK, int _DTQ):RST(_RST),CLK(_CLK),DTQ(_DTQ){
    
    pinMode(RST,OUTPUT);
    pinMode(CLK,OUTPUT);
    pinMode(DTQ,OUTPUT );
    digitalWrite(RST,LOW);
    digitalWrite(CLK,LOW);
    digitalWrite(DTQ,LOW);
    
    ICs = 1;
    for(int i=0;i<ICs*2;i++)
        POT+= char(0);
    
    STK = 0;
}

void DS1267::digitalWriteCLK(int _PIN,int _VAL){
    digitalWrite(CLK,LOW);
    digitalWrite(_PIN,_VAL);
    digitalWrite(CLK,HIGH);
}

void DS1267::WRT(){
    digitalWrite(RST,HIGH);
    for(int i=0; i<ICs; i++){
        digitalWriteCLK(DTQ,LOW);
        for(int j=0; j<2; j++){
            byte Value = byte(POT[j+i*ICs]);
            for(int k=0; k<8; k++){
                digitalWriteCLK(DTQ,bitRead(Value,8-1-k));
            }
        }
    }
    digitalWrite(RST,LOW);
}

void DS1267::SET(int _POT,int _VAL){
    POT[_POT]=char(_VAL);
}

int  DS1267::GET(int _POT){
    return POT[_POT];
}


