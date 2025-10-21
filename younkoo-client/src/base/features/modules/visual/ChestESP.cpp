#include "ChestESP.h"
TitanHook<decltype(&glTranslatef)> glTranslatefHook;

struct Object
{
	enum Type
	{
		Chest,
		LargeChest
	};

	Type m_type;

	glm::mat4 m_projection;
	glm::mat4 m_modelview;

	Object(Type type) : m_type{ type }
	{
		// Automatically fill it with the data of the current matrices
		glGetFloatv(GL_PROJECTION_MATRIX, glm::value_ptr(m_projection));
		glGetFloatv(GL_MODELVIEW_MATRIX, glm::value_ptr(m_modelview));
	}
};

std::list<Object> objects;
ChestESP& ChestESP::getInstance()
{
	static ChestESP inst = ChestESP();
	return inst;
}

void ChestESP::onEnable()
{
	glTranslatefHook.SetHook();
}

void ChestESP::onDisable()
{
	glTranslatefHook.RemoveHook();
}

void ChestESP::onUpdate()
{
	ToggleCheck;
}
void ChestESP::onRender(const EventRender2D& e)
{
	ToggleCheck;
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Transforming matrices
	for (auto& object : objects)
	{
		glm::mat4& modelview = object.m_modelview;
		glm::mat4& projection = object.m_projection;

		glm::vec4 color = glm::vec4(1.0f);
		glm::vec3 translate = glm::vec3(1.0f);
		glm::vec3 scale = glm::vec3(1.0f);

		switch (object.m_type)
		{
		case Object::Chest:
			color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			translate = glm::vec3(0.5f, 0.5f, 0.5f);
			scale = glm::vec3(0.5f, 0.5f, 0.5f);
			break;

		case Object::LargeChest:
			color = glm::vec4(0.91f, 0.87f, 0.42f, 1.0f);
			translate = glm::vec3(1.0f, 0.5f, 0.5f);
			scale = glm::vec3(1.0f, 0.5f, 0.5f);
			break;
		}

		modelview = glm::translate(modelview, translate);
		modelview = glm::scale(modelview, scale);

		// Setup matrices
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(glm::value_ptr(projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(modelview));

		// Drawing box
		drawBox(color);
	}

	objects.clear();

	// Restoring settings (context and matrix)
	glPopAttrib();
	glPopMatrix();
}

void WINAPI hk_glTranslatef(float x, float y, float z)
{
	if (x == 0.5f and y == 0.4375f and z == 0.9375f)
		objects.push_back(Object::Chest);
	if (x == 1.0f and y == 0.4375f and z == 0.9375f)
		objects.push_back(Object::LargeChest);
	glTranslatefHook.GetOrignalFunc()(x, y, z);
}

ChestESP::ChestESP() :AbstractModule(xorstr_("ChestESP"), Category::VISUAL, xorstr_("ChestESP."))
{
	REGISTER_EVENT(EventRender2D, ChestESP::onRender);
	glTranslatefHook.InitHook(glTranslatef, hk_glTranslatef);
}

void ChestESP::drawBox(glm::vec4 color)
{
	glColor4f(color.r, color.g, color.b, color.a);

	glBegin(GL_LINES);
	{
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
	}
	glEnd();
}
