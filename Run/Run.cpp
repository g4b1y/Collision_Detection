#include "Run.h"

col::Run::Run() {
    getInfo();
    decide();
}

void col::Run::decide() {
    switch(num)
    {
        case 1:{
            create(col::Point_Point);
        }break;

        case 2: {
            create(col::Point_Circle);
        }break;

        case 3: {
            create(col::Circle_Circle);
        }break;

        case 4: {
            create(col::Point_Rectangle);
        }break;

        case 5: {
            create(col::Circle_Rectangle);
        }break;

        case 6: {
            create(col::Point_Polygon);
        }break;

        case 7: {
            create(col::Circle_Polygon);
        }break;

        case 8: {
            create(col::Rectangle_Polygon);
        }break;

        case 9 : {
            create(col::Polygon_Polygon);
        }break;

        case 10: {
            create(col::Rectangle_Rectangle);
        }break;

        default:{
            std::cerr << "\nNothing was picked" << std::endl;
            create(col::Polygon_Polygon);
        }
    }
}

void col::Run::create(col::C_TYPE type) {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    window.setMouseCursorVisible(false);

    switch(type) {
        case col::Point_Point: {
            sf::CircleShape p1(20.f);
            sf::CircleShape p2(20.f);
            p2.setPosition((window.getSize().x / 2) - p2.getRadius(), (window.getSize().y / 2) - p2.getRadius());

            while (window.isOpen()) {
                p1.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                p1.setFillColor(sf::Color(75, 75, 75));
                p2.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::PointCollision(p1, p2)) { window.clear(sf::Color(255, 150, 0)); }
                else { window.clear(sf::Color::White); }


                window.draw(p1);
                window.draw(p2);
                window.display();
            }
        }
            break;

        case col::Point_Circle: {
            sf::CircleShape p1(3.f);
            sf::CircleShape p2(60.f);
            p2.setPosition((window.getSize().x / 2) - p2.getRadius(), (window.getSize().y / 2) - p2.getRadius());

            while (window.isOpen()) {
                p1.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                p1.setFillColor(sf::Color(75, 75, 75));
                p2.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::PointCircleCollision(p1, p2)) { p2.setFillColor(sf::Color(255, 150, 0)); }
                else { p2.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p1);
                window.draw(p2);
                window.display();
            }
        }
            break;

        case col::Circle_Circle: {
            sf::CircleShape p1(40.f);
            sf::CircleShape p2(50.f);
            p2.setPosition((window.getSize().x / 2) - p2.getRadius(), (window.getSize().y / 2) - p2.getRadius());

            while (window.isOpen()) {
                p1.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                p1.setFillColor(sf::Color(75, 75, 75));
                p2.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                if (col::Collision::CircleCircleCollision(p1, p2)) {
                    p1.setFillColor(sf::Color(255, 150, 0));
                    p2.setFillColor(sf::Color(255, 150, 0));
                } else {
                    p1.setFillColor(sf::Color::Green);
                    p2.setFillColor(sf::Color::Green);
                }

                window.clear(sf::Color::White);
                window.draw(p1);
                window.draw(p2);
                window.display();
            }
        }
            break;

        case col::Point_Rectangle: {
            sf::RectangleShape r1;
            r1.setPosition(sf::Vector2f(100, 70));
            r1.setSize(sf::Vector2f(210, 170));

            sf::CircleShape p1(3.f);

            while (window.isOpen()) {
                p1.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                p1.setFillColor(sf::Color(75, 75, 75));
                r1.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::PointRectangleCollision(p1, r1)) { r1.setFillColor(sf::Color(255, 150, 0)); }
                else { r1.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p1);
                window.draw(r1);
                window.display();
            }
        }
            break;

        case col::Rectangle_Rectangle: {
            sf::RectangleShape r1;
            r1.setPosition(sf::Vector2f(100, 70));
            r1.setSize(sf::Vector2f(170, 130));

            sf::RectangleShape r2;
            r2.setPosition(sf::Vector2f(50, 70));
            r2.setSize(sf::Vector2f(35, 35));


            while (window.isOpen()) {
                r2.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                r2.setFillColor(sf::Color(0, 0, 0));
                r1.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::RectangleRectangleCollision(r2, r1)) { r1.setFillColor(sf::Color(255, 150, 0)); }
                else { r1.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(r2);
                window.draw(r1);
                window.display();
            }
        }
            break;

        case col::Circle_Rectangle: {
            sf::RectangleShape r1;
            r1.setPosition(sf::Vector2f(100, 70));
            r1.setSize(sf::Vector2f(170, 135));

            sf::CircleShape p1(25.f);

            while (window.isOpen()) {
                p1.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                p1.setFillColor(sf::Color(75, 75, 75));
                r1.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::CircleRectangleCollision(p1, r1)) { r1.setFillColor(sf::Color(255, 150, 0)); }
                else { r1.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p1);
                window.draw(r1);
                window.display();
            }
        }
            break;

        case col::Point_Polygon: {
            std::vector<sf::Vector2f> vertices(4);
            vertices[0] = sf::Vector2f(150, 100);
            vertices[1] = sf::Vector2f(350, 130);
            vertices[2] = sf::Vector2f(300, 300);
            vertices[3] = sf::Vector2f(200, 300);

            sf::ConvexShape p;
            p.setPointCount(vertices.size());
            for (int _p = 0; _p < vertices.size(); _p++) {
                p.setPoint(_p, vertices.at(_p));
            }

            sf::CircleShape c(3.f);

            c.setFillColor(sf::Color(75, 75, 75));
            p.setFillColor(sf::Color(0, 150, 255));

            while (window.isOpen()) {
                c.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                c.setFillColor(sf::Color(75, 75, 75));
                p.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::PointPolygonCollision(c, p)) { p.setFillColor(sf::Color(255, 150, 0)); }
                else { p.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p);
                window.draw(c);
                window.display();
            }
        }
            break;

        case col::Circle_Polygon: {
            std::vector<sf::Vector2f> vertices(4);
            vertices[0] = sf::Vector2f(150, 130);
            vertices[1] = sf::Vector2f(350, 130);
            vertices[2] = sf::Vector2f(300, 300);
            vertices[3] = sf::Vector2f(200, 300);

            sf::ConvexShape p;
            p.setPointCount(vertices.size());
            for (int _p = 0; _p < vertices.size(); _p++) {
                p.setPoint(_p, vertices.at(_p));
            }

            sf::CircleShape c(15.f);

            c.setFillColor(sf::Color(75, 75, 75));
            p.setFillColor(sf::Color(0, 150, 255));

            while (window.isOpen()) {
                c.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                c.setFillColor(sf::Color(75, 75, 75));
                p.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::CirclePolygonCollision(c, p)) { p.setFillColor(sf::Color(255, 150, 0)); }
                else { p.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p);
                window.draw(c);
                window.display();
            }
        }
            break;

        case col::Rectangle_Polygon: {
            std::vector<sf::Vector2f> vertices;
            vertices.push_back(sf::Vector2f(150, 130));
            vertices.push_back(sf::Vector2f(350, 130));
            vertices.push_back(sf::Vector2f(300, 300));
            vertices.push_back(sf::Vector2f(200, 300));

            sf::ConvexShape p;
            p.setPointCount(vertices.size());
            for (int _p = 0; _p < vertices.size(); _p++) {
                p.setPoint(_p, vertices.at(_p));
            }

            sf::RectangleShape r;
            r.setPosition(sf::Vector2f(50, 70));
            r.setSize(sf::Vector2f(35, 35));

            r.setFillColor(sf::Color(75, 75, 75));
            p.setFillColor(sf::Color(0, 150, 255));

            while (window.isOpen()) {
                r.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                r.setFillColor(sf::Color(75, 75, 75));
                p.setFillColor(sf::Color(0, 150, 255));
                sf::Event event;


                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                if (col::Collision::RectanglePolygonCollision(r, p)) { p.setFillColor(sf::Color(255, 150, 0)); }
                else { p.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(p);
                window.draw(r);
                window.display();
            }
        }
        break;

        case col::Polygon_Polygon: {
            sf::ConvexShape Pentagon;
            sf::ConvexShape randomPolygon;

            Pentagon.setPointCount(5);
            randomPolygon.setPointCount(7);

            float angle = M_PI * 2 / Pentagon.getPointCount();
            for (int i = 0; i < Pentagon.getPointCount(); i++) {
                float a = angle * i;
                float x = 300 + cos(a) * 100;
                float y = 200 + sin(a) * 100;
                Pentagon.setPoint(i, sf::Vector2f(x, y));
            }


            for (int i = 0; i < randomPolygon.getPointCount(); i++) {
                float x = 300 + cos(rand() % 50 + 15) * 45;
                float y = 200 + sin(rand() % 50 + 15) * 45;
                randomPolygon.setPoint(i, sf::Vector2f(x, y));
            }

            Pentagon.setFillColor(sf::Color(255, 150, 0));
            randomPolygon.setFillColor(sf::Color(75, 75, 75));


            while (window.isOpen()) {
                sf::Vector2f mouse(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                sf::Vector2f diff(mouse.x - randomPolygon.getPoint(0).x, mouse.y - randomPolygon.getPoint(0).y);
                for (int i = 0; i < randomPolygon.getPointCount(); i++) {
                    randomPolygon.setPoint(i, randomPolygon.getPoint(i) + diff);
                }

                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                if (col::Collision::PolygonPolygonCollision(randomPolygon, Pentagon)) {
                    Pentagon.setFillColor(sf::Color(255, 150, 0));
                }
                else { Pentagon.setFillColor(sf::Color(0, 150, 255)); }

                window.clear(sf::Color::White);
                window.draw(Pentagon);
                window.draw(randomPolygon);
                window.display();
            }
        }
            break;
    }
}

void col::Run::getInfo() {
    std::cout << "What simulation would you like to see?\n";
    std::cout <<    "1) Point-Point Collision\n"
                 << "2) Point-Circle Collision\n"
                 << "3) Circle-Circle Collision\n"
                 << "4) Point-Rectangle Collision\n"
                 << "5) Circle-Rectangle Collision\n"
                 << "6) Point-Polygon Collision\n"
                 << "7) Circle-Polygon Collision\n"
                 << "8) Rectangle-Polygon Collision\n"
                 << "9) Polygon-Polygon Collision\n"
                 << "10) Rectangle-Rectangle Collision" << std::endl;
    int a = 0;
    std::cin >> a;
    num = a;
}