import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random


EP1Seq = [
[86.696,	86.055,		85.364,		85.425,		83.508,		83.106,		85.347,		83.528,		85.978,		87.382,		85.999,		85.544,		85.75,		85.76  ],
[171.29,	169.856,	171.119,	169.898,	171.214,	169.83,		171.036,	171.495,	172.792,	171.955,	170.86,		170.295,	172.382,	172.727],
[8240.89,	8301.76,	8193.78,	8174.59,	8188.2,		8161.23,	8222.26,	8172.86,	8206.92,	8200.92,	8236.88,	8192.29,	8183.28,	8160.97],
[40582.3,	40623.6,	40714.9,	40447,		40461.5,	40422.6,	40558.7,	40553.9,	40646.4,	40435.5,	39383.8,	39408.8,	39468.5,	39517.8],
[78831.4,	80671.1,	81038.8,	81837.1,	81091.8,	81292.3,	81236.7,	79093,		82047.1,	81312.8,	81353.7,	81238.1,	81264.5,	82012.4],
[211715,	208188,		208776,		220687,		220578,		205377,		244793,		232870,		226241,		219832,		220524,		224368,		214117,		203868]
]

EP1Paralel1 = [
[235.7,		235.06,		234.36,		234.42,		232.51,		232.11,		234.35,		232.53,		234.98,		236.38,		235,		234.54,		234.75,		236.76 ],
[320.29,	318.86,		320.12,		318.9,		320.21,		318.83,		320.04,		320.5,		321.79,		320.96,		319.86,		319.29,		321.38,		172.727],
[8389.89,	8450.76,	8342.78,	8323.59,	8337.2,		8310.23,	8371.26,	8321.86,	8355.92,	8349.92,	8385.88,	8341.29,	8332.28,	8311.97],
[40731.3,	40772.6,	40863.9,	40596,		40610.5,	40571.6,	40707.7,	40702.9,	40795.4,	40584.5,	39532.8,	39557.8,	39617.5,	39668.8],
[78980.4,	80820.1,	81187.8,	81986.1,	81240.8,	81441.3,	81385.7,	79242,		82196.1,	81461.8,	81502.7,	81387.1,	81413.5,	82163.4],
[211864,	208337,		208925,		220836,		220727,		205526,		244942,		233019,		226390,		219981,		220673,		224517,		214266,		204019]
]

EP1Paralel2 = [
[165.79,	177.752,	174.197,	178.637,	192.425,	200.051,	164.926,	165.613,	203.921,	163.456,	172.135,	173.82,		160.994,	204.416],
[188.725,	179.386,	186.096,	182.118,	188.485,	205.232,	287.172,	227.158,	188.365,	186.687,	175.473,	196.664,	230.414,	181.529],
[2012.19,	2016.48,	1995.73,	2212.51,	2011.16,	1994.2,		2013.77,	2031.01,	1972.46,	2038.32,	2034.78,	1988.65,	2004.43,	2009.48],
[9365.51,	9249.3,		9258.68,	9859.73,	9566.04,	10226.3,	9615.82,	9573.95,	9580.71,	9530.37,	9831.41,	9814.07,	9732.43,	9992.16],
[19495.4,	19256.4,	19282.3,	19313.6,	19503.4,	21108.5,	20399.5,	21930.7,	21018.6,	20471.4,	19868.2,	19851.4,	20530.5,	20115.7],
[115142,	115741,		115940,		112642,		113416,		112269,		111424,		114240,		113703,		130301,		154274,		148021,		145623,		145857 ]
]

EP1Paralel3 = [
[219.993,	196.903,	181.446,	190.452,	192.877,	201.356,	188.91,		190.583,	176.982,	189.402,	236.194,	201.227,	176.542,	194.217],
[229.499,	212.085,	214.482,	217.318,	225.005,	234.746,	213.633,	212.609,	220.676,	219.206,	237.169,	226.69,		209.604,	212.977],
[2267.77,	2329.31,	2287.8,		2242.2,		2275.99,	2325.33,	2247.81,	2250.37,	2357.82,	2288.82,	2285.03,	2305.17,	2323.29,	2322.75],
[10887.8,	11499,		11652.6,	11411.2,	11397.5,	11539.4,	11304.3,	11582,		11286.2,	11565.6,	11758.1,	11657.3,	11771.8,	11682.2],
[23608,		24628.2,	22906.2,	22842.3,	22656.2,	22626.2,	23921.6,	23072,		22881.3,	23013,		23415.4,	22899.1,	22568.7,	24188.8],
[129560,	132264,		153504,		161914,		159823,		148036,		124890,		126991,		141060,		152103,		148561,		145825,		146284,		144886 ]
]

EP1Paralel4 = [
[137.182,	138.457,	135.526,	137.253,	140.263,	155.708,	138.439,	137.359,	137.663,	139.075,	140.788,	138.601,	139.314,	141.322],
[160.988,	235.727,	160.425,	158.788,	159.262,	164.138,	160.213,	161.523,	161.741,	159.354,	161.744,	159.888,	160.065,	159.857],
[1737.82,	1745.02,	1745.68,	1743.47,	1732.42,	1789.47,	1742.03,	1756.73,	1763.08,	1736.13,	1754.53,	1756.8,		1736.88,	1741.81],
[8228.32,	8367.44,	8303.03,	8383.35,	8409.38,	8393.03,	8397.45,	8505.2,		8484.42,	8369.76,	8485.28,	8456.08,	8470.89,	8463.01],
[17166.9,	17537,		17728.4,	17130.5,	18064.8,	17360.2,	17085.4,	17112.4,	17112.6,	17069.4,	17596.7,	17612.1,	17589.8,	17596.3],
[94185.7,	93334.9,	95357.2,	93835,		93870.1,	95343.7,	93485.3,	93301.6,	92632.8,	95532.7,	92629.3,	92630.9,	93027.1,	96062  ]
]

