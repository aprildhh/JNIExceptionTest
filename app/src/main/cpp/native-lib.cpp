#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_dhh_jniexceptiontest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject jobj) {

    jstring excptionStr = env->NewStringUTF("JNI中返回的异常！！！");

    jclass clazz = env->GetObjectClass(jobj);
    jmethodID mid = env->GetMethodID(clazz, "ExceptionTest", "()V");
    env->CallVoidMethod(jobj, mid);
//中间不能有其他操作
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();//描述异常
        env->ExceptionClear();//清除异常
        env->ThrowNew(env->FindClass("java/lang/Exception"),"JNI中抛出的异常~~~");
        return excptionStr;
    }

    __android_log_print(ANDROID_LOG_ERROR, "JNI", "----------");

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_dhh_jniexceptiontest_MainActivity_exceptionJNI(JNIEnv *env, jobject instance) {

//    jclass clazz = env->GetObjectClass(instance);
//    jmethodID mid = env->GetMethodID(clazz, "ExceptionTest", "()V");
//    env->CallVoidMethod(instance,mid);
//
////中间不能有其他操作
//    if (env->ExceptionCheck()) {
//        env->ExceptionDescribe();//描述异常
//        env->ExceptionClear();//清除异常
//        env->ThrowNew(env->FindClass("java/lang/Exception"),"JNI中抛出的异常~~~");
//        return 1;
//    }

    return 0;
}