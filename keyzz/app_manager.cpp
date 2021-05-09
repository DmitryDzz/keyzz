// Copyright 2021 DmitryDzz

#include "app_manager.hpp"

using keyzz::AppManager;
// using keyzz::Player;

static AppManager* s_instance = nullptr;

AppManager& AppManager::get_instance() {
    if (!s_instance) {
        s_instance = new AppManager();
    }
    return *s_instance;
}

void AppManager::load_settings() {
    settings_ = std::shared_ptr<Settings>(new Settings(0x27A7, 0x21B2, true));
}

void AppManager::save_settings() {
}

// void AppManager::set_player(std::shared_ptr<Player> player) {
//     player_ = player;
// }
//
// std::shared_ptr<Player> AppManager::get_player() {
//     return player_;
// }
