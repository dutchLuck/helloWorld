helloWorld: helloWorld.c
	cc -Wall -o helloWorld helloWorld.c

check:
	./helloWorld

clean:
	rm helloWorld

