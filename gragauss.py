import numpy as np
import matplotlib.pyplot as plt

tmax = data[:,0].max()
tmin = data[:,0].min()

xi = data[data[:,0]==tmin, 1]
ui = data[data[:,0]==tmin, 2]

xf = data[data[:,0]==tmax, 1]
uf = data[data[:,0]==tmax, 2]

plt.plot(xi, ui, label='inicial')
plt.plot(xf, uf, '--', label='final')
plt.legend()
plt.xlabel("x")
plt.ylabel("u")
plt.title('segundo orden')
plt.savefig('segundo.png')
