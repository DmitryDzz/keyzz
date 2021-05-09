// Copyright 2021 DmitryDzz

#include "app_manager.hpp"

#include <logger/easylogging++.h>

using keyzz::AppManager;

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

void AppManager::set_color_pair_indexes(const char primary, const char secondary) {
    color_pair_indexes_ = std::shared_ptr<ColorPairIndexes>(new ColorPairIndexes(primary, secondary));
}
