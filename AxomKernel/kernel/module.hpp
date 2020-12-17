#include "types/linkedlist.hpp"

class Module
{
public:
    virtual void Init() = 0;
    virtual void DeInit() = 0;
};

class ModuleManager
{
public:
    ~ModuleManager()
    {
        for(size_t i = 0;i<m_Modules.length();i++)
        {
            m_Modules[i]->node->DeInit();
        }
    }

    Module* RegisterModule(Module* module)
    {
        m_Modules.AddNode(module);
        module->Init();
    }
private:
    LinkedList<Module> m_Modules;
};