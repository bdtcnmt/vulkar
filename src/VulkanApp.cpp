#include "VulkanApp.h"
#include <stdexcept>
#include <iostream>
#include <vector>

namespace vge {
void VulkanApp::run() {
    initVulkan();
    mainLoop();
    cleanup();
}

void VulkanApp::initVulkan() {
    createInstance();
}

void VulkanApp::createInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Application";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // Print the number of required GLFW extensions
    std::cout << "GLFW requires " << glfwExtensionCount << " extensions:\n";

    // Print each GLFW extension name
    for (uint32_t i = 0; i < glfwExtensionCount; i++) {
        std::cout << '\t' << glfwExtensions[i] << '\n';
    }

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Vulkan instance!");
    }

    // List available vulkan extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "Available Extensions:\n";
    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    } 
}

void VulkanApp::mainLoop() {
    while (!vgeWindow.shouldClose()) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup() {
    vkDestroyInstance(instance, nullptr);
    // glfwDestroyWindow(window);
    glfwTerminate();
}
} // namespace vge