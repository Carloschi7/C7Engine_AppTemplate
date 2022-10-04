#include "../application/Application.h"

std::unique_ptr<Window> WindowMaker::MakeWindow()
{
    return std::make_unique<Window>(1920, 1080, "Application", true);
}

Application::Application(Window& window)
	:m_Window(window)
{
	
}

Application::~Application()
{
}

void Application::OnUserCreate()
{
	m_Window.SetVsync(true);
	m_Window.SetWndInCurrentContext();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Application::OnUserRun()
{
	float verts[]{ -0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,
				    0.5f, -0.5f,  0.0f,  0.0f,  1.0f,  0.0f,
				    0.0f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f };

	Layout lyt;
	lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0 });
	lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 3 * sizeof(float)});


	VertexManager manager(verts, sizeof(verts), lyt);
	Entity obj(manager);

	Shader shd("assets/basic.shader");
	shd.UniformMat4f(glm::mat4(1.0f), "model");
	shd.UniformMat4f(glm::mat4(1.0f), "view");
	shd.UniformMat4f(glm::mat4(1.0f), "proj");

	while (!m_Window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		obj.Draw(shd);
		m_Window.Update();
	}
}