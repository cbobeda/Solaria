//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//bool rayIntersectsRect(const sf::Vector2f& rayOrigin,
//    const sf::Vector2f& rayDir,
//    const sf::FloatRect& rect,
//    sf::Vector2f& hitPoint) {
//    
//
//    float tMin = 0.0f, tMax = 1000.0f; // Distance min et max pour le recast
//    sf::Vector2f invDir(1.0f / rayDir.x, 1.0f / rayDir.y); // Inverse du vecteur direction
//
//    // Limites du rectangle
//    sf::Vector2f rectMin(rect.left, rect.top);
//    sf::Vector2f rectMax(rect.left + rect.width, rect.top + rect.height);
//
//    // Vérification sur X
//    float t1x = (rectMin.x - rayOrigin.x) * invDir.x;
//    float t2x = (rectMax.x - rayOrigin.x) * invDir.x;
//    if (t1x > t2x) std::swap(t1x, t2x);
//
//    // Vérification sur Y
//    float t1y = (rectMin.y - rayOrigin.y) * invDir.y;
//    float t2y = (rectMax.y - rayOrigin.y) * invDir.y;
//    if (t1y > t2y) std::swap(t1y, t2y);
//
//    tMin = std::max(tMin, t1x);
//    tMax = std::min(tMax, t2x);
//
//    tMin = std::max(tMin, t1y);
//    tMax = std::min(tMax, t2y);
//
//    if (tMax < tMin) return false; // Pas d'intersection
//
//    hitPoint = rayOrigin + tMin * rayDir; // Calcul du point d'impact
//    return true;
//}
//
//sf::Vector2f normalize(const sf::Vector2f& vector) {
//    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
//
//    if (length == 0.0f)
//        return sf::Vector2f(0.0f, 0.0f);
//    return sf::Vector2f(vector.x / length, vector.y / length);
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Raycast SFML");
//
//    sf::Vector2f rayOrigin(100, 300); // Origine du rayon
//    sf::Vector2f rayDir(1, 0); // Direction horizontale vers la droite
//    sf::Vector2f normalize(const sf::Vector2f& vector);
//  
//
//
//   
//
//    sf::RectangleShape wall(sf::Vector2f(100, 100));
//    wall.setPosition(400, 250);
//    wall.setFillColor(sf::Color::Red);
//
//    sf::Vector2f hitPoint;
//    bool hit = rayIntersectsRect(rayOrigin, rayDir, wall.getGlobalBounds(), hitPoint);
//
//    sf::CircleShape hitMarker(5);
//    hitMarker.setFillColor(sf::Color::Green);
//    if (hit) hitMarker.setPosition(hitPoint - sf::Vector2f(2.5f, 2.5f)); // Centrer le point d'impact
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear(sf::Color::Black);
//
//        // Dessiner le mur
//        window.draw(wall);
//
//        // Dessiner le rayon
//        sf::Vertex line[] = {
//            sf::Vertex(rayOrigin, sf::Color::White),
//            sf::Vertex(hit ? hitPoint : rayOrigin + rayDir * 800.0f, sf::Color::White)
//        };
//        window.draw(line, 2, sf::Lines);
//
//        // Dessiner le point d'impact si le rayon touche le mur
//        if (hit) window.draw(hitMarker);
//
//        window.display();
//    }
//
//    return 0;
//}
