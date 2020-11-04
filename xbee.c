
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char MOTORS                   = 0b00000000;
const char MODE                     = 0b11000000;
const char P_GAIN                   = 0b00100000;
const char I_GAIN                   = 0b01000000;
const char D_GAIN                   = 0b01100000;
const char IR_SAMPLES_PER_ESTIMATE  = 0b10000000;
const char IR_SAMPLE_RATE           = 0b10100000;
const char DISPLAY_MODE             = 0b11100000;
const char X_JOYSTICK               = 0b01000000;
const char Y_JOYSTICK               = 0b10000000;

char MotorVal                   = 0;
char ModeVal                    = 0;
char PGainVal                   = 0;
char IGainVal                   = 0;
char DGainVal                   = 0;
char IRSamplesPerEstimateVal    = 0;
char IRSampleRateVal            = 0;
char DispModeVal                = 0;
char XJoystickVal               = 0;
char YJoystickVal               = 0;

int main(void)
{
    char value;
    char sym;
    char dataTrasmitted;


    // TRANSMIT SIDE
    char motorOn    = 0;
    value           = 7;
    sym             = D_GAIN;
    dataTrasmitted  = sym | value;


    // WRITEUSART
    printf("x = %d, sym = %d, dataTrasmitted= %d\n",value,sym,dataTrasmitted);

    // RECEIVE SIDE

    // READUSART

    if(motorOn)
    {
        // isolate symbol from 2 MSB
        sym     = dataTrasmitted & 0b11000000;

        // isolate value from 6 LSB
        value   = dataTrasmitted & 0b00111111;

        printf("value = %d, sym = %d, dataTrasmitted = %d\n",value,sym,dataTrasmitted);

        switch(sym)
        {
            case MOTORS:
                // Motors on or off
                MotorVal = value;
                printf("Motor Val = %d\n", MotorVal);
                break;

            case MODE:
                // Set mode
                ModeVal = value;
                printf("Mode Val = %d\n", ModeVal);
                break;

            case X_JOYSTICK:
                // set x joystick
                XJoystickVal = value;
                printf("X Joystick Val = %d\n", XJoystickVal);
                break;

            case Y_JOYSTICK:
                // set y joystick
                YJoystickVal = value;
                printf("Y Joystick Val = %d\n", YJoystickVal);
                break;

            default:
                // Not sure
                break;
        }

    }
    else
    {
        // isolate symbol from 3 MSB
        sym     = dataTrasmitted& 0b11100000;

        // isolate value from 5 LSB
        value   = dataTrasmitted& 0b00011111;

        printf("value = %d, sym = %d, dataTrasmitted = %d\n",value,sym,dataTrasmitted);

        switch(sym)
        {
            case MOTORS:
                // Motors on or off
                MotorVal = value;
                printf("Motor Val = %d\n", MotorVal);
                break;

            case MODE:
                // Set mode
                ModeVal = value;
                printf("Mode Val = %d\n", ModeVal);
                break;

            case P_GAIN:
                // set P gain
                PGainVal = value;
                printf("P Gain Val = %d\n", PGainVal);
                break;

            case I_GAIN:
                // set I gain
                IGainVal = value;
                printf("I Gain Val = %d\n", IGainVal);
                break;

            case D_GAIN:
                // set D gai
                DGainVal = value;
                printf("D Gain Val = %d\n", DGainVal);
                break;

            case IR_SAMPLES_PER_ESTIMATE:
                // set IR samples per estimate
                IRSamplesPerEstimateVal  = value;
                printf("IRSampPerEstimate Val = %d\n", IRSamplesPerEstimateVal);
                break;

            case IR_SAMPLE_RATE:
                // set IT sample rate
                IRSampleRateVal  = value;
                printf("IRSampleRate Val = %d\n", IRSampleRateVal);
                break;

            case DISPLAY_MODE:
                DispModeVal = value;
                printf("Display Mode Val = %d\n", DispModeVal);
                break;

            default:
                // Not sure
                break;
        }

    }

    return 0;
}