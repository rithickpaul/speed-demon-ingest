FROM gcc:14-bookworm

WORKDIR /app

COPY main.cpp .

RUN g++ -std=c++17 -O2 main.cpp -o main

CMD ["/app/main"]