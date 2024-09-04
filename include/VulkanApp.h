#ifndef VULKAN_APP_H
#define VULKAN_APP_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "vge_pipeline.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class VulkanApp {
    public:
        void run();

    private:
        void initWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();
        void createInstance();

        GLFWwindow* window;
        VkInstance instance;

        VgePipeline vgePipelin{"../shaders/simple_shader.vert.spv", "../shaders/simple_shader.frag.spv"};
};

#endif // VULKAN_APP_H