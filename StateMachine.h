#pragma once
#include "State.h"
#include <iostream>
template<class T>
class StateMachine
{
    T *m_pOwner;
    State<T>*m_pCurrentState;
    bool m_firstRun = true;
public:
    StateMachine() { std::cout<<"State machine created\n"; }
    ~StateMachine() { std::cout<<"State machine destroyed\n"; }

    void Init(T*pOwner, State<T>*initialState);
    void Update();
    void ChangeState(State<T>*newState);
};

template<class T>
inline void StateMachine<T>::Init(T*pOwner, State<T>*initialState)
{
    m_pCurrentState = initialState;
    m_pOwner = pOwner;
    std::cout<<"State machine ready\n";
}
template<class T>
void StateMachine<T>::Update()
{
    if(m_firstRun)
    {
        m_firstRun = false;
        m_pCurrentState -> Enter(m_pOwner);
    }
    m_pCurrentState->Execute(m_pOwner);
}

template<class T>
void StateMachine<T>::ChangeState(State<T>*newState)
{
    m_pCurrentState->Exit(m_pOwner);
    m_pCurrentState = newState;
    m_pCurrentState->Enter(m_pOwner);

}