all: compile run

compile: Catalog.h Catalog.cpp Music.h Music.cpp Book.h Book.cpp Movie.h Movie.cpp 
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++ -std=c++11 main.cpp -o test
	

run:
	@echo "-------------------------------------------"
	@echo "Running the tests.."
	@echo "============================================================="
	./test
	
	
	@echo "============================================================="
	@echo "Output.txt is created."
