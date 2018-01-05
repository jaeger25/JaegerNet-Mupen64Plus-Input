#define M64P_PLUGIN_PROTOTYPES

#include <array>
#include <JaegerNetServer/JaegerNetServer.h>
#include <m64p/m64p_common.h>
#include <m64p/m64p_plugin.h>
#include "Constants.h"

using namespace JaegerNet;
using namespace JaegerNet::Mupen64Plus::Input;

std::array<CONTROL*, 4> MupenControllers;

EXPORT m64p_error CALL PluginGetVersion(m64p_plugin_type* PluginType, int* PluginVersion, int* APIVersion, const char** PluginNamePtr, int* Capabilities)
{
    if (PluginType)
    {
        *PluginType = m64p_plugin_type::M64PLUGIN_INPUT;
    }
    if (PluginVersion)
    {
        *PluginVersion = JaegerNetPluginVersion;
    }
    if (APIVersion)
    {
        *APIVersion = InputPluginApiVersion;
    }
    if (PluginNamePtr)
    {
        *PluginNamePtr = JaegerNetPluginName;
    }
    if (Capabilities)
    {
        *Capabilities = JaegerNetPluginCapabilities;
    }

    return m64p_error::M64ERR_SUCCESS;
}

EXPORT m64p_error CALL PluginStartup(m64p_dynlib_handle /*CoreLibHandle*/, void* /*Context*/, void(* /*DebugCallback*/)(void *, int, const char *))
{
    // TODO: Logging / DebugCallback
    // TODO: Port from config
    JaegerNet_StartServer(31337);

    return m64p_error::M64ERR_SUCCESS;
}

EXPORT m64p_error CALL PluginShutdown(void)
{
    JaegerNet_StopServer();

    return m64p_error::M64ERR_SUCCESS;
}

EXPORT int CALL RomOpen(void)
{
    return true;
}

EXPORT void CALL RomClosed(void)
{
}

EXPORT void CALL ControllerCommand(int /*Control*/, unsigned char* /*Command*/)
{
    // Unused
}

EXPORT void CALL GetKeys(int /*Control*/, BUTTONS* /*Keys*/)
{

}

EXPORT void CALL InitiateControllers(CONTROL_INFO ControlInfo)
{
    constexpr size_t NumControllers = 4;

    for (int i = 0; i < NumControllers; i++)
    {
        MupenControllers[i] = ControlInfo.Controls + i;
        MupenControllers[i]->Plugin = PLUGIN_NONE;
        MupenControllers[i]->Present = true;
    }
}

EXPORT void CALL ReadController(int /*Control*/, unsigned char* /*Command*/)
{
    // Unused
}

EXPORT void CALL SDL_KeyDown(int /*keymod*/, int /*keysym*/)
{
    // Unused
}

EXPORT void CALL SDL_KeyUp(int /*keymod*/, int /*keysym*/)
{
    // Unused
}

EXPORT void CALL RenderCallback(void)
{
}
