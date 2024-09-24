#pragma once

#include <vector>
#include <variant>

namespace ValueSemantics
{
    class TypeA
    {
    public:
        [[nodiscard]] int32_t GetInt() const { return m_IntValue; }
        void SetInt(int32_t value) { m_IntValue = value; }
    private:
        int32_t m_IntValue{0};
    };

    class TypeB
    {
    public:
        [[nodiscard]] float_t GetFloat() const { return m_FloatValue; }
        void SetFloat(float_t value) { m_FloatValue = value; }
    private:
        float_t m_FloatValue{0.0f};
    };

    using Type = std::variant<TypeA, TypeB>;
    using Types = std::vector<Type>;
}
