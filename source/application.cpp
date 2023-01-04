///////////////////////////////////////////////
//*-----------------------------------------*//
//| Auto-Generated by the Core Engine       |//
//| Direct modifications may be overwritten |//
//*-----------------------------------------*//
///////////////////////////////////////////////
#include "main.h"


// ****************************************************************
// project settings
const coreChar* const CoreApp::Settings::Name                   = "Last Fall";
const coreChar* const CoreApp::Settings::IconPath               = DEFINED(_CORE_EMSCRIPTEN_) ? NULL : "data/textures/game_icon.png";
const coreChar* const CoreApp::Settings::CursorPath             = DEFINED(_CORE_EMSCRIPTEN_) ? NULL : "data/textures/default_cursor.png";
const coreBool        CoreApp::Settings::UserManagement         = false;
const coreUint8       CoreApp::Settings::Graphics::DepthSize    = 16u;
const coreUint8       CoreApp::Settings::Graphics::StencilSize  = 8u;
const coreBool        CoreApp::Settings::Graphics::AlphaChannel = false;
const coreBool        CoreApp::Settings::Graphics::DoubleBuffer = true;
const coreBool        CoreApp::Settings::Graphics::StereoRender = false;
const coreUint32      CoreApp::Settings::Platform::SteamAppID   = 0u;


// ****************************************************************
// setup the application
void CoreApp::Setup()
{
    Core::Manager::Resource->Load<coreModel>  ("default_sphere.md3",      CORE_RESOURCE_UPDATE_AUTO,   "data/models/default_sphere.md3", CORE_MODEL_LOAD_NO_CLUSTERS);
    Core::Manager::Resource->Load<coreModel>  ("object_cube.md3",         CORE_RESOURCE_UPDATE_AUTO,   "data/models/object_cube.md3", CORE_MODEL_LOAD_NO_CLUSTERS);
    Core::Manager::Resource->Load<coreModel>  ("object_enemy.md3",        CORE_RESOURCE_UPDATE_AUTO,   "data/models/object_enemy.md3", CORE_MODEL_LOAD_NO_CLUSTERS);
    Core::Manager::Resource->Load<coreModel>  ("object_player.md3",       CORE_RESOURCE_UPDATE_AUTO,   "data/models/object_player.md3", CORE_MODEL_LOAD_NO_CLUSTERS);

    Core::Manager::Resource->Load<coreTexture>("text.png",                CORE_RESOURCE_UPDATE_AUTO,   "data/textures/text.png");

    Core::Manager::Resource->Load<coreShader> ("fullscreen.vert",         CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/fullscreen.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("fullscreen.frag",         CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/fullscreen.frag");
    Core::Manager::Resource->Load<coreShader> ("object_door.vert",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_door.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("object_door.frag",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_door.frag");
    Core::Manager::Resource->Load<coreShader> ("object_door_inst.vert",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_door.vert", CORE_SHADER_OPTION_INSTANCING CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("object_door_inst.frag",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_door.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_enemy.vert",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_enemy.vert");
    Core::Manager::Resource->Load<coreShader> ("object_enemy.frag",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_enemy.frag");
    Core::Manager::Resource->Load<coreShader> ("object_enemy_inst.vert",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_enemy.vert", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_enemy_inst.frag",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_enemy.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_player.vert",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_player.vert");
    Core::Manager::Resource->Load<coreShader> ("object_player.frag",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_player.frag");
    Core::Manager::Resource->Load<coreShader> ("object_tile.vert",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_tile.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("object_tile.frag",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_tile.frag");
    Core::Manager::Resource->Load<coreShader> ("object_tile_inst.vert",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_tile.vert", CORE_SHADER_OPTION_INSTANCING CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("object_tile_inst.frag",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_tile.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("shadow_layer.vert",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_layer.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("shadow_layer.frag",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_layer.frag");
    Core::Manager::Resource->Load<coreShader> ("shadow_object.vert",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_object.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("shadow_object.frag",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_object.frag", CORE_SHADER_OPTION_NO_EARLY_DEPTH);
    Core::Manager::Resource->Load<coreShader> ("shadow_object_inst.vert", CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_object.vert", CORE_SHADER_OPTION_INSTANCING CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("shadow_object_inst.frag", CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/shadow_object.frag", CORE_SHADER_OPTION_INSTANCING CORE_SHADER_OPTION_NO_EARLY_DEPTH);

    Core::Manager::Resource->Load<coreFont>   ("sadanasquare.ttf",        CORE_RESOURCE_UPDATE_AUTO,   "data/fonts/sadanasquare.ttf");

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("fullscreen_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("fullscreen.vert")
        ->AttachShader("fullscreen.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_door_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_door.vert")
        ->AttachShader("object_door.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_door_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_door_inst.vert")
        ->AttachShader("object_door_inst.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_enemy_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_enemy.vert")
        ->AttachShader("object_enemy.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_enemy_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_enemy_inst.vert")
        ->AttachShader("object_enemy_inst.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_player_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_player.vert")
        ->AttachShader("object_player.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_tile_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_tile.vert")
        ->AttachShader("object_tile.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_tile_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_tile_inst.vert")
        ->AttachShader("object_tile_inst.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("shadow_layer_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("shadow_layer.vert")
        ->AttachShader("shadow_layer.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("shadow_object_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("shadow_object.vert")
        ->AttachShader("shadow_object.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("shadow_object_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("shadow_object_inst.vert")
        ->AttachShader("shadow_object_inst.frag")
        ->Finish();
}