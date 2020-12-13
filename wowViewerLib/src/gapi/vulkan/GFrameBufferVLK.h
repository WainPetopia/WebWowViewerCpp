//
// Created by Deamon on 12/11/2020.
//

#ifndef AWEBWOWVIEWERCPP_GFRAMEBUFFERVLK_H
#define AWEBWOWVIEWERCPP_GFRAMEBUFFERVLK_H

#include <vector>
#include "../interface/IFrameBuffer.h"
#include "../interface/textures/ITexture.h"
#include "GDeviceVulkan.h"

class GFrameBufferVLK : public IFrameBuffer {
public:
    GFrameBufferVLK(IDevice &device, std::vector<ITextureFormat> textureAttachments, ITextureFormat depthAttachment, int width, int height);
    ~GFrameBufferVLK() override;

    void readRGBAPixels(int x, int y, int width, int height, void *data) override;
    HGTexture getAttachment(int index) override;
    HGTexture getDepthTexture() override;
    void bindFrameBuffer() override;
    void copyRenderBufferToTexture() override;

    VkRenderPass m_renderPass;
    VkFramebuffer m_frameBuffer;

    static void iterateOverAttachments(std::vector<ITextureFormat> textureAttachments, std::function<void(int i, VkFormat textureFormat)> callback);


private:
    GDeviceVLK &mdevice;

    std::vector<HGTexture> attachmentTextures;
    HGTexture depthTexture;

    std::vector<VkFormat> attachmentFormats;

    int m_width = 0;
    int m_height = 0;
};



#endif //AWEBWOWVIEWERCPP_GFRAMEBUFFERVLK_H
