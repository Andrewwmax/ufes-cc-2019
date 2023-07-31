import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random
import math


EP1Seq = 		[
				[1.02, 1.02, 1.02],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[76.44, 76.44, 76.44],[4934.16, 4934.16, 4934.16],[1.001, 1.001, 1.001],[4847.18, 4847.18, 4847.18],[5275.18, 5275.18, 5275.18],[1.02, 1.02, 1.02],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[92.12, 92.12, 92.12],[5572.76, 5572.76, 5572.76],[1.001, 1.001, 1.001],[1.02, 1.02, 1.02],[1.05, 1.05, 1.05],[42.38, 42.38, 42.38],[2454.22, 2454.22, 2454.22],[1.02, 1.02, 1.02],[1.03, 1.03, 1.03],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[36.88, 36.88, 36.88],[94.39, 94.39, 94.39],[2461.99, 2461.99, 2461.99],[5730.75, 5730.75, 5730.75],[86341.16, 86341.16, 86341.16],[92.63, 92.63, 92.63],[2443.76, 2443.76, 2443.76],[96.28, 96.28, 96.28],[2.79, 2.79, 2.79],[1.001, 1.001, 1.001],[1.02, 1.02, 1.02],[1.03, 1.03, 1.03],[1.001, 1.001, 1.001],[38.79, 38.79, 38.79],[2850.08, 2850.08, 2850.08],[165944.94, 165944.94, 165944.94],[1.001, 1.001, 1.001],[648.13, 648.13, 648.13],[880.43, 880.43, 880.43],[19.35, 19.35, 19.35],[1.02, 1.02, 1.02],[1.02, 1.02, 1.02],[1.001, 1.001, 1.001],[1.02, 1.02, 1.02],[1.03, 1.03, 1.03],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[11.39, 11.39, 11.39],[57.51, 57.51, 57.51],[1173.09, 1173.09, 1173.09],[3563.14, 3563.14, 3563.14],[69298.40, 69298.40, 69298.40],[1.001, 1.001, 1.001],[1231.29, 1231.29, 1231.29],[1310.11, 1310.11, 1310.11],[24.10, 24.10, 24.10],[1.59, 1.59, 1.59],[1694.61, 1694.61, 1694.61],[27.66, 27.66, 27.66],[1.02, 1.02, 1.02],[1.02, 1.02, 1.02],[1.001, 1.001, 1.001],[1.03, 1.03, 1.03],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[23.71, 23.71, 23.71],[77.21, 77.21, 77.21],[2321.29, 2321.29, 2321.29],[4759.28, 4759.28, 4759.28],[1.001, 1.001, 1.001],[80064.41, 80064.41, 80064.41]
				]

EP1Paralel1 = 	[
				[1.04, 1.04, 1.04],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[7.37, 7.37, 7.37],[274.23, 274.23, 274.23],[17265.20, 17265.20, 17265.20],[445.11, 445.11, 445.11],[584.60, 584.60, 584.60],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[6.34, 6.34, 6.34],[15.06, 15.06, 15.06],[839.21, 839.21, 839.21],[43276.05, 43276.05, 43276.05],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[3.99, 3.99, 3.99],[272.09, 272.09, 272.09],[1.001, 1.001, 1.001],[1.04, 1.04, 1.04],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[3.32, 3.32, 3.32],[1.001, 1.001, 1.001],[8.35, 8.35, 8.35],[154.05, 154.05, 154.05],[403.13, 403.13, 403.13],[8870.44, 8870.44, 8870.44],[8.63, 8.63, 8.63],[126.48, 126.48, 126.48],[11.54, 11.54, 11.54],[1.30, 1.30, 1.30],[6659.34, 6659.34, 6659.34],[1.001, 1.001, 1.001],[1.04, 1.04, 1.04],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[381.22, 381.22, 381.22],[35722.63, 35722.63, 35722.63],[1.001, 1.001, 1.001],[311.08, 311.08, 311.08],[59.79, 59.79, 59.79],[3.74, 3.74, 3.74],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[21724.94, 21724.94, 21724.94],[1.04, 1.04, 1.04],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[4.38, 4.38, 4.38],[1.001, 1.001, 1.001],[241.32, 241.32, 241.32],[590.45, 590.45, 590.45],[14500.11, 14500.11, 14500.11],[24156.49, 24156.49, 24156.49],[214.30, 214.30, 214.30],[250.64, 250.64, 250.64],[9.75, 9.75, 9.75],[1.001, 1.001, 1.001],[111.19, 111.19, 111.19],[3.56, 3.56, 3.56],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[4.29, 4.29, 4.29],[6.30, 6.30, 6.30],[214.73, 214.73, 214.73],[130.14, 130.14, 130.14],[19277.84, 19277.84, 19277.84],[6174.88, 6174.88, 6174.88]
				]

