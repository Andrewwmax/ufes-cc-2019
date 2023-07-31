import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random



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


for i in range(6):
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



fig = plt.figure(figsize=(10,10))
ax1 = fig.add_subplot(111)


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



ax1.yaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)
ax1.xaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)

fontSize=12

ax1.set_axisbelow(True)
ax1.set_title('EP1 - Busca Binaria Sequencial e Paralelo - Nucleo', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoEP1BSTNucleo.pdf',bbox_inches='tight')
