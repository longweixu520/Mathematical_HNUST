import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams['axes.unicode_minus'] = False

def func(x):
    return 0.5*x**5+x**4+x**3-5*x**2-4*x+1

#递归算法实现 费内存 费时间 重复运算中间变量
def Newton(l,r):
    global xList, bList
    if l == r:
        return func(xList[l])
    left = Newton(l, r-1)
    right= Newton(l+1,r)
    numb = (left - right)/(xList[l]-xList[r])
    if l == 0:
        bList[r] = numb
    return numb
#循环法求y值
def Newton_function(n,x):
    global bList
    yList = list(np.ones(10))
    for i in range(n-1):
        temp = 1
        j = i
        while j > -1:
            temp *= (x - xList[j])
            j-=1
        yList[i+1] = temp
    numb = 0   
    for i in range(n):
        numb  = numb + bList[i]*yList[i]
    return numb
        
global xList, bList
xList = list()
bList = list(np.zeros(100))
n = int(input('请输入要点数：\n'))
for i in range(n):
    xList.append(np.random.uniform(-2.5,3))
xList.sort()
bList[0] = func(xList[0])
Newton(0, len(xList)-1)

line = np.arange(-3,3.5,0.1)
plt.figure(figsize=(8,18))
plt.subplot(3,1,1)
plt.title("原函数和选取的点")
plt.plot(line,func(line),color = 'g',label = '原函数')
plt.scatter(np.array(xList),func(np.array(xList)),color = 'r')
plt.legend(['原函数'])
plt.grid()
plt.subplot(3,1,2)
plt.title("牛顿插值法拟合曲线")
plt.grid()
plt.plot(line,Newton_function(n,line),color = 'b',label='拟合函数')
plt.scatter(np.array(xList),func(np.array(xList)),color = 'r')
plt.legend(['拟合函数'])
plt.subplot(3,1,3)
plt.title("原函数和拟合函数的重合度")
plt.grid()
plt.plot(line,func(line),color = 'g',label = '原函数')
plt.scatter(np.array(xList),func(np.array(xList)),color = 'r')
plt.plot(line,Newton_function(n,line),color = 'b',label = '拟合函数')
plt.legend(['原函数','拟合函数'])
'''
最好效果为6个点！
'''

