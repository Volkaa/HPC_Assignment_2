import numpy as np
import matplotlib.pyplot as plt

x = [1,2,4,8,12,16,20,24,28,32]
y_mean = []
y_std = []

for i in range(10):
	array = []
	for j in range(10):
		a = float(input())
		array.append(a)
	array = np.array(array)
	y_mean.append(np.mean(array))
	y_std.append(np.std(array))
plt.errorbar(x,y_mean,y_std)
plt.xlabel('Number of threads')
plt.ylabel('Execution time (s)')
plt.savefig('Ex3_4.png')