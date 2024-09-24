#include "visitorpatterntypes_referencesemantics.h"
#include "visitorpattern_referencesemantics.h"

namespace ReferenceSemantics
{
    void TypeA::Accept(const TypeVisitor& visitor)
    {
        visitor.Visit(*this);
    }

    void TypeB::Accept(const TypeVisitor& visitor)
    {
        visitor.Visit(*this);
    }
}
