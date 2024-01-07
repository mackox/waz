#pragma once
#include <SFML/Graphics.hpp>
#include "owoc.h"
class Waz {
public:
    Waz(float startX, float startY, float rozmiar);
    void ruch();
    void kolizje(int szerokoscPlanszy, int wysokoscPlanszy,int rozmiarBloku);
    void rysuj(sf::RenderWindow& okno);
    const sf::Time zegar;

    const sf::Time czasMiedzyRuchami;
    void ustawKierunek(sf::Vector2f nowyKierunek);

private:
    sf::RectangleShape blok;
    sf::Vector2f kierunek;
    float predkoscX;
    float predkoscY;
    int szerokoscPlanszy;
    int wysokoscPlanszy;
    sf::Clock zegarRuchu;
    Owoc owoc;
};