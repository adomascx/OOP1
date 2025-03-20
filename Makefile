CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17

OOP1: OOP1.cpp Bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o Build/OOP1.exe OOP1.cpp Bibliotekos/apdorojimas.cpp Bibliotekos/ivedimas.cpp Bibliotekos/isvedimas.cpp Bibliotekos/main_lib.cpp

testavimas: testavimas.cpp Bibliotekos/*.cpp
	$(CXX) $(CXXFLAGS) -o Build/testavimas.exe testavimas.cpp Bibliotekos/apdorojimas.cpp Bibliotekos/ivedimas.cpp Bibliotekos/isvedimas.cpp Bibliotekos/main_lib.cpp

clean:
	del Build\OOP1.exe Build\testavimas.exe