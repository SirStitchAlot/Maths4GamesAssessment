#pragma once

#include <raymath.h>
#include <iostream>
using namespace std;

#include "SceneObject.h"
#include "SpriteObject.h"
#include "Helper.h"


class Game_01{
public:
    Game_01();
    ~Game_01();


    float Speed = 100.0f;

    float Scale_Multi = 2.0f;    // scale multiplier 
    bool Scale_Active = false;  // scale switch

    SceneObject* tankObject = new SceneObject();
    SpriteObject* tankSprite = new SpriteObject();

    void Init();
    void Shutdown();
    void Update();
    void Draw();


};

