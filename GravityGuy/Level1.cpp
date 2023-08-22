/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "Obstacle.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene * Level1::scene = nullptr;
Obstacle * obstacle = nullptr;
list<Obstacle*> objects;
// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();
    backg = new Background();
    scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    Platform * plat = new Platform(683, 707);
    scene->Add(plat, STATIC);

    obstacle = new Obstacle();
    scene->Add(obstacle, MOVING);

    // pano de fundo do jogo
    //backg = new Background(Color{ 1,1,1,1 });
    //scene->Add(backg, STATIC);

    // adiciona jogador na cena
    //scene->Add(GravityGuy::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    //Platform* plat = nullptr;
   /* float posX, posY;
    uint  platType;
    Color white { 1,1,1,1 };

    ifstream fin;
    fin.open("Level1.txt");

    fin >> posX;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha com informações da plataforma
            fin >> posY; fin >> platType;
            //plat = new Platform(posX, posY, platType, white);
            scene->Add(plat, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();*/

    // ----------------------

    // inicia com música
    
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        
        GravityGuy::NextLevel<Home>();
        //GravityGuy::player->Reset();
    }
    else if (obstacle->isCollision())
    {
        
        GravityGuy::NextLevel<GameOver>();
        //GravityGuy::player->Reset();
    }
    else {
        scene->Update();
        scene->CollisionDetection();
    }
     
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    //backg->Draw();
    scene->Draw();
    scene->DrawBBox();

    
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    //scene->Remove(GravityGuy::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
