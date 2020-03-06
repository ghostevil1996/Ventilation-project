
/*
 * MenuItem.h
 *
 *  Created on: 1.2.2016
 *      Author: krl
 */

#ifndef HOMESCREEN_H_
#define HOMESCREEN_H_

#include "MenuItem.h"
#include "IntegerEdit.h"
#include "ModeEdit.h"
#include "LiquidCrystal.h"
#include <string>

class HomeScreen : MenuItem {
public:
	HomeScreen(LiquidCrystal *lcd_, IntegerEdit *Speed_, IntegerEdit *Pressure_, ModeEdit *mode_);
	~HomeScreen() { };
    void setModeTitle(const char *title_) { modeTitle = title_; }
    void setSpeedTitle(const char *title_) { speedTitle = title_; }
    void setPressureTitle(const char *title_) { pressureTitle = title_; }

    const char *getModeTitle() { return modeTitle.c_str(); }
    const char *getSpeedTitle() { return speedTitle.c_str(); }
    const char *getPressureTitle() { return pressureTitle.c_str(); }
	bool event(menuEvent e);
    void display();

private:
    LiquidCrystal *lcd;
    IntegerEdit *speed;      // in percent
    IntegerEdit *pressure;   // in pascal
    ModeEdit *mode;

    std::string modeTitle;
    std::string speedTitle;
    std::string pressureTitle;

};

#endif /* HOMESCREEN_H_ */
