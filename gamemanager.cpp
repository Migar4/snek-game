#include "gamemanager.h"
#include <assert.h>

gameManager::gameManager(string name)
{
    mEngine = new engine(name.c_str());

    mPlayer = new snek("/home/migar/Desktop/C++/snek/assets/head.png");
    mBody = new snekBody(*mPlayer);
    //assert(mBody != NULL);
    mFood = new food("/home/migar/Desktop/C++/snek/assets/food.png");

    mStartSprite = new sprite("/home/migar/Desktop/C++/snek/assets/start.jpg", vector3(engine::SCREEN_WIDTH/2, engine::SCREEN_HEIGHT/2));
    mStartSprite->flipVertically();
    mGameOverSprite = new sprite("/home/migar/Desktop/C++/snek/assets/gameover.jpeg", vector3(engine::SCREEN_WIDTH/2, engine::SCREEN_HEIGHT/2));
    mGameOverSprite->flipVertically();

    mBody->createSpr("/home/migar/Desktop/C++/snek/assets/body1.png");

    for(int i = 0 ; i < 2 ; i++){
        mBody->createSpr("/home/migar/Desktop/C++/snek/assets/body1.png");
    }

    mState = state::START;
}

gameManager::~gameManager(){
    delete mEngine;
    delete mPlayer;
    delete mFood;
    delete mStartSprite;
    delete mGameOverSprite;
}

void gameManager::start(){
    bool quit = false;
    while(!quit){
        mEngine->update();

        switch(mState){
        case state::START:
        {
            mEngine->beginRender();
            mStartSprite->render();
            mEngine->endRender();

            mBody->reset();

            if(keyboard::keyDown(GLFW_KEY_SPACE)){
                setState(state::GAMEPLAY);
            }
            if(keyboard::keyDown(GLFW_KEY_ESCAPE)){
                quit = true;
            }
        }
            break;

        case state::GAMEPLAY:
        {
            mPlayer->update();
            mFood->update();
            mBody->update();


            mEngine->beginRender();
            mBody->render();
            mPlayer->render();
            mFood->render();
            mEngine->endRender();


            if(keyboard::keyDown(GLFW_KEY_Q )){
                setState(state::GAMEOVER);
            }
            if(keyboard::keyDown(GLFW_KEY_ESCAPE)){
                quit = true;
            }

            if(rigidbody::isRectColliding(mPlayer->getRigidBody(), mFood->getRigidbody())){
                mFood->changePos();


                for(int i = 0; i < 2; i++){
                       mBody->createSpr("/home/migar/Desktop/C++/snek/assets/body1.png");

                    }
            }

            //cout << "rb size " << mBody->getRigidBody().size() << endl;
            //cout << "rect size " << mBody->getRc().size() << endl;
            //cout << "pos size " << mBody->getPos().size() << endl;
            //cout << "sprite size " << mBody->getSpr().size() << endl;

            unsigned int i = 5;
            for(; i < mBody->getRigidBody().size(); i++){
                if(rigidbody::isRectColliding(mBody->getRigidBody()[0], mBody->getRigidBody()[i])){

                    cout << "colliding " << i << endl;
                    //cout << i << ": " << *mBody->getSpr()[i].getPos() << "\n" << i << ": " << *mBody->getSpr()[i].getPos() << endl;
                    //cout << i << ": " << mBody->getRc()[i].getPos() << endl;
                    //cout << "bodyrbpos " << i << " " << mBody->getRigidBody()[i].getPos() << endl;
                    //setState(state::GAMEOVER);
                }
            }
            //cout << "Score is : " << mPlayer->getScore() << endl;
        }
            break;

        case state::GAMEOVER:
        {
            mEngine->beginRender();
            mGameOverSprite->render();
            mEngine->endRender();

            if(keyboard::keyDown(GLFW_KEY_SPACE)){
                setState(state::START);
            }
            if(keyboard::keyDown(GLFW_KEY_ESCAPE)){
                quit = true;
            }
        }
            break;

        case state::COUNT:
        {
            cout << "undefined game state" << endl;
        }
        }
    }
}

void gameManager::setState(state S){
    mState = S;

    if(mState == state::START){
        mPlayer->reset();
        mFood->reset();
    }
}
