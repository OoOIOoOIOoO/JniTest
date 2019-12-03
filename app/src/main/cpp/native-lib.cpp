#include <jni.h>
#include <string>
#include <unistd.h>
#include "main.c"
extern "C" JNIEXPORT jstring

JNICALL
Java_jni_test_com_jnitest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    mains();
    return env->NewStringUTF(hello.c_str());
}
