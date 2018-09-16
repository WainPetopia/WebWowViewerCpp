//
// Created by deamon on 05.06.18.
//

#ifndef WEBWOWVIEWERCPP_GMESH_4X_H
#define WEBWOWVIEWERCPP_GMESH_4X_H

#include "../GVertexBufferBindingsGL4x.h"
#include "../textures/GBlpTextureGL4x.h"
#include "../../interface/meshes/IMesh.h"
#include "../GDeviceGL4x.h"

class GMeshGL4x : public IMesh {
    friend class GDeviceGL4x;
protected:
    explicit GMeshGL4x(IDevice &device,
                   const gMeshTemplate &meshTemplate
    );

public:
    ~GMeshGL4x() override;
    HGUniformBuffer getVertexUniformBuffer(int slot) override;
    HGUniformBuffer getFragmentUniformBuffer(int slot) override;
    EGxBlendEnum getGxBlendMode() override;
    bool getIsTransparent() override;
    MeshType getMeshType()  override;
    void setRenderOrder(int renderOrder) override;

    void setEnd(int end) override;
public:
    void setM2Object(void * m2Object) override { throw "Not Implemented";};
    void setLayer(int layer) override { throw "Not Implemented";};
    void setPriorityPlane(int priorityPlane) override { throw "Not Implemented";};
    void setQuery(const HGOcclusionQuery &query) override { throw "Not Implemented";};
    void setSortDistance(float distance) override { throw "Not Implemented";};

protected:
    MeshType m_meshType;
private:

    HGShaderPermutation m_shader;

    HGUniformBuffer m_vertexUniformBuffer[3] = {nullptr, nullptr, nullptr};
    HGUniformBuffer m_fragmentUniformBuffer[3] = {nullptr, nullptr, nullptr};

    int8_t m_depthWrite;
    int8_t m_depthCulling;
    int8_t m_backFaceCulling;
    int8_t m_triCCW = 1;
    EGxBlendEnum m_blendMode;
    bool m_isTransparent;


    uint8_t m_colorMask = 0;

    int m_element;

    void *m_indirectPointer = nullptr;

private:
    IDevice &m_device;
};


#endif //WEBWOWVIEWERCPP_GMESH_4X_H
