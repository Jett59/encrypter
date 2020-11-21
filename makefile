all: app.exe

app.exe: clean
	gcc -o app.exe *.c

clean:
	rm -f *.o *.exe
