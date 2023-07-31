import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random


EP1BSTSeq = [
[9414.24,	9401.25,	9167.85,	9167.32,	9351.46,	9394.7,		9162.98,	9386.92,	9376.28,	9166.85,	9183.81,	9209.47,	9148.04,	9155.64],
[9255.58,	9386.5,		9431.21,	9411.77,	9197.73,	9134.46,	9180.06,	9139.45,	9179.35,	9176.55,	9234.93,	9176.35,	9177.19,	9224.99],
[10535,		11045.7,	10793,		10773.1,	10845.4,	10514.9,	10459,		10520.4,	10452.4,	10475.8,	10484,		10762.3,	10916,		10548.3],
[9512.5,	9278.78,	9323.75,	9554.5,		9525.05,	9311.42,	9301.44,	9532.97,	9543.04,	9570.26,	9358.95,	9520.22,	9297.63,	9302.32],
[9328.1,	9398.96,	9197.34,	9191.82,	9176.18,	9211.03,	9184.45,	9454.67,	9802.89,	9417.08,	9172.06,	9321.42,	9222.83,	9193.46],
[9649.61, 	9215.41,	9362.88,	9157.71, 	9456.45, 	9484.48, 	9482.05, 	9249.26, 	9188.7, 	9206.47, 	9459.97, 	9472.62, 	9214.97, 	9190.68]
]

EP1BST1 = [
[9080.36,	9059.01,	9163.45,	9108.8,		9093.11,	9113.47,	9310.29,	9328.39,	9056.22,	9117.68,	9204.12,	9334.28,	9326.74,	9281.75],
[9290.04,	9080.32,	9076.76,	9396.73,	9069.17,	9317.39,	9103.18,	9356.21,	9310.68,	9074.01,	9141.72,	9076.21,	9100.04,	9310.16],
[10689.5,	10391.3,	10350.7,	10394.1,	10656.3,	10404.9,	10575.2,	10805.3,	10695.3,	10828.5,	10908.5,	10895,		10751.4,	10881.8],
[9478.89,	9631.04,	9197.88,	9196.46,	9191.12,	9415.13,	9508.41,	9188.15,	9186.09,	9173.52,	9160.41,	9155.45,	9406.36,	9344.34],
[9046.41,	9274.63,	9277.62,	9082.92,	9058.1,		9376.17,	9041.17,	9069.13,	9063.43,	9038.08,	9100.61,	9064.91,	9074.37,	9396.09],
[9315.66,	9348.52,	9073.11,	9322.37,	9299.12,	9130.08,	9309.23,	9277.54,	9330.15,	9085.32,	9088.17,	9293.74,	9039.22,	9070.88]
]

EP1BST2 = [
[9418.51,	9521.83,	9371.12,	9333.46,	9049.98,	9370.91,	9042.3,		9056.22,	9328.61,	9086.11,	9101.49,	9048.88,	9282.75,	9310.26],
[9070.49,	9034.83,	9154.6,		9110.84,	9059.91,	9145.81,	9367.5,		9373.35,	9063.79,	9062.68,	9081.9,		9285.87,	9293.19,	9096.12],
[10333.3,	10345.5,	10790.8,	10337.5,	10352.8,	10648.3,	10693.6,	10643.7,	10825.9,	10305.5,	10654.8,	10545,		10328.8,	10655.4],
[9214.38,	9423.46,	9510.97,	9436.89,	9424.8,		9407.83,	9459.74,	9413.54,	9432.83,	9224.67,	9162.68,	9404.78,	9397.65,	9417.44],
[9340.75,	9133.48,	9288.89,	9070.96,	9056.64,	9297.44,	9036.82,	9027.72,	9087.41,	9043.51,	9037.31,	9284.77,	9307.37,	9312.53],
[9349.85,	9067.31,	9364,		9329.06,	9299.98,	9353.11,	9297.17,	9343.02,	9341.23,	9229.5,		9068.75,	9362.51,	9303.28,	9076.71]
]

