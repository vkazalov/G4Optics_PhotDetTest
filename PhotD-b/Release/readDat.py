print "START!"

from ROOT import *
import matplotlib.pyplot as plt
import numpy as np
from scipy import signal


r1 =TRandom();

SpcEG4_v1=np.loadtxt("h:/work/TScinPhotDet/PhotD-b/Release/TScinPhotDet_EMSnd.dat",usecols=[0], unpack=True)
SpcEG4_v2=np.loadtxt("h:/work/TScinPhotDet/PhotD-b/Release/TScinPhotDet_EmSNdOpt4.dat",usecols=[0], unpack=True)
SpcEG4=np.loadtxt("h:/work/TScinPhotDet/PhotD-b/Release/TScinPhotDet_LowEn.dat",usecols=[0], unpack=True)





plt.figure(1)
plt.plot(SpcEG4_v1[1:200],'r',linewidth = 1.5,label="EmSnd")
plt.plot(SpcEG4_v2[1:200],'b',linewidth = 1.5,label="EmSndOpt4")
plt.plot(SpcEG4[1:200],'k',linewidth = 1.5,label="EmLowE")
plt.grid(True)
plt.legend()



plt.show()



