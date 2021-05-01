#ifndef MY_RUNNER_HPP_INCLUDED
#define MY_RUNNER_HPP_INCLUDED

#include <optional>
#include <memory>

#include <minunity/animation_component.hpp>
#include <minunity/animator_component.hpp>
#include <minunity/game_object.hpp>
#include <minunity/graph.hpp>
#include <minunity/sprite.hpp>

#include "base_runner.hpp"

namespace keyzz {

class MyRunner : public BaseRunner {
public:
    MyRunner(int x, int y, std::shared_ptr<Track> track_record);
    void awake() override;
    void render_layer(minunity::Layer layer) override;
    void start_lap(int lap_index, int laps_count) override;
    void move_one_step();
    void finish();
protected:
    minunity::Sprite* create_sprite() override;
private:
    std::shared_ptr<minunity::AnimationComponent> idle_animation_ = nullptr;
    std::shared_ptr<minunity::AnimationComponent> finish_animation_ = nullptr;
    std::shared_ptr<minunity::AnimatorComponent> animator_ = nullptr;
    std::optional<uint32_t> race_start_time_ = std::nullopt;
};

}

#endif // MY_RUNNER_HPP_INCLUDED
