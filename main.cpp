#include <catch2/catch_session.hpp>

#include "valuesemantics/visitorpatternexamples_valuesemantics.h"
#include "referencesemantics/visitorpatternexamples_referencesemantics.h"

int main(const int argc, const char* const argv[])
{
    return Catch::Session().run(argc, argv);
}
