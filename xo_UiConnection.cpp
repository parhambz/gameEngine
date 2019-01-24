//
// Created by Parham Bagherzadeh on 1/24/2019 AD.
//

#include "xo_UiConnection.h"
#include <jni.h>
Engine * eng= nullptr;
JNIEXPORT jobject JNICALL Java_xo_UiConnection_start
        (JNIEnv * env, jobject obj, jint x, jint y, jstring name1, jstring name2,jobject isAuto1,jobject isAuto2) {
    eng = Engine::getInstance();
    eng->setBoard(new DoozBoard(Pair(x,y)));
    eng->setRule(new DoozRule);
    eng->setGameStruct(x,y,name1,name2,isAuto1,isAuto2);
    eng->start();
}

JNIEXPORT jobject JNICALL Java_xo_UiConnection_botMove(JNIEnv *, jobject){

}