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

        case 11: {
            create(col::OOP_Rectangles);
        }break;

        case 12: {
            create(col::Matrix_Transformation);
        }break;

        default:{
            std::cerr << "\nNothing was picked" << std::endl;
            create(col::Polygon_Polygon);
        }
    }
}

void col::Run::create(col::C_TYPE type) {
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!", sf::Style::Resize);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(90.f);

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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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

        case col::OOP_Rectangles : {
            sf::CircleShape c(30.f);
            std::vector<sf::RectangleShape> rects(8);

            c.setFillColor(sf::Color(75,75,75));

            for(int i = 0; i < 18; i++)
            {
                float x = static_cast<int> ((rand() % (window.getSize().x - 50) + 50) /50) * 50;
                float y = static_cast<int> ((rand() %(window.getSize().y -50) + 50) /50) * 50;
                std::cout << x << '\t'  << y << std::endl;
                sf::RectangleShape temp(sf::Vector2f(50,50));
                temp.setPosition(sf::Vector2f(x, y));
                temp.setFillColor(sf::Color(0,150,255));
                rects.push_back(temp);
            }

            while (window.isOpen()) {
                c.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - c.getRadius(), sf::Mouse::getPosition(window).y - c.getRadius()));

                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();

                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        window.close();
                }

                for(int i = 0; i < rects.size(); i++)
                {
                    if(col::Collision::CircleRectangleCollision(c, rects.at(i))) {
                        rects.at(i).setFillColor((sf::Color(255,150,0)));
                    }
                    else {
                        rects.at(i).setFillColor((sf::Color(0,150,255)));
                    }
                }

                window.clear(sf::Color::White);
                window.draw(c);
                for(int i = 0; i < rects.size(); i++)
                    window.draw(rects.at(i));
                window.display();
            }
        }
        break;

        case col::Matrix_Transformation : {


            col::square s1(4);
            s1.regularPolygon(70.71, 4);
            s1.center = sf::Vector2f(window.getSize().x / 3, window.getSize().y / 2);

            col::square s2(4);
            s2.regularPolygon(148.421, 4);
            s2.center = sf::Vector2f(window.getSize().x - window.getSize().x / 3, window.getSize().y / 2);


            s1.pointsToScreenCords();
            s2.pointsToScreenCords();


            while (window.isOpen()) {
                //rotate

                col::square::collision(s1.p, s2.p);


                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();

                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        window.close();
                }

                window.clear(sf::Color::White);
                window.draw(s1.p);
                window.draw(s2.p);
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
                 << "10) Rectangle-Rectangle Collision\n"
                 << "11) OOP-Rectangles Collision\n"
                 << "12) Matrix Transformation\n" << std::endl;
    int a = 0;

    //std::cin >> a;
    num = 12;
}

void col::square::pointsToScreenCords() {
    sf::ConvexShape temp(p.getPointCount());
    for(int i = 0; i < p.getPointCount(); i++)
    {
        temp.setPoint(i, sf::Vector2f(
                p.getPoint(i).x + p.getPosition().x,
                p.getPoint(i).y + p.getPosition().y
        ));
    }
    p = temp;
    p.setPosition(center);
}

void col::square::collision(sf::ConvexShape &p1, sf::ConvexShape &p2)
{
    if(Collision::PolygonPolygonCollision(p2, p1))
    {
        p2.setFillColor(sf::Color(255, 150, 0));
        p1.setFillColor(sf::Color(255, 150, 0));
    }
    else
    {
        p2.setFillColor(sf::Color(0, 150, 255));
        p1.setFillColor(sf::Color(0, 150, 255));
    }
}

void col::square::regularPolygon(float r, int n) {
    sf::Vector2f temp;
    for( int i = 0; i < n; i++)
    {
        temp.x = cos((2 * M_PI * (i )) / (n))  * r;
        temp.y = sin((2 * M_PI * (i )) / (n))  * r;
        p.setPoint(i, temp);
    }
}

sf::Vector2f col::square::rotate(sf::Vector2f pt, float angleDeg) {
    float angleRad = (angleDeg/180)* M_PI;
    float cosAngle = cos(angleRad );
    float sinAngle = sin(angleRad );
    float dx = (pt.x-center.x);
    float dy = (pt.y-center.y);

    pt.x = center.x + (dx*cosAngle-dy*sinAngle);
    pt.y = center.y + (dx*sinAngle+dy*cosAngle);
    return pt;
}




