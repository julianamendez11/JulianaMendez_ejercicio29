from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
from matplotlib import style
from matplotlib import cm
import numpy as np

data = np.loadtxt("onda.dat")

fig=plt.figure(figsize=(15,5))
ax1 = fig.add_subplot(111,projection='3d')
x, y=np.mgrid[0:data.shape[0], 0:data.shape[1]]
print(np.shape(x), np.shape(y), np.shape(data))
ax1.plot_surface(x/100, y/100, data, cmap=cm.rainbow)
plt.xlabel("Tiempo (segundos)")
plt.ylabel("Posición (metros)")



plt.show()
plt.legend()
plt.savefig("plot.png")