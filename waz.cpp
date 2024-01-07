#include "Waz.h"
#include "plansza.h"
#include "owoc.h"
#include <iostream>
//Owoc owoc(10, 10, 10);
const int KRATKA = 10;

Waz::Waz(float startX, float startY, float rozmiar) 
    : czasMiedzyRuchami(sf::seconds(0.125f)), predkoscX(0.0f), predkoscY(0.0f), owoc(startX, startY, rozmiar)
{
    blok.setSize(sf::Vector2f(rozmiar, rozmiar));//tworzenie weza, ustawianie koloru rozmiaru itd
    blok.setFillColor(sf::Color::Black);
    blok.setOutlineThickness(1);
    blok.setOutlineColor(sf::Color::Red);
    blok.setPosition(startX, startY);




}
void Waz::ustawKierunek(sf::Vector2f nowyKierunek)
{

    predkoscX = nowyKierunek.x;
    predkoscY = nowyKierunek.y;

}


void Waz::ruch() {


    if (zegarRuchu.getElapsedTime() >= czasMiedzyRuchami)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            predkoscX = 0.0f;
            predkoscY = -1.0f;
            //blok.move(0, -KRATKA);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            predkoscX = 0.0f;
            predkoscY = 1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            predkoscX = -1.0f;
            predkoscY = 0.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            predkoscX = 1.0f;
            predkoscY = 0.0f;
        }
        blok.move(predkoscX * KRATKA, predkoscY * KRATKA);
        zegarRuchu.restart();
    }


}

void Waz::kolizje(int szerokoscPlanszy, int wysokoscPlanszy, int rozmiarBloku)
{
    if (blok.getPosition().x < 0)
        blok.setPosition(0, blok.getPosition().y);
    if (blok.getPosition().y < 0)
        blok.setPosition(blok.getPosition().x, 0);
    if (blok.getPosition().x > 390)
        blok.setPosition(390, blok.getPosition().y);
    if (blok.getPosition().y > 390)
        blok.setPosition(blok.getPosition().x, 390);
    
    //sf::FloatRect blokBounds = blok.getGlobalBounds();
    //sf::FloatRect owocBounds = owoc.getOwoc().getGlobalBounds();

    //if (blokBounds.intersects(owocBounds)) 
    sf::FloatRect blokBounds = blok.getGlobalBounds();
    sf::FloatRect owocBounds = owoc.getOwoc().getGlobalBounds();

    std::cout << "Pozycja bloku: " << blok.getPosition().x << ", " << blok.getPosition().y << std::endl;
    std::cout << "Pozycja owocu: " << owoc.getOwoc().getPosition().x << ", " << owoc.getOwoc().getPosition().y << std::endl;

    if (blokBounds.intersects(owocBounds)) {
        owoc.generujOwoc(szerokoscPlanszy, wysokoscPlanszy);
        
        std::cout << "Kolizja! Nowa pozycja owocu: " << owoc.getOwoc().getPosition().x << ", " << owoc.getOwoc().getPosition().y << std::endl;
    }
    

}


void Waz::rysuj(sf::RenderWindow& okno) {
    okno.draw(blok);
}