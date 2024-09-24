#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "referencesemantics/visitorpattern_referencesemantics.h"
#include "referencesemantics/visitorpatterntypes_referencesemantics.h"

namespace ReferenceSemantics
{
    TEST_CASE("Visitor Pattern - Reference Semantics - Unit Tests")
    {
        Types types{};
        REQUIRE(types.size() == 0);

        SECTION("Visit Types with Operations")
        {
            types.push_back(std::make_unique<TypeA>());
            types.push_back(std::make_unique<TypeB>());
            REQUIRE(types.size() == 2);
            REQUIRE(dynamic_cast<const TypeA*>(types[0].get()));
            REQUIRE(dynamic_cast<const TypeB*>(types[1].get()));
            REQUIRE_FALSE(dynamic_cast<const TypeB*>(types[0].get()));
            REQUIRE_FALSE(dynamic_cast<const TypeA*>(types[1].get()));

            // Type A
            {
                Type* const type{types[0].get()};
                const TypeA* const typeA{static_cast<const TypeA*>(type)};
                REQUIRE(typeA->GetInt() == 0);
                type->Accept(TypeOperationA{});
                REQUIRE(typeA->GetInt() == 1);
                type->Accept(TypeOperationB{});
                REQUIRE(typeA->GetInt() == -1);
            }

            // Type B
            {
                Type* const type{types[1].get()};
                const TypeB* const typeB{static_cast<const TypeB*>(type)};
                REQUIRE(typeB->GetFloat() == 0.0f);
                type->Accept(TypeOperationA{});
                REQUIRE(typeB->GetFloat() == 1.0f);
                type->Accept(TypeOperationB{});
                REQUIRE(typeB->GetFloat() == -1.0f);
            }
        }
    }

    TEST_CASE("Visitor Pattern - Reference Semantics - Benchmarks")
    {
        BENCHMARK("Benchmark")
        {
            constexpr uint32_t creationCount{100'000};
            Types types{};

            for(uint32_t i{0}; i != creationCount; ++i)
            {
                types.push_back(std::make_unique<TypeA>());
                types.push_back(std::make_unique<TypeB>());
            }

            for(const std::unique_ptr<Type>& type : types)
            {
                type->Accept(TypeOperationA{});
                type->Accept(TypeOperationB{});
            }
        };
    }
}
