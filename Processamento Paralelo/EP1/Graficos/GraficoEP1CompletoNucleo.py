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

EP1BSTSeq = [
[6910.73,	6945.39,	7000.13,	6799.58,	6779.88,	6755.57,	6969.95,	7009.3,		6739.88,	6845.14,	6730.04,	7139.8,		7000.67,	6648.92],
[6995.84,	6965.24,	7085.33,	7139.36,	7218.36,	6768.62,	6837.88,	6741,		6950.24,	6959.38,	6794.6,		6759.21,	6800.43,	6644.72],
[8129.96,	8895.07,	8525.57,	8339.82,	8377.28,	8079.81,	8369.82,	8340.14,	8389.85,	8235.75,	8434.01,	8255.69,	8160.95,	8303.66],
[7149,		7128.72,	7290.83,	6949.65,	6965.75,	7135,		7145.62,	7137.15,	7144.93,	6969.66,	7144.8,		6985.52,	7089.87,	6828.45],
[7029.87,	6980.39,	6970.85,	7007.51,	6969.91,	7085.26,	7015.25,	6969.06,	7004.48,	6790.07,	6757.72,	6720.05,	6737.58,	6653.93],
[6784.55,	6790.2,		6760.31,	7029.33,	7005.23,	6760.93,	6960.49,	6815.96,	6865.09,	6855.11,	6780.08,	7018.18,	7105.06,	6809.88]
]

EP1BST1= [
[6826.73,	6843.39,	6916.13,	6708.58,	6688.88,	6653.57,	6878.95,	6918.3,		6648.88,	6743.14,	6646.04,	7048.8,		6916.67,	6648.92],
[6893.84,	6863.24,	6983.33,	7048.36,	7125.36,	6675.62,	6744.88,	6648,		6866.24,	6868.38,	6701.6,		6668.21,	6716.43,	6644.72],
[8038.96,	8793.07,	8423.57,	8248.82,	8284.28,	7988.81,	8278.82,	8256.14,	8298.85,	8133.75,	8341.01,	8153.69,	8076.95,	8303.66],
[7056,		7035.72,	7206.83,	6858.65,	6863.75,	7042,		7043.62,	7044.15,	7051.93,	6878.66,	7051.8,		6883.52,	6998.87,	6828.45],
[6938.87,	6896.39,	6886.85,	6914.51,	6878.91,	6983.26,	6913.25,	6878.06,	6911.48,	6706.07,	6664.72,	6636.05,	6644.58,	6653.93],
[6691.55,	6706.2,		6676.31,	6938.33,	6903.23,	6676.93,	6876.49,	6713.96,	6763.09,	6753.11,	6696.08,	6925.18,	7003.06,	6811.88]
]

EP1BST2 = [
[6818.73,	6810.39,	6908.13,	6684.58,	6664.88,	6610.57,	6859.95,	6891.3,		6621.88,	6700.14,	6627.04,	7029.8,		6897.67,	6648.92],
[6843.84,	6820.24,	6940.33,	7024.36,	7106.36,	6656.62,	6725.88,	6629,		6847.24,	6849.38,	6682.6,		6641.21,	6697.43,	6644.72],
[8014.96,	8743.07,	8380.57,	8224.82,	8265.28,	7961.81,	8259.82,	8248.14,	8274.85,	8083.75,	8322.01,	8103.69,	8068.95,	8272.66],
[7037,		7016.72,	7198.83,	6831.65,	6813.75,	7023,		7000.62,	7025.15,	7032.93,	6854.66,	7032.8,		6833.52,	6974.87,	6828.45],
[6911.87,	6877.39,	6867.85,	6895.51,	6854.91,	6933.26,	6870.25,	6851.06,	6892.48,	6698.07,	6645.72,	6617.05,	6625.58,	6622.93],
[6672.55,	6698.2,		6668.31,	6919.33,	6853.23,	6668.93,	6857.49,	6663.96,	6713.09,	6710.11,	6688.08,	6906.18,	6953.06,	6811.88]
]

