#pragma once
#include <queue>
#include <JaegerNetServer\JaegerNetServer.h>

namespace JaegerNet::Mupen64Plus::Input
{
    class Player
    {
    public:
        Player(int playerNumber);
        ~Player();

        int PlayerNumber() const;
        const ControllerState NextControllerState();

    private:
        void OnControllerStateChanged(int playerNumber, const JaegerNet::ControllerState controllerState);
        void OnPlayerConnected(int playerNumber);

        int m_playerNumber;
        JaegerNet::EventRegistrationToken m_controllerStateChangedToken;
        JaegerNet::EventRegistrationToken m_playerConnectedToken;
        std::queue<const ControllerState> m_controllerStates;
    };
}
