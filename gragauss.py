import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("seg.txt")
tmax = datos[:,0].max()
tmin = datos[:,0].min()
xi = datos[datos[:,0]==tmin, 1]
ui = datos[datos[:,0]==tmin, 2]
xf = datos[datos[:,0]==tmax, 1]
uf = datos[datos[:,0]==tmax, 2]
plt.plot(xi, ui, label='inicial')
plt.plot(xf, uf, '--', label='final')
plt.legend()
plt.xlabel("x")
plt.ylabel("u")
plt.title('segundo orden')
plt.savefig('segundo.png')
