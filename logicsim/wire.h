#ifndef WIRE_H
#define WIRE_H
#include <string>
#include <cstdint>

class Wire 
{
    public:
        Wire(int, std::string name="");
        char getState() const;
        std::string setState(char state, uint64_t);
        void wireInput(int id, Wire* in);
        std::string getName() const;
        int getId() const;
        
    private:
        char m_state;
        std::string m_name;
        int m_id;
};

#endif