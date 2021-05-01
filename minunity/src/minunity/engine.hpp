#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <logger/easylogging++.h>

#include <vector>

#include "collider_component.hpp"
#include "collider_groups.hpp"
#include "scene.hpp"
#include "time.hpp"

namespace minunity {

class Engine {
public:
    static Engine *get_instance();
    
    el::base::type::StoragePointer get_log_storage();

    void start();
    void run();
    void run_once();
    void stop();
    void terminate();
    Scene* get_scene();
    void set_scene(Scene *scene);
    ColliderGroups& get_collider_groups();
    Time *get_time();
private:
    bool is_started_ = false;
    bool is_running_ = false;
    Scene *scene_ = nullptr;
    ColliderGroups collider_groups_;
    Time *game_time = new Time(50);
    void run_once_impl();
};

} // namespace minunity

#endif // ENGINE_HPP_INCLUDED
