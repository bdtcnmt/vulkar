#include "vge_window.h"

#include <stdexcept>

namespace vge {
    
    VgeWindow::VgeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    VgeWindow::~VgeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VgeWindow::initWindow() {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW!");
        }
        
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

        if (!window) {
            throw std::runtime_error("Failed to create GLFW window!");
        }
    }

    void VgeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface");
        }
    }
} // namespace vge