#include "referencesemantics/visitorpatterntypes_referencesemantics.h"
#include "referencesemantics/visitorpattern_referencesemantics.h"

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