EP1BST3 = [
[6981.14,	6911.69,	6990.46,	7002.86,	6670.32,	7404.88,	6807.93,	6706.25,	7095.67,	7270.85,	7161.04,	6714.07,	6979.61,	6841.2 ],
[6833.96,	6881.06,	6811.8,		6758.2,		6800.15,	6530.94,	6750.02,	6759.57,	6740.63,	6480.15,	6545.92,	6500.77,	6853.42,	6716.1 ],
[7946.96,	7848.27,	8095.96,	8090.73,	8124.81,	8112.17,	8415.54,	8052.29,	7911.51,	8115.47,	8113.99,	7820.67,	7861.62,	8220.71],
[6913.21,	7369.25,	7326.44,	6688.45,	6844.57,	6610.23,	6677.18,	6627.07,	6668.61,	6662.82,	6906.46,	6811.34,	6967.76,	6869.6 ],
[6769.68,	6558.62,	6507,		6557.55,	6642.14,	6935.57,	6882.52,	6686.19,	6686.17,	6695.21,	6820.96,	6879.62,	6761.89,	6717.63],
[6715.25,	6715.6,		6659.47,	6652.85,	6940.43,	6694.85,	6685.21,	6907.45,	6867.43,	6784.07,	6714.95,	6910.1,		7087.99,	6907.12]
]

EP1BST4 = [
[6785.08,	6669.14,	6632.37,	6864.59,	6927.23,	6696.06,	6704.59,	6764.54,	6949.97,	6662.21,	6663.55,	6789.07,	7110.21,	6975.64],
[6894.36,	6745.02,	6968.18,	6812.45,	6667.22,	6859,		6856.48,	6850.52,	6907.1,		6894.59,	6724.27,	6711.55,	6864.66,	6872.68],
[8259.92,	8237.42,	8223.56,	8269.59,	8280.36,	8294.13,	8284.4,		8018.71,	8240.81,	8149.73,	8228.53,	8093.58,	8253.09,	8287.59],
[7082.07,	7030.55,	6799.71,	6781.54,	7018.7,		7032.23,	7438.02,	7402.66,	7401.32,	6990.02,	6928.62,	6828.44,	6891.29,	7054.6 ],
[6686.02,	6657.25,	6664.08,	8107.58,	7098.97,	6904.08,	6852.83,	6682.45,	6854.65,	6665.4,		6711.37,	6753.56,	7011.69,	6771.6 ],
[6979.48,	6663.05,	6614.33,	6928.13,	6931.62,	6761.5,		6798.36,	6605.79,	6637.3,		6805.97,	6772.52,	6716.67,	6971.05,	6691.49]
]

EP1BST8 = [
[6780.75,	6765.56,	6806.4,		6800.65,	6649.95,	6792.4,		6627.43,	6625.88,	6984.58,	6667.82,	6647.28,	6739.15,	6834.76,	6835.11],
[6747.29,	6948.36,	6630.44,	6864.7,		6984.97,	7405.15,	7217.04,	6765.6,		7995.02,	6914.22,	6868.78,	7013.06,	6825.41,	6782.76],
[8155.95,	8211.2,		8228.37,	8288.85,	8215.71,	8450.36,	8438,		8191.5,		8205.1,		8187.82,	8178.17,	8149.56,	8368.53,	8166.64],
[6912.52,	6988.3,		6929.05,	6929.01,	6881.71,	6955.51,	6956.1,		6907.71,	7024.57,	6858.79,	6946.94,	7011.17,	6952.43,	6971.31],
[6726.05,	6764.89,	6695.65,	6772.78,	6722.89,	6656.14,	6780.27,	6702.75,	6773.81,	6751.98,	6751.05,	6834.18,	6824.49,	6748.25],
[6933.32,	6852.42,	6833.48,	6751.07,	6983.29,	6816.21,	6759.84,	6798.25,	6836.08,	6670.67,	6757.64,	6752.37,	6855.32,	6940.7 ]
]

