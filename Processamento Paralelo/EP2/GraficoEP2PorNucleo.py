import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random


EP1Seq = [
[7975.25,	8178.25,	8601.25,	8826.25,	8343.22],	
[3635.25,	3750.25,	3768.25,	3797.25,	3733.23],
[6656.25,	6907.25,	7492.25,	7598.25,	6874.33],
[55.81,		64.37,		66.72,		79.65,		66.64],
[7585.25,	8114.25,	8266.25,	10547.25,	7910.18]
]

EP1Paralel1 = [
[784.24,	858.1,		872.98,		897.9,		930.22],	
[376.64,	407.2,		414.19,		416.9,		469.80],
[616.92,	771.35,		786.40,		970.60,		976.12],
[8.39,		8.83,		14.6,		16.31,		16.31],
[1270.85,	1605.61,	1630.4,		2096.63,	2294.71]
]

EP1Paralel2 = [
[160.28,	174.54,		176.82,		206.46,		260.39],
[87.79,		121.17,		126.97,		128.5,		141.54],
[160.71,	176.91,		188.27,		203.43,		251.48],
[3.36,		3.58,		3.98,		4.80,		5.30],
[166.1,		167.38,		185.67,		212.39,		268.1]
]

EP1Paralel3 = [
[160.25,	182.7,		218.28,		231.21,		265.12],	
[268.34,	413.1,		438.9,		452.49,		481.97],
[156.48,	186.92,		261.77,		290.66,		323.56],
[3.30,		3.31,		5.1,		5.33,		5.51],
[708.76,	733.42,		734.25,		489.41,		547.90]
]

EP1Seq = np.log10(EP1Seq)
# EP1Paralel1 = np.log10(EP1Paralel1)
# EP1Paralel2 = np.log10(EP1Paralel2)
# EP1Paralel3 = np.log10(EP1Paralel3)

mediaEP1Seq = []
stdEP1Seq = []

mediaEP1Paralel1 = []
stdEP1Paralel1 = []

mediaEP1Paralel2 = []
stdEP1Paralel2 = []

mediaEP1Paralel3 = []
stdEP1Paralel3 = []

# mediaEP1Paralel4 = []
# stdEP1Paralel4 = []

# mediaEP1Paralel8 = []
# stdEP1Paralel8 = []


# mediaEP1BSTSeq = []
# stdEP1BSTSeq = []

# mediaEP1BST1 = []
# stdEP1BST1 = []

# mediaEP1BST2 = []
# stdEP1BST2 = []

# mediaEP1BST3 = []
# stdEP1BST3 = []

# mediaEP1BST4 = []
# stdEP1BST4 = []

# mediaEP1BST8 = [] 
# stdEP1BST8 = []


# mediaEP1Hash = []
# stdEP1Hash = []


for i in range(5):
	mediaEP1Seq.append(np.mean(EP1Seq[i]))
	stdEP1Seq.append(np.std(EP1Seq[i]))

	mediaEP1Paralel1.append(np.mean(EP1Paralel1[i]))
	stdEP1Paralel1.append(np.std(EP1Paralel1[i]))

	mediaEP1Paralel2.append(np.mean(EP1Paralel2[i]))
	stdEP1Paralel2.append(np.std(EP1Paralel2[i]))

	mediaEP1Paralel3.append(np.mean(EP1Paralel3[i]))
	stdEP1Paralel3.append(np.std(EP1Paralel3[i]))

	# mediaEP1Paralel4.append(np.mean(EP1Paralel4[i]))
	# stdEP1Paralel4.append(np.std(EP1Paralel4[i]))

	# mediaEP1Paralel8.append(np.mean(EP1Paralel8[i]))
	# stdEP1Paralel8.append(np.std(EP1Paralel8[i]))


	# mediaEP1BSTSeq.append(np.mean(EP1BSTSeq[i]))
	# stdEP1BSTSeq.append(np.std(EP1BSTSeq[i]))

	# mediaEP1BST1.append(np.mean(EP1BST1[i]))
	# stdEP1BST1.append(np.std(EP1BST1[i]))

	# mediaEP1BST2.append(np.mean(EP1BST2[i]))
	# stdEP1BST2.append(np.std(EP1BST2[i]))

	# mediaEP1BST3.append(np.mean(EP1BST3[i]))
	# stdEP1BST3.append(np.std(EP1BST3[i]))

	# mediaEP1BST4.append(np.mean(EP1BST4[i]))
	# stdEP1BST4.append(np.std(EP1BST4[i]))

	# mediaEP1BST8.append(np.mean(EP1BST8[i]))
	# stdEP1BST8.append(np.std(EP1BST8[i]))


	# mediaEP1Hash.append(np.mean(EP1Hash[i]))
	# stdEP1Hash.append(np.std(EP1Hash[i]))


