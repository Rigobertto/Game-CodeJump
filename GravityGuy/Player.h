
#ifndef _PLATFORMER_PLAYER_H_
#define _PLATFORMER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum Gravity { NORMAL, INVERTED };         // tipo da gravidade
enum Forma { JUMP, MOVE };
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    TileSet* tilesetJump = nullptr;
    Animation* anim = nullptr;         // anima��o do personagem
    Animation* animJump = nullptr;
    Animation* animMove = nullptr;
    uint gravity = NORMAL;              // gravidade atuando sobre o jogador
    bool keyCtrl = false;               // controle do pressionamento da barra de espa�o
    bool jumpCtrl = true;
    uint forma = MOVE;
    bool gameover = false;

public:
    
    Player();                           // construtor
    ~Player();                          // destrutor


    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    bool isColision();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Player::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------



#endif