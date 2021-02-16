import matplotlib.pyplot as plt

data = []

with open('out.txt', 'r') as f:
    data = f.readlines()

for i in range(len(data)):
    data[i] = list(map(float, data[i].split()))
    plt.scatter(data[i][0], data[i][1])
    plt.scatter(data[i][2], data[i][3])

plt.show()