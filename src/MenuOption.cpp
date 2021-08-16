#include "MenuOption.h"

#include "LiquidCrystal.h"

MenuOption::MenuOption():
_name(""),
_value(0.0),
_unit(""),
_unitLength()
{
}

void MenuOption::init(const String& name, const String& unit, const uint8_t unitLength)
{
    _name = name;
    _value=0.0;
    _unit=unit;
    _unitLength = unitLength;
}

void MenuOption::setValue(double val){
    _value = val;
}

void MenuOption::print(LiquidCrystal* lcd, uint8_t cName){
    lcd->setCursor(cName,0);
    lcd->print(_name);
    lcd->setCursor(0,1);
    lcd->print(_value,1);
    lcd->setCursor(16-_unitLength,1);
    lcd->print(_unit);
}