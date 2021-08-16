#ifndef MenuOption_h
#define MenuOption_h
#include "LiquidCrystal.h"

class MenuOption{
private:
String _name;
float _value;
String _unit;
uint8_t _unitLength;


public:
MenuOption();
void init(const String& name, const String& unit, const uint8_t unitLength);
void setValue(double val);
void print(LiquidCrystal* lcd, uint8_t c1Name);
};

#endif