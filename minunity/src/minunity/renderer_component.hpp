#ifndef RENDERER_COMPONENT_HPP_INCLUDED
#define RENDERER_COMPONENT_HPP_INCLUDED

#include "component.hpp"
#include "position_component.hpp"
#include "sprite.hpp"
#include <ncurses.h>

namespace minunity {

enum class Layer {
    BACKGROUND = 0,
    LEVEL,
    ENEMY,
    PROPS,
    BULLET,
    PLAYER,
    GUI,
    RESERVED
};

class RendererComponent : public Component {
public:
    void init(PositionComponent *positionComponent, Sprite *sprite, Layer layer);
    void update() override;
    void destroy() override;
    void clear();

    void set_visible(bool visible);
    bool get_visible();
    void skip_frame() { skip_frame_ = true; }

    Layer get_layer() { return layer_; }
    void set_layer(Layer layer) { layer_ = layer; }
private:
    PositionComponent *position_component_ = nullptr;
    Sprite *sprite_ = nullptr;
    WINDOW *win = nullptr;
    bool win_has_content = false;
    bool visible_ = true;
    bool visibility_modified_ = false;
    Layer layer_ = Layer::BACKGROUND;
    bool skip_frame_ = false;
};

}

#endif // RENDERER_COMPONENT_HPP_INCLUDED
