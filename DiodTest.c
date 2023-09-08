/*
 * File:   main.c
 * Author: Ronnie
 *
 * Created on den 22 juli 2023, 13:09
 */

#include "DiodTest.h"

/*
################################################################################
###################  MAIN PROGRAM  #############################################
################################################################################   
*/

int main(void){
    float photoDiodeResult = 7;
    unitTest(photoDiodeResult);
    return 0;
}

/*
================================================================================
===================  UNIT TEST INTERRUPT SERVICE ROTINE  =======================
================================================================================ 
*/

int unitTest(float photoDiodeResult){
    
    //float photoDiodeResult;
    //int timeENA; 
    int timeENAReference = 0;
    bool optimise = false;

    int timeENAMeasure = 0;

    timeENAMeasure = (int)(0.25 * ((sqrt(photoDiodeResult + 10)) + 2 * photoDiodeResult));
    if(timeENAMeasure <= 0) timeENAMeasure = 1;
    else if(timeENAMeasure >= 110) timeENAMeasure = 110;

    if(optimise && abs(abs(timeENAReference) - abs(timeENAMeasure)) <= 2){
        timeENAReference = timeENAMeasure;
        optimise = false;
    }        
    else if((timeENAReference - timeENAMeasure) > 2){
        timeENAReference -= 2;
        optimise = true;
    }
    else if((timeENAMeasure - timeENAReference) > 2){
        timeENAReference += 2;
        optimise = true;
    }
    return timeENAMeasure;
}

