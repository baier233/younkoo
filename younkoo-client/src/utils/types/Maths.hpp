﻿#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>

#define PI 3.141592653589793238462643383279502884197


namespace Math {

	struct ChunkPos
	{
		int x, z;
	};


	template<typename T> class Vector3
	{
	public:

		T x{ NAN };
		T y{ NAN };
		T z{ NAN };

		Vector3<T>() {};
		Vector3<T>(const T x, const T y, const T z) : x(x), y(y), z(z) {}
		Vector3<T> operator + (const Vector3<T>& rhs) const { return Vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z); }
		Vector3<T> operator + (const T rhs) const { return Vector3<T>(x + rhs, y + rhs, z + rhs); }
		Vector3<T> operator - (const Vector3<T>& rhs) const { return Vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z); }
		Vector3<T> operator - (const T rhs) const { return Vector3<T>(x - rhs, y - rhs, z - rhs); }
		Vector3<T> operator * (const Vector3<T>& rhs) const { return Vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z); }
		Vector3<T> operator * (const T& rhs) const { return Vector3<T>(x * rhs, y * rhs, z * rhs); }
		Vector3<T> operator / (const T& rhs) const { return Vector3<T>(x / rhs, y / rhs, z / rhs); }
		Vector3<T>& operator += (const Vector3<T>& rhs) { return *this = *this + rhs; }
		Vector3<T>& operator -= (const Vector3<T>& rhs) { return *this = *this - rhs; }
		Vector3<T>& operator *= (const T& rhs) { return *this = *this * rhs; }
		Vector3<T>& operator /= (const T& rhs) { return *this = *this / rhs; }
		//Vector3<T> operator == (const Vector3<T>& rhs) { return this == rhs; }
		T Length() const { return sqrtf(x * x + y * y + z * z); }
		Vector3<T> Normalize() const { return *this * (1 / Length()); }
		Vector3<T> Invert() const { return Vector3<T>{ -x, -y, -z }; }
		T Distance(const Vector3<T>& rhs) const { return (*this - rhs).Length(); }
		T Dist() { return std::sqrt(x * x + y * y); }
	};
	template<typename T>
	struct Box {
		T minX, minY, minZ;
		T maxX, maxY, maxZ;


		Box<T> operator + (const Box<T>& rhs) const {
			return Box<T>{minX + rhs.minX,
				minY + rhs.minY,
				minZ + rhs.minZ,
				maxX + rhs.maxX,
				maxY + rhs.maxY,
				maxZ + rhs.maxZ};
		}
		Box<T> operator + (const Vector3<T>& rhs) const {
			return Box<T>{minX + rhs.x,
				minY + rhs.y,
				minZ + rhs.z,
				maxX + rhs.x,
				maxY + rhs.y,
				maxZ + rhs.z};
		}
		Box<T> operator - (const Box<T>& rhs) const {
			return Box<T>{minX - rhs.minX,
				minY - rhs.minY,
				minZ - rhs.minZ,
				maxX - rhs.maxX,
				maxY - rhs.maxY,
				maxZ - rhs.maxZ};
		}
		Box<T> operator - (const Vector3<T>& rhs) const {
			return Box<T>{minX - rhs.x,
				minY - rhs.y,
				minZ - rhs.z,
				maxX - rhs.x,
				maxY - rhs.y,
				maxZ - rhs.z};
		}
		template<typename NT>
		inline Box<NT> cast() const {
			return Box<NT>{
				static_cast<NT>(minX),
					static_cast<NT>(minY),
					static_cast<NT>(minZ),
					static_cast<NT>(maxX),
					static_cast<NT>(maxY),
					static_cast<NT>(maxZ)
			};
		}

	};

	struct Rotation {
		Rotation operator - (const Rotation& rhs) const { return Rotation(xRot - rhs.xRot, yRot - rhs.yRot); }
		Rotation Invert() const { return Rotation{ -xRot, -yRot }; }
		float xRot{ NAN };
		float yRot{ NAN };
	};
	struct Vector2
	{

		Vector2 operator - (const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
		Vector2 Invert() const { return Vector2{ -x, -y }; }
		float x{ NAN };
		float y{ NAN };
	};

	struct Vector2i
	{
		unsigned int x{ 0 };
		unsigned int y{ 0 };
	};

	struct Vector2D
	{
		Vector2D operator - (const Vector2D& rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
		Vector2D Invert() const { return Vector2D{ -x, -y }; }
		double x{ 0 };
		double y{ 0 };
	};

	struct Vector3i {
		Vector3i(const int x, const int y, const int z) : x(x), y(y), z(z) {}
		Vector3i() = default;
		unsigned int x{ 0 };
		unsigned int y{ 0 };
		unsigned int z{ 0 };
	};
	using Vector3D = Vector3<double>;
	/*struct Vector3D {
		double x, y, z;

		double distance(const Vector3D& other) const
		{
			return sqrt(pow(x - other.x, 2.0) + pow(y - other.y, 2.0) + pow(z - other.z, 2.0));
		}
		Vector3D operator - (const Vector3D& rhs) const { return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z); }
		Vector3D operator + (const Vector3D& rhs) const { return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z); }
		Vector3D operator += (const Vector3D& rhs) { return *this = *this + rhs; }
		Vector3D& operator -= (const Vector3D& rhs) { return *this = *this - rhs; }

		Vector3D operator * (const float& rhs) const { return Vector3D(x * rhs, y * rhs, z * rhs); }
	};*/


	struct Vector4
	{
		float x{ NAN };
		float y{ NAN };
		float z{ NAN };
		float w{ NAN };
	};

	struct Vector4D
	{
		double x{ NAN };
		double y{ NAN };
		double z{ NAN };
		double w{ NAN };
	};
	struct Rect
	{
		float left{ FLT_MAX };
		float top{ FLT_MAX };
		float right{ FLT_MIN };
		float bottom{ FLT_MIN };
		inline bool vaild() {
			return left != FLT_MAX && top != FLT_MAX && right != FLT_MIN && bottom != FLT_MIN;
		}
	};

	// https://github.com/Marcelektro/MCP-919/blob/main/src/minecraft/net/minecraft/util/Matrix4f.java
	// For readability & maybe security purposes.
	struct Matrix
	{
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;
	};

	struct BoundingBox {
		double minX;
		double minY;
		double minZ;
		double maxX;
		double maxY;
		double maxZ;
	};

	struct AxisAlignedBB {
		float minX, minY, minZ, maxX, maxY, maxZ;
	};

	inline std::vector<double> structToVector(const Matrix& matrix)
	{

		//column-major order

		std::vector<double> result;
		result.reserve(16);

		result.push_back(matrix.m00);
		result.push_back(matrix.m10);
		result.push_back(matrix.m20);
		result.push_back(matrix.m30);

		result.push_back(matrix.m01);
		result.push_back(matrix.m11);
		result.push_back(matrix.m21);
		result.push_back(matrix.m31);

		result.push_back(matrix.m02);
		result.push_back(matrix.m12);
		result.push_back(matrix.m22);
		result.push_back(matrix.m32);

		result.push_back(matrix.m03);
		result.push_back(matrix.m13);
		result.push_back(matrix.m23);
		result.push_back(matrix.m33);


		return result;
	}

	inline std::array<float, 16> structToArray(const Matrix& matrix)
	{

		//column-major order

		std::array<float, 16> result{
			matrix.m00 ,matrix.m10,matrix.m20,matrix.m30,
			matrix.m01 ,matrix.m11,matrix.m21,matrix.m31,
			matrix.m02 ,matrix.m12,matrix.m22,matrix.m32,
			matrix.m03 ,matrix.m13,matrix.m23,matrix.m33,
		};


		return result;
	}

	inline std::vector<double> structToVector2(const Matrix& matrix)
	{
		std::vector<double> result;
		result.reserve(16);

		result.reserve(16);

		result.push_back(matrix.m00);
		result.push_back(matrix.m01);
		result.push_back(matrix.m02);
		result.push_back(matrix.m03);

		result.push_back(matrix.m10);
		result.push_back(matrix.m11);
		result.push_back(matrix.m12);
		result.push_back(matrix.m13);

		result.push_back(matrix.m20);
		result.push_back(matrix.m21);
		result.push_back(matrix.m22);
		result.push_back(matrix.m23);

		result.push_back(matrix.m30);
		result.push_back(matrix.m31);
		result.push_back(matrix.m32);
		result.push_back(matrix.m33);


		return result;
	}

	struct Matrix4 {
		std::array<std::array<float, 4>, 4> mat;

		Matrix4(std::initializer_list<float> values) {
			auto it = values.begin();
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					mat[i][j] = *it++;
				}
			}
		}
	};

	inline Vector4 Multiply(Vector4 v, Matrix m) {
		return Vector4{
			v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
			v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33
		};
	}

	inline Vector4D Multiply(Vector4D v, Matrix m) {
		return Vector4D{
			v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
			v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33
		};
	}



	namespace W2S {

		std::array<double, 3> world2Screen(const std::array<float, 16>& modelViewMatrix, const std::array<float, 16>& projectionMatrix, const Math::Vector3D& pos, const std::array<int, 4>& viewport, double guiScale = 2.0f);
		inline std::array<double, 3> world2Screen(const Math::Matrix& modelViewMatrix, const Math::Matrix& projectionMatrix, const Math::Vector3D& pos, const std::array<int, 4>& viewport, double guiScale = 2.0f) {
			return world2Screen(Math::structToArray(modelViewMatrix), Math::structToArray(projectionMatrix), pos, viewport, guiScale);
		}

		inline bool WorldToScreen(Vector3D point, Matrix modelView, Matrix projection, int screenWidth, int screenHeight, Vector2D& screenPos) {
			// csp = Clip Space Position
			Vector4D csp = Multiply(
				Multiply(
					Vector4D{ point.x, point.y, point.z, 1.0f },
					modelView
				),
				projection
			);

			// ndc = Native Device Coordinate
			Vector3D ndc{
				csp.x / csp.w,
				csp.y / csp.w,
				csp.z / csp.w
			};

			//Logger::Log("NDC.Z: " + std::to_string(ndc.z));
			if (ndc.z > 1 && ndc.z < 1.15) {
				screenPos = Vector2D{
					((ndc.x + 1.0f) / 2.0f) * screenWidth,
					((1.0f - ndc.y) / 2.0f) * screenHeight,
				};
				return true;
			}

			return false;
		}
	}

	inline float wrapAngleTo180(float angle)
	{
		angle = std::fmod(angle, 360.0f);
		if (angle >= 180.0f) {
			angle -= 360.0f;
		}

		if (angle < -180.0f) {
			angle += 360.0f;
		}

		return angle;
	}
	inline float radiantsToDeg(float x)
	{
		return x * 180.f / PI;
	}
	inline float degToRadiants(float x)
	{
		return x * PI / 180.f;
	}
	inline Vector2 getAngles(Vector3<float> pos, Vector3<float> pos1)
	{
		double d_x = pos1.x - pos.x;
		double d_y = pos1.y - pos.y;
		double d_z = pos1.z - pos.z;

		double hypothenuse = sqrt(d_x * d_x + d_z * d_z);
		float yaw = radiantsToDeg(atan2(d_z, d_x)) - 90.f;
		float pitch = radiantsToDeg(-atan2(d_y, hypothenuse));

		return Vector2(yaw, pitch);
	}

	inline Vector2 getAngles(Vector3D pos, Vector3D pos1)
	{
		double d_x = pos1.x - pos.x;
		double d_y = pos1.y - pos.y;
		double d_z = pos1.z - pos.z;

		double hypothenuse = sqrt(d_x * d_x + d_z * d_z);
		float yaw = radiantsToDeg(atan2(d_z, d_x)) - 90.f;
		float pitch = radiantsToDeg(-atan2(d_y, hypothenuse));

		return Vector2(yaw, pitch);
	}
	inline Vector2 vec_wrapAngleTo180(Vector2 angle)
	{
		return Vector2{
			wrapAngleTo180(angle.x),
			wrapAngleTo180(angle.y),
		};
	}

	inline float coterminal(float angle) {
		return std::fmod(angle, 180) < 0 ? angle + 170 : angle;
	}

}
