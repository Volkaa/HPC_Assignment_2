import numpy as np
import matplotlib.pyplot as plt

x = [1,2,4,8,12,16,20,24,28,32]
y_mean = []


for i in range(10):
	a = float(input())
	y_mean.append(a)

plt.plot(x,y_mean)
plt.xlabel('Number of threads')
plt.ylabel('Execution time (s)')
plt.savefig('Ex3_4.png')