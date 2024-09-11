#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "vge_window.h"
#include "vge_pipeline.h"

namespace vge {
class VulkanApp {
    public:
        void run();
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

    private:
        void initVulkan();
        vge::VgeWindow vgeWindow{WIDTH, HEIGHT, "yell and scream"};
        void mainLoop();
        void cleanup();
        void createInstance();

        GLFWwindow* window;
        VkInstance instance;

        VgePipeline vgePipelin{"../shaders/simple_shader.vert.spv", "../shaders/simple_shader.frag.spv"};
};
} // namespace vge