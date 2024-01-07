#include <SFML/Graphics.hpp>
#include "Waz.h"
#include "Plansza.h"
#include "Owoc.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
int rozx = 400;
int rozy = 400;


int main() {
    sf::RenderWindow okno(sf::VideoMode(rozx, rozy), "Waz");
    Waz waz(200, 200, 10);//WAZ
    Owoc owoc(100, 100, 10);
    Plansza plansza(rozx / 10, rozy / 10, 10);

    sf::Clock zegar;

    while (okno.isOpen()) {
        sf::Event e;
        while (okno.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                okno.close();
        }
        okno.clear();

        plansza.rysuj(okno);
        waz.ruch();
        waz.kolizje(rozx/10,rozy/10,10);

        //owoc.generujOwoc(100, 100);
        
       

        waz.rysuj(okno);//WAZ
        owoc.rysuj(okno, 10);
        okno.display();

    }

    return 0;
}