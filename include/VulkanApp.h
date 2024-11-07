#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "vge_window.h"
#include "vge_pipeline.h"
#include "vge_device.h"

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
        VgeDevice vgeDevice{vgeWindow};
        VgePipeline vgePipeline{
            vgeDevice, 
            "../shaders/simple_shader.vert.spv", 
            "../shaders/simple_shader.frag.spv", 
            VgePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
} // namespace vge