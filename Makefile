objects=Exercises_4_5_6_7.o TREEImplementation.o STACKImplementation.o
headers=TREEInterface.h TREETypes.h STACKInterface.h STACKTypes.h

Exercises_4_5_6_7: $(objects)
	gcc $(objects) -o Exercises_4_5_6_7

Exercises_4_5_6_7.o: Exercises_4_5_6_7.c $(headers)
	gcc -c Exercises_4_5_6_7.c

TREEImplementation.o: TREEImplementation.c $(headers)
	gcc -c TREEImplementation.c

STACKImplementation.o: STACKImplementation.c $(headers)
	gcc -c STACKImplementation.c

clean:
	rm Exercises_4_5_6_7 $(objects)
