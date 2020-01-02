cmake_minimum_required(VERSION 3.15)
project(langGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(langGame main.cpp Questions.cpp Questions.h Scorer.cpp Scorer.h Game.cpp Game.h)