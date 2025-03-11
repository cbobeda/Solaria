#include "Entity.h"

using namespace std;
using namespace sf;

class FlyingEnemy : public Entity
{
private:
    int hp = 4;
    float speed = 20;
    Texture texture;
    Sprite sprite;


public:
    void update(float deltatime) override;
    void draw(RenderWindow& window) override;
    ~FlyingEnemy();
};