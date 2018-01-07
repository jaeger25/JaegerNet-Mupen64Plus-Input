#include "Player.h"

using namespace JaegerNet;
using namespace JaegerNet::Mupen64Plus::Input;

Player::Player(int playerNumber) :
    m_playerNumber(playerNumber)
{
    m_playerConnectedToken = JaegerNet_RegisterPlayerConnectedCallback(
        std::bind(&Player::OnPlayerConnected, this, std::placeholders::_1));
}

Player::~Player()
{
    JaegerNet_UnregisterPlayerConnectedCallback(m_playerConnectedToken);
}

int Player::PlayerNumber() const
{
    return m_playerNumber;
}

const ControllerState Player::NextControllerState()
{
    if (m_controllerStates.empty())
    {
        return {};
    }

    auto nextState = m_controllerStates.front();
    if (m_controllerStates.size() > 1)
    {
        m_controllerStates.pop();
    }

    return nextState;
}

void Player::OnPlayerConnected(int playerNumber)
{
    if (playerNumber == m_playerNumber)
    {
        JaegerNet_RegisterControllerStateChangedCallback(playerNumber,
            std::bind(&Player::OnControllerStateChanged, this, std::placeholders::_1, std::placeholders::_2));
    }
}

void Player::OnControllerStateChanged(int /*playerNumber*/, const ControllerState controllerState)
{
    m_controllerStates.push(controllerState);
}
