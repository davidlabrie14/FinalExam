import os
import time
import sys 
import csv 


temp = eval (int(sys.argv[1]))
file = open('sensor_temp.txt', 'r')

Sum = 0;
UTemp = 0; 
numTemp = 0;
for line in file.read().split('\n')[2:-1]:
     numTemp += 1
     Sum += eval(line)
     if eval(line) < temp:
        UTemp += 1

avg = Sum / numTemp

print(" CPE 422/522 Final Exam File name of sensor temperatures:{}" .format(sys.argv[0]))
print(" Number of temp below{}" .format(temp)) 
print(":{}" .format (Utemp)) 
print("Average Temperature:{}" .format(avg))

