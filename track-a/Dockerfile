FROM gcc:15@sha256:eb5e64286ad47187b32bda75c6b6916166ecb41da56559b8b09e0001748d2cce AS build

WORKDIR /build

COPY main.cpp ./main.cpp

RUN g++ -O3 -std=c++17 -DNDEBUG -static -s -o /build/solution /build/main.cpp

FROM debian:13-slim

COPY --from=build /build/solution /app/solution

WORKDIR /app

ENTRYPOINT ["/app/solution", "--data", "/data", "--out", "/out"]
