#include <iostream>

#include <GLFW/glfw3.h>
#include "DemoConfig.h"
//#include <boost/python.hpp>
#include "DemoConfig.h"



#ifdef USE_ADDER
#include <adder.h>
#endif




int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
#ifdef USE_ADDER
    std::cout << add(5.0f, 6.0f) << std::endl;
#endif
    std::cout << argv[0] << " Version " << Demo_VERSION_MAJOR << "." << Demo_VERSION_MINOR << std::endl;




    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        //draw();

        // Update animation
        //animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}