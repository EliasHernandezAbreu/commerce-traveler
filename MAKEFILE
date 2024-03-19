b:
	mkdir -p bin
	g++ -o bin/tsp.out src/*

i:
	mkdir -p bin
	g++ -o bin/graph-generator.out graph-generator/main.cc

r:
	bin/tsp.out -o output -t 2 test

c:
	rm bin/*
