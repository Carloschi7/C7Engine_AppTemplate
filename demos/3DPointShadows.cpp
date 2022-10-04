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
    lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 3 * sizeof(float)});
    lyt.PushAttribute({ 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 6 * sizeof(float) });

    m_Camera.SetVectors(glm::vec3(0.0f, 70.0f, 20.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
    m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
    m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
    m_Camera.SetMouseFunction(MouseForCameraFun);

    VertexManager mgr(vertices, sizeof(vertices), lyt);

    Shader shd("assets/shaders/point_shadow.shader");
    Shader shd_light("assets/shaders/basic_color.shader");
    shd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");
    shd_light.UniformMat4f(m_Camera.GetProjMatrix(), "proj");

    Texture tex("assets/images/parquet.jpg");
    
    glm::vec3 lightPos(0.0f, 70.0f, 20.0f);

    Entity obj(mgr);
    Entity obj2(mgr);
    Entity obj3(mgr);
    Entity obj4(mgr);
    Entity obj5(mgr);
    obj.Scale(100.0f);
    obj2.Translate(glm::vec3(3.0f, 55.0f, 0.0f));
    obj2.Rotate(glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    obj2.Scale(2.0f);
    obj3.Translate(glm::vec3(-3.0f, 55.0f, 0.0f));
    obj3.Rotate(glm::radians(60.0f), glm::vec3(1.0f, 0.0f, 1.0f));
    obj3.Scale(2.0f);
    obj4.Translate(glm::vec3(-8.0f, 55.0f, 0.0f));
    obj4.Rotate(glm::radians(70.0f), glm::vec3(0.0f, 1.0f, 1.0f));
    obj4.Scale(2.0f);
    obj5.Translate(lightPos);

    //Create depth buffer
    FrameBuffer depth_buffer(1000, 1000, FrameBufferType::DEPTH_ATTACHMENT);
    Shader depth_shd("assets/shaders/depth.shader");

    glm::mat4 lightProj = glm::perspective(glm::radians(45.0f), 1.0f, 1.0f, 100.0f);
    glm::mat4 lightView = glm::lookAt(lightPos, glm::vec3(0.0f, 50.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shd.UniformMat4f(lightProj * lightView, "light_space");
    shd.UniformVec3f(lightPos, "light_pos");
    depth_shd.UniformMat4f(lightProj * lightView, "space");

    m_Window.SetVsync(true);
    glEnable(GL_DEPTH_TEST);

    while (!m_Window.ShouldClose())
    {
        //Drawing to depth texture
        depth_buffer.Bind();
        glViewport(0, 0, 1000, 1000);
        glClear(GL_DEPTH_BUFFER_BIT);
        obj2.Draw(depth_shd);
        obj3.Draw(depth_shd);
        obj4.Draw(depth_shd);

        //Drawing to screen
        FrameBuffer::BindDefault();
        tex.Bind();
        shd.Uniform1i(0, "diffuse_texture");
        depth_buffer.BindFrameTexture(1);
        shd.Uniform1i(1, "depth_texture");
        glViewport(0, 0, 1920, 1080);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Camera.ProcessInput(m_Window, 1.0);

        shd.UniformVec3f(m_Camera.GetPosition(), "camera_pos");
        shd.UniformMat4f(m_Camera.GetViewMatrix(), "view");
        shd_light.UniformMat4f(m_Camera.GetViewMatrix(), "view");
        

        obj.Draw(shd);
        obj2.Draw(shd);
        obj3.Draw(shd);
        obj4.Draw(shd);
        obj5.Draw(shd_light);
        m_Window.Update();
    }
}
