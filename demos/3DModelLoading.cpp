#include "../application/Application.h"

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
    m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f,0.0f, -1.0f));
    float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
    m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
    m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
    m_Camera.SetMouseFunction(MouseForCameraFun);

    m_Models.emplace_back("assets/models/man/FinalBaseMesh.obj");

    //Shader setup
    m_Shaders.emplace_back("assets/shaders/basic_lighting.shader");
    m_Shaders[0].UniformMat4f(m_Camera.GetProjMatrix(), "proj");

    //A random texture for now
    m_Textures.emplace_back("assets/images/parquet.jpg");
    m_Textures[0].Bind(0);
    m_Shaders[0].Uniform1i(0, "diffuse_texture");

    glEnable(GL_DEPTH);
    while (!m_Window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Shaders[0].UniformMat4f(m_Camera.GetViewMatrix(), "view");
        m_Models[0].Draw(m_Shaders[0]);

        m_Camera.ProcessInput(m_Window, 1.0f);

        m_Window.Update();
    }
}