fig = plt.figure(figsize=(10,5))
ax1 = fig.add_subplot(111)


colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, stdEP1Seq,label=r'1 (log10)', color=colors, fmt='o', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, stdEP1Paralel1,label=r'8', color=colors, fmt='+', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, stdEP1Paralel2,label=r'16', color=colors, fmt='.', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel3)))*2, mediaEP1Paralel3, stdEP1Paralel3,label=r'32', color=colors, fmt='h', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel3)))*2, mediaEP1Paralel3, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1Paralel4)))*2, mediaEP1Paralel4, stdEP1Paralel4,label=r'99999', color=colors, fmt='*', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1Paralel4)))*2, mediaEP1Paralel4, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1Paralel8)))*2, mediaEP1Paralel8, stdEP1Paralel8,label=r'EP1Paralel8', color=colors, fmt='>', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1Paralel8)))*2, mediaEP1Paralel8, color=colors,lw=2)


# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BSTSeq)))*2, mediaEP1BSTSeq, stdEP1BSTSeq,label=r'EP1BSTSeq', color=colors, fmt='s', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BSTSeq)))*2, mediaEP1BSTSeq, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BST1)))*2, mediaEP1BST1, stdEP1BST1,label=r'EP1BST1', color=colors, fmt='p', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BST1)))*2, mediaEP1BST1, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BST2)))*2, mediaEP1BST2, stdEP1BST2,label=r'EP1BST2', color=colors, fmt='s', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BST2)))*2, mediaEP1BST2, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BST3)))*2, mediaEP1BST3, stdEP1BST3,label=r'EP1BST3', color=colors, fmt='v', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BST3)))*2, mediaEP1BST3, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BST4)))*2, mediaEP1BST4, stdEP1BST4,label=r'EP1BST4', color=colors, fmt='^', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BST4)))*2, mediaEP1BST4, color=colors,lw=2)

# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1BST8)))*2, mediaEP1BST8, stdEP1BST8,label=r'EP1BST8', color=colors, fmt='D', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1BST8)))*2, mediaEP1BST8, color=colors,lw=2)


# colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
# plt.errorbar(np.array(range(len(mediaEP1Hash)))*2, mediaEP1Hash, stdEP1Hash,label=r'EP1Hash', color=colors, fmt='x', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
# plt.plot(np.array(range(len(mediaEP1Hash)))*2, mediaEP1Hash, color=colors,lw=2)


ax1.yaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)
ax1.xaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)

fontSize=12

ax1.set_axisbelow(True)
ax1.set_title('EP2 - Por Nucleo', fontsize=fontSize+3, fontweight='bold')
ax1.set_xlabel(r'Senhas Verificadas', fontsize=fontSize+2)
ax1.set_ylabel('Tempo medio (em microseg)', fontsize=fontSize+2)
ax1.xaxis.set_label_coords(0.5, -0.08)
ax1.set_facecolor('white')


handles, labels = ax1.get_legend_handles_labels()
leg = ax1.legend(handles, labels, bbox_to_anchor=(0.01, 0.98), loc=2, borderaxespad=0., fontsize=fontSize)
leg.get_frame().set_facecolor('#FFFFFF')
# plt.legend(title=r'Compilador')

ticksx = ['12345', 'A1B2C', '123ZZ', 'DCEL', '99999']
# ticksy = ['0', '50000', '100000', '150000', '200000', '250000', '300000', '350000', '400000', '450000']
plt.xticks(range(0, len(ticksx)*2, 2), ticksx, fontsize=fontSize)
# plt.yticks(range(0, len(ticksy)*2, 2), ticksy, fontsize=fontSize)
plt.xlim(-1, len(ticksx)* 2 - 1)
# plt.ylim(-1, len(ticksy)* 2 - 1)


plt.tight_layout()
# plt.show()

plt.savefig('GraficoEp2PorNucleo.pdf',bbox_inches='tight')
