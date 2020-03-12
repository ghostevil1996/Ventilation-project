
/*
 * MenuItem.h
 *
 *  Created on: 1.2.2016
 *      Author: krl
 */

#ifndef HOMESCREEN_H_
#define HOMESCREEN_H_

#include "IntegerEdit.h"
#include "ModeEdit.h"
#include "LiquidCrystal.h"
#include "MenuItem.h"
#include "Pressure.h"
#include "Fan.h"
#include <string>
#include "BarGraph.h"

#define BUF_SIZE 17

class HomeScreen : public MenuItem {
public:
    HomeScreen(LiquidCrystal *lcd_, Fan *fan_, Pressure *pressure_, IntegerEdit *targetSpeed_, IntegerEdit *targetPressure_, ModeEdit *mode_);
    ~HomeScreen() { };
    void setModeTitle(const char *title)     { modeTitle = title;     }
    void setFanTitle(const char *title)    { fanTitle = title;    }
    void setPressureTitle(const char *title) { pressureTitle = title; }

    const char *getModeTitle()     { return modeTitle.c_str();     }
    const char *getFanTitle()    { return fanTitle.c_str();    }
    const char *getPressureTitle() { return pressureTitle.c_str(); }
    void display();
    void displayTitles();
    void displayMode();
    void displayFan();
    void displayPressure();
    void event(menuEvent e);

private:
    LiquidCrystal *lcd;
    Fan *fan;    // in percent
    Pressure *pressure; // in pascal
    IntegerEdit *targetSpeed;
    IntegerEdit *targetPressure;
    ModeEdit *mode;
    BarGraph barGraph;

    // Titles hold what we print in the top row
    std::string modeTitle     = "MODE";
    std::string fanTitle    = "S";
    std::string pressureTitle = "P";
};

#endif /* HOMESCREEN_H_ */
