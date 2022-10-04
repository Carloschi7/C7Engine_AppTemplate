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

	m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
	m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 100.0f);
	m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
	m_Camera.SetMouseFunction(MouseForCameraFun);


	VertexManager manager(verts, sizeof(verts), lyt);
	Entity obj(manager);
	obj.Scale(glm::vec3(5.0f, 5.0f, 1.0f));

	Shader shd("assets/basic.shader");

	m_Window.SetVsync(true);

	while (!m_Window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		m_Camera.ProcessInput(m_Window, 1.0);
		shd.UniformMat4f(m_Camera.GetViewMatrix(), "view");
		shd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");

		obj.Draw(shd);
		m_Window.Update();
	}
}