from matplotlib import lines
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

p1 = matplotlib.pyplot
p2 = matplotlib.pyplot
p3 = matplotlib.pyplot
p4 = matplotlib.pyplot
p5 = matplotlib.pyplot
p6 = matplotlib.pyplot


file = open('NewFile.txt', 'r')
f = file.readlines()

graphCount = 0
lineCount = 0 # This will keep the line count for using in iteration

graphx = []

for x in range(1, 11):
    graphx.append(pow(10,6) * x)

#Graph1 -- quadratic
graph1y = []

#Graph2 -- log n * n
graph2y = []

#Graph3 -- linear
graph3y = []

#Graph4 -- quadratic
graph4y = []

#Graph5 -- log n * n
graph5y = []

#Graph6 -- linear
graph6y = []

x = 0
for file in f:
    if x % 6 == 0:
        graph1y.append(int(file[:-1]))
    
    elif x % 6 == 1:
        graph2y.append(int(file[:-1]))

    elif x % 6 == 2:
        graph3y.append(int(file[:-1]))

    elif x % 6 == 3:
        graph4y.append(int(file[:-1]))

    elif x % 6 == 4:
        graph5y.append(int(file[:-1]))

    elif x % 6 == 5:
        graph6y.append(int(file[:-1]))

    x = x + 1   

print(graphx)
print(graph5y)


p4.title("10^4 arr2 length Algorithm 3")
p4.xlabel("Arr1 Length") 
p4.plot(graphx, graph6y, 'ro')
p4.savefig("p6dot.png")
p4.show()



