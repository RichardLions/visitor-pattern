#pragma once

#include <vector>
#include <memory>

namespace ReferenceSemantics
{
    class TypeVisitor;

    class Type
    {
    public:
        virtual ~Type() = default;
        virtual void Accept(const TypeVisitor& visitor) = 0;
    };

    using Types = std::vector<std::unique_ptr<Type>>;

    class TypeA final : public Type
    {
    public:
        void Accept(const TypeVisitor& visitor) override;
        [[nodiscard]] int32_t GetInt() const { return m_IntValue; }
        void SetInt(int32_t value) { m_IntValue = value; }
    private:
        int32_t m_IntValue{0};
    };

    class TypeB final : public Type
    {
    public:
        void Accept(const TypeVisitor& visitor) override;
        [[nodiscard]] float_t GetFloat() const { return m_FloatValue; }
        void SetFloat(float_t value) { m_FloatValue = value; }
    private:
        float_t m_FloatValue{0.0f};
    };
}
