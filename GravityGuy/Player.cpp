/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"
#include "Obstacle.h"
#include <typeinfo>

// ---------------------------------------------------------------------------------

Player::Player()
{

    tileset = new TileSet("Resources/spritesplayer/player_moving.png", 72, 178, 6, 12); //("Resources/spritesplayer/p_running.png", 86, 214, 5,  10)
    tilesetJump = new TileSet("Resources/spritesplayer/player_moving.png", 72, 178, 6, 12);
    gameover = false;
    uint move[6] = { 6, 7, 8, 9, 10, 11 };
    uint jump[6] = { 0,1,2,3,4, 5 };

    animJump = new Animation(tilesetJump, 0.25f, true);
    animMove = new Animation(tileset, 0.090f, true);
    animMove->Add(MOVE, move, 6);
    animJump->Add(JUMP, jump, 6);
    anim = animMove;

    MoveTo(100.0f, 600.0f, 0.0f);

    uint normal[5] = { 0,1,2,3,4 };


    //anim->Add(INVERTED, invertido, 4);


    BBox(new Rect(-43, -80, +43, +90));
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete tilesetJump;
    delete animJump;
    delete animMove;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    // mant�m personagem na posi��o correta em cima da plataforma
    if (gravity == NORMAL) {
        MoveTo(100.0f, obj->Y() - 71);
        anim = animMove;
    }

    if (typeid(obj) == typeid(Obstacle)) {
        gameover = true;
    }

    jumpCtrl = true;


}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();
    float time = 0;
    //MoveTo(80.0f, obj->Y() - 50);
    // a��o da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);


    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = true;
        // gravity = !gravity;
        //Translate(0, -200 * gameTime);

        if (gravity == NORMAL) {
            Translate(0, 0);
            anim->Select(NORMAL);
            anim->Select(MOVE);

        }

    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }

    if (jumpCtrl && window->KeyDown(VK_SPACE)) {

        Translate(0, (-window->Height() - 18000) * gameTime);
        anim = animJump;
        jumpCtrl = false;

    }



}
void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    gravity = NORMAL;
   // level = 0;
}
bool Player::isColision() {
    return gameover;
}

// ---------------------------------------------------------------------------------