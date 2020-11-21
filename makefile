all: app.exe

Encrypter.dll: clean
	gcc --shared -o Encrypter.dll Encryption.c

Encrypter.dylib: clean
	gcc --shared -o Encrypter.dylib encryption.c

Encrypter.so: clean
	gcc --shared -o Encrypter.so encryption.c

app.exe: clean
	gcc -o app.exe encryption.c

clean:
	rm -f *.o *.exe *.dll *.dylib *.so
