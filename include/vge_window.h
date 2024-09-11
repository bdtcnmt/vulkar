#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace vge {

    class VgeWindow {
        public:
            VgeWindow(int w, int h, std::string name);
            ~VgeWindow();

            VgeWindow(const VgeWindow &) = delete;
            VgeWindow &operator=(const VgeWindow &) = delete;

            bool shouldClose() { return glfwWindowShouldClose(window); }

            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        private:
            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
} // namespace vge