import numpy as np
import matplotlib.pyplot as plt

labels = ['static', 'dynamic', 'guided']
static = [19265.3,19311.9,19309.7,19249.3,19366.0]
dynamic = [778.6,776.3,777.3,839.3,1004.6]
guided = [18903.4,18982.0,18962.1]
val = [np.mean(static), np.mean(dynamic), np.mean(guided)]

fig, ax = plt.subplots()

plt.bar(np.arange(len(val)), val)

plt.ylabel('Average best rate (MB/s')
plt.xlabel('Schedules')
ax.set_xticks(np.arange(len(val)))
ax.set_xticklabels(labels)
plt.savefig('Ex2_2.png')