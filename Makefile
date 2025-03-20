CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17

OOP1: OOP1.cpp bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/OOP1.exe OOP1.cpp bibliotekos/apdorojimas.cpp bibliotekos/ivedimas.cpp bibliotekos/isvedimas.cpp bibliotekos/main_lib.cpp

testavimas: testavimas.cpp bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o build/testavimas.exe testavimas.cpp bibliotekos/apdorojimas.cpp bibliotekos/ivedimas.cpp bibliotekos/isvedimas.cpp bibliotekos/main_lib.cpp

clean:
	del build\