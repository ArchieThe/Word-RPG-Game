#Config
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS  :=

#Sources
COMMON_SRCS := player.cpp monster.cpp slime.cpp variant.cpp areas.cpp tower.cpp plains.cpp game.cpp
GAME_SRCS   := main.cpp $(COMMON_SRCS)
TEST_SRCS   := test_driver.cpp $(COMMON_SRCS)

GAME_OBJS := $(GAME_SRCS:.cpp=.o)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)

#target
all: game test

#Binaries
game: $(GAME_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#compile .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#targets
run: game
	./game

runtest: test
	./test

#Clean
clean:
	rm -f $(GAME_OBJS) $(TEST_OBJS) game test

#Mark phony targets
.PHONY: all run runtest clean