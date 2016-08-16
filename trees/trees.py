'''
Creat on Oct 5,2016
Decision Tree Source Code for Shin learning in Action Ch.3
@author: Shin BoboSha
'''

from math import log
import operator


def createDataSet():
	dataSet = [[1,1,'yes'],
		[1,1,'yes'],
		[1,0,'no'],
		[0,1,'no'],
		[0,1,'no']]
	labels = ['no surfacing','flippers']
	return dataSet,labels 

def calcShannonEnt(dataSet):
	numEntries = len(dataSet)
	labelCounts = {}
	for featVec in dataSet:
		currentLabel = featVec[-1]
		if currentLabel not in labelCounts.keys(): 
			labelCounts[currentLabel] = 0
		labelCounts[currentLabel] += 1
	shannonEnt = 0.0
	for key in labelCounts:
		prob = float(labelCounts[key])/numEntries
		shannonEnt -= prob * log(prob,2)
	return shannonEnt


def splitDataSet(dataSet,axis,value):
	retDataSet =[]
	for featVec in dataSet:
		if featVec[axis] == value:
			reducedFeatVec = featVec[:axis]
			reducedFeatVec.extend(featVec[axis+1:])  #[:axis] ex featVec[axis]
			retDataSet.append(reducedFeatVec)
	return retDataSet

def chooseBestFeatureToSplit(dataSet):
	numFeatures = len(dataSet[0]) -1
	baseEntropy = calcShannonEnt(dataSet)
	bestInfoGain = 0.0; bestFeature = -1
	for i in range(numFeatures):
		featList =[example[i] for example in dataSet]
		uniqueVals = set(featList)
		newEntropy
