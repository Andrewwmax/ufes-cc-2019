import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np
import random


EP1Seq = [
[3163.53,	2943.31,	2934.73,	2946.43,	2960.94,	2934.12,	2940.34,	2954.83,	2955.95,	2980.45,	3093.21,	2951.15,	3070.36,	2956.27],
[3000.83,	2995.46,	2968.16,	2991.22,	2951.64,	3060.52,	2954.85,	3045.76,	3129.07,	3004.12,	3090.21,	3042.53, 	3019.49,	3859.6 ],
[6222.18,	6183.79,	6085.46,	6234.45,	6234.08,	6209.05,	6098.19,	6232.93,	6129.42,	6316.7,		6111.36,	6056.91,	6000.84,	6038.62],
[18968.4,	18986,		19031.1,	19068,		18993.2,	18981.9,	19121,		18991.8,	19144.8,	18963,		19086.1,	18998.3,	19050.4,	18993  ],
[34243,		34366,		34243,		34437.3,	35258.7,	34399.6,	34345.5,	34203.1,	34264.1,	34359.2,	34220.3,	34115,		34269.8,	34202.7],
[195897,	196060,		196194,		196268,		196615,		196051,		192978,		195385,		195947,		195797,		193845,		190516,		195425,		195466 ]
]

EP1Paralel1 = [
[2964.51,	2980.8,		2955.91,	2947.05,	3021.73,	2989.92,	3032.54,	2941.07,	2931.01,	2926.27,	2931.58,	2925.94,	2926,		2944.71],
[2990.74,	2998.31,	3013.92,	2958.85,	2958.36,	2962,		2964,		2948.12,	2949.08,	2958.92,	2946.81,	2954.12,	2966.84,	3019.07],
[6372.06,	6526.49,	6346.65,	6490.51,	6396.1,		6343.92,	6370.31,	6399.4,		6451.82,	6372.32,	6380.98,	6359.79,	6389.57,	6371.62],
[20120.4,	20102.5,	20108.4,	20066.5,	20244.2,	20130.5,	20037.1,	20141.9,	20318.2,	20022.1,	20015.9,	20042.3,	20034,		20063.1],
[36899,		37001.1,	37047.1,	36976.4,	37075.4,	36944.8,	37025.1,	36937.6,	37000.2,	37064.8,	37144.2,	36962.2,	37093.9,	36973.1],
[196871,	197268,		197609,		197079,		196423,		200830,		202386,		201827,		200765,		200337,		203281,		200484,		203688,		200786]
]

EP1Paralel2 = [
[2786.18,	2788.97,	2788.58,	2791.88,	2778.56,	2786.07,	2781.15,	2778.12,	2786.01,	2779.61,	2789.48,	2782.22,	2788.65,	2797.29],
[2846.17,	2789.65,	2794.28,	2804.42,	2827.25,	2808.07,	2872.95,	2833.81,	2792.7,		2809.07,	2804.72,	2803.71,	2805.83,	2809.02],
[4561.46,	4559.76,	4560.29,	4562.77,	4596.59,	4559.71,	4565.71,	4552.22,	4556.79,	4564.61,	4588.48,	4570.32,	4576.07,	4652.67],
[11648.6,	11653.3,	11737.1,	11704.4,	11855.5,	11847.1,	11830,		11850,		11864.8,	11841.6,	11854.3,	11877.4,	11869.2,	11863.3],
[21195.1,	21192.9,	21216.3,	21202.3,	21207.6,	21212.6,	21215,		21304.9,	21231,		21221.1,	21242.1,	21285.7,	21183.7,	21262.7],
[115120,	117391,		117305,		124889,		119670,		119418,		111477,		111631,		112165,		112076,		111886,		112843,		110715,		112583]
]

EP1Paralel3 = [
[2833.46,	2796.84,	2809.95,	2785.14,	2832.84,	2794.96,	2801.6,		2791.41,	2801.14,	2823.35,	2802.54,	2789.52,	2795.79,	2808.2],
[2824.06,	2806.96,	2815.4,		2806.5,		2817.22,	2811.64,	2803.67,	2805.94,	2813.18,	2803.27,	2809.07,	2805.78,	2818.63,	2844.33],
[4508.1,	4514.51,	4497.55,	4491.57,	4494.84,	4497.23,	4489.75,	4518.87,	4504.38,	4500.1,		4504.01,	4506.55,	4456.5,		4542.19],
[11449.4,	11574.2,	11435.3,	11438.6,	12178.9,	11515.5,	11634.4,	11662,		11648.6,	11609.1,	11602.5,	11601.6,	11637.1,	11697.5],
[21463.7,	21249,		20962.1,	20890.2,	20879.6,	21402.5,	21446.7,	20778.3,	21032,		21669.2,	20611.5,	20885.2,	21317.7,	21331.7],
[108530,	105056,		105760,		107347,		107073,		109210,		109008,		111838,		106566,		105640,		110613,		106664,		106513,		106865]
]

EP1Paralel4 = [
[2769.16,	2766.23,	2771.61,	2771.68,	2775.79,	2762.83,	2784.04,	2764.44,	2765.37,	2765.54,	2760.42,	2763.45,	2759.11,	2761.25],
[2797.6,	2793.75,	2792.47,	2794.63,	2789.87,	2789.03,	2800.54,	2785.14,	2779.87,	2785.48,	2788.03,	2786.41,	2782.06,	2778.69],
[4351.22,	4378.46,	4349.21,	4362.02,	4357.24,	4344.25,	4358.37,	4356.34,	4356.61,	4342.64,	4345.86,	4348.71,	4348.89,	4348.64],
[10912.4,	10739.4,	10716.8,	10820,		10922.4,	10971.6,	11002.7,	10969.1,	10973.2,	10996.3,	10942.7,	10971.3,	11038.5,	10890.4],
[19417.7,	19435.8,	19384.9,	19439.2,	19444.5,	19390.3,	19555.4,	19770.9,	19475.6,	19460.2,	19404.6,	19466.1,	19341.9,	19442],
[97155.4,	96772,		99187.2,	96562.5,	98454.6,	96707.4,	96705.3,	96567.7,	96608.6,	95779.6,	96186.8,	96580.2,	99530.5,	97915.6]
]

EP1Paralel8 = [
[2800.81,	2780.67,	2762.92,	2766.75,	2760.68,	2767.67,	2800.93,	2757.03,	2768.55,	2755.19,	2768.21,	3024.68,	2765.91,	2756.99],
[2794.23,	2794.2,		2807.39,	2805.68,	2775.74,	2788.28,	2792.12,	3038.82,	2792.61,	2799.52,	2798.33,	2788.91,	2830.37,	2778.4],
[4383.74,	4356.64,	4345.91,	4341.88,	4364.84,	4355.92,	4341.08,	4381.08,	4355.06,	4350.34,	4363.2,		4377.07,	4349.18,	4349.91],
[10763.4,	10788.7,	10744.9,	10737.8,	10930.4,	10951.6,	10921.6,	10890.3,	10932.1,	10997.4,	10856,		10879.7,	10861.5,	10875.5],
[19590.1,	19951.5,	20712.1,	19758.7,	19806.4,	19825,		19947.5,	19753.7,	20123.9,	19766.8,	19735.1,	19854.5,	19821,		20890.8],
[95703.2,	96775.9,	97704.8,	95464.6,	97844.7,	96981.8,	95940.4,	97328.1,	96964.5,	95174.4,	97742.1,	94848.9,	97215.3,	96984.7]
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
ax1.set_title('EP1 - Sequencial e Paralelo - Total', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoEP1-Seq-Par-Total.pdf',bbox_inches='tight')
