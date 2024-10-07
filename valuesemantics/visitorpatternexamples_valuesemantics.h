#pragma once

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "valuesemantics/visitorpattern_valuesemantics.h"
#include "valuesemantics/visitorpatterntypes_valuesemantics.h"

namespace ValueSemantics
{
    TEST_CASE("Visitor Pattern - Value Semantics - Unit Tests")
    {
        Types types{};
        REQUIRE(types.size() == 0);

        SECTION("Visit Types with Operations")
        {
            types.emplace_back(TypeA{});
            types.emplace_back(TypeB{});
            REQUIRE(types.size() == 2);
            REQUIRE_NOTHROW(std::get<TypeA>(types[0]));
            REQUIRE_NOTHROW(std::get<TypeB>(types[1]));
            REQUIRE_THROWS(std::get<TypeB>(types[0]));
            REQUIRE_THROWS(std::get<TypeA>(types[1]));

            // Type A
            {
                Type& type{types[0]};
                const TypeA& typeA{std::get<TypeA>(type)};
                REQUIRE(typeA.GetInt() == 0);
                TypeOperationA::Visit(type);
                REQUIRE(typeA.GetInt() == 1);
                TypeOperationB::Visit(type);
                REQUIRE(typeA.GetInt() == -1);
            }

            // Type B
            {
                Type& type{types[1]};
                const TypeB& typeB{std::get<TypeB>(type)};
                REQUIRE(typeB.GetFloat() == 0.0f);
                TypeOperationA::Visit(type);
                REQUIRE(typeB.GetFloat() == 1.0f);
                TypeOperationB::Visit(type);
                REQUIRE(typeB.GetFloat() == -1.0f);
            }
        }
    }

    TEST_CASE("Visitor Pattern - Value Semantics - Benchmarks")
    {
        BENCHMARK("Benchmark")
        {
            constexpr uint32_t creationCount{100'000};
            Types types{};

            for(uint32_t i{0}; i != creationCount; ++i)
            {
                types.emplace_back(TypeA{});
                types.emplace_back(TypeB{});
            }

            for(Type& type : types)
            {
                TypeOperationA::Visit(type);
                TypeOperationB::Visit(type);
            }
        };
    }
}