EP1Hash = [
[0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001],
[0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.001,		0.002,		0.001,		0.001,		0.001,		0.001,		0.009],
[0.037,		0.037,		0.044,		0.039,		0.043,		0.037,		0.036,		0.036,		0.05,		0.035,		0.04,		0.036,		0.039,		0.043],
[0.19,		0.2,		0.182,		0.196,		0.191,		0.194,		0.19,		0.19,		0.185,		0.19,		0.201,		0.194,		0.193,		0.188],
[0.377,		0.383,		0.449,		0.397,		0.38,		0.383,		0.377,		0.383,		0.381,		0.398,		0.379,		0.371,		0.378,		0.372],
[1.817,		1.87,		1.822,		1.849,		1.809,		1.825,		1.921,		1.883,		1.846,		1.866,		1.887,		1.848,		1.854,		1.867]
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


mediaEP1BSTSeq = []
stdEP1BSTSeq = []

mediaEP1BST1 = []
stdEP1BST1 = []

mediaEP1BST2 = []
stdEP1BST2 = []

mediaEP1BST3 = []
stdEP1BST3 = []

mediaEP1BST4 = []
stdEP1BST4 = []

mediaEP1BST8 = [] 
stdEP1BST8 = []


mediaEP1Hash = []
stdEP1Hash = []


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
	

	mediaEP1BSTSeq.append(np.mean(EP1BSTSeq[i]))
	stdEP1BSTSeq.append(np.std(EP1BSTSeq[i]))

	mediaEP1BST1.append(np.mean(EP1BST1[i]))
	stdEP1BST1.append(np.std(EP1BST1[i]))

	mediaEP1BST2.append(np.mean(EP1BST2[i]))
	stdEP1BST2.append(np.std(EP1BST2[i]))

	mediaEP1BST3.append(np.mean(EP1BST3[i]))
	stdEP1BST3.append(np.std(EP1BST3[i]))

	mediaEP1BST4.append(np.mean(EP1BST4[i]))
	stdEP1BST4.append(np.std(EP1BST4[i]))

	mediaEP1BST8.append(np.mean(EP1BST8[i]))
	stdEP1BST8.append(np.std(EP1BST8[i]))


	mediaEP1Hash.append(np.mean(EP1Hash[i]))
	stdEP1Hash.append(np.std(EP1Hash[i]))



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


colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BSTSeq)))*2, mediaEP1BSTSeq, stdEP1BSTSeq,label=r'EP1BSTSeq', color=colors, fmt='s', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BSTSeq)))*2, mediaEP1BSTSeq, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BST1)))*2, mediaEP1BST1, stdEP1BST1,label=r'EP1BST1', color=colors, fmt='p', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BST1)))*2, mediaEP1BST1, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BST2)))*2, mediaEP1BST2, stdEP1BST2,label=r'EP1BST2', color=colors, fmt='s', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BST2)))*2, mediaEP1BST2, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BST3)))*2, mediaEP1BST3, stdEP1BST3,label=r'EP1BST3', color=colors, fmt='v', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BST3)))*2, mediaEP1BST3, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BST4)))*2, mediaEP1BST4, stdEP1BST4,label=r'EP1BST4', color=colors, fmt='^', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BST4)))*2, mediaEP1BST4, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1BST8)))*2, mediaEP1BST8, stdEP1BST8,label=r'EP1BST8', color=colors, fmt='D', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1BST8)))*2, mediaEP1BST8, color=colors,lw=2)


colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Hash)))*2, mediaEP1Hash, stdEP1Hash,label=r'EP1Hash', color=colors, fmt='x', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Hash)))*2, mediaEP1Hash, color=colors,lw=2)



ax1.yaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)
ax1.xaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)

fontSize=12

ax1.set_axisbelow(True)
ax1.set_title('EP1 - Completo - Nucleo', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoEP1CompletoNucleo.pdf',bbox_inches='tight')
