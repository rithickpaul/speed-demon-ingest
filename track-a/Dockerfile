FROM gcc:13

WORKDIR /app

COPY track-a/main.cpp ./main.cpp

RUN g++ -O3 -std=c++17 -DNDEBUG -Wall -Wextra -pedantic main.cpp -o ingest

ENTRYPOINT ["/app/ingest"]
CMD ["--data", "/data", "--out", "/out"]
