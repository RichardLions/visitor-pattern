#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "visitorpattern_referencesemantics.h"
#include "visitorpatterntypes_referencesemantics.h"

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

            for(const std::unique_ptr<Type>& type : types)
            {
                if(const TypeA* const typeA{dynamic_cast<const TypeA*>(type.get())})
                {
                    REQUIRE(typeA->GetInt() == 0);
                    type->Accept(TypeOperationA{});
                    REQUIRE(typeA->GetInt() == 1);
                    type->Accept(TypeOperationB{});
                    REQUIRE(typeA->GetInt() == -1);
                }
                else if(const TypeB* const typeB{dynamic_cast<const TypeB*>(type.get())})
                {
                    REQUIRE(typeB->GetFloat() == 0.0f);
                    type->Accept(TypeOperationA{});
                    REQUIRE(typeB->GetFloat() == 1.0f);
                    type->Accept(TypeOperationB{});
                    REQUIRE(typeB->GetFloat() == -1.0f);
                }
                else
                {
                    REQUIRE(false);
                }
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
