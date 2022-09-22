span: span.o main.o
	g++ -g span.o main.o -o span

main.o: main.cpp
	g++ -c -g main.cpp

span.o: span.h span.cpp
	g++ -c -g span.cpp

clean:
	rm *.o
	rm span

run: span
	./span

debug: span
	gdb queens

valgrind: span
	valgrind --leak-check=full ./span
