#include "Controller.h"
#include "math.h"


Controller::Controller(Fan *fan_, Pressure *pressure_, IntegerEdit *targetSpeed_, IntegerEdit *targetPressure_, ModeEdit *state_)
    : fan(fan_), pressure(pressure_), targetSpeed(targetSpeed_), targetPressure(targetPressure_), currentMode(state_)
{
    previousMode = currentMode->getValue();
}

bool Controller::updatePeripherals()
{
    switch (currentMode->getValue()) {

        // TODO everytime this is called if we are in homescreen we should update the
        // screen
        case Mode::manual:
            if (fan->getSpeed() != targetSpeed->getValue()) {
                fan->setSpeed(targetSpeed->getValue());
            }
            break;

        case Mode::automatic:
            int16_t difference = pressureDifference();
            if (difference < 0)
                difference = -sqrt(abs(difference));
            else
                difference = sqrt(abs(difference));

            fan->setSpeed(fan->getSpeed() + difference);

            // Calculate difference
            //int16_t difference = pressureDifference();
            //// Proportional term
            //double Pout = P * difference;

            //// Integral term
            //integral += difference * 0.1;
            //double Iout = I * integral;

            //// Derivative term
            //double derivative = (difference - preDifference) / 0.2;
            //double Dout = D * derivative;

            //// Calculate total output
            //double output = Pout + Iout + Dout;

            //preDifference = difference;

            //fan->setSpeed(fan->getSpeed() + output);

            break;
    }
    return true;
}

int16_t Controller::pressureDifference()
{
    return targetPressure->getValue() - pressure->getPressure();
}
