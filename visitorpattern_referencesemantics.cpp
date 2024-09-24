#include "visitorpattern_referencesemantics.h"
#include "visitorpatterntypes_referencesemantics.h"

namespace ReferenceSemantics
{
    void TypeOperationA::Visit(TypeA& type) const
    {
        type.SetInt(1);
    }

    void TypeOperationA::Visit(TypeB& type) const
    {
        type.SetFloat(1.0f);
    }

    void TypeOperationB::Visit(TypeA& type) const
    {
        type.SetInt(-1);
    }

    void TypeOperationB::Visit(TypeB& type) const
    {
        type.SetFloat(-1.0f);
    }
}
