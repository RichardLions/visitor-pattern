#include "valuesemantics/visitorpattern_valuesemantics.h"

namespace ValueSemantics
{
    void TypeOperationA::Visit(Type& type)
    {
        std::visit(TypeOperationA{}, type);
    }

    void TypeOperationA::operator()(TypeA& type) const
    {
        type.SetInt(1);
    }

    void TypeOperationA::operator()(TypeB& type) const
    {
        type.SetFloat(1.0f);
    }

    void TypeOperationB::Visit(Type& type)
    {
        std::visit(TypeOperationB{}, type);
    }

    void TypeOperationB::operator()(TypeA& type) const
    {
        type.SetInt(-1);
    }

    void TypeOperationB::operator()(TypeB& type) const
    {
        type.SetFloat(-1.0f);
    }
}
