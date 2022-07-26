#include "../application/Application.h"

//Template applications, try some of this engine's demos by browsing the cpp
//files contained in the demos folder

//Application window generation(required)
std::unique_ptr<Window> WindowMaker::MakeWindow()
{
    /*
     * PARAMETERS: width, height, application name, is fullscreen
     * */
    return std::make_unique<Window>(1920, 1080, "Application", true);
}

Application::Application(Window& window)
    :m_Window(window)
{
}

Application::~Application()
{
}

//Static setup for the application
void Application::OnUserCreate()
{
    m_Window.SetVsync(true);
    m_Window.SetWndInCurrentContext();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Application variables/application logic
void Application::OnUserRun()
{
    glEnable(GL_DEPTH_TEST);
    while (!m_Window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Window.Update();
    }
}