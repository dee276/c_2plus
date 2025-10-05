#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 400), "Calculatrice SFML");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cout << "Police non trouvée !" << std::endl;
        return 1;
    }

    std::string input = "";
    sf::Text display(input, font, 30);
    display.setPosition(10, 10);
    display.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                char c = static_cast<char>(event.text.unicode);
                if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '.') {
                    input += c;
                } else if (c == '\b' && !input.empty()) {
                    input.pop_back();
                } else if (c == '\r' || c == '\n') { // Entrée
                    try {
                        double result = std::stod(input);
                        input = std::to_string(result);
                    } catch (...) {
                        input = "Erreur";
                    }
                }
                display.setString(input);
            }
        }
        window.clear(sf::Color::White);
        window.draw(display);
        window.display();
    }
    return 0;
}