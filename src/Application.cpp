#include "../application/Application.h"

//Template applications, try some of this engine's demos by browsing the cpp
//files contained in the build folder

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
    while (!m_Window.ShouldClose())
    {
        m_Window.Update();
    }
}
