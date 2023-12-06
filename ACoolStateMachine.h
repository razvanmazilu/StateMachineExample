#pragma once
#include "StateMachine.h"

class ACoolStateMachine: public StateMachine<ACoolStateMachine>
{
    State<ACoolStateMachine>*m_startState;
    State<ACoolStateMachine>*m_state1;
    State<ACoolStateMachine>*m_state2;
    State<ACoolStateMachine>*m_stateN;

    bool m_done;

public:
    ACoolStateMachine();
    ~ACoolStateMachine();

    void Update();
    void Done() { m_done = true; }
    bool HasDone() {return m_done;}

    friend class StartState;
    friend class State1;
    friend class State2;
    friend class StateN;
};