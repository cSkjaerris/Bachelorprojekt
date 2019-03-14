cmake_minimum_required(VERSION 3.13)
project(FinanceSimulator)

set(CMAKE_CXX_STANDARD 17)

add_library(FinanceSimulator SHARED FinanceSimulator.cpp FinanceSimulator.h Security.cpp Security.h Statistician.cpp Statistician.h CornerPortfolio.h Investor.cpp Investor.h Trader.cpp Trader.h OrderSlip.cpp OrderSlip.h)