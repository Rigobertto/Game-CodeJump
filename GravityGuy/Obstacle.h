#ifndef _PLATFORMER_OBSTACLE_H_
#define _PLATFORMER_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"         // interface de object
#include "Sprite.h"           // interface de sprites
#include "Image.h"                     // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"
// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    uint obstacle;
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;
    Sprite* sprite;
    float vel;
    bool gameover = false;

public:
    Obstacle();
    ~Obstacle();

    void OnCollision(Object* obj);
    bool isCollision();
    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline

inline void Obstacle::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
