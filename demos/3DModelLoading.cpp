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
    //Camera setup
    m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
    m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
    m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
    m_Camera.SetMouseFunction(MouseForCameraFun);

    m_Models.emplace_back("assets/models/earth/Earth 2K.fbx");
    m_Models[0].LoadExternalTexture("assets/models/earth/Textures/Diffuse_2K.png", "diffuse_texture");

    //Shader setup
    m_Shaders.emplace_back("assets/shaders/basic_lighting.shader");
    m_Shaders[0].UniformMat4f(m_Camera.GetProjMatrix(), "proj");

    glEnable(GL_DEPTH_TEST);
    while (!m_Window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Shaders[0].UniformMat4f(m_Camera.GetViewMatrix(), "view");
        m_Models[0].Draw(m_Shaders[0]);

        m_Camera.ProcessInput(m_Window, 1.0f);

        m_Window.Update();
    }
}
