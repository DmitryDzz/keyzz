#ifndef KEYZZ_APP_MANAGER_HPP_INCLUDED
#define KEYZZ_APP_MANAGER_HPP_INCLUDED

#include <memory>

#include <minunity/group_id.hpp>

// #include "player.hpp"

namespace keyzz {

class AppManager {
public:
    static const int ERR_WRONG_PARAMETERS = -1;
    static const int ERR_FILE_NOT_FOUND = -2;
    static const int ERR_CANT_OPEN_FILE = -3;
    static const int ERR_CANT_READ_FILE = -4;
    static const int ERR_FILE_IS_EMPTY = -5;
    static const int ERR_ENGINE_NOT_STARTED = -6;
    static const int ERR_WRONG_SPRITE_SIZE = -7;

    static AppManager& get_instance();
    
    void load_settings();
    void save_settings();

    class ColliderGroup {
    public:
        const minunity::group_id player = 0;
        const minunity::group_id border = 1;
        const minunity::group_id enemy = 2;
    };

    const ColliderGroup collider_group;

    class Settings {
    private:
        const int tab_code_;
        const int return_code_;
    public:
        Settings(const int tab_code, const int return_code) :
            tab_code_(tab_code), return_code_(return_code) {}
        int get_tab_code() const { return tab_code_; }
        int get_return_code() const { return return_code_; }
    };

    Settings* get_settings() { return settings_; }
//    void set_player(std::shared_ptr<Player> player);
//    std::shared_ptr<Player> get_player();
private:
//    std::shared_ptr<Player> player_ = nullptr; 
    Settings* settings_ = nullptr;
};

}

#endif // KEYZZ_APP_MANAGER_HPP_INCLUDED
