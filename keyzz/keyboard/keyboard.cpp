// Copyright 2021 DmitryDzz

#include "keyboard.hpp"

#include <memory>

#include "../keyboard/shift_button.hpp"

#include "../app_manager.hpp"

using keyzz::Button;
using keyzz::ShiftButton;
using keyzz::Keyboard;

using minunity::GameObject;
using minunity::Scene;

Keyboard::Keyboard(Scene *scene, IKeyboardCallback *keyboard_callback)
    : GameObject(), scene_(scene), keyboard_callback_(keyboard_callback) {
    build();
}

void Keyboard::before_pressed(Button& sender, const int key_code, bool* proceed) {
    *proceed = get_active();
}

void Keyboard::after_pressed(Button& sender, const int key_code) {
    if (keyboard_callback_)
        keyboard_callback_->on_key_pressed(sender, key_code);
}

void Keyboard::build() {
    std::shared_ptr<ShiftButton> left_shift =
        std::dynamic_pointer_cast<ShiftButton>(scene_->add_game_object(new ShiftButton(3, 18, 11, L" Shift L ")));
    std::shared_ptr<ShiftButton> right_shift =
        std::dynamic_pointer_cast<ShiftButton>(scene_->add_game_object(new ShiftButton(64, 18, 13, L"  Shift R  ")));
    int x = 3;
    int y = 9;
    scene_->add_game_object(new Button(x, y, 5, L"`╱~", L" ` ", L" ~ ", '`', '~', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"1╱!", L" 1 ", L" ! ", '1', '!', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"2╱@", L" 2 ", L" @ ", '2', '@', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"3╱#", L" 3 ", L" # ", '3', '#', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"4╱$", L" 4 ", L" $ ", '4', '$', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"5╱%", L" 5 ", L" % ", '5', '%', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"6╱^", L" 6 ", L" ^ ", '6', '^', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"7╱&", L" 7 ", L" & ", '7', '&', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"8╱*", L" 8 ", L" * ", '8', '*', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"9╱(", L" 9 ", L" ( ", '9', '(', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"0╱)", L" 0 ", L" ) ", '0', ')', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"-╱_", L" - ", L" _ ", '-', '_', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"=╱+", L" = ", L" + ", '=', '+', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 9, L"  Back ", L"  Back ", L"  Back ", 0x107, 0x107, this, left_shift));
    x = 3;
    y += 3;
    scene_->add_game_object(new Button(x, y, 7, L" Tab ", L" Tab ", L" TAB ", 0x09, 0x161, this, right_shift));
    scene_->add_game_object(new Button(x+=7, y, 5, L" Q ", L" q ", L" Q ", 'q', 'Q', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" W ", L" w ", L" W ", 'w', 'W', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" E ", L" e ", L" E ", 'e', 'E', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" R ", L" r ", L" R ", 'r', 'R', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" T ", L" t ", L" T ", 't', 'T', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" Y ", L" y ", L" Y ", 'y', 'Y', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" U ", L" u ", L" U ", 'u', 'U', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" I ", L" i ", L" I ", 'i', 'I', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" O ", L" o ", L" O ", 'o', 'O', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" P ", L" p ", L" P ", 'p', 'P', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"[╱{", L" [ ", L" { ", '[', '{', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"]╱}", L" ] ", L" } ", ']', '}', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 7, L" \\╱| ", L"  \\  ", L"  |  ", '\\', '|', this, left_shift));
    x = 3;
    y += 3;
    scene_->add_game_object(new Button(x, y, 8, L" Caps ", L" Caps ", L" Caps ", std::nullopt, std::nullopt, nullptr));
    scene_->add_game_object(new Button(x+=8, y, 5, L" A ", L" a ", L" A ", 'a', 'A', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" S ", L" s ", L" S ", 's', 'S', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" D ", L" d ", L" D ", 'd', 'D', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" F ", L" f ", L" F ", 'f', 'F', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" G ", L" g ", L" G ", 'g', 'G', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" H ", L" h ", L" H ", 'h', 'H', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" J ", L" j ", L" J ", 'j', 'J', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" K ", L" k ", L" K ", 'k', 'K', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" L ", L" l ", L" L ", 'l', 'L', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L";╱:", L" ; ", L" : ", ';', ':', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"'╱\"", L" ' ", L" \" ", '\'', '"', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 11, L"  Enter  ", L"  Enter  ", L"  Enter  ", 0x0A, 0x0A, this,
                left_shift));
    x = 14;
    y += 3;
    scene_->add_game_object(new Button(x, y, 5, L" Z ", L" z ", L" Z ", 'z', 'Z', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" X ", L" x ", L" X ", 'x', 'X', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" C ", L" c ", L" C ", 'c', 'C', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" V ", L" v ", L" V ", 'v', 'V', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" B ", L" b ", L" B ", 'b', 'B', this, right_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" N ", L" n ", L" N ", 'n', 'N', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L" M ", L" m ", L" M ", 'm', 'M', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L",╱<", L" , ", L" < ", ',', '<', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L".╱>", L" . ", L" > ", '.', '>', this, left_shift));
    scene_->add_game_object(new Button(x+=5, y, 5, L"/╱?", L" / ", L" ? ", '/', '?', this, left_shift));
    x = 21;
    y += 3;
    scene_->add_game_object(new Button(x, y, 31, L"                             ", L"                             ",
                L"                             ", ' ', ' ', this));
}
