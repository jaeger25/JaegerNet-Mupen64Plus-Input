#define M64P_PLUGIN_PROTOTYPES

#include <array>
#include <JaegerNetServer/JaegerNetServer.h>
#include <m64p/m64p_common.h>
#include <m64p/m64p_plugin.h>
#include "Constants.h"
#include "Player.h"

using namespace JaegerNet;
using namespace JaegerNet::Mupen64Plus::Input;

// N64 input values are between -80 and 80.
// SDL input values are between -32,768 and 32,768
int8_t SdlAxisValueToN64AxisValue(int16_t sdlAxisValue, bool invert)
{
    constexpr int16_t SdlUnitsPerN64Unit = 409;
    auto n64AxisValue = static_cast<int8_t>(sdlAxisValue / SdlUnitsPerN64Unit);
    return invert ? -n64AxisValue : n64AxisValue;
}

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

EXPORT void CALL GetKeys(int Control, BUTTONS* Keys)
{
    static std::array<Player, 4> Players = { {1, 2, 3, 4} };

    if (Control < 0 || Control > 3)
    {
        std::terminate();
    }

    ControllerState controllerState = Players[Control].NextControllerState();
    Keys->A_BUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::A);
    Keys->B_BUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::B);
    Keys->START_BUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::Start);
    Keys->L_TRIG = static_cast<bool>(controllerState.ButtonState & ControllerButton::Trigger_Left);
    Keys->R_TRIG = static_cast<bool>(controllerState.ButtonState & ControllerButton::Trigger_Right);
    Keys->Z_TRIG = static_cast<bool>(controllerState.ButtonState & ControllerButton::Trigger_Z);
    Keys->L_CBUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::C_Left);
    Keys->U_CBUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::C_Up);
    Keys->R_CBUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::C_Right);
    Keys->D_CBUTTON = static_cast<bool>(controllerState.ButtonState & ControllerButton::C_Down);

    Keys->L_DPAD = static_cast<bool>(controllerState.DPadButtonState & ControllerDPadButton::Left);
    Keys->U_DPAD = static_cast<bool>(controllerState.DPadButtonState & ControllerDPadButton::Up);
    Keys->R_DPAD = static_cast<bool>(controllerState.DPadButtonState & ControllerDPadButton::Right);
    Keys->D_DPAD = static_cast<bool>(controllerState.DPadButtonState & ControllerDPadButton::Down);

    Keys->X_AXIS = SdlAxisValueToN64AxisValue(controllerState.AxisXValue, false);
    Keys->Y_AXIS = SdlAxisValueToN64AxisValue(controllerState.AxisYValue, true);
}

EXPORT void CALL InitiateControllers(CONTROL_INFO ControlInfo)
{
    constexpr size_t NumControllers = 4;

    for (int i = 0; i < NumControllers; i++)
    {
        CONTROL* pController = ControlInfo.Controls + i;
        pController->Plugin = PLUGIN_NONE;
        pController->Present = true;
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
