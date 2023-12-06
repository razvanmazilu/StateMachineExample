#include "CoolStates.h"
#include "EventGenerator.h"
#include "ACoolStateMachine.h"


    void StartState::Execute(ACoolStateMachine* pOwner)
    {
        std::cout<<"StartState: Executing\n";
        if(EventGenerator::GetInstance()->Generate(1))
        {
            pOwner->ChangeState(pOwner->m_state1);
        }
    }

    void State1::Execute(ACoolStateMachine* pOwner)
    {
        std::cout<<"State1: Executing\n";
        int event = EventGenerator::GetInstance()->Generate(2);
        if(event == 1)
        {
            pOwner->ChangeState(pOwner->m_state2);
        }
        else if(event == 0)
        {
            pOwner->ChangeState(pOwner->m_stateN);
        }
        
    }

    void State2::Execute(ACoolStateMachine* pOwner)
    {
        std::cout<<"State2: Executing\n";
        if(EventGenerator::GetInstance()->Generate(1))
        {
            pOwner->ChangeState(pOwner->m_state1);
        }
    }

    void StateN::Execute(ACoolStateMachine* pOwner)
    {
        pOwner->Done();
        std::cout<<"StateN: Terminated\n";
    }
