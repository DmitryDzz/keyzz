#ifndef KEYZZ_SHIFT_BUTTON_HPP_INCLUDED
#define KEYZZ_SHIFT_BUTTON_HPP_INCLUDED

#include "button.hpp"

namespace keyzz {

class ShiftButton : public Button {
public:
    ShiftButton(int x, int y, int w, std::wstring text);
    void play_animation();
};

}

#endif // KEYZZ_SHIFT_BUTTON_HPP_INCLUDED
