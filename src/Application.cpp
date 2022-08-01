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
    lyt.PushAttribute({ 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 6 * sizeof(float)});

    Layout lyt2;
    lyt2.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0 });
    lyt2.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 3 * sizeof(float)});
    lyt2.PushAttribute({ 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 6 * sizeof(float) });

    m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
    m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
    m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
    m_Camera.SetMouseFunction(MouseForCameraFun);

    VertexManager manager2attr(vertices, sizeof(vertices), lyt);
    VertexManager manager3attr(vertices, sizeof(vertices), lyt2);

    Shader shd("assets/shaders/directional_shadow.shader");
    shd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");
    
    Texture tex("assets/images/parquet.jpg");
    tex.Bind();
    shd.Uniform1i(0, "texture1");
    

    Entity obj(manager3attr);
    Entity obj2(manager3attr);
    Entity obj3(manager3attr);
    Entity obj4(manager3attr);
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

    //Create depth buffer
    uint32_t i = 0;
    FrameBuffer depth_buffer(1000, 1000, FrameBufferType::DEPTH_ATTACHMENT);
    Shader depth_shd("assets/shaders/depth.shader");

    glm::vec3 lightPos(0.0f, 30.0f, 0.0f);
    glm::mat4 lightProj = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 100.0f);
    glm::mat4 lightView = glm::lookAt(glm::vec3(0.0f, 80.0f, 0.01f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
        obj.Draw(depth_shd);
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

        //shd.UniformMat4f(lightProj, "proj");
        //shd.UniformMat4f(lightView, "view");
        shd.UniformVec3f(m_Camera.GetPosition(), "light_pos");
        shd.UniformMat4f(m_Camera.GetViewMatrix(), "view");
        

        obj.Draw(shd);
        obj2.Draw(shd);
        obj3.Draw(shd);
        obj4.Draw(shd);
        m_Window.Update();
    }
}
