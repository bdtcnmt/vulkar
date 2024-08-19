#ifndef VULKAN_APP_H
#define VULKAN_APP_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanApp {
    public:
        void run();

    private:
        void initWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();

        GLFWwindow* window;
        VkInstance instance;
};

#endif // VULKAN_APP_H