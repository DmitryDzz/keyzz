// Copyright 2021 DmitryDzz

#include <logger/easylogging++.h>

#include <iostream>
#include <fstream>
#include <string>

#include <minunity/collider_groups.hpp>
#include <minunity/engine.hpp>
#include <minunity/game_exception.hpp>

#include "app_manager.hpp"
#include "scenes/scene_level_1.hpp"

using keyzz::AppManager;
using keyzz::SceneLevel1;

using minunity::ColliderGroups;

const char VERSION[] = "1.0.0";

int main(int argc, char** argv) {
    std::stringstream intro;
    intro << "keyzz© v" << VERSION << " terminal game by @DmitryDzz";
    std::cout << intro.str() << std::endl;
    if (argc != 2) {
        std::cout << std::endl;
        std::cout << "Usage: ./keyzz <filename>" << std::endl;
        std::cout << "<filename>: text file" << std::endl;
        return AppManager::ERR_WRONG_PARAMETERS;
    }
    std::string filename(argv[1]);

    minunity::Engine *engine = minunity::Engine::get_instance();

    el::Helpers::setStorage(engine->get_log_storage());

    LOG(INFO) << intro.str();

    try {
        engine->start();

        AppManager& app_manager = AppManager::get_instance();
        app_manager.load_settings();

        ColliderGroups& collider_groups = engine->get_collider_groups();
        collider_groups.clear();
        const AppManager::ColliderGroup& collider_group = app_manager.collider_group;
        collider_groups.add_pair(collider_group.player, collider_group.border);
        collider_groups.add_pair(collider_group.enemy, collider_group.border);

        SceneLevel1 *sceneLevel1 = new SceneLevel1(filename);
        engine->set_scene(sceneLevel1);

        engine->run();
        engine->stop();
        delete engine;

        return 0;
    } catch (minunity::GameException &e) {
        engine->stop();
        delete engine;

        std::cerr << "ERROR: " << e.what() << std::endl;
        return e.get_code();
    }


    // setlocale(LC_ALL, "");
    // initscr();

    // if (!has_colors()) {
    //     endwin();
    //     std::cout << "Terminal doesn't support colors" << std::endl;
    //     return -1;
    // }

    // start_color();
    // init_pair(1, COLOR_CYAN, COLOR_BLACK);

    // printw("Hello ncurses!\n");

    // attron(COLOR_PAIR(1));
    // //wchar_t playerChar = L'\u2588';
    // const char* idle = "█";
    // printw(idle);
    // // printw(idle + "\n");
    // // const char* jump0 = "▄";
    // // const char* jump1 = "▀";
    // // const char* jump2 = "█";
    // // printw(jump0 + "\n");
    // // printw(jump1 + "\n");
    // // printw(jump2 + "\n");
    // // printw("%c\n", (char)219);
    // printw("\n");
    // for (int i = 0; i < 5; i++) {
    //       printw("%c %lc\n", '0' + i, L'０' + i);
    // }
    // attroff(COLOR_PAIR(1));

    // refresh();
    // getch();
    // endwin();
}
