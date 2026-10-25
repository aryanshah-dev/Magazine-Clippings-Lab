
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace std;

bool canCreateNote(
    const string& note,
    const vector<string>& articles
);

TEST_CASE("Basic magazine clipping tests") {
    REQUIRE(canCreateNote("a", {"a"}));
    REQUIRE(canCreateNote("a", {"ab"}));
    REQUIRE(canCreateNote("a", {"a", "b"}));
    REQUIRE(canCreateNote("abc", {"a", "b", "c"}));

    REQUIRE(canCreateNote("The bird is red!", {
        "I write a lot.",
        "To and fro.",
        "Here be deadly dragons!"
    }));

    REQUIRE_FALSE(canCreateNote("a", {"b"}));
    REQUIRE_FALSE(canCreateNote("a", {"bc"}));
    REQUIRE_FALSE(canCreateNote("abc", {"a", "b", "d"}));
    REQUIRE_FALSE(canCreateNote("aba", {"ab"}));

    REQUIRE_FALSE(canCreateNote("The bird is red!", {
        "I write a lot.",
        "To and fro.",
        "Here be deadly dragons"
    }));
}

TEST_CASE("Case and whitespace tests") {
    REQUIRE(canCreateNote("HELLO world", {"hello", "WORLD"}));
    REQUIRE(canCreateNote("a b c", {"abc"}));
    REQUIRE(canCreateNote("  a  ", {"a"}));
    REQUIRE(canCreateNote("", {"anything"}));
    REQUIRE(canCreateNote("anything", {""}) == false);
}

TEST_CASE("Punctuation tests") {
    REQUIRE(canCreateNote("Hi!", {"h", "I!"}));
    REQUIRE_FALSE(canCreateNote("Hi!", {"Hi"}));
    REQUIRE_FALSE(canCreateNote("Hello?", {"Hello!"}));
    REQUIRE(canCreateNote("Wait...", {"Wait..."}));
}

TEST_CASE("Character count tests") {
    REQUIRE(canCreateNote("aaa", {"aa", "a"}));
    REQUIRE_FALSE(canCreateNote("aaa", {"aa"}));
    REQUIRE(canCreateNote("book", {"bo", "ok"}));
    REQUIRE_FALSE(canCreateNote("letter", {"leter"}));
}

TEST_CASE("Multiple article tests") {
    REQUIRE(canCreateNote("computer science", {
        "computer", "science"
    }));

    REQUIRE(canCreateNote("hello world", {
        "hel", "lo wo", "rld"
    }));

    REQUIRE_FALSE(canCreateNote("hello world!", {
        "hello", "world"
    }));
}