EP1Paralel8 = [
[138.582,	143.917,	145.102,	140.159,	140.18,		141.279,	144.592,	139.185,	139.467,	139.064,	139.314,	141.315,	147.471,	141.026],
[162.103,	163.041,	164.846,	230.707,	162.648,	165.108,	160.767,	160.294,	163.125,	161.57,		161.327,	158.948,	161.805,	160.101],
[1742.19,	1733.69,	1737.51,	1738.7,		1742.74,	1772.38,	1764.6,		1734.76,	1753,		1761.19,	1742.26,	1740.78,	2366.3,		1754.09],
[8339.49,	8190.68,	8227,		8321.62,	8406.85,	8385.73,	8395.92,	8424.75,	8407.06,	8393.2,		8390.54,	8629.68,	8367.84,	8445.5 ],
[17410.2,	17379,		17366.4,	17581,		17398.5,	17278.4,	18573,		17249.9,	17594.1,	17400,		17525.9,	17373.2,	17618.7,	17540.3],
[92448.5,	92872.7,	93988,		93879.7,	93320.3,	92952,		94370.7,	93734.4,	94399,		93486.2,	95717.5,	92485.3,	92147.9,	92717.2]
]



mediaEP1Seq = []
stdEP1Seq = []

mediaEP1Paralel1 = []
stdEP1Paralel1 = []

mediaEP1Paralel2 = []
stdEP1Paralel2 = []

mediaEP1Paralel3 = []
stdEP1Paralel3 = []

mediaEP1Paralel4 = []
stdEP1Paralel4 = []

mediaEP1Paralel8 = []
stdEP1Paralel8 = []



for i in range(6):
	mediaEP1Seq.append(np.mean(EP1Seq[i]))
	stdEP1Seq.append(np.std(EP1Seq[i]))

	mediaEP1Paralel1.append(np.mean(EP1Paralel1[i]))
	stdEP1Paralel1.append(np.std(EP1Paralel1[i]))

	mediaEP1Paralel2.append(np.mean(EP1Paralel2[i]))
	stdEP1Paralel2.append(np.std(EP1Paralel2[i]))

	mediaEP1Paralel3.append(np.mean(EP1Paralel3[i]))
	stdEP1Paralel3.append(np.std(EP1Paralel3[i]))

	mediaEP1Paralel4.append(np.mean(EP1Paralel4[i]))
	stdEP1Paralel4.append(np.std(EP1Paralel4[i]))

	mediaEP1Paralel8.append(np.mean(EP1Paralel8[i]))
	stdEP1Paralel8.append(np.std(EP1Paralel8[i]))
	


fig = plt.figure(figsize=(10,10))
ax1 = fig.add_subplot(111)



colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, stdEP1Seq,label=r'EP1Seq', color=colors, fmt='o', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, stdEP1Paralel1,label=r'EP1Paralel1', color=colors, fmt='+', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, stdEP1Paralel2,label=r'EP1Paralel2', color=colors, fmt='.', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel3)))*2, mediaEP1Paralel3, stdEP1Paralel3,label=r'EP1Paralel3', color=colors, fmt='h', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel3)))*2, mediaEP1Paralel3, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel4)))*2, mediaEP1Paralel4, stdEP1Paralel4,label=r'EP1Paralel4', color=colors, fmt='*', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel4)))*2, mediaEP1Paralel4, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel8)))*2, mediaEP1Paralel8, stdEP1Paralel8,label=r'EP1Paralel8', color=colors, fmt='>', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel8)))*2, mediaEP1Paralel8, color=colors,lw=2)



ax1.yaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)
ax1.xaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)

fontSize=12

ax1.set_axisbelow(True)
ax1.set_title('EP1 - Sequencial e Paralelo - Nucleo', fontsize=fontSize+3, fontweight='bold')
ax1.set_xlabel(r'Quantidade de senhas verificadas', fontsize=fontSize+2)
ax1.set_ylabel('Tempo medio (em microseg)', fontsize=fontSize+2)
ax1.xaxis.set_label_coords(0.5, -0.08)
ax1.set_facecolor('white')


handles, labels = ax1.get_legend_handles_labels()
leg = ax1.legend(handles, labels, bbox_to_anchor=(0.01, 0.98), loc=2, borderaxespad=0., fontsize=fontSize)
leg.get_frame().set_facecolor('#FFFFFF')
# plt.legend(title=r'Compilador')

ticksx = ['1', '2', '100', '500', '1000', '5000']
# ticksy = ['0', '50000', '100000', '150000', '200000', '250000', '300000', '350000', '400000', '450000']
plt.xticks(range(0, len(ticksx)*2, 2), ticksx, fontsize=fontSize)
# plt.yticks(range(0, len(ticksy)*2, 2), ticksy, fontsize=fontSize)
plt.xlim(-1, len(ticksx)* 2 - 1)
# plt.ylim(-1, len(ticksy)* 2 - 1)


plt.tight_layout()
# plt.show()

plt.savefig('GraficoEP1-Seq-Par-Nucleo.pdf',bbox_inches='tight')
