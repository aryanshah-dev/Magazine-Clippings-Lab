
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <string>
#include <vector>

using namespace std;

bool canCreateNote(
    const string& note,
    const vector<string>& articles
);

TEST_CASE("Magazine Clippings Benchmarks") {
    vector<string> articles1(10, string(100, 'a'));
    string note1(500, 'a');

    vector<string> articles2(50, string(100, 'a'));
    string note2(2500, 'a');

    vector<string> articles3(100, string(100, 'a'));
    string note3(5000, 'a');

    vector<string> articles4(250, string(100, 'a'));
    string note4(12500, 'a');

    vector<string> articles5(500, string(100, 'a'));
    string note5(25000, 'a');

    vector<string> articles6(1000, string(100, 'a'));
    string note6(50000, 'a');

    BENCHMARK("1000 article characters") {
        return canCreateNote(note1, articles1);
    };

    BENCHMARK("5000 article characters") {
        return canCreateNote(note2, articles2);
    };

    BENCHMARK("10000 article characters") {
        return canCreateNote(note3, articles3);
    };

    BENCHMARK("25000 article characters") {
        return canCreateNote(note4, articles4);
    };

    BENCHMARK("50000 article characters") {
        return canCreateNote(note5, articles5);
    };

    BENCHMARK("100000 article characters") {
        return canCreateNote(note6, articles6);
    };
}