EP1Paralel2 = 	[
				[1.001, 1.001, 1.001],[1.12, 1.12, 1.12],[1.13, 1.13, 1.13],[2.38, 2.38, 2.38],[80.69, 80.69, 80.69],[4632.40, 4632.40, 4632.40],[78.69, 78.69, 78.69],[178.70, 178.70, 178.70],[1.001, 1.001, 1.001],[1.11, 1.11, 1.11],[1.19, 1.19, 1.19],[5.90, 5.90, 5.90],[479.21, 479.21, 479.21],[25365.33, 25365.33, 25365.33],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[5.31, 5.31, 5.31],[271.31, 271.31, 271.31],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.16, 1.16, 1.16],[1.12, 1.12, 1.12],[1.21, 1.21, 1.21],[4.70, 4.70, 4.70],[6.91, 6.91, 6.91],[223.53, 223.53, 223.53],[368.46, 368.46, 368.46],[14318.90, 14318.90, 14318.90],[8.50, 8.50, 8.50],[187.91, 187.91, 187.91],[11.64, 11.64, 11.64],[1.50, 1.50, 1.50],[12065.53, 12065.53, 12065.53],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.17, 1.17, 1.17],[4.89, 4.89, 4.89],[225.75, 225.75, 225.75],[14395.43, 14395.43, 14395.43],[1.12, 1.12, 1.12],[205.88, 205.88, 205.88],[100.75, 100.75, 100.75],[5.91, 5.91, 5.91],[1.10, 1.10, 1.10],[1.10, 1.10, 1.10],[391.66, 391.66, 391.66],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.001, 1.001, 1.001],[1.18, 1.18, 1.18],[1.49, 1.49, 1.49],[5.22, 5.22, 5.22],[24.68, 24.68, 24.68],[245.22, 245.22, 245.22],[1512.14, 1512.14, 1512.14],[15328.53, 15328.53, 15328.53],[27.02, 27.02, 27.02],[108.26, 108.26, 108.26],[5.49, 5.49, 5.49],[1.19, 1.19, 1.19],[186.14, 186.14, 186.14],[4.19, 4.19, 4.19],[1.001, 1.001, 1.001],[1.10, 1.10, 1.10],[1.12, 1.12, 1.12],[1.001, 1.001, 1.001],[1.14, 1.14, 1.14],[1.21, 1.21, 1.21],[7.17, 7.17, 7.17],[3.33, 3.33, 3.33],[350.38, 350.38, 350.38],[131.58, 131.58, 131.58],[22634.28, 22634.28, 22634.28],[8128.79, 8128.79, 8128.79]
				]

