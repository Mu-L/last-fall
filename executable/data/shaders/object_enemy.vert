/////////////////////////////////////////////////////
//*-----------------------------------------------*//
//| Part of Last Fall (https://www.maus-games.at) |//
//*-----------------------------------------------*//
//| Copyright (c) 2021 Martin Mauersics           |//
//| Released under the zlib License               |//
//*-----------------------------------------------*//
/////////////////////////////////////////////////////


varying vec3  v_v3Normal;
varying vec3  v_v3Relative;
varying float v_v1Length;


void VertexMain()
{
    gl_Position = coreObject3DPositionRaw();

    v_v3Normal   = coreQuatApply(u_v4Rotation, -a_v3RawNormal);
    v_v3Relative = (u_m4Camera * vec4(coreObject3DTransformRaw(), 1.0)).xyz;
    v_v1Length   = 1.5 - 1.0 * length(a_v3RawPosition);
}