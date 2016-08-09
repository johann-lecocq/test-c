run:compile 
	./main

compile:
	#Pour compiler la bibliothèque dynamique
	gcc -fPIC -c biblio.c -o biblio.o
	gcc -shared biblio.o -o biblio.so
	
	#Ajout de ldl pour les fonctions dlopen et dlsym
	#Ajout de lcunit pour les tests unitaires Cunit
	gcc -c main.c
	gcc main.o -o main.out -ldl -lcunit

clean:
	rm main *.o *.so
