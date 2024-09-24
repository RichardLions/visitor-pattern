#pragma once

#include <span>

#include "valuesemantics/visitorpatterntypes_valuesemantics.h"

namespace ValueSemantics
{
    class TypeOperationA final
    {
    public:
        static void Visit(Type& type);
        void operator()(TypeA& type) const;
        void operator()(TypeB& type) const;
    };

    class TypeOperationB
    {
    public:
        static void Visit(Type& type);
        void operator()(TypeA& type) const;
        void operator()(TypeB& type) const;
    };
}
