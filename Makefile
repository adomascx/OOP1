CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17

build_d: konteineriai/deque/OOP1.cpp konteineriai/deque/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/OOP1_D.exe konteineriai/deque/OOP1.cpp konteineriai/deque/bibliotekos/*.cpp

test_d: konteineriai/deque/testavimas.cpp konteineriai/deque/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/testavimas_D.exe konteineriai/deque/testavimas.cpp konteineriai/deque/bibliotekos/*.cpp

build_l: konteineriai/list/OOP1.cpp konteineriai/list/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/OOP1_L.exe konteineriai/list/OOP1.cpp konteineriai/list/bibliotekos/*.cpp

test_l: konteineriai/list/testavimas.cpp konteineriai/list/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/testavimas_L.exe konteineriai/list/testavimas.cpp konteineriai/list/bibliotekos/*.cpp

build_v: konteineriai/vector/OOP1.cpp konteineriai/vector/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/OOP1_V.exe konteineriai/vector/OOP1.cpp konteineriai/vector/bibliotekos/*.cpp

test_v: konteineriai/vector/testavimas.cpp konteineriai/vector/bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/testavimas_V.exe konteineriai/vector/testavimas.cpp konteineriai/vector/bibliotekos/*.cpp

clean:
	del build\