/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _DT_BINDINGS_CLK_QCOM_CAM_CC_PINEAPPLE_H
#define _DT_BINDINGS_CLK_QCOM_CAM_CC_PINEAPPLE_H

/* CAM_CC clocks */
#define CAM_CC_BPS_AHB_CLK					0
#define CAM_CC_BPS_CLK						1
#define CAM_CC_BPS_CLK_SRC					2
#define CAM_CC_BPS_FAST_AHB_CLK					3
#define CAM_CC_BPS_SHIFT_CLK					4
#define CAM_CC_CAMNOC_AXI_NRT_CLK				5
#define CAM_CC_CAMNOC_AXI_RT_CLK				6
#define CAM_CC_CAMNOC_AXI_RT_CLK_SRC				7
#define CAM_CC_CAMNOC_DCD_XO_CLK				8
#define CAM_CC_CAMNOC_XO_CLK					9
#define CAM_CC_CCI_0_CLK					10
#define CAM_CC_CCI_0_CLK_SRC					11
#define CAM_CC_CCI_1_CLK					12
#define CAM_CC_CCI_1_CLK_SRC					13
#define CAM_CC_CCI_2_CLK					14
#define CAM_CC_CCI_2_CLK_SRC					15
#define CAM_CC_CORE_AHB_CLK					16
#define CAM_CC_CPAS_AHB_CLK					17
#define CAM_CC_CPAS_BPS_CLK					18
#define CAM_CC_CPAS_CRE_CLK					19
#define CAM_CC_CPAS_FAST_AHB_CLK				20
#define CAM_CC_CPAS_IFE_0_CLK					21
#define CAM_CC_CPAS_IFE_1_CLK					22
#define CAM_CC_CPAS_IFE_2_CLK					23
#define CAM_CC_CPAS_IFE_LITE_CLK				24
#define CAM_CC_CPAS_IPE_NPS_CLK					25
#define CAM_CC_CPAS_SBI_CLK					26
#define CAM_CC_CPAS_SFE_0_CLK					27
#define CAM_CC_CPAS_SFE_1_CLK					28
#define CAM_CC_CPAS_SFE_2_CLK					29
#define CAM_CC_CPHY_RX_CLK_SRC					30
#define CAM_CC_CRE_AHB_CLK					31
#define CAM_CC_CRE_CLK						32
#define CAM_CC_CRE_CLK_SRC					33
#define CAM_CC_CSI0PHYTIMER_CLK					34
#define CAM_CC_CSI0PHYTIMER_CLK_SRC				35
#define CAM_CC_CSI1PHYTIMER_CLK					36
#define CAM_CC_CSI1PHYTIMER_CLK_SRC				37
#define CAM_CC_CSI2PHYTIMER_CLK					38
#define CAM_CC_CSI2PHYTIMER_CLK_SRC				39
#define CAM_CC_CSI3PHYTIMER_CLK					40
#define CAM_CC_CSI3PHYTIMER_CLK_SRC				41
#define CAM_CC_CSI4PHYTIMER_CLK					42
#define CAM_CC_CSI4PHYTIMER_CLK_SRC				43
#define CAM_CC_CSI5PHYTIMER_CLK					44
#define CAM_CC_CSI5PHYTIMER_CLK_SRC				45
#define CAM_CC_CSI6PHYTIMER_CLK					46
#define CAM_CC_CSI6PHYTIMER_CLK_SRC				47
#define CAM_CC_CSI7PHYTIMER_CLK					48
#define CAM_CC_CSI7PHYTIMER_CLK_SRC				49
#define CAM_CC_CSID_CLK						50
#define CAM_CC_CSID_CLK_SRC					51
#define CAM_CC_CSID_CSIPHY_RX_CLK				52
#define CAM_CC_CSIPHY0_CLK					53
#define CAM_CC_CSIPHY1_CLK					54
#define CAM_CC_CSIPHY2_CLK					55
#define CAM_CC_CSIPHY3_CLK					56
#define CAM_CC_CSIPHY4_CLK					57
#define CAM_CC_CSIPHY5_CLK					58
#define CAM_CC_CSIPHY6_CLK					59
#define CAM_CC_CSIPHY7_CLK					60
#define CAM_CC_DRV_AHB_CLK					61
#define CAM_CC_DRV_XO_CLK					62
#define CAM_CC_FAST_AHB_CLK_SRC					63
#define CAM_CC_GDSC_CLK						64
#define CAM_CC_ICP_AHB_CLK					65
#define CAM_CC_ICP_CLK						66
#define CAM_CC_ICP_CLK_SRC					67
#define CAM_CC_IFE_0_CLK					68
#define CAM_CC_IFE_0_CLK_SRC					69
#define CAM_CC_IFE_0_FAST_AHB_CLK				70
#define CAM_CC_IFE_0_SHIFT_CLK					71
#define CAM_CC_IFE_1_CLK					72
#define CAM_CC_IFE_1_CLK_SRC					73
#define CAM_CC_IFE_1_FAST_AHB_CLK				74
#define CAM_CC_IFE_1_SHIFT_CLK					75
#define CAM_CC_IFE_2_CLK					76
#define CAM_CC_IFE_2_CLK_SRC					77
#define CAM_CC_IFE_2_FAST_AHB_CLK				78
#define CAM_CC_IFE_2_SHIFT_CLK					79
#define CAM_CC_IFE_LITE_AHB_CLK					80
#define CAM_CC_IFE_LITE_CLK					81
#define CAM_CC_IFE_LITE_CLK_SRC					82
#define CAM_CC_IFE_LITE_CPHY_RX_CLK				83
#define CAM_CC_IFE_LITE_CSID_CLK				84
#define CAM_CC_IFE_LITE_CSID_CLK_SRC				85
#define CAM_CC_IPE_NPS_AHB_CLK					86
#define CAM_CC_IPE_NPS_CLK					87
#define CAM_CC_IPE_NPS_CLK_SRC					88
#define CAM_CC_IPE_NPS_FAST_AHB_CLK				89
#define CAM_CC_IPE_PPS_CLK					90
#define CAM_CC_IPE_PPS_FAST_AHB_CLK				91
#define CAM_CC_IPE_SHIFT_CLK					92
#define CAM_CC_JPEG_1_CLK					93
#define CAM_CC_JPEG_CLK						94
#define CAM_CC_JPEG_CLK_SRC					95
#define CAM_CC_MCLK0_CLK					96
#define CAM_CC_MCLK0_CLK_SRC					97
#define CAM_CC_MCLK1_CLK					98
#define CAM_CC_MCLK1_CLK_SRC					99
#define CAM_CC_MCLK2_CLK					100
#define CAM_CC_MCLK2_CLK_SRC					101
#define CAM_CC_MCLK3_CLK					102
#define CAM_CC_MCLK3_CLK_SRC					103
#define CAM_CC_MCLK4_CLK					104
#define CAM_CC_MCLK4_CLK_SRC					105
#define CAM_CC_MCLK5_CLK					106
#define CAM_CC_MCLK5_CLK_SRC					107
#define CAM_CC_MCLK6_CLK					108
#define CAM_CC_MCLK6_CLK_SRC					109
#define CAM_CC_MCLK7_CLK					110
#define CAM_CC_MCLK7_CLK_SRC					111
#define CAM_CC_PLL0						112
#define CAM_CC_PLL0_OUT_EVEN					113
#define CAM_CC_PLL0_OUT_ODD					114
#define CAM_CC_PLL1						115
#define CAM_CC_PLL10						116
#define CAM_CC_PLL10_OUT_EVEN					117
#define CAM_CC_PLL1_OUT_EVEN					118
#define CAM_CC_PLL2						119
#define CAM_CC_PLL3						120
#define CAM_CC_PLL3_OUT_EVEN					121
#define CAM_CC_PLL4						122
#define CAM_CC_PLL4_OUT_EVEN					123
#define CAM_CC_PLL5						124
#define CAM_CC_PLL5_OUT_EVEN					125
#define CAM_CC_PLL6						126
#define CAM_CC_PLL6_OUT_EVEN					127
#define CAM_CC_PLL7						128
#define CAM_CC_PLL7_OUT_EVEN					129
#define CAM_CC_PLL8						130
#define CAM_CC_PLL8_OUT_EVEN					131
#define CAM_CC_PLL9						132
#define CAM_CC_PLL9_OUT_EVEN					133
#define CAM_CC_PLL9_OUT_ODD					134
#define CAM_CC_QDSS_DEBUG_CLK					135
#define CAM_CC_QDSS_DEBUG_CLK_SRC				136
#define CAM_CC_QDSS_DEBUG_XO_CLK				137
#define CAM_CC_SBI_CLK						138
#define CAM_CC_SBI_FAST_AHB_CLK					139
#define CAM_CC_SBI_SHIFT_CLK					140
#define CAM_CC_SFE_0_CLK					141
#define CAM_CC_SFE_0_CLK_SRC					142
#define CAM_CC_SFE_0_FAST_AHB_CLK				143
#define CAM_CC_SFE_0_SHIFT_CLK					144
#define CAM_CC_SFE_1_CLK					145
#define CAM_CC_SFE_1_CLK_SRC					146
#define CAM_CC_SFE_1_FAST_AHB_CLK				147
#define CAM_CC_SFE_1_SHIFT_CLK					148
#define CAM_CC_SFE_2_CLK					149
#define CAM_CC_SFE_2_CLK_SRC					150
#define CAM_CC_SFE_2_FAST_AHB_CLK				151
#define CAM_CC_SFE_2_SHIFT_CLK					152
#define CAM_CC_SLEEP_CLK					153
#define CAM_CC_SLEEP_CLK_SRC					154
#define CAM_CC_SLOW_AHB_CLK_SRC					155
#define CAM_CC_TITAN_TOP_SHIFT_CLK				156
#define CAM_CC_XO_CLK_SRC					157

/* CAM_CC resets */
#define CAM_CC_BPS_BCR						0
#define CAM_CC_DRV_BCR						1
#define CAM_CC_ICP_BCR						2
#define CAM_CC_IFE_0_BCR					3
#define CAM_CC_IFE_1_BCR					4
#define CAM_CC_IFE_2_BCR					5
#define CAM_CC_IPE_0_BCR					6
#define CAM_CC_QDSS_DEBUG_BCR					7
#define CAM_CC_SBI_BCR						8
#define CAM_CC_SFE_0_BCR					9
#define CAM_CC_SFE_1_BCR					10
#define CAM_CC_SFE_2_BCR					11

#endif
