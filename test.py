t=range(0,10000)
fil="error"
b='0'
for name in t:
	a=str(name)
	f=open(fil,"w")
	f.write(a)
	fil=fil+b
	b=b+'1'
f.close()