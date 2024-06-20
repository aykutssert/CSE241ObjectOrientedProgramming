all: compile run

compile: World.h World.cpp Robot.h Robot.cpp Bulldozer.h Bulldozer.cpp Humanic.h Humanic.cpp OptimusPrime.h OptimusPrime.cpp Roomba.h Roomba.cpp Robocop.h Robocop.cpp 
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++ -std=c++11 main.cpp  World.cpp Robot.cpp Bulldozer.cpp Humanic.cpp OptimusPrime.cpp Roomba.cpp Robocop.cpp -o test
	

run:
	@echo "-------------------------------------------"
	@echo "Running the tests.."
	@echo "============================================================="
	./test
	
	
	@echo "============================================================="
	@echo "Completed tests.."
