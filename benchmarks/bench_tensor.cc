#include <benchmark/benchmark.h>

static void BM_HorribleAdd(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(42 * 1337);
  }
}

BENCHMARK(BM_HorribleAdd);
BENCHMARK_MAIN();

