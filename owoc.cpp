#include "Owoc.h"
#include <cstdlib>
#include <ctime>


Owoc::Owoc(float pozX, float pozY, float rozmiarBloku) 
{
    owoc.setSize(sf::Vector2f(rozmiarBloku, rozmiarBloku));
    owoc.setFillColor(sf::Color::Red);
    owoc.setPosition(pozX,pozY);
    /*float x = rand() % 200;
    float y = rand() % 200;
    owoc.setPosition(x, y);*/
   // std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Owoc::generujOwoc(int szerokoscPlanszy, int wysokoscPlanszy)
{
   
    /*float x = static_cast<float>(rand() % szerokoscPlanszy);
    float y = static_cast<float>(rand() % wysokoscPlanszy);
    
    owoc.setPosition(x, y);*/
    float x = static_cast<float>(rand() % szerokoscPlanszy);
    float y = static_cast<float>(rand() % wysokoscPlanszy);

    

    owoc.setPosition(x, y);
    
}
//bool Owoc::czyJestPozaPlansza(int szerokoscPlanszy, int wysokoscPlanszy) {
//    sf::Vector2f pozycja = owoc.getPosition();
//    if (pozycja.x < 0 || pozycja.y < 0 || pozycja.x > szerokoscPlanszy || pozycja.y > wysokoscPlanszy) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}

void Owoc::rysuj(sf::RenderWindow& okno, int rozmiarBloku)
{
    sf::RectangleShape owocCopy = owoc;
    owocCopy.setPosition(owoc.getPosition().x * rozmiarBloku, owoc.getPosition().y * rozmiarBloku);
    owocCopy.setSize(sf::Vector2f(rozmiarBloku, rozmiarBloku));

    okno.draw(owocCopy);
}
sf::RectangleShape Owoc::getOwoc() {
    return owoc;
}