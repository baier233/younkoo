#pragma once
#include <jni/Wrapper.hpp>
#include <mapper/SRGParser.h>
//#define TEST
#define EMPTY_CONTENT

#include <base/Younkoo.hpp>
namespace SDK {

	inline jobject MinecraftClassLoader;

	inline bool SetUpClassLoader(std::string class_name) {
		auto env = JNI::get_env();
		jclass c_Thread = env->FindClass("java/lang/Thread");
		jclass c_Map = env->FindClass("java/util/Map");
		jclass c_Set = env->FindClass("java/util/Set");
		jclass c_ClassLoader = env->FindClass("java/lang/ClassLoader");

		jmethodID mid_getAllStackTraces = env->GetStaticMethodID(c_Thread, "getAllStackTraces", "()Ljava/util/Map;");
		jmethodID mid_keySet = env->GetMethodID(c_Map, "keySet", "()Ljava/util/Set;");
		jmethodID mid_toArray = env->GetMethodID(c_Set, "toArray", "()[Ljava/lang/Object;");
		jmethodID mid_getContextClassLoader = env->GetMethodID(c_Thread, "getContextClassLoader", "()Ljava/lang/ClassLoader;");
		static auto mid_findClass = env->GetMethodID(c_ClassLoader, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
		//jmethodID mid_currentThread = env->GetStaticMethodID(c_Thread, "currentThread", "()Ljava/lang/Thread;");

		jobject obj_stackTracesMap = env->CallStaticObjectMethod(c_Thread, mid_getAllStackTraces);
		jobject obj_threadsSet = env->CallObjectMethod(obj_stackTracesMap, mid_keySet);

		jobjectArray threads = (jobjectArray)env->CallObjectMethod(obj_threadsSet, mid_toArray);
		jint szThreads = env->GetArrayLength(threads);

		for (int i = 0; i < szThreads; i++)
		{
			jobject thread = env->GetObjectArrayElement(threads, i);
			jobject classLoaderObj = env->CallObjectMethod(thread, mid_getContextClassLoader);

			if (classLoaderObj) {

				jstring className = env->NewStringUTF(class_name.c_str());
				jobject klass = env->CallObjectMethod(classLoaderObj, mid_findClass, className);

				if (klass)
				{
					MinecraftClassLoader = env->NewGlobalRef(classLoaderObj);
					std::lock_guard lock{ JNI::_refs_to_delete_mutex };
					JNI::_refs_to_delete.push_back(MinecraftClassLoader);
					env->DeleteLocalRef(className);
					env->DeleteLocalRef(klass);
					env->DeleteLocalRef(classLoaderObj);
					break;
				}
				env->DeleteLocalRef(className);
			}

			env->DeleteLocalRef(thread);
		}

		env->DeleteLocalRef(threads);
		env->DeleteLocalRef(obj_stackTracesMap);
		env->DeleteLocalRef(obj_threadsSet);
		env->DeleteLocalRef(c_Thread);
		env->DeleteLocalRef(c_Map);
		env->DeleteLocalRef(c_Set);
		env->DeleteLocalRef(c_ClassLoader);
		return MinecraftClassLoader != nullptr;
	}

	[[deprecated]]
	inline bool SetUpForge1181ClassLoader(std::string thread_name) {
		auto jniEnv = JNI::get_env();
		//(void)jniEnv->PushLocalFrame(15);
		jobject targetClassLoader = NULL;
		typedef jobjectArray(JNICALL* JVM_GetAllThreads)(JNIEnv* env, jclass dummy);
		JVM_GetAllThreads getAllThreads = (JVM_GetAllThreads)GetProcAddress(GetModuleHandleW(L"jvm.dll"), "JVM_GetAllThreads");
		jobjectArray threadsArray = getAllThreads(jniEnv, NULL);
		int threadsCount = jniEnv->GetArrayLength(threadsArray);
		(void)jniEnv->PushLocalFrame(threadsCount * 2 + 15);
		jclass thread_class = jniEnv->FindClass("java/lang/Thread");
		jfieldID ctxClsLoader = jniEnv->GetFieldID(thread_class, "contextClassLoader", "Ljava/lang/ClassLoader;");
		jmethodID getName = jniEnv->GetMethodID(thread_class, "getName", "()Ljava/lang/String;");
		for (int i = 0; i < threadsCount; i++) {
			jobject thread = jniEnv->GetObjectArrayElement(threadsArray, i);
			jstring threadName = (jstring)jniEnv->CallObjectMethod(thread, getName);
			auto threadNameStr = std::string(jniEnv->GetStringUTFChars(threadName, 0));
			if (threadNameStr == thread_name) {
				jobject classLoader = jniEnv->GetObjectField(thread, ctxClsLoader);
				MinecraftClassLoader = jniEnv->NewGlobalRef(classLoader);
				std::lock_guard lock{ JNI::_refs_to_delete_mutex };
				JNI::_refs_to_delete.push_back(MinecraftClassLoader);
				break;
			}
		}
		(void)jniEnv->PopLocalFrame(nullptr);
		jniEnv->DeleteLocalRef(threadsArray);
		return MinecraftClassLoader != nullptr;
	}

	inline bool isForge() {
		static auto result = false;
		static auto checked = false;
		static jclass ref = nullptr;
		if (!checked) {
			ref = JNI::get_env()->FindClass("net/minecraftforge/common/ForgeVersion");
			result = ref != nullptr;
		}
		return result;
	}

	inline void CheckVersion() {
		std::string cmd = GetCommandLineA();
		if (cmd.find("1.18.1") != std::string::npos and cmd.find("forgeclient") != std::string::npos) {
			LOG("forge 1.18.1");
			SRGParser::get().SetVersion(Versions::FORGE_1_18_1);
		}
		else if (cmd.find("1.8.9") != std::string::npos) {
			if (isForge()) {
				LOG("forge 1.8.9");
				SRGParser::get().SetVersion(Versions::FORGE_1_8_9);
			}
			else if (cmd.find("lunar") != std::string::npos)
			{
				LOG("lunar 1.8.9");
				SRGParser::get().SetVersion(Versions::LUNAR_1_8_9);
			}
		}
		else if (cmd.find("1.12.2") != std::string::npos) {
			if (isForge()) {
				LOG("forge 1.12.2");
				SRGParser::get().SetVersion(Versions::FORGE_1_12_2);
			}
			else if (cmd.find("lunar") != std::string::npos)
			{
				LOG("lunar 1.12.2");
				SRGParser::get().SetVersion(Versions::LUNAR_1_12_2);
			}
		}
		else if (cmd.find("1.20.1") != std::string::npos and cmd.find("forgeclient") != std::string::npos) {
			LOG("forge 1.20.1");
			SRGParser::get().SetVersion(Versions::FORGE_1_20_1);
		}
		else if (cmd.find("1.20.4") != std::string::npos and cmd.find("fabricmc") != std::string::npos) {
			LOG("fabric 1.20.4");
			SRGParser::get().SetVersion(Versions::FABRIC_1_20_4);
		}
		else {
			MessageBox(0, L"Unsupported version", 0, 0);
			return;
		}

		auto v = SRGParser::get().GetVersion();
		if (v == Versions::MCP_1_8_9 || v == Versions::FORGE_1_8_9 || v == Versions::LUNAR_1_8_9)
		{
			Younkoo::get().info.major = MajorVersion::MAJOR_189;
		}
		else  if (v == Versions::FORGE_1_18_1)
		{
			Younkoo::get().info.major = MajorVersion::MAJOR_1181;
		}
		else if (v == Versions::FORGE_1_20_1)
		{
			Younkoo::get().info.major = MajorVersion::MAJOR_1201;
		}
		else if (v == Versions::FORGE_1_12_2 || v == Versions::LUNAR_1_12_2 || v == Versions::MCP_1_12_2)
		{
			Younkoo::get().info.major = MajorVersion::MAJOR_112;
		}
		else if (v == Versions::FABRIC_1_20_4)
		{
			Younkoo::get().info.major = MajorVersion::MAJOR_1204;
		}
	}

	inline std::string GetKlassName(jclass cls) {
		auto env = JNI::get_env();
		jmethodID mid_getName = env->GetMethodID(cls, "getName", "()Ljava/lang/String;");
		jstring name = (jstring)env->CallObjectMethod(cls, mid_getName);
		const char* name_chars = env->GetStringUTFChars(name, nullptr);
		std::string name_str = name_chars;
		env->ReleaseStringUTFChars(name, name_chars);
		env->DeleteLocalRef(name);
		return name_str;
	}
}


namespace maps
{



}

#define BEGIN_WRAP namespace Wrapper{

#define END_WRAP }

#define BEGIN_1_18_1 namespace V1_18_1{

#define END_1_18_1 }

#define BEGIN_1_8_9 namespace V1_8_9{

#define END_1_8_9 }

#define BEGIN_1_12_2 namespace V1_12_2{

#define END_1_12_2 }

#define BEGIN_1_20_1 namespace V1_20_1 {

#define END_1_20_1 }
#define BEGIN_1_20_4 namespace V1_20_4 {

#define END_1_20_4 }