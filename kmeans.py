#coding=utf-8
__anthor__='Haoyang Li'
'''K-means算法的实现
样本数据集采用datesaet16.mat中的ex_3th.mat'''

import numpy as np
import time
import matplotlib.pyplot as plt
import scipy.io as sio
import math
from mpl_toolkits.mplot3d import Axes3D

#计算欧式距离(Euclidean distance)
def eucl_distance(vec_1,vec_2):
    return math.sqrt(np.sum(np.power(vec_1-vec_2,2)))

#s随机初始化聚类中心(inicialize centroids)
def init_centroids(data_set,k):
    data_num,dimension = data_set.shape
    centroids = np.zeros((k,dimension))
    for i in range(k):
        index = int(np.random.uniform(0,data_num))
        centroids[i,:] = data_set[index,:]
    return  centroids

def k_means(data_set,k):
    data_num = data_set.shape[0]
    clus_assiment = np.zeros((data_num, 1))
    clus_adjusted = True
    #初始化聚类
    centroids = init_centroids(data_set,k)
    while clus_adjusted:
        clus_adjusted=False
        #对于每个样本
        for i in range(data_num):
            min_dist = 1000000
            min_index = 0
            #对于每个聚类中心
            for j in range(k):
                #找到最近的聚类
                distance = eucl_distance(centroids[j,:],data_set[i,:])
                if distance < min_dist:
                    min_dist = distance
                    min_index = j
            #更新点的聚类
            if clus_assiment[i,0] != min_index:
                clus_adjusted = True
                clus_assiment[i] = min_index
        #更新聚类
        for j in range(k):
            points = data_set[np.nonzero(clus_assiment[:, 0] == j)[0]]
            centroids[j, :] = np.mean(points, axis=0)
    print('K-means聚类完成~')
    print(data_num)
    nation = ['China', 'Japan', 'Iran', 'South Korea', 'Saudi', 'Iraq', 'Qatar', 'United Arab Emirates',
              'Uzbekistan', 'Thailand', 'Vietnam', 'Oman', 'Bahrain', 'North Korea', 'Indonesia']
    # 打印
    for i in range(k):
        print('第', i, '类')
        for j in range(data_num):
            if int(clus_assiment[j,0]) == int(i):
                print(nation[j])
    #绘图
    colors = ['b', 'g', 'r', 'k', 'c', 'm', 'y', '#e24fff', '#524C90', '#845868']
    ax = plt.subplot(111, projection='3d')
    for i in range(data_num):
        mark_index = int(clus_assiment[i,0])
        ax.scatter(data_set[i,0],data_set[i,1],data_set[i,2],color=colors[mark_index])
        ax.text(data_set[i,0],data_set[i,1],data_set[i,2], [nation[i]])
        #print(data_set[i,0],data_set[i,1],data_set[i,2],clus_assiment[i,0])
    plt.show()

#测试
d = sio.loadmat('dataset16.mat')
data = (d['ex_3th'])
k=3
k_means(data,k)