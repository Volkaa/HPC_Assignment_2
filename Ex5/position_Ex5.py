import numpy as np
import matplotlib.pyplot as plt


pos_x = [[],[],[]]
pos_y = [[],[],[]]

for i in range(100):
	array = []
	for j in range(3):
		pos_x[j].append(float(input()))
		pos_y[j].append(float(input()))

plt.scatter(pos_x[0],pos_y[0], c='b')
plt.scatter(pos_x[1],pos_y[1], c='y')
plt.scatter(pos_x[2],pos_y[2], c='r')

plt.xlabel('X')
plt.ylabel('Y')
plt.savefig('pos.png')