EP1BST3 = [
[9064.5,	9290.41,	9046.65,	9072.15,	9079.89,	9111.47,	9052.55,	9288.17,	9087.43,	9271.91,	9310.82,	9012.93,	9297.37,	9051.41],
[9054.14,	9234.47,	9066.5,		9295.5,		9054,		9069.51,	9109.38,	9307.73,	9125.35,	9288.37,	9247.57,	9068.91,	9311.58,	9313.46],
[10738.2,	10325.7,	10331.1,	10333.5,	10661.4,	10607.4,	10621.7,	10606.9,	10317.2,	10348.8,	10344.2,	10402.2,	10309.3,	10301.7],
[9250.81,	9441.41,	9340.97,	9029.31,	9108.18,	9048.16,	8999.77,	9261.52,	9023.47,	9250.12,	8997.32,	9025.12,	8994.25,	9257.26],
[9145.95,	9154.53,	9098.83,	9338.83,	9137.18,	9165.56,	8878.34,	8873.42,	8885.61,	8907.73,	8867.88,	8952.18,	9103,		8876.9],
[9069.99,	9287.1,		9362.63,	9096.13,	9316.8,		9325.71,	9316.29,	9354.94,	9353.81,	9333.09,	9105.62,	9378.14,	9277.45,	9320.7]
]

EP1BST4 = [
[9112.64,	10339.2,	9274.96,	9109.59,	9112.95,	9165.11,	8858.1,		9131.2,		8967.51,	8861.51,	8875.38,	8926.44,	9111.54,	9013.66],
[9117.64,	9143.83,	9159.72,	9109.52,	9261.07,	9041.9,		9018.25,	9025.79,	9290.72,	9007.06,	9081.3,		9061.09,	9088.77,	9033.25],
[10612.7,	11111.9,	10323.2,	10516.5,	10369.3,	10692,		10356.6,	10755.7,	10626.1,	10644.8,	10622.1,	10318.2,	10647.6,	10326.2],
[9270.3,	9205.04,	9240.11,	9443.34,	9416.98,	9212.48,	9418.49,	9169.41,	9213.8,		9502.13,	9520.35,	9238.69,	9478.89,	9425.78],
[9124.15,	9075.21,	9043.82,	9120.19,	9085.5,		9088.82,	9115.33,	9098.55,	9062.14,	9308.98,	9055.22,	9308.19,	9282.91,	9294.13],
[9388.56,	9307.1,		9081,		9147.13,	9320.55,	9354.96,	9346.37,	9087.62,	9281.08,	9187.87,	9078.98,	9735.31,	9087.27,	9215.25]
]

EP1BST8 = [
[9072.61,	9306.92,	9056.66,	9063.96,	9403.36,	9271.15,	9306.42,	9289.19,	9159.35,	9308.65,	9079.87,	9279.55,	9290.15,	9052.98],
[9193.97,	9033.52,	9293.76,	9315.94,	9306.87,	9044.33,	9048.22,	9264.72,	9283.69,	9265.57,	9278.96,	9058.63,	9044.55,	9330.37],
[10717.6,	10648.5,	10868.7,	10710.4,	10384.2,	10646.3,	10338.5,	10323.6,	10775.8,	10428.1,	10330.9,	10657.9,	10354.8,	10505.8],
[9207.44,	9181.48,	9174.97,	9186.78,	9488.49,	9236.71,	9462.22,	9202.56,	9186.63,	9159.23,	9169.14,	9190.88,	9414.08,	9430.89],
[9642.48,	9069.01,	9064.9,		9059.84,	9469.42,	9028.5,		9074.65,	9340.12,	9315.24,	9080.34,	9373.64,	9031.1,		9092.36,	9438.06],
[9096.55,	9337.3,		9342.97,	9363.69,	9112.4,		9334.28,	9309.04,	9310.92,	9353.68,	9058.81,	9296.7,		9355.82,	9331.19,	9319.25]
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
ax1.set_title('EP1 - Busca Binaria Sequencial e Paralelo - Total', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoEP1BSTTotal.pdf',bbox_inches='tight')
