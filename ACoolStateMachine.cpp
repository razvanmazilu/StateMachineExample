#include "ACoolStateMachine.h"
#include "CoolStates.h"

    ACoolStateMachine::ACoolStateMachine()
    {
        m_startState = new StartState();
        m_state1 = new State1();
        m_state2 = new State2();
        m_stateN = new StateN();
        StateMachine<ACoolStateMachine>::Init(this,m_startState);

    }
    ACoolStateMachine::~ACoolStateMachine()
    {
        delete m_startState;
        delete m_state1;
        delete m_state2;
        delete m_stateN;
    }

    void ACoolStateMachine::Update()
    {
        StateMachine<ACoolStateMachine>::Update();
    }