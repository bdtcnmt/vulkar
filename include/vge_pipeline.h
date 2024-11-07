#pragma once

#include "vge_device.h"

#include <string>
#include <vector>
namespace vge { 

struct PipelineConfigInfo {

};

class VgePipeline {
    public:
    VgePipeline(
        VgeDevice &device, 
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo);

    ~VgePipeline();

    VgePipeline(const VgePipeline&) = delete;
    void operator=(const VgePipeline&) = delete;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
    static std::vector<char> readFile(const std::string& filepath);

    void createGraphicsPipeline(
        const std::string& vertFilepath, 
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo);

    void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

    VgeDevice& vgeDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
};
}