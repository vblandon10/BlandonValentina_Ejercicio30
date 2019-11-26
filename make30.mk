grafica.png : grafica.py dat30.dat
	python grafica.py 
dat30.dat : a.out
	./a.out > dat30.dat
a.out : BlandonValentina_Ejercicio30.cpp
	c++ BlandonValentina_Ejercicio30.cpp

    