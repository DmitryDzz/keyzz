#ifndef KEYZZ_TEXT_BLOCK_HPP_INCLUDED
#define KEYZZ_TEXT_BLOCK_HPP_INCLUDED

#include <string>
#include <ncurses.h>
#include <minunity/game_object.hpp>

namespace keyzz {

class TextBlock : public minunity::GameObject {
public:
    TextBlock(int x, int y, int w);
    void destroy() override;
//    void awake() override;
//    void update() override;
    void set_active(bool active) override;
    void start_lap(std::wstring lap_text, int lap_index, int laps_count);
    bool input(const int key);
    bool get_race_finished();
    bool get_lap_finished();
private:
    int x_, y_, w_;
    WINDOW* win_ = nullptr;
    std::wstring lap_text_;
    int lap_index_ = 0;
    int laps_count_ = 0;
    int position_ = 0;
    bool lap_finished_ = false;
    bool race_finished_ = false;
    void set_cursor(int position, bool show_error);
    void clear_cursor(int position);
    void clear();
};

}

#endif // KEYZZ_TEXT_BLOCK_HPP_INCLUDED

