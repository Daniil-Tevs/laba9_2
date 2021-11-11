#include <SFML/Graphics.hpp>
struct RectangleShape
{
    sf::Vector2<float> a;
    float x{};
    float y{};
    float s{};
    sf::Color c;
    float x0{};
    float y0{};
};
void PullShape(sf::RectangleShape &shape_z, RectangleShape shape_t)
{
    shape_z.setFillColor(shape_t.c);
    shape_z.setOrigin(shape_t.x0,shape_t.y0);
}
