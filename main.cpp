#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "function.cpp"
//Вариант 3.
//Создайте 3 прямоугольника разных цветов и размеров. Перемещайте их из исходного положения влево
//до конца экрана с разной скорость. При достижении конца экрана остановите фигуры.
using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Laba_9");
    RectangleShape shape_a{sf::Vector2f(120.f, 50.f),1000,60,5,sf::Color::Red,60,25};
    RectangleShape shape_b{sf::Vector2f(240.f, 100.f),650,180,3,sf::Color::Yellow,120,50};
    RectangleShape shape_c{sf::Vector2f(70.f, 400.f),1000,600,7, sf::Color::Green,35,300};
    sf::RectangleShape shape1,shape2(shape_b.a),shape3(shape_c.a);
    PullShape(shape1, shape_a);
    PullShape(shape2, shape_b);
    PullShape(shape3, shape_c);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(shape_a.x-shape_a.s >= 60)
            shape_a.x -= shape_a.s;
        else if(shape_a.x != 60)
            shape_a.x--;
        if(shape_b.x-shape_b.s >= 120)
            shape_b.x -= shape_b.s;
        else if(shape_b.x != 120)
            shape_b.x--;
        if(shape_c.x-shape_c.s >= 35)
            shape_c.x -= shape_c.s;
        else if(shape_c.x != 35)
            shape_c.x--;
        shape1.setPosition(shape_a.x,shape_a.y);
        shape2.setPosition(shape_b.x,shape_b.y);
        shape3.setPosition(shape_c.x,shape_c.y);
        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
        std::this_thread::sleep_for(40ms);
    }
    return 0;
}