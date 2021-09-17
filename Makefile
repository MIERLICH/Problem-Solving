build: gard.cpp
	g++ -Wall -Wextra -g  bani.cpp -o bani
	g++ -Wall -Wextra -g  gard.cpp -o gard
	g++ -Wall -Wextra -g  bomboane.cpp -o bomboane
	g++ -Wall -Wextra -g  sala.cpp -o sala

run-p1: bani
	./bani
run-p2: gard
	./gard
run-p3: bomboane
	./bomboane
run-p4: sala
	./sala
clean:
	rm -f bani gard bomboane sala
