import numpy as np
import matplotlib.pyplot as plt

array = []
for j in range(5):
	a = float(input())
	array.append(a)
array = np.array(array)
ref = np.mean(array)

x = [1,2,4,6,8,10,12,16,20,24,28,32]
y_mean = []

for i in range(12):
	array = []
	for j in range(5):
		a = float(input())
		array.append(a)
	array = np.array(array)
	y_mean.append(ref/np.mean(array))

plt.plot(x,y_mean)
plt.xlabel('Number of threads')
plt.ylabel('Execution time ratio')
plt.savefig('Ex5_reduced.png')