# https://github.com/happylife10201020/SortingAlgorithm

all: compile run

compile: QuickSortAlgorithm.cpp
	g++ QuickSortAlgorithm.cpp -o QuickSortAlgorithm

run: QuickSortAlgorithm
	./QuickSorotAlgorithm

clean:
	rm QuickSortAlgorithm