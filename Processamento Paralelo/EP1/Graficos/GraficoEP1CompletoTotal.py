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

EP1Hash = [
[8261.47,	8255.4,		8559.3,		8419.45,	8347.24,	8140.57,	8536.76,	8272.07,	8251.51,	8265.46,	8273.48,	8131.68,	8292.99,	8157.35],
[8165.74,	8164.25,	8303.15,	8325.16,	8124.15,	8348.24,	8333,		8134.11,	8179.05,	8399.32,	9640.9,		10055.3,	9111.24,	8882.38],
[8603.82,	8708.47,	9826.66,	9017.63,	9111.52,	8960.41,	9148.74,	9220.12,	9277.96,	9519.75,	10422.5,	10229.6,	9196.39,	9267.17],
[9556.89,	9365.04,	9245.11,	9109.26,	9755.26,	9045,		9521.5,		10386.8,	11408.6,	10811.3,	9061.94,	9233.2,		9307.61,	9269.08],
[8000.1,	8128.94,	8010.52,	7984.97,	8159.45,	8156.38,	8189.94,	8001.65,	8183.69,	8093.4,		8175.72,	8274.35,	8174.67,	7978.18],
[10247.3,	10036,		10241.2,	9895.06,	9385.96,	9357.45,	9467.28,	9336.99,	9201.34,	9247.25,	9138.52,	9156.33,	8859.69,	8987.28]
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
ax1.set_title('EP1 - Completo - Total', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoEP1CompletoTotal.pdf',bbox_inches='tight')
