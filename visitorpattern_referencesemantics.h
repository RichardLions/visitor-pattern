#pragma once

namespace ReferenceSemantics
{
    class TypeA;
    class TypeB;

    class TypeVisitor
    {
    public:
        virtual ~TypeVisitor() = default;
        virtual void Visit(TypeA& type) const = 0;
        virtual void Visit(TypeB& type) const = 0;
    };

    class TypeOperationA final : public TypeVisitor
    {
        void Visit(TypeA& type) const override;
        void Visit(TypeB& type) const override;
    };

    class TypeOperationB final : public TypeVisitor
    {
        void Visit(TypeA& type) const override;
        void Visit(TypeB& type) const override;
    };
}
