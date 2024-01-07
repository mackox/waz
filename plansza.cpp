#include "Plansza.h"

Plansza::Plansza(int szerokosc, int wysokosc, int rozmiarKomorki) : szerokosc(szerokosc), wysokosc(wysokosc), rozmiarKomorki(rozmiarKomorki) {
    kwadrat.setSize(sf::Vector2f(rozmiarKomorki, rozmiarKomorki));
    kwadrat.setOutlineThickness(1);
    kwadrat.setOutlineColor(sf::Color::Black);
}

void Plansza::rysuj(sf::RenderWindow& okno) {
    for (int i = 0; i < szerokosc; ++i) {
        for (int j = 0; j < wysokosc; ++j) {
            kwadrat.setPosition(i * rozmiarKomorki, j * rozmiarKomorki);
            okno.draw(kwadrat);
        }
    }
}