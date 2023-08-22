

#ifndef _CODEJUMPER_BACKGROUND_H_
#define _CODEJUMPER_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float yF, yB;                       // posi��o horizontal dos sprites
    Image* imgF;                       // imagem de fundo frontal
    Image* imgB;                       // imagem de fundo traseira    

    Sprite* sky;                       // fundo est�tico

    Sprite* backgF1;                   // pano de fundo din�mico (frontal 1)
    Sprite* backgF2;                   // pano de fundo din�mico (frontal 2)
    Sprite* backgB1;                   // pano de fundo din�mico (traseiro 1)
    Sprite* backgB2;                   // pano de fundo din�mico (traseiro 2)

public:
    Background();                       // construtor
    ~Background();                      // destrutor
    Sprite* backgroundHome;
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif