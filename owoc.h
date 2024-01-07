#pragma once

#include <SFML/Graphics.hpp>

class Owoc {
public:
    Owoc(float pozX,float pozY, float rozmiarBloku);
    void generujOwoc(int szerokoscPlanszy, int wysokoscPlanszy);
    void rysuj(sf::RenderWindow& okno, int rozmiarBloku);
    //bool czyJestPozaPlansza(int szerokoscPlanszy, int wysokoscPlanszy);
    //float getX() const { return x; }
    sf::RectangleShape getOwoc();
    sf::RectangleShape owoc;
private:
    
    float rozmiarBloku;
    //float x;
};