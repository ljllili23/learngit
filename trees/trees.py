'''
Creat on Oct 5,2016
Decision Tree Source Code for Shin learning in Action Ch.3
@author: Shin BoboSha
'''

from math import log
import operator

def calcShannonEnt(dataSet):
	numEntries = len(dataSet)
	labelCounts = {}
	for featVec in dataSet:
		currentlabel = featVec[-1]
		if currentLabel not in labelCounts.keys(): labelCounts[currentLavel] = 0
		labelCounts[currentLabel] += 1
	shannonEnt = 0.0
	for key in labelCounts:
		prob = float(labelCounts[key])/numEntries
		shannonEnt -= prob * log(prob,2)
	return shannonEnt