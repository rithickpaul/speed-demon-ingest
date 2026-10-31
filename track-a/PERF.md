# Track A — Performance Report

## Test environment

- Platform: macOS (Docker Desktop)
- Language: C++17
- Compiler optimization: -O3 -DNDEBUG
- Input file: requests.log
- Input size: approximately 148 MiB

## Measured Docker run

Command:

    /usr/bin/time -l docker run --rm \
      -v "$(pwd)/data:/data" \
      -v "$(pwd)/output:/out" \
      speed-demon-ingest

Results:

- Elapsed time (real): 0.64 seconds
- User CPU time: 0.02 seconds
- System CPU time: 0.04 seconds
- Maximum resident set size reported by macOS: 32,899,072 bytes
  (approximately 31.4 MiB)
- Peak memory footprint reported by macOS: 15,090,384 bytes

Note: These measurements are from the macOS time command around
the Docker invocation. They include Docker command/container overhead
and are not an isolated measurement of the application inside the container.

## Correctness and output checks

- Input file successfully mounted into the container.
- Output file generated: output/summary.txt
- Output records: 120
- Hours represented: 24
- Endpoints per hour: 5

## Optimization techniques

- Buffered file input.
- Endpoint interning.
- Efficient hash-table lookup.
- Compact aggregation records.
- Sorting and grouped percentile calculation.
- Sequential output generation.

## Benchmark status

These are local test measurements, not official benchmark results.
Official benchmark scoring and performance should be measured separately.
