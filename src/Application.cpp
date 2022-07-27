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
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

	Layout lyt;
	lyt.PushAttribute({ 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0 });
	lyt.PushAttribute({ 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 3 * sizeof(float)});

	m_Camera.SetVectors(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	float fAspectRatio = float(m_Window.Width()) / float(m_Window.Height());
	m_Camera.SetPerspectiveValues(glm::radians(45.0f), fAspectRatio, 0.1f, 1000.0f);
	m_Camera.SetKeyboardFunction(KeyboardForCameraFun);
	m_Camera.SetMouseFunction(MouseForCameraFun);


	VertexManager manager(vertices, sizeof(vertices), lyt);
	

	Shader shd("assets/shaders/basic_texture.shader");
    Shader cubeshd("assets/shaders/basic_cubemap.shader");
    Texture tex("assets/images/saul_goodman.png", true);
    shd.Uniform1i(0, "texture1");

    std::vector<std::string> vec({ "assets/images/skybox/right.jpg",
                                    "assets/images/skybox/left.jpg",
                                    "assets/images/skybox/bottom.jpg",
                                    "assets/images/skybox/top.jpg",
                                    "assets/images/skybox/front.jpg",
                                    "assets/images/skybox/back.jpg"
        });
    CubeMap cube(vec, 500.0f);
    cube.BindTexture(1);
    cubeshd.Uniform1i(1, "skybox");
    

    Entity obj(manager);
    obj.Scale(20.0f);
    Entity cubeobj(cube.GetVertexManager());


	m_Window.SetVsync(true);
	glEnable(GL_DEPTH_TEST);

	while (!m_Window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_Camera.ProcessInput(m_Window, 1.0);
		
        shd.UniformMat4f(m_Camera.GetViewMatrix(), "view");
        shd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");
        cubeshd.UniformMat4f(glm::mat4(glm::mat3(m_Camera.GetViewMatrix())), "view");
        cubeshd.UniformMat4f(m_Camera.GetProjMatrix(), "proj");


        cubeobj.Draw(cubeshd);
		obj.Draw(shd);
		m_Window.Update();
	}
}

