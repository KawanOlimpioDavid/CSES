
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f BuildingRoads CountingRooms MessageRoute
