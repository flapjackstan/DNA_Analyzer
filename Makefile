camargo: dna_analyzer.o reader.o
	g++ dna_analyzer.o reader.o -o camargo.out

dna_analyzer.o: dna_analyzer.cpp
	g++ -c dna_analyzer.cpp

reader.o: reader.cpp reader.h
	g++ -c reader.cpp

clean: 
	rm *.o output