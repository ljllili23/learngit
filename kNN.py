'''
2016.08.01

kNN: k Nearest Neighbors  
Input:		inX: vector to compare to existing dataset (1xN)
			dataSet: size m data set of know vectors (NxM)
			labels: data set labels (1xM vector)
			k: number of meighbors to use for comparison (should be an odd number)

Output:		the most popular class label

@author: ShinBoboSha
'''
from numpy import*
import operator
from os import listdir

def classify0(inX,dataSet,labels,k):
	dataSetSize = dataSet.shape[0]
	diffMat = tile(inX,(dataSetSize,1)) - dataSet
	sqDiffMat = diffMat ** 2
	sqDistances = sqDiffMat.sum(axis=1)
	distances = sqDistances ** 0.5
	sortedDistIndicies = distances.argsort()
	classCount = {}
	for i in range(k):
		voteIlabel = labels[sortedDistIndicies[i]]
		classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
		sortedClassCount = sorted(classCount.iteritems(),key = operator.itemgetter(1),reverse=True)
		return sortedClassCount[0][0]

def creatDataSet():
	group = arrray([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]])
	labels = ['A','A','B','B']
	return group,labels


def file2matrix(filename):
	fr = open(filename)
	numberOfLines = len(fr.readlines())
	returnMat = zeros((numberOfLines,3))
	classLabelVector = []
	fr = open(filename)
	index = 0
	for line in fr.readlines():
		line = line.strip()
		listFromLine = line.split('\t')
		returnMat[index,:] = listFromLine[0:3]
		classLabelVector.append(int(listFromLine[-1]))
		index += 1
	return returnMat,classLabelVector
		

def autoNorm(dataSet):
	minVals = dataSet.min(0)
	maxVals = dataSet.max(0)  # canshu0 shide hanshu lie not hang 
	ranges = maxVals -minVals
	normdataSet = zeros(shape(dataSet))
	m = dataSet.shape[0]
	normDataSet = dataSet - tile(minVals,(m,1))
	normDataSet = normdataSet/tile(ranges,(m,1))
	return normdataSet,ranges,minVals
	

