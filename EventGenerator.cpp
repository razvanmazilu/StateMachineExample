#include "EventGenerator.h"

EventGenerator* EventGenerator::GetInstance()
{
    static EventGenerator s_instance;
    return &s_instance;
}

int EventGenerator::Generate(int num)
{
    if(m_counter == 0)
    {
        m_counter = rand()%MAX_COUNTER+1;
        if(num>1)
        {
            return rand()%num;
        }
        return 1;
    }
    else
    {
        m_counter--;
    }
}