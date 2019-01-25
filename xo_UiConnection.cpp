//
// Created by Parham Bagherzadeh on 1/25/2019 AD.
//

#include "xo_UiConnection.h"
Engine * eng= nullptr;

JNIEXPORT jobject JNICALL Java_xo_UiConnection_start (JNIEnv * env, jobject obj, jint x, jint y, jstring name1, jstring name2,jobject isAuto1,jobject isAuto2) {
    Engine* eng = Engine::getInstance();
    Pair size(6, 6);
    DoozBoard board(size);
    engine->setBoard(&board);
    Rule* rule = DoozRule::getInstance();
    engine->setRule(rule);
    UIConnection* conection = new UIConnection() ;
    engine->setUIConnection(conection);
    GameStruct * gs=new GameStruct();
    gs->BoardSize->setX(x);
    gs->BoardSize->setY(y);
    gs->playersNames.push_back(name1);
    gs->playersNames.push_back(name2);
    gs->isAuto.push_back(isAuto1);
    gs->isAuto.push_back(isAuto2);
    engine->setGameStruct(gs);
    for (int i = 0; i < gs->playersNames.size(); i++) {
        if(gs->isAuto[i]==false) {
            Pair p(-1, -1);
            Player *playerr = new RealPlayer(i, p, gs->playersNames[i], 0);
            engine->addPlayer(playerr);
        }else{
            Pair p(-1, -1);
            Player *playerr = new AutoPlayer(i, p, gs->playersNames[i], 0);
            engine->addPlayer(playerr);
        }
    }
    jboolean jb = true;
    return jb;
}

JNIEXPORT jobject JNICALL Java_xo_UiConnection_botMove(JNIEnv *env, jobject obj){
    jstirng js;
    env->ReleaseStringUTFChars(js,eng->botMove());
    return js;
}
JNIEXPORT jobject JNICALL Java_xo_UiConnection_end
        (JNIEnv * env, jobject obj){
    jint ji= eng->end();
    return ji;
}
JNIEXPORT jobject JNICALL Java_xo_UiConnection_move
        (JNIEnv * env, jobject obj, jint x, jint y){
    jboolaen jb=eng->move(x,y);
return jb;
}

JNIEXPORT jobject JNICALL Java_xo_UiConnection_isOver(JNIEnv * env, jobject obj){
    jboolaen jb=eng->isOver();
    return jb;
}

