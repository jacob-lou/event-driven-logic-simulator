#include <set>
#include <iostream>
#include <string>
#include <sstream>

#include "wire.h"

Wire::Wire(int id, std::string name) : m_state('X'), m_name(name), m_id(id)
{
    
}

char Wire::getState() const
{
    return m_state;
}

std::string Wire::getName() const
{
    return m_name;
}

int Wire::getId() const
{
    return m_id;
}

std::string Wire::setState(char state, uint64_t current_time)
{
    std::stringstream ss("");
    
    std::set<char> valid_states {'0','1','X'};

    if(valid_states.find(state) != valid_states.end())
    {
        if(m_state != state && m_name != "")
        {
            std::string uml_state("");
            if(state == '0') uml_state = "low";
            if(state == '1') uml_state = "high";
            if(state == 'X') uml_state = "{low,high}";
            ss << "W" << m_id << " is " << uml_state << std::endl;
        }
            
        m_state = state;
    }
    return ss.str();
}

void Wire::wireInput(int id, Wire* in) {
    // Implementation if needed
}