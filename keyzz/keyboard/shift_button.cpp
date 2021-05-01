// Copyright 2021 DmitryDzz

#include "shift_button.hpp"

using keyzz::ShiftButton;

ShiftButton::ShiftButton(int x, int y, int w, std::wstring text)
        : Button(x, y, w, text, text, text, std::nullopt, std::nullopt, nullptr) {
}

void ShiftButton::play_animation() {
    animator_->play(pressed_animation_->get_id());
}
