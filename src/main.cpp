#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    std::cout << "Hello world! Desktop test 1"
    
    return 0;
}

class Menu
{
    
private:
    
    sf::RenderWindow menuWindow
    
    sf::Font mainFont;
    
    sf::Texture image1;
    sf::Texture image2;
    sf::Texture image3;
    sf::Texture image4;
    sf::Texture image5;
    
    sf::Text menuTitle;
    sf::Text menuHint;
    sf::Text menuExitButtonWord;
    
    sf::Sprite choiceImage1;
    sf::Sprite choiceImage2;
    sf::Sprite choiceImage3;
    sf::Sprite choiceImage4;
    sf::Sprite choiceImage5;
    
    sf::RectangleShape titleRect;
    sf::RectangleShape buttonRect;
    
    sf::Vector2f choiceImage1Pos;
    sf::Vector2f choiceImage2Pos;
    sf::Vector2f choiceImage3Pos;
    sf::Vector2f choiceImage4Pos;
    sf::Vector2f choiceImage5Pos;
    sf::Vector2f menuTitlePos;
    sf::Vector2f menuHintPos;
    sf::Vector2f menuExitButtonWord1Pos;
    sf::Vector2f titleRectPos;
    sf::Vector2f buttonRectPos;
    sf::Vector2f menuWindowLocation;
    
    sf::Color textColor;
    sf::Color backgroundColor;
    sf::Color buttonColor1;
    sf::Color buttonColor2;
    
    sf::FloatRect menuWindowSize;
    
    const int gameSizeSmall;
    const int gameSizeMedium;
    const int gameSizeLarge;
    const int titleTextSize;
    const int textSize;
    const int subTextSize;
    
    std::string gameSizeChoice;
    std::string menuTitleText;
    std::string menuHintText;
    std::string menuExitButtonWordText;
    
public:
    
    Menu();
    
};

class Jigsaw: public menu
{
    
private:
    
    sf::RenderWindow jigsawWindow;
    
    sf::Sprite gamePiece1;
    sf::Sprite gamePiece2;
    sf::Sprite gamePiece3;
    sf::Sprite gamePiece4;
    sf::Sprite gamePiece5;
    sf::Sprite gamePiece6;
    sf::Sprite gamePiece7;
    sf::Sprite gamePiece8;
    sf::Sprite gamePiece9;
    sf::Sprite gamePiece10;
    sf::Sprite gamePiece11;
    sf::Sprite gamePiece12;
    sf::Sprite gamePiece13;
    sf::Sprite gamePiece14;
    sf::Sprite gamePiece15;
    sf::Sprite gamePiece16;
    sf::Sprite gamePiece17;
    sf::Sprite gamePiece18;
    sf::Sprite gamePiece19;
    sf::Sprite gamePiece20;
    sf::Sprite gamePiece21;
    sf::Sprite gamePiece22;
    sf::Sprite gamePiece23;
    sf::Sprite gamePiece24;
    sf::Sprite gamePiece25;
    sf::Sprite gamePiece26;
    sf::Sprite gamePiece27;
    sf::Sprite gamePiece28;
    sf::Sprite gamePiece29;
    sf::Sprite gamePiece30;
    sf::Sprite gamePiece31;
    sf::Sprite gamePiece32;
    sf::Sprite gamePiece33;
    sf::Sprite gamePiece34;
    sf::Sprite gamePiece35;
    sf::Sprite gamePiece36;
    sf::Sprite gamePiece37;
    sf::Sprite gamePiece38;
    sf::Sprite gamePiece39;
    sf::Sprite gamePiece40;
    sf::Sprite gamePiece41;
    sf::Sprite gamePiece42;
    sf::Sprite gamePiece43;
    sf::Sprite gamePiece44;
    sf::Sprite gamePiece45;
    sf::Sprite gamePiece46;
    sf::Sprite gamePiece47;
    sf::Sprite gamePiece48;
    sf::Sprite gamePiece49;
    sf::Sprite gamePiece50;
    
    std::vector <std::vector <std::string> > gameSet;
    std::vector <std::vector <std::string> > gamePieces;
    std::vector <std::vector <std::string> > temp;   
     
public:
    
    Jigsaw();
    jigsawToVector();
    
};

Menu::Menu()
    {
        if(! (mainFont.loadFromFile =  "../fnt/Georgia.ttf"))
            std::cout << std::endl << "Error loading font 'Georgia.ttf'" << std::endl;
        
        gameSizeSmall = 12;
        gameSizeMedium = 25;
        gameSizeLarge = 50;
        titleTextSize = 40;
        textSize = 25;
        subTextSize = 10;
        
        menuTitleText = "Jigsaw Time!";

        menuHintText = "Hi! Welcome to Jigsaw Time! There is lots of awesome landscape jigsaw puzzle fun to be had!";
        menuExitButtonWordText = "Quit"; 
        
        textColor = sf::Color::Black;
        backgroundColor = sf::Color::Black;
        buttonColor1 = (200, 202, 206);
        buttonColor2 = (227, 228, 232);
        
        menuTitle.setCharacterSize(titleTextSize);
        menuHint.setCharacterSize(textSize);
        menuExitButtonWord.setCharacterSize(textSize);
        
        menuTitle.setColor(textColor);
        menuHint.setColor(textColor);
        menuExitButtonWord.setColor(textColor);
        
        menuTitle.setString(menuTitleText);
        menuHint.setString(menuHintText);
        menuExitButtonWord.setString(menuExitButtonWordText);
        
        image1.loadFromFile(../img/landscape1.jpg);
        image2.loadFromFile(../img/landscape2.jpg);
        image3.loadFromFile(../img/landscape3.jpg);
        image4.loadFromFile(../img/landscape4.jpg);
        image5.loadFromFile(../img/landscape5.jpg);
        
        choiceImage1.setTexture(image1);
        choiceImage2.setTexture(image2);
        choiceImage3.setTexture(image3);
        choiceImage4.setTexture(image4);
        choiceImage5.setTexture(image5);
        
        titleRect.setFillColor(buttonColor1);
        buttonRect.setFillColor(buttonColor2);
        
        choiceImage1Pos = (sf::Vector2f(0, 0));
        choiceImage2Pos = (sf::Vector2f(0, 0));
        choiceImage3Pos = (sf::Vector2f(0, 0));
        choiceImage4Pos = (sf::Vector2f(0, 0));
        choiceImage5Pos = (sf::Vector2f(0, 0));
        menuTitlePos = (sf::Vector2f(0, 0));
        menuHintPos = (sf::Vector2f(0, 0));
        menuExitButtonWord1Pos = (sf::Vector2f(0, 0));
        titleRectPos = (sf::Vector2f(0, 0));
        buttonRectPos = (sf::Vector2f(0, 0));
        menuWindowLocation = (sf::Vector2f(0, 0));
        
        menuWindowSize = (sf::Vector2f(0, 0));
        
    }

Jigsaw::JigsawToVector()
{
    
};
