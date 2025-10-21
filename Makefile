test: test_driver.cpp player.cpp monster.cpp slime.cpp variant.cpp areas.cpp tower.cpp plains.cpp game.cpp
	g++ test_driver.cpp player.cpp monster.cpp slime.cpp variant.cpp areas.cpp tower.cpp plains.cpp game.cpp -o test
	./test

game: main.cpp player.cpp monster.cpp slime.cpp variant.cpp areas.cpp tower.cpp plains.cpp game.cpp 
	g++ main.cpp player.cpp monster.cpp slime.cpp variant.cpp areas.cpp tower.cpp plains.cpp game.cpp -o game