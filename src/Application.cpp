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
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,   0.0f, 0.0f,
                       
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
                       
        -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
                       
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
                       
        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,   1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    0.0f, -1.0f, 0.0f,   1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, -1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, -1.0f, 0.0f,   0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,   0.0f, 1.0f,
                       
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    Layout lyt;
    lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0 });
    //lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 3 * sizeof(float) });
    lyt.PushAttribute({ 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 6 * sizeof(float)});

    m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
    m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
    m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
    m_Camera.SetMouseFunction(MouseForCameraFun);

    VertexManager manager(vertices, sizeof(vertices), lyt);

    Shader shd("assets/shaders/basic_texture.shader");
    shd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");
    
    
    Texture tex("assets/images/parquet.jpg");
    tex.Bind();
    shd.Uniform1i(0, "texture1");
    

    Entity obj(manager);
    Entity obj2(manager);
    Entity obj3(manager);
    Entity obj4(manager);
    obj.Scale(100.0f);
    obj2.Translate(glm::vec3(3.0f, 55.0f, 0.0f));
    obj2.Rotate(glm::radians(30.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    obj2.Scale(2.0f);
    obj3.Translate(glm::vec3(-3.0f, 55.0f, 0.0f));
    obj3.Rotate(glm::radians(60.0f), glm::vec3(1.0f, 0.0f, 1.0f));
    obj3.Scale(2.0f);
    obj4.Translate(glm::vec3(-8.0f, 55.0f, 0.0f));
    obj4.Rotate(glm::radians(70.0f), glm::vec3(0.0f, 1.0f, 1.0f));
    obj4.Scale(2.0f);

    m_Window.SetVsync(true);
    glEnable(GL_DEPTH_TEST);

    while (!m_Window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_Camera.ProcessInput(m_Window, 1.0);

        shd.UniformMat4f(m_Camera.GetViewMatrix(), "view");
        

        obj.Draw(shd);
        obj2.Draw(shd);
        obj3.Draw(shd);
        obj4.Draw(shd);
        m_Window.Update();
    }
}