EP1Paralel3 = 	[
				[1.27, 1.27, 1.27],[1.15, 1.15, 1.15],[1.15, 1.15, 1.15],[1.16, 1.16, 1.16],[1.15, 1.15, 1.15],[1.15, 1.15, 1.15],[1.14, 1.14, 1.14],[1.17, 1.17, 1.17],[1.14, 1.14, 1.14],[1.14, 1.14, 1.14],[1.15, 1.15, 1.15],[1.16, 1.16, 1.16],[1.14, 1.14, 1.14],[1.15, 1.15, 1.15],[1.17, 1.17, 1.17],[1.14, 1.14, 1.14],[1.14, 1.14, 1.14],[1.16, 1.16, 1.16],[1.16, 1.16, 1.16],[1.17, 1.17, 1.17],[1.18, 1.18, 1.18],[1.15, 1.15, 1.15],[1.15, 1.15, 1.15],[1.18, 1.18, 1.18],[1.19, 1.19, 1.19],[1.17, 1.17, 1.17],[1.18, 1.18, 1.18],[1.15, 1.15, 1.15],[1.16, 1.16, 1.16],[1.22, 1.22, 1.22],[1.47, 1.47, 1.47],[3.26, 3.26, 3.26],[1.91, 1.91, 1.91],[1.81, 1.81, 1.81],[2.25, 2.25, 2.25],[2.68, 2.68, 2.68],[1.86, 1.86, 1.86],[3.47, 3.47, 3.47],[1.47, 1.47, 1.47],[3.32, 3.32, 3.32],[2.65, 2.65, 2.65],[1.30, 1.30, 1.30],[2.19, 2.19, 2.19],[3.93, 3.93, 3.93],[21.58, 21.58, 21.58],[133.86, 133.86, 133.86],[42.61, 42.61, 42.61],[49.10, 49.10, 49.10],[61.56, 61.56, 61.56],[104.43, 104.43, 104.43],[59.51, 59.51, 59.51],[105.61, 105.61, 105.61],[117.65, 117.65, 117.65],[5.30, 5.30, 5.30],[6.15, 6.15, 6.15],[8.76, 8.76, 8.76],[97.81, 97.81, 97.81],[20.27, 20.27, 20.27],[25.01, 25.01, 25.01],[108.09, 108.09, 108.09],[10.33, 10.33, 10.33],[84.74, 84.74, 84.74],[53.85, 53.85, 53.85],[175.39, 175.39, 175.39],[1287.56, 1287.56, 1287.56],[8079.38, 8079.38, 8079.38],[2583.53, 2583.53, 2583.53],[2869.29, 2869.29, 2869.29],[3677.08, 3677.08, 3677.08],[5948.79, 5948.79, 5948.79],[2860.97, 2860.97, 2860.97],[8772.65, 8772.65, 8772.65],[214.39, 214.39, 214.39],[569.57, 569.57, 569.57]
				]


EP1Seq = np.log10(EP1Seq)
EP1Paralel1 = np.log10(EP1Paralel1)
EP1Paralel2 = np.log10(EP1Paralel2)
EP1Paralel3 = np.log10(EP1Paralel3)

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


for i in range(74):
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


fig = plt.figure(figsize=(75,10))
ax1 = fig.add_subplot(111)


colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, stdEP1Seq,label=r'1 (log10)', color=colors, fmt='o', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Seq)))*2, mediaEP1Seq, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, stdEP1Paralel1,label=r'8 (log10)', color=colors, fmt='+', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel1)))*2, mediaEP1Paralel1, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, stdEP1Paralel2,label=r'16 (log10)', color=colors, fmt='.', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
plt.plot(np.array(range(len(mediaEP1Paralel2)))*2, mediaEP1Paralel2, color=colors,lw=2)

colors = "#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
plt.errorbar(np.array(range(len(mediaEP1Paralel3)))*2, mediaEP1Paralel3, stdEP1Paralel3,label=r'32 (log10)', color=colors, fmt='h', lw=1, capsize=4, markersize=8, markeredgecolor=colors, markerfacecolor=colors)
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
ax1.set_title('EP2 - Por Nucleo Total', fontsize=fontSize+3, fontweight='bold')
ax1.set_xlabel(r'Senhas Verificadas', fontsize=fontSize+2)
ax1.set_ylabel('Tempo medio (em microseg)', fontsize=fontSize+2)
ax1.xaxis.set_label_coords(0.5, -0.08)
ax1.set_facecolor('white')


