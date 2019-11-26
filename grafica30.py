import numpy as np
import matplotlib.pyplot as plt 

datos= np.genfromtxt("dat30.dat")

plt.figure()
plt.plot(datos[0], datos[1])
plt.savefig("puntoa.png")