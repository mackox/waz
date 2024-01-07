#pragma once
#include <SFML/Graphics.hpp>

class Plansza {
public:
    Plansza(int szerokosc, int wysokosc, int rozmiarKomorki);
    void rysuj(sf::RenderWindow& okno);

private:
    sf::RectangleShape kwadrat;
    int szerokosc;
    int wysokosc;
    int rozmiarKomorki;
};