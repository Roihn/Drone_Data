import numpy as np
import matplotlib.pyplot as plt
import math


t=np.linspace(0,36,37)
f1=np.multiply(t,7750)
plt.plot(t,f1,'lime')
f2=np.multiply(t,500)+35000
plt.plot(t,f2,'darkgreen')
plt.stem([140/29],[140*7750/29],basefmt='',linefmt='--')
plt.stem([36],[36*7750],basefmt='',linefmt='--')
plt.stem([36],[36*500+35000],basefmt='',linefmt='--')
axes = plt.gca()
axes.set_xlim([0,37])
axes.set_ylim([0,8000*36])
x_ticks = [0,140/29,36]#label of M-index
plt.ylabel("Cost")
plt.xlabel("Month")

plt.xticks(x_ticks,[0,4.82,36],fontsize=10)


plt.show()