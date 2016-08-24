'''
try:
	f = open('H:/learngit/learngit/new.txt','r')
	print(f.read())
finally:
	if f:
		f.close()
		'''
		
with open('new1.txt','r',encoding = 'utf-8') as f:
	print(f.read())