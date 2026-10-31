FROM gcc:15

WORKDIR /app

COPY main.cpp .

RUN g++ -O3 -std=c++17 -DNDEBUG -static -s -o solution main.cpp

ENTRYPOINT ["./solution", "--data", "/data", "--out", "/out"]
