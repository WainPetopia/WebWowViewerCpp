//
// Created by deamon on 09.07.18.
//

#ifndef AWEBWOWVIEWERCPP_M2MESHBUFFERUPDATER_H
#define AWEBWOWVIEWERCPP_M2MESHBUFFERUPDATER_H


#include <mathfu/glsl_mappings.h>
#include "../../../../gapi/UniformBufferStructures.h"
#include "M2MaterialInst.h"
#include "../../../persistance/header/skinFileHeader.h"
#include "../../../persistance/header/M2FileHeader.h"
#include "../m2Object.h"

class M2MeshBufferUpdater {
public:
    static bool updateBufferForMat(HGMesh &hmesh, M2Object &m2Object, M2MaterialInst &materialData, M2Data * m2Data, M2SkinProfile * m2SkinProfile);

    static void fillLights(const M2Object &m2Object, meshWideBlockPS &meshblockPS);

    static void fillTextureMatrices(const M2Object &m2Object, const M2MaterialInst &materialData, M2Data *m2Data,
                             M2SkinProfile *m2SkinProfile, mathfu::mat4 *uTextMat);

    static inline mathfu::vec3 &getFogColor(EGxBlendEnum blendMode, mathfu::vec3 &originalFogColor);
};


#endif //AWEBWOWVIEWERCPP_M2MESHBUFFERUPDATER_H
