//
//  DS1267.h
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

#include <Arduino.h>
#ifndef _DS1267_h
#define _DS1267_h

class DS1267{
    
public:
    DS1267(int _ICs, int _RST, int _CLK, int _DTQ, int _STK);
    DS1267(int _ICs, int _RST, int _CLK, int _DTQ);
    DS1267(int _RST, int _CLK, int _DTQ);
    
    void WRT();
    void SET(int _POT,int _VAL);
    int  GET(int _POT);
    
private:
    
    int    ICs;
    int    RST;
    int    CLK;
    int    DTQ;
    int    STK;
    String POT;
    
    void digitalWriteCLK(int _PIN,int _VAL);
    
};

#endif