handles, labels = ax1.get_legend_handles_labels()
leg = ax1.legend(handles, labels, bbox_to_anchor=(0.01, 0.98), loc=2, borderaxespad=0., fontsize=fontSize)
leg.get_frame().set_facecolor('#FFFFFF')
# plt.legend(title=r'Compilador')
ticksx =	['0', '00', '000', '0000', '00000', '000000', '012ab', '54321', '9', '99', '999', '9999', '99999', '999999', 'A', 'a', 'A1B2', 'A2019', 'aa', 'AA', 'AAA', 'aaa', 'aaaa', 'AAAA', 'aaaaa', 'AAAAA', 'aaaaaa', 'AAAAAA', 'abc12', 'AbCdE', 'admin', 'amor', 'ceunes', 'E', 'EE', 'EEE', 'EEEE', 'EEEEE', 'EEEEEE', 'etc', 'globo', 'jesus', 'love', 'm', 'M', 'mateus', 'mm', 'MM', 'mmm', 'MMM', 'mmmm', 'MMMM', 'mmmmm', 'MMMMM', 'mmmmmm', 'MMMMMM', 'money', 'ninja', 'pass', 'Red', 'senha', 'sexy', 'Z', 'z', 'ZZ', 'zz', 'zzz', 'ZZZ', 'ZZZZ', 'zzzz', 'ZZZZZ', 'zzzzz', 'ZZZZZZ', 'zzzzzz']
# ticksx = 	['0', '00', '000', '0000', '00000', '000000', '012ab', '54321', '9', '99', '999', '9999', '99999', '999999', 'a', 'A', 'A1B2', 'A2019', 'aa', 'AA', 'aaa', 'AAA', 'aaaa', 'AAAA', 'aaaaa', 'AAAAA', 'aaaaaa', 'AAAAAA', 'abc12', 'AbCdE', 'admin', 'amor', 'ceunes', 'E', 'EE', 'EEE', 'EEEE', 'EEEEE', 'EEEEEE', 'etc', 'globo', 'jesus', 'love', 'm', 'M', 'mateus', 'mm', 'MM', 'mmm', 'MMM', 'mmmm', 'MMMM', 'mmmmm', 'MMMMM', 'mmmmmm', 'MMMMMM', 'money', 'ninja', 'pass', 'Red', 'senha', 'sexy', 'z', 'Z', 'zz', 'ZZ', 'zzz', 'ZZZ', 'zzzz', 'ZZZZ', 'zzzzz', 'ZZZZZ', 'zzzzzz', 'ZZZZZZ']
# ticksx = 	['a', 'm', 'z', 'E', 'A', 'M', 'Z', '0', '9', 'aa', 'mm', 'zz', 'EE', 'AA', 'MM', 'ZZ', '00', '99', 'aaa', 'mmm', 'zzz', 'EEE', 'AAA', 'MMM', 'ZZZ', '000', '999', 'etc', 'Red', 'aaaa', 'mmmm', 'zzzz', 'EEEE', 'AAAA', 'MMMM', 'ZZZZ', '0000', '9999', 'amor', 'love', 'pass', 'sexy', 'A1B2', 'aaaaa', 'mmmmm', 'zzzzz', 'AAAAA', 'EEEEE', 'MMMMM', 'ZZZZZ', '00000', '99999', '54321', 'abc12', 'AbCdE', 'admin', 'jesus', 'globo', 'money', 'ninja', 'senha', 'A2019', '012ab', 'aaaaaa', 'mmmmmm', 'zzzzzz', 'AAAAAA', 'EEEEEE', 'MMMMMM', 'ZZZZZZ', '000000', '999999', 'mateus', 'ceunes']
# ticksx = 	['a', 'm', 'z', 'E', 'A', 'M', 'Z', '0', '9', 'aa', 'mm', 'zz', 'EE', 'AA', 'MM', 'ZZ', '00', '99', 'aaa', 'mmm', 'zzz', 'EEE', '000', 'Red', 'mmmm', 'zzzz', 'EEEE', 'AAAA', 'MMMM', 'ZZZZ', '0000', '9999', 'amor', 'love', 'pass', 'sexy', 'A1B2', 'aaaaa', 'mmmmm', 'zzzzz', 'AAAAA', 'EEEEE', 'MMMMM', 'ZZZZZ', '00000', '99999', '54321', 'abc12', 'AbCdE', 'admin', 'jesus', 'globo', 'money', 'ninja', 'senha', 'A2019', '012ab', 'aaaaaa', 'mmmmmm', 'zzzzzz', 'AAAAAA', 'EEEEEE', '999999']
# ticksy = ['0', '50000', '100000', '150000', '200000', '250000', '300000', '350000', '400000', '450000']
plt.xticks(range(0, len(ticksx)*2, 2), ticksx, fontsize=fontSize)
# plt.yticks(range(0, len(ticksy)*2, 2), ticksy, fontsize=fontSize)
plt.xlim(-1, len(ticksx)* 2 - 1)
# plt.ylim(-1, len(ticksy)* 2 - 1)


plt.tight_layout()
# plt.show()

plt.savefig('GraficoEp2PorNucleoFULL.pdf',bbox_inches='tight')
