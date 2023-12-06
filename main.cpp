#include<iostream>
#include"ACoolStateMachine.h"

int main() 
{
    std::cout<<"hello State Machine"<< std::endl;
    ACoolStateMachine stateMachine;
    //Loop
    while(!stateMachine.HasDone()) 
    {
        stateMachine.Update();
    }

    return 0;
}