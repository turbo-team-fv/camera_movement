#include <iostream>
#include <SFML/Graphics.hpp>

//#define kVel 5

int main()
{
    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex;
    if (!tex.loadFromFile("resources/sprites.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }

    sf::Texture texmap;
    if (!texmap.loadFromFile("resources/map.png"))
    {
        std::cerr << "Error cargando la imagen map.png";
        exit(0);
    }

    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);
    sf::Sprite spriteMap(texmap);

    //Le pongo el centroide donde corresponde
    sprite.setOrigin(75/2,75/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
// Lo dispongo en el centro de la pantalla
    sprite.setPosition(320, 240);
    int kVel = 5;

    // Vamo a ponerle un view sabroso
    sf::View view;
    // Pongo el view centrado en el jugador
    view.reset(sf::FloatRect(sprite.getPosition().x-200, sprite.getPosition().y-100, 400, 200));









    //Bucle del juego
    while (window.isOpen())
    {

  // Posicionar camara donde el jugador
//        std::cout<< sprite.getPosition().x<<sprite.getPosition().y <<std::endl;
        view.setCenter(sprite.getPosition().x, sprite.getPosition().y);

        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){

                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;

                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:

                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {

                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Escala por defecto
                            sprite.setScale(1,1);
                            sprite.move(kVel,0);
//                                spriteMap.setOrigin(75/2,75/2);
                        break;

                        case sf::Keyboard::Left:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Reflejo vertical
                            sprite.setScale(-1,1);
                            sprite.move(-kVel,0);
                        break;

                        case sf::Keyboard::Up:
                            sprite.setTextureRect(sf::IntRect(0*75, 3*75, 75, 75));
                            sprite.move(0,-kVel);
                        break;

                        case sf::Keyboard::Down:
                            sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
                            sprite.move(0,kVel);
                        break;

                        case sf::Keyboard::A:
                            kVel++;
                        break;
                          case sf::Keyboard::S:
                            kVel--;
                        break;

                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;

                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;

                    }

            }

        }


        window.clear();
   // Apply it
    window.setView(view);
        window.draw(spriteMap);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
