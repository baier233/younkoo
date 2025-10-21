#pragma once
#include <SDK.hpp>
#include <wrapper/java/lang/String.h>

namespace JDK {

	BEGIN_KLASS_DEF(Object, return "java/lang/Object");
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(Collection, return "java/util/Collection")
		JNI::Method<JNI::Array<Object>, JNI::NOT_STATIC, DECLARE_NAME(return "toArray")> toArray{ *this };
	END_KLASS_DEF();

	BEGIN_KLASS_DEF_EX(List, return "java/util/List", Collection)
		END_KLASS_DEF();

	BEGIN_KLASS_DEF(FloatBuffer, return "java/nio/FloatBuffer")
		JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(return "get"), jint> get{ *this };

	Math::Matrix GetMatrix() {
		std::vector<float> arr;
		for (int i = 0; i < 16; i++)
		{
			arr.push_back(this->get(i));
		}
		Math::Matrix m;
		m.m00 = arr[0];
		m.m01 = arr[1];
		m.m02 = arr[2];
		m.m03 = arr[3];
		m.m10 = arr[4];
		m.m11 = arr[5];
		m.m12 = arr[6];
		m.m13 = arr[7];
		m.m20 = arr[8];
		m.m21 = arr[9];
		m.m22 = arr[10];
		m.m23 = arr[11];
		m.m30 = arr[12];
		m.m31 = arr[13];
		m.m32 = arr[14];
		m.m33 = arr[15];

		return m;
	}
	END_KLASS_DEF();
	BEGIN_KLASS_DEF(IntBuffer, return "java/nio/IntBuffer")
		END_KLASS_DEF();

	namespace java_util {

		BEGIN_KLASS_DEF(Iterator, return "java/util/Iterator")
			JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(return "hasNext")> hasNext{ *this };
		JNI::Method<JDK::Object, JNI::NOT_STATIC, DECLARE_NAME(return "next")> next{ *this };
		END_KLASS_DEF();

		BEGIN_KLASS_DEF(UUID, return "java/util/UUID")
			JNI::Method < String, JNI::NOT_STATIC, DECLARE_NAME(
				return "toString";
			) > toString{ *this };
		END_KLASS_DEF();
	}
	namespace java_lang {
		BEGIN_KLASS_DEF(Iterable, return "java/lang/Iterable")
			JNI::Method<java_util::Iterator, JNI::NOT_STATIC, DECLARE_NAME(return "iterator")> iterator{ *this };
		END_KLASS_DEF();
	}


	BEGIN_KLASS_DEF(Integer, return "java/lang/Integer")
		JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(return "intValue")> intValue{ *this };
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(Runnable, return "java/lang/Runnable")
		END_KLASS_DEF();

}