'''
import matplotlib.pyplot as plt
import numpy as np
#plt.plot([1,2,3,4])
#plt.plot([1,2,3,4],[1,4,9,16],'ro')
#plt.axis([0,6,0,20])
plt.ylabel('number')
t = np.arange(0.,5.,0.2)
plt.plot(t,t,'r--',t,t**2,'bs',t,t**3,'g^')
#for idx,color in enumerate("rgbyck"):
	#plt.subplot(321+idx,axisbg=color)
plt.subplot(321,axisbg='red')
plt.show()
'''
'''
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
plt.figure(1) #创建图表1
plt.figure(2) #创建图表2
ax1 = plt.subplot(211) #在图表2中创建子图1
ax2 = plt.subplot(212) #在图表2中创建子图2
x = np.linspace(0,3,100) #???
for i in xrange(5):
	plt.figure(1) #选择图表1
	plt.plot(x,np.exp(i*x/3))
	plt.sca(ax1) # 选择图表2的子图1
	plt.plot(x,np.sin(i*x))
	plt.sca(ax2) # 选择图表2的子图2
	plt.plot(x,np.cos(i*x))
plt.show()
'''
'''
import matplotlib.pyplot as plt
X1 = range(0,50)
Y1 = [num**2 for num in X1] #y = x^2
X2 = [0,1]
Y2 = [0,1] # y = x
#Fig = plt.figure(figsize=(8,4))  #Create a figure instance
Ax1 = plt.subplot(211)   #Create a 'axes' instance in the figure
Ax2 = plt.subplot(212)
Ax1.plot(X1,Y1)	#Create a Line2D instance in the axes
Ax2.plot(X2,Y2)
plt.show()
'''
import numpy as np
import pylab as pl

x = [1,2,3,4,5] #Make an array of x values
y = [1,4,9,16,25] #Make an array of y values for each x value
pl.plot(x,y,'b') #use pylab to plot x and y
pl.title('plot of y vs. x') #give plot a title
pl.xlabel('x axis') #set axis limits
pl.ylabel('y axis')
pl.show() #show the plot on the screen