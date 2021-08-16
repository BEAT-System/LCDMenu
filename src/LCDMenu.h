#ifndef LCDMenu_h
#define LCDMenu_h
#include "MenuOption.h"
#include <Arduino.h>

template<int SIZE>
class LCDMenu{
private:
    MenuOption _menuOptions[SIZE];
    uint8_t _menuId;
    bool _circleSelect;
    LiquidCrystal* _lcd;  

public:
    LCDMenu(LiquidCrystal* lcd, bool circleSelect=true):
    _menuId(0),
    _circleSelect(circleSelect)
    {
        _lcd=lcd;
    }

    MenuOption& getMenuEntry(int index)
    {return _menuOptions[index];}

    void goLeft(){
        --_menuId;
        if(_menuId < 0){
            if (_circleSelect)
            {
               _menuId = SIZE -1;
               print();
            }
            else{
                _menuId = 0;
            }
        }else{
            print();
        }
    }

    void goRight(){
        ++_menuId;
        if(_menuId >  SIZE-1){
            if (_circleSelect)
            {
               _menuId = 0;
               print();
            }
            else{
                _menuId = SIZE-1;
            }
        }else{
            print();
        }
    }

    void setValue(double val){
        _menuOptions[_menuId].setValue(val);
        print();
    }

    void print(){
        _lcd->clear();
        delay(100);
        _lcd->setCursor(0,0);
        _lcd->print("<");
        _lcd->setCursor(15,0);
        _lcd->print(">");
        if (!_circleSelect)
        {
            if (_menuId == 0)
            {
                _lcd->clear();
                _lcd->setCursor(15,0);
                _lcd->print(">");
            }

            if (_menuId == SIZE-1)
            {
                _lcd->clear();
                _lcd->setCursor(0,0);
                _lcd->print("<");
            }

        }
        _menuOptions[_menuId].print(_lcd, 2);
    }
};

#endif