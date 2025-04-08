#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <vector>
#include <ctime>

// Базовый класс "Фигура"
class Shape {
protected:
    sf::Color color;
    sf::Vector2f position;

public:
    Shape(sf::Vector2f pos, sf::Color col) : position(pos), color(col) {}
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void move(float dx, float dy) {
        position.x += dx;
        position.y += dy;
    }
    virtual void changeColor() {
        // Генерация случайного цвета
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }
};

// Класс "Точка"
class Point : public Shape {
private:
    float radius;

public:
    Point(sf::Vector2f pos, sf::Color col, float r = 5)
        : Shape(pos, col), radius(r) {
    }

    void draw(sf::RenderWindow& window) override {
        sf::CircleShape point(radius);
        point.setFillColor(color);
        point.setPosition(position);
        window.draw(point);
    }
};

// Класс "Круг"
class Circle : public Shape {
protected:
    float radius;

public:
    Circle(sf::Vector2f pos, sf::Color col, float r = 50)
        : Shape(pos, col), radius(r) {
    }

    void draw(sf::RenderWindow& window) override {
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setPosition(position);
        window.draw(circle);
    }

    // Методы для задания 2
    void scaleUp() {
        radius += 5;
    }

    void scaleDown() {
        if (radius > 10) radius -= 5;
    }
};

// Класс "Кольцо" (наследует круг)
class Ring : public Circle {
private:
    float innerRadius;

public:
    Ring(sf::Vector2f pos, sf::Color col, float r = 60, float innerR = 40)
        : Circle(pos, col, r), innerRadius(innerR) {
    }

    void draw(sf::RenderWindow& window) override {
        // Наружный круг
        sf::CircleShape outer(radius);
        outer.setFillColor(color);
        outer.setPosition(position);
        window.draw(outer);

        // Внутренний круг другого цвета (фон)
        sf::CircleShape inner(innerRadius);
        inner.setFillColor(sf::Color::Black); // Имитируем "вырез"
        inner.setPosition(position.x + (radius - innerRadius),
            position.y + (radius - innerRadius));
        window.draw(inner);
    }

    // Методы для задания 2
    void expand() {
        if (radius < 150) {
            radius += 5;
            innerRadius += 5;
        }
    }

    void shrink() {
        if (innerRadius > 10) {
            radius -= 5;
            innerRadius -= 5;
        }
    }
};

// Основная функция
int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab 7 - SFML");
    window.setFramerateLimit(60);

    // Создаём объекты
    Point point({ 100, 100 }, sf::Color::Green);
    Ring ring({ 300, 200 }, sf::Color::Red, 60, 40);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Управление с клавиатуры
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            ring.move(0, -5);
            ring.changeColor();  // смена цвета при движении
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ring.move(0, 5);
            ring.changeColor();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ring.move(-5, 0);
            ring.changeColor();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ring.move(5, 0);
            ring.changeColor();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            point.move(0, -5);
            point.changeColor();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            point.move(0, 5);
            point.changeColor();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            point.move(-5, 0);
            point.changeColor();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            point.move(5, 0);
            point.changeColor();
        }

        // Масштабирование кольца
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            ring.expand(); // увеличение кольца
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            ring.shrink(); // уменьшение кольца
        }

        window.clear(sf::Color::Black);
        point.draw(window);
        ring.draw(window);
        window.display();
    }

    return 0;
}
