/////////////////////////////////////////////////////
//*-----------------------------------------------*//
//| Part of Last Fall (https://www.maus-games.at) |//
//*-----------------------------------------------*//
//| Copyright (c) 2021 Martin Mauersics           |//
//| Released under the zlib License               |//
//*-----------------------------------------------*//
/////////////////////////////////////////////////////


void FragmentMain()
{
    float v1Value = coreTexture2D(0, v_av2TexCoord[0]).r;

    gl_FragColor = vec4(u_v4Color.rgb, u_v4Color.a * v1Value);
}