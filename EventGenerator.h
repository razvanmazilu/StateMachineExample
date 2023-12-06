#pragma once
#include <iostream>
#define MAX_COUNTER 5
class EventGenerator
{
    int m_counter;
    EventGenerator() 
    {
        //inital value
        m_counter = rand() % MAX_COUNTER + 1;
    }
public:
    static EventGenerator *GetInstance();
    void CleanUp(){}

    int Generate(int evenNum);
};