#define M64P_PLUGIN_PROTOTYPES
#include <m64p_common.h>
#include <m64p_plugin.h>
#include "Constants.h"

using namespace JaegerNet::Mupen64Plus::Input;

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

    return m64p_error::M64ERR_SUCCESS;
}

EXPORT m64p_error CALL PluginShutdown(void)
{
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

}

EXPORT void CALL GetKeys(int /*Control*/, BUTTONS* /*Keys*/)
{

}

EXPORT void CALL InitiateControllers(CONTROL_INFO /*ControlInfo*/)
{

}

EXPORT void CALL ReadController(int /*Control*/, unsigned char* /*Command*/)
{

}

EXPORT void CALL SDL_KeyDown(int /*keymod*/, int /*keysym*/)
{

}

EXPORT void CALL SDL_KeyUp(int /*keymod*/, int /*keysym*/)
{

}

EXPORT void CALL RenderCallback(void)
{

}
