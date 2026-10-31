# Track A — Ingest

A C++17 log-processing program that aggregates request logs by UTC hour and endpoint.

## Features

- Reads request logs from `requests.log`.
- Groups records by UTC hour and endpoint.
- Calculates request counts.
- Calculates p50, p95, and p99 latency percentiles.
- Counts HTTP 5xx errors.
- Calculates error rate in parts per million (PPM).
- Sorts output by hour and endpoint.
- Uses buffered input and efficient aggregation structures.

## Input format

Each input record follows this format:

    YYYY-MM-DDTHH:MM:SS.ffffffZ METHOD ENDPOINT STATUS LATENCY_US

Example:

    2026-01-01T20:07:01.777572Z GET /api/gamma 200 2267

## Output format

The program writes `summary.txt` with one record per UTC hour and endpoint.

Each record contains:

    timestamp endpoint requests p50 p95 p99 errors error_ppm

Latency percentile values are in microseconds.

An HTTP status from 500 through 599 is counted as an error.

## Build with Docker

From the repository root:

    docker build -f track-a/Dockerfile -t speed-demon-ingest .

## Run with Docker

Place `requests.log` inside the `data/` directory, then run:

    mkdir -p data output

    docker run --rm \
      -v "$(pwd)/data:/data" \
      -v "$(pwd)/output:/out" \
      speed-demon-ingest

The generated report will be available at:

    output/summary.txt

## Current test

The local Docker test processed a 148 MB input file and generated 120 summary records covering 24 hours and 5 endpoints.

This is a local test result, not an official benchmark score.
