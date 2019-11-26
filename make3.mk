grafica.png : grafica30.py dat30.dat
	python grafica30.py 
dat30.dat : a.out
	./a.out > dat30.dat
a.out : BlandonValentina_Ejercicio30.cpp
	c++ BlandonValentina_Ejercicio30.cpp

    