#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(640, 350), "KEMU");

int CursorX, CursorY;
void DrawText(char* Text);
void DrawTextWindow();
void DrawWindow()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    //window.clear();
    //window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.display();
        window.clear();
        DrawTextWindow();
       
        //window.draw(shape);

        //DrawText("sas");
        
    }
}

void DrawText(char Text)
{
    sf::Font font;//шрифт 
    font.loadFromFile("src/KemuWindow/Fonts/arialmt.ttf");//передаем нашему шрифту файл шрифта
    sf::Text text(Text, font, 15);
    text.setPosition(CursorX * 10, CursorY * 20);//задаем позицию текста, центр камеры
	window.draw(text);//рисую этот текст
}

void DrawTextWindow()
{
    sf::Font font;//шрифт 
    font.loadFromFile("src/KemuWindow/Fonts/SF.ttf");//передаем нашему шрифту файл шрифта
    for(int i = 0 ; i < 32; i++)
    {
        sf::Text text(TextVideoMemory[i], font, 15);
        text.setPosition(CursorX * 10 - 100, CursorY * 20);//задаем позицию текста, центр камеры
	    window.draw(text);//рисую этот текст
    }
}

void ClearWindow()
{
    window.clear();
}