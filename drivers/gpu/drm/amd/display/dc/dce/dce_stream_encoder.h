/*
 * Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_STREAM_ENCODER_DCE110_H__
#define __DC_STREAM_ENCODER_DCE110_H__

#include "stream_encoder.h"

#define DCE110STRENC_FROM_STRENC(stream_encoder)\
	container_of(stream_encoder, struct dce110_stream_encoder, base)

#ifndef TMDS_CNTL__TMDS_PIXEL_ENCODING_MASK
	#define TMDS_CNTL__TMDS_PIXEL_ENCODING_MASK       0x00000010L
	#define TMDS_CNTL__TMDS_COLOR_FORMAT_MASK         0x00000300L
	#define	TMDS_CNTL__TMDS_PIXEL_ENCODING__SHIFT     0x00000004
	#define	TMDS_CNTL__TMDS_COLOR_FORMAT__SHIFT       0x00000008
#endif


#define SE_COMMON_REG_LIST_DCE_BASE(id) \
	SE_COMMON_REG_LIST_BASE(id),\
	SRI(AFMT_AVI_INFO0, DIG, id), \
	SRI(AFMT_AVI_INFO1, DIG, id), \
	SRI(AFMT_AVI_INFO2, DIG, id), \
	SRI(AFMT_AVI_INFO3, DIG, id)

#define SE_COMMON_REG_LIST_BASE(id) \
	SRI(AFMT_GENERIC_0, DIG, id), \
	SRI(AFMT_GENERIC_1, DIG, id), \
	SRI(AFMT_GENERIC_2, DIG, id), \
	SRI(AFMT_GENERIC_3, DIG, id), \
	SRI(AFMT_GENERIC_4, DIG, id), \
	SRI(AFMT_GENERIC_5, DIG, id), \
	SRI(AFMT_GENERIC_6, DIG, id), \
	SRI(AFMT_GENERIC_7, DIG, id), \
	SRI(AFMT_GENERIC_HDR, DIG, id), \
	SRI(AFMT_INFOFRAME_CONTROL0, DIG, id), \
	SRI(AFMT_VBI_PACKET_CONTROL, DIG, id), \
	SRI(AFMT_AUDIO_PACKET_CONTROL, DIG, id), \
	SRI(AFMT_AUDIO_PACKET_CONTROL2, DIG, id), \
	SRI(AFMT_AUDIO_SRC_CONTROL, DIG, id), \
	SRI(AFMT_60958_0, DIG, id), \
	SRI(AFMT_60958_1, DIG, id), \
	SRI(AFMT_60958_2, DIG, id), \
	SRI(DIG_FE_CNTL, DIG, id), \
	SRI(HDMI_CONTROL, DIG, id), \
	SRI(HDMI_GC, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL0, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL1, DIG, id), \
	SRI(HDMI_INFOFRAME_CONTROL0, DIG, id), \
	SRI(HDMI_INFOFRAME_CONTROL1, DIG, id), \
	SRI(HDMI_VBI_PACKET_CONTROL, DIG, id), \
	SRI(HDMI_AUDIO_PACKET_CONTROL, DIG, id),\
	SRI(HDMI_ACR_PACKET_CONTROL, DIG, id),\
	SRI(HDMI_ACR_32_0, DIG, id),\
	SRI(HDMI_ACR_32_1, DIG, id),\
	SRI(HDMI_ACR_44_0, DIG, id),\
	SRI(HDMI_ACR_44_1, DIG, id),\
	SRI(HDMI_ACR_48_0, DIG, id),\
	SRI(HDMI_ACR_48_1, DIG, id),\
	SRI(TMDS_CNTL, DIG, id), \
	SRI(DP_MSE_RATE_CNTL, DP, id), \
	SRI(DP_MSE_RATE_UPDATE, DP, id), \
	SRI(DP_PIXEL_FORMAT, DP, id), \
	SRI(DP_SEC_CNTL, DP, id), \
	SRI(DP_STEER_FIFO, DP, id), \
	SRI(DP_VID_M, DP, id), \
	SRI(DP_VID_N, DP, id), \
	SRI(DP_VID_STREAM_CNTL, DP, id), \
	SRI(DP_VID_TIMING, DP, id), \
	SRI(DP_SEC_AUD_N, DP, id), \
	SRI(DP_SEC_TIMESTAMP, DP, id)

#define SE_COMMON_REG_LIST(id)\
	SE_COMMON_REG_LIST_DCE_BASE(id), \
	SRI(AFMT_CNTL, DIG, id)

#define SE_DCN_REG_LIST(id)\
	SE_COMMON_REG_LIST_BASE(id),\
	SRI(AFMT_CNTL, DIG, id),\
	SRI(AFMT_VBI_PACKET_CONTROL1, DIG, id),\
	SRI(HDMI_GENERIC_PACKET_CONTROL2, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL3, DIG, id), \
	SRI(DP_DB_CNTL, DP, id), \
	SRI(DP_MSA_MISC, DP, id), \
	SRI(DP_MSA_COLORIMETRY, DP, id), \
	SRI(DP_MSA_TIMING_PARAM1, DP, id), \
	SRI(DP_MSA_TIMING_PARAM2, DP, id), \
	SRI(DP_MSA_TIMING_PARAM3, DP, id), \
	SRI(DP_MSA_TIMING_PARAM4, DP, id), \
	SRI(HDMI_DB_CONTROL, DIG, id)

#define SE_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define SE_COMMON_MASK_SH_LIST_DCE_COMMON(mask_sh)\
	SE_SF(AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC_INDEX, mask_sh),\
	SE_SF(AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC0_UPDATE, mask_sh),\
	SE_SF(AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC2_UPDATE, mask_sh),\
	SE_SF(AFMT_GENERIC_HDR, AFMT_GENERIC_HB0, mask_sh),\
	SE_SF(AFMT_GENERIC_HDR, AFMT_GENERIC_HB1, mask_sh),\
	SE_SF(AFMT_GENERIC_HDR, AFMT_GENERIC_HB2, mask_sh),\
	SE_SF(AFMT_GENERIC_HDR, AFMT_GENERIC_HB3, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_CONT, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_SEND, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_LINE, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_CONT, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_SEND, mask_sh),\
	SE_SF(HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_LINE, mask_sh),\
	SE_SF(DP_PIXEL_FORMAT, DP_PIXEL_ENCODING, mask_sh),\
	SE_SF(DP_PIXEL_FORMAT, DP_COMPONENT_DEPTH, mask_sh),\
	SE_SF(DP_PIXEL_FORMAT, DP_DYN_RANGE, mask_sh),\
	SE_SF(DP_PIXEL_FORMAT, DP_YCBCR_RANGE, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_PACKET_GEN_VERSION, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_KEEPOUT_MODE, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_DEEP_COLOR_ENABLE, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_DEEP_COLOR_DEPTH, mask_sh),\
	SE_SF(HDMI_VBI_PACKET_CONTROL, HDMI_GC_CONT, mask_sh),\
	SE_SF(HDMI_VBI_PACKET_CONTROL, HDMI_GC_SEND, mask_sh),\
	SE_SF(HDMI_VBI_PACKET_CONTROL, HDMI_NULL_SEND, mask_sh),\
	SE_SF(HDMI_VBI_PACKET_CONTROL, HDMI_ACP_SEND, mask_sh),\
	SE_SF(HDMI_INFOFRAME_CONTROL0, HDMI_AUDIO_INFO_SEND, mask_sh),\
	SE_SF(AFMT_INFOFRAME_CONTROL0, AFMT_AUDIO_INFO_UPDATE, mask_sh),\
	SE_SF(HDMI_INFOFRAME_CONTROL1, HDMI_AUDIO_INFO_LINE, mask_sh),\
	SE_SF(HDMI_GC, HDMI_GC_AVMUTE, mask_sh),\
	SE_SF(DP_MSE_RATE_CNTL, DP_MSE_RATE_X, mask_sh),\
	SE_SF(DP_MSE_RATE_CNTL, DP_MSE_RATE_Y, mask_sh),\
	SE_SF(DP_MSE_RATE_UPDATE, DP_MSE_RATE_UPDATE_PENDING, mask_sh),\
	SE_SF(AFMT_AVI_INFO3, AFMT_AVI_INFO_VERSION, mask_sh),\
	SE_SF(HDMI_INFOFRAME_CONTROL0, HDMI_AVI_INFO_SEND, mask_sh),\
	SE_SF(HDMI_INFOFRAME_CONTROL0, HDMI_AVI_INFO_CONT, mask_sh),\
	SE_SF(HDMI_INFOFRAME_CONTROL1, HDMI_AVI_INFO_LINE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_GSP0_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_STREAM_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_GSP1_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_GSP2_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_GSP3_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_AVI_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_MPG_ENABLE, mask_sh),\
	SE_SF(DP_VID_STREAM_CNTL, DP_VID_STREAM_DIS_DEFER, mask_sh),\
	SE_SF(DP_VID_STREAM_CNTL, DP_VID_STREAM_ENABLE, mask_sh),\
	SE_SF(DP_VID_STREAM_CNTL, DP_VID_STREAM_STATUS, mask_sh),\
	SE_SF(DP_STEER_FIFO, DP_STEER_FIFO_RESET, mask_sh),\
	SE_SF(DP_VID_TIMING, DP_VID_M_N_GEN_EN, mask_sh),\
	SE_SF(DP_VID_N, DP_VID_N, mask_sh),\
	SE_SF(DP_VID_M, DP_VID_M, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_START, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_STEREOSYNC_SELECT, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_STEREOSYNC_GATE_EN, mask_sh),\
	SE_SF(AFMT_AUDIO_SRC_CONTROL, AFMT_AUDIO_SRC_SELECT, mask_sh),\
	SE_SF(AFMT_AUDIO_PACKET_CONTROL2, AFMT_AUDIO_CHANNEL_ENABLE, mask_sh),\
	SE_SF(HDMI_AUDIO_PACKET_CONTROL, HDMI_AUDIO_PACKETS_PER_LINE, mask_sh),\
	SE_SF(HDMI_AUDIO_PACKET_CONTROL, HDMI_AUDIO_DELAY_EN, mask_sh),\
	SE_SF(AFMT_AUDIO_PACKET_CONTROL, AFMT_60958_CS_UPDATE, mask_sh),\
	SE_SF(AFMT_AUDIO_PACKET_CONTROL2, AFMT_AUDIO_LAYOUT_OVRD, mask_sh),\
	SE_SF(AFMT_AUDIO_PACKET_CONTROL2, AFMT_60958_OSF_OVRD, mask_sh),\
	SE_SF(HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUTO_SEND, mask_sh),\
	SE_SF(HDMI_ACR_PACKET_CONTROL, HDMI_ACR_SOURCE, mask_sh),\
	SE_SF(HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUDIO_PRIORITY, mask_sh),\
	SE_SF(HDMI_ACR_32_0, HDMI_ACR_CTS_32, mask_sh),\
	SE_SF(HDMI_ACR_32_1, HDMI_ACR_N_32, mask_sh),\
	SE_SF(HDMI_ACR_44_0, HDMI_ACR_CTS_44, mask_sh),\
	SE_SF(HDMI_ACR_44_1, HDMI_ACR_N_44, mask_sh),\
	SE_SF(HDMI_ACR_48_0, HDMI_ACR_CTS_48, mask_sh),\
	SE_SF(HDMI_ACR_48_1, HDMI_ACR_N_48, mask_sh),\
	SE_SF(AFMT_60958_0, AFMT_60958_CS_CHANNEL_NUMBER_L, mask_sh),\
	SE_SF(AFMT_60958_0, AFMT_60958_CS_CLOCK_ACCURACY, mask_sh),\
	SE_SF(AFMT_60958_1, AFMT_60958_CS_CHANNEL_NUMBER_R, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_2, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_3, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_4, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_5, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_6, mask_sh),\
	SE_SF(AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_7, mask_sh),\
	SE_SF(DP_SEC_AUD_N, DP_SEC_AUD_N, mask_sh),\
	SE_SF(DP_SEC_TIMESTAMP, DP_SEC_TIMESTAMP_MODE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_ASP_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_ATP_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_AIP_ENABLE, mask_sh),\
	SE_SF(DP_SEC_CNTL, DP_SEC_ACM_ENABLE, mask_sh),\
	SE_SF(AFMT_AUDIO_PACKET_CONTROL, AFMT_AUDIO_SAMPLE_SEND, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_SOURCE_SELECT, mask_sh)

#define SE_COMMON_MASK_SH_LIST_SOC(mask_sh)\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC_INDEX, mask_sh),\
	SE_SF(DIG0_AFMT_GENERIC_HDR, AFMT_GENERIC_HB0, mask_sh),\
	SE_SF(DIG0_AFMT_GENERIC_HDR, AFMT_GENERIC_HB1, mask_sh),\
	SE_SF(DIG0_AFMT_GENERIC_HDR, AFMT_GENERIC_HB2, mask_sh),\
	SE_SF(DIG0_AFMT_GENERIC_HDR, AFMT_GENERIC_HB3, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_LINE, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_PIXEL_ENCODING, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_COMPONENT_DEPTH, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_PACKET_GEN_VERSION, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_KEEPOUT_MODE, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DEEP_COLOR_ENABLE, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DEEP_COLOR_DEPTH, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DATA_SCRAMBLE_EN, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_GC_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_GC_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_NULL_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_ACP_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL0, HDMI_AUDIO_INFO_SEND, mask_sh),\
	SE_SF(DIG0_AFMT_INFOFRAME_CONTROL0, AFMT_AUDIO_INFO_UPDATE, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL1, HDMI_AUDIO_INFO_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GC, HDMI_GC_AVMUTE, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_CNTL, DP_MSE_RATE_X, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_CNTL, DP_MSE_RATE_Y, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_UPDATE, DP_MSE_RATE_UPDATE_PENDING, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP0_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_STREAM_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP1_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP2_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP3_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_MPG_ENABLE, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_DIS_DEFER, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_ENABLE, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_STATUS, mask_sh),\
	SE_SF(DP0_DP_STEER_FIFO, DP_STEER_FIFO_RESET, mask_sh),\
	SE_SF(DP0_DP_VID_TIMING, DP_VID_M_N_GEN_EN, mask_sh),\
	SE_SF(DP0_DP_VID_N, DP_VID_N, mask_sh),\
	SE_SF(DP0_DP_VID_M, DP_VID_M, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_START, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_SRC_CONTROL, AFMT_AUDIO_SRC_SELECT, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_PACKET_CONTROL2, AFMT_AUDIO_CHANNEL_ENABLE, mask_sh),\
	SE_SF(DIG0_HDMI_AUDIO_PACKET_CONTROL, HDMI_AUDIO_PACKETS_PER_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_AUDIO_PACKET_CONTROL, HDMI_AUDIO_DELAY_EN, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_PACKET_CONTROL, AFMT_60958_CS_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_PACKET_CONTROL2, AFMT_AUDIO_LAYOUT_OVRD, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_PACKET_CONTROL2, AFMT_60958_OSF_OVRD, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUTO_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_SOURCE, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUDIO_PRIORITY, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_32_0, HDMI_ACR_CTS_32, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_32_1, HDMI_ACR_N_32, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_44_0, HDMI_ACR_CTS_44, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_44_1, HDMI_ACR_N_44, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_48_0, HDMI_ACR_CTS_48, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_48_1, HDMI_ACR_N_48, mask_sh),\
	SE_SF(DIG0_AFMT_60958_0, AFMT_60958_CS_CHANNEL_NUMBER_L, mask_sh),\
	SE_SF(DIG0_AFMT_60958_0, AFMT_60958_CS_CLOCK_ACCURACY, mask_sh),\
	SE_SF(DIG0_AFMT_60958_1, AFMT_60958_CS_CHANNEL_NUMBER_R, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_2, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_3, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_4, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_5, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_6, mask_sh),\
	SE_SF(DIG0_AFMT_60958_2, AFMT_60958_CS_CHANNEL_NUMBER_7, mask_sh),\
	SE_SF(DP0_DP_SEC_AUD_N, DP_SEC_AUD_N, mask_sh),\
	SE_SF(DP0_DP_SEC_TIMESTAMP, DP_SEC_TIMESTAMP_MODE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ASP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ATP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_AIP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ACM_ENABLE, mask_sh),\
	SE_SF(DIG0_AFMT_AUDIO_PACKET_CONTROL, AFMT_AUDIO_SAMPLE_SEND, mask_sh),\
	SE_SF(DIG0_AFMT_CNTL, AFMT_AUDIO_CLOCK_EN, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_CLOCK_CHANNEL_RATE, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, TMDS_PIXEL_ENCODING, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, TMDS_COLOR_FORMAT, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_STEREOSYNC_SELECT, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_STEREOSYNC_GATE_EN, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_SOURCE_SELECT, mask_sh)

#define SE_COMMON_MASK_SH_LIST_DCE80_100(mask_sh)\
	SE_COMMON_MASK_SH_LIST_DCE_COMMON(mask_sh),\
	SE_SF(TMDS_CNTL, TMDS_PIXEL_ENCODING, mask_sh),\
	SE_SF(TMDS_CNTL, TMDS_COLOR_FORMAT, mask_sh)

#define SE_COMMON_MASK_SH_LIST_DCE110(mask_sh)\
	SE_COMMON_MASK_SH_LIST_DCE_COMMON(mask_sh),\
	SE_SF(AFMT_CNTL, AFMT_AUDIO_CLOCK_EN, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_CLOCK_CHANNEL_RATE, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_DATA_SCRAMBLE_EN, mask_sh),\
	SE_SF(DIG_FE_CNTL, TMDS_PIXEL_ENCODING, mask_sh),\
	SE_SF(DIG_FE_CNTL, TMDS_COLOR_FORMAT, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_STEREOSYNC_SELECT, mask_sh),\
	SE_SF(DIG_FE_CNTL, DIG_STEREOSYNC_GATE_EN, mask_sh)

#define SE_COMMON_MASK_SH_LIST_DCE112(mask_sh)\
	SE_COMMON_MASK_SH_LIST_DCE_COMMON(mask_sh),\
	SE_SF(AFMT_CNTL, AFMT_AUDIO_CLOCK_EN, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_CLOCK_CHANNEL_RATE, mask_sh),\
	SE_SF(HDMI_CONTROL, HDMI_DATA_SCRAMBLE_EN, mask_sh),\
	SE_SF(DIG_FE_CNTL, TMDS_PIXEL_ENCODING, mask_sh),\
	SE_SF(DIG_FE_CNTL, TMDS_COLOR_FORMAT, mask_sh),\
	SE_SF(DP_VID_TIMING, DP_VID_M_DOUBLE_VALUE_EN, mask_sh)

#define SE_COMMON_MASK_SH_LIST_DCE120(mask_sh)\
	SE_COMMON_MASK_SH_LIST_SOC(mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC0_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC2_UPDATE, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_DYN_RANGE, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_YCBCR_RANGE, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL0, HDMI_AVI_INFO_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL0, HDMI_AVI_INFO_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL1, HDMI_AVI_INFO_LINE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_AVI_ENABLE, mask_sh),\
	SE_SF(DIG0_AFMT_AVI_INFO3, AFMT_AVI_INFO_VERSION, mask_sh),\
	SE_SF(DP0_DP_VID_TIMING, DP_VID_M_DOUBLE_VALUE_EN, mask_sh)

#define SE_COMMON_MASK_SH_LIST_DCN10(mask_sh)\
	SE_COMMON_MASK_SH_LIST_SOC(mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC_LOCK_STATUS, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC_CONFLICT, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL, AFMT_GENERIC_CONFLICT_CLR, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC0_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC1_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC2_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC3_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC4_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC5_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC6_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC7_FRAME_UPDATE_PENDING, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC0_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC1_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC2_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC3_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC4_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC5_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC6_FRAME_UPDATE, mask_sh),\
	SE_SF(DIG0_AFMT_VBI_PACKET_CONTROL1, AFMT_GENERIC7_FRAME_UPDATE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP4_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP5_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP6_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP7_ENABLE, mask_sh),\
	SE_SF(DP0_DP_DB_CNTL, DP_DB_DISABLE, mask_sh),\
	SE_SF(DP0_DP_MSA_COLORIMETRY, DP_MSA_MISC0, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM1, DP_MSA_HTOTAL, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM1, DP_MSA_VTOTAL, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM2, DP_MSA_HSTART, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM2, DP_MSA_VSTART, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_HSYNCWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_HSYNCPOLARITY, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_VSYNCWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_VSYNCPOLARITY, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM4, DP_MSA_HWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM4, DP_MSA_VHEIGHT, mask_sh),\
	SE_SF(DIG0_HDMI_DB_CONTROL, HDMI_DB_DISABLE, mask_sh),\
	SE_SF(DP0_DP_VID_TIMING, DP_VID_N_MUL, mask_sh)

struct dce_stream_encoder_shift {
	uint8_t AFMT_GENERIC_INDEX;
	uint8_t AFMT_GENERIC0_UPDATE;
	uint8_t AFMT_GENERIC2_UPDATE;
	uint8_t AFMT_GENERIC_HB0;
	uint8_t AFMT_GENERIC_HB1;
	uint8_t AFMT_GENERIC_HB2;
	uint8_t AFMT_GENERIC_HB3;
	uint8_t AFMT_GENERIC_LOCK_STATUS;
	uint8_t AFMT_GENERIC_CONFLICT;
	uint8_t AFMT_GENERIC_CONFLICT_CLR;
	uint8_t AFMT_GENERIC0_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC1_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC2_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC3_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC4_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC5_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC6_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC7_FRAME_UPDATE_PENDING;
	uint8_t AFMT_GENERIC0_FRAME_UPDATE;
	uint8_t AFMT_GENERIC1_FRAME_UPDATE;
	uint8_t AFMT_GENERIC2_FRAME_UPDATE;
	uint8_t AFMT_GENERIC3_FRAME_UPDATE;
	uint8_t AFMT_GENERIC4_FRAME_UPDATE;
	uint8_t AFMT_GENERIC5_FRAME_UPDATE;
	uint8_t AFMT_GENERIC6_FRAME_UPDATE;
	uint8_t AFMT_GENERIC7_FRAME_UPDATE;
	uint8_t HDMI_GENERIC0_CONT;
	uint8_t HDMI_GENERIC0_SEND;
	uint8_t HDMI_GENERIC0_LINE;
	uint8_t HDMI_GENERIC1_CONT;
	uint8_t HDMI_GENERIC1_SEND;
	uint8_t HDMI_GENERIC1_LINE;
	uint8_t DP_PIXEL_ENCODING;
	uint8_t DP_COMPONENT_DEPTH;
	uint8_t DP_DYN_RANGE;
	uint8_t DP_YCBCR_RANGE;
	uint8_t HDMI_PACKET_GEN_VERSION;
	uint8_t HDMI_KEEPOUT_MODE;
	uint8_t HDMI_DEEP_COLOR_ENABLE;
	uint8_t HDMI_CLOCK_CHANNEL_RATE;
	uint8_t HDMI_DEEP_COLOR_DEPTH;
	uint8_t HDMI_GC_CONT;
	uint8_t HDMI_GC_SEND;
	uint8_t HDMI_NULL_SEND;
	uint8_t HDMI_DATA_SCRAMBLE_EN;
	uint8_t HDMI_ACP_SEND;
	uint8_t HDMI_AUDIO_INFO_SEND;
	uint8_t AFMT_AUDIO_INFO_UPDATE;
	uint8_t HDMI_AUDIO_INFO_LINE;
	uint8_t HDMI_GC_AVMUTE;
	uint8_t DP_MSE_RATE_X;
	uint8_t DP_MSE_RATE_Y;
	uint8_t DP_MSE_RATE_UPDATE_PENDING;
	uint8_t AFMT_AVI_INFO_VERSION;
	uint8_t HDMI_AVI_INFO_SEND;
	uint8_t HDMI_AVI_INFO_CONT;
	uint8_t HDMI_AVI_INFO_LINE;
	uint8_t DP_SEC_GSP0_ENABLE;
	uint8_t DP_SEC_STREAM_ENABLE;
	uint8_t DP_SEC_GSP1_ENABLE;
	uint8_t DP_SEC_GSP2_ENABLE;
	uint8_t DP_SEC_GSP3_ENABLE;
	uint8_t DP_SEC_GSP4_ENABLE;
	uint8_t DP_SEC_GSP5_ENABLE;
	uint8_t DP_SEC_GSP6_ENABLE;
	uint8_t DP_SEC_GSP7_ENABLE;
	uint8_t DP_SEC_AVI_ENABLE;
	uint8_t DP_SEC_MPG_ENABLE;
	uint8_t DP_VID_STREAM_DIS_DEFER;
	uint8_t DP_VID_STREAM_ENABLE;
	uint8_t DP_VID_STREAM_STATUS;
	uint8_t DP_STEER_FIFO_RESET;
	uint8_t DP_VID_M_N_GEN_EN;
	uint8_t DP_VID_N;
	uint8_t DP_VID_M;
	uint8_t DIG_START;
	uint8_t AFMT_AUDIO_SRC_SELECT;
	uint8_t AFMT_AUDIO_CHANNEL_ENABLE;
	uint8_t HDMI_AUDIO_PACKETS_PER_LINE;
	uint8_t HDMI_AUDIO_DELAY_EN;
	uint8_t AFMT_60958_CS_UPDATE;
	uint8_t AFMT_AUDIO_LAYOUT_OVRD;
	uint8_t AFMT_60958_OSF_OVRD;
	uint8_t HDMI_ACR_AUTO_SEND;
	uint8_t HDMI_ACR_SOURCE;
	uint8_t HDMI_ACR_AUDIO_PRIORITY;
	uint8_t HDMI_ACR_CTS_32;
	uint8_t HDMI_ACR_N_32;
	uint8_t HDMI_ACR_CTS_44;
	uint8_t HDMI_ACR_N_44;
	uint8_t HDMI_ACR_CTS_48;
	uint8_t HDMI_ACR_N_48;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_L;
	uint8_t AFMT_60958_CS_CLOCK_ACCURACY;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_R;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_2;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_3;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_4;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_5;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_6;
	uint8_t AFMT_60958_CS_CHANNEL_NUMBER_7;
	uint8_t DP_SEC_AUD_N;
	uint8_t DP_SEC_TIMESTAMP_MODE;
	uint8_t DP_SEC_ASP_ENABLE;
	uint8_t DP_SEC_ATP_ENABLE;
	uint8_t DP_SEC_AIP_ENABLE;
	uint8_t DP_SEC_ACM_ENABLE;
	uint8_t AFMT_AUDIO_SAMPLE_SEND;
	uint8_t AFMT_AUDIO_CLOCK_EN;
	uint8_t TMDS_PIXEL_ENCODING;
	uint8_t TMDS_COLOR_FORMAT;
	uint8_t DIG_STEREOSYNC_SELECT;
	uint8_t DIG_STEREOSYNC_GATE_EN;
	uint8_t DP_DB_DISABLE;
	uint8_t DP_MSA_MISC0;
	uint8_t DP_MSA_HTOTAL;
	uint8_t DP_MSA_VTOTAL;
	uint8_t DP_MSA_HSTART;
	uint8_t DP_MSA_VSTART;
	uint8_t DP_MSA_HSYNCWIDTH;
	uint8_t DP_MSA_HSYNCPOLARITY;
	uint8_t DP_MSA_VSYNCWIDTH;
	uint8_t DP_MSA_VSYNCPOLARITY;
	uint8_t DP_MSA_HWIDTH;
	uint8_t DP_MSA_VHEIGHT;
	uint8_t HDMI_DB_DISABLE;
	uint8_t DP_VID_N_MUL;
	uint8_t DP_VID_M_DOUBLE_VALUE_EN;
	uint8_t DIG_SOURCE_SELECT;
};

struct dce_stream_encoder_mask {
	uint32_t AFMT_GENERIC_INDEX;
	uint32_t AFMT_GENERIC0_UPDATE;
	uint32_t AFMT_GENERIC2_UPDATE;
	uint32_t AFMT_GENERIC_HB0;
	uint32_t AFMT_GENERIC_HB1;
	uint32_t AFMT_GENERIC_HB2;
	uint32_t AFMT_GENERIC_HB3;
	uint32_t AFMT_GENERIC_LOCK_STATUS;
	uint32_t AFMT_GENERIC_CONFLICT;
	uint32_t AFMT_GENERIC_CONFLICT_CLR;
	uint32_t AFMT_GENERIC0_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC1_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC2_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC3_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC4_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC5_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC6_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC7_FRAME_UPDATE_PENDING;
	uint32_t AFMT_GENERIC0_FRAME_UPDATE;
	uint32_t AFMT_GENERIC1_FRAME_UPDATE;
	uint32_t AFMT_GENERIC2_FRAME_UPDATE;
	uint32_t AFMT_GENERIC3_FRAME_UPDATE;
	uint32_t AFMT_GENERIC4_FRAME_UPDATE;
	uint32_t AFMT_GENERIC5_FRAME_UPDATE;
	uint32_t AFMT_GENERIC6_FRAME_UPDATE;
	uint32_t AFMT_GENERIC7_FRAME_UPDATE;
	uint32_t HDMI_GENERIC0_CONT;
	uint32_t HDMI_GENERIC0_SEND;
	uint32_t HDMI_GENERIC0_LINE;
	uint32_t HDMI_GENERIC1_CONT;
	uint32_t HDMI_GENERIC1_SEND;
	uint32_t HDMI_GENERIC1_LINE;
	uint32_t DP_PIXEL_ENCODING;
	uint32_t DP_COMPONENT_DEPTH;
	uint32_t DP_DYN_RANGE;
	uint32_t DP_YCBCR_RANGE;
	uint32_t HDMI_PACKET_GEN_VERSION;
	uint32_t HDMI_KEEPOUT_MODE;
	uint32_t HDMI_DEEP_COLOR_ENABLE;
	uint32_t HDMI_CLOCK_CHANNEL_RATE;
	uint32_t HDMI_DEEP_COLOR_DEPTH;
	uint32_t HDMI_GC_CONT;
	uint32_t HDMI_GC_SEND;
	uint32_t HDMI_NULL_SEND;
	uint32_t HDMI_DATA_SCRAMBLE_EN;
	uint32_t HDMI_ACP_SEND;
	uint32_t HDMI_AUDIO_INFO_SEND;
	uint32_t AFMT_AUDIO_INFO_UPDATE;
	uint32_t HDMI_AUDIO_INFO_LINE;
	uint32_t HDMI_GC_AVMUTE;
	uint32_t DP_MSE_RATE_X;
	uint32_t DP_MSE_RATE_Y;
	uint32_t DP_MSE_RATE_UPDATE_PENDING;
	uint32_t AFMT_AVI_INFO_VERSION;
	uint32_t HDMI_AVI_INFO_SEND;
	uint32_t HDMI_AVI_INFO_CONT;
	uint32_t HDMI_AVI_INFO_LINE;
	uint32_t DP_SEC_GSP0_ENABLE;
	uint32_t DP_SEC_STREAM_ENABLE;
	uint32_t DP_SEC_GSP1_ENABLE;
	uint32_t DP_SEC_GSP2_ENABLE;
	uint32_t DP_SEC_GSP3_ENABLE;
	uint32_t DP_SEC_GSP4_ENABLE;
	uint32_t DP_SEC_GSP5_ENABLE;
	uint32_t DP_SEC_GSP6_ENABLE;
	uint32_t DP_SEC_GSP7_ENABLE;
	uint32_t DP_SEC_AVI_ENABLE;
	uint32_t DP_SEC_MPG_ENABLE;
	uint32_t DP_VID_STREAM_DIS_DEFER;
	uint32_t DP_VID_STREAM_ENABLE;
	uint32_t DP_VID_STREAM_STATUS;
	uint32_t DP_STEER_FIFO_RESET;
	uint32_t DP_VID_M_N_GEN_EN;
	uint32_t DP_VID_N;
	uint32_t DP_VID_M;
	uint32_t DIG_START;
	uint32_t AFMT_AUDIO_SRC_SELECT;
	uint32_t AFMT_AUDIO_CHANNEL_ENABLE;
	uint32_t HDMI_AUDIO_PACKETS_PER_LINE;
	uint32_t HDMI_AUDIO_DELAY_EN;
	uint32_t AFMT_60958_CS_UPDATE;
	uint32_t AFMT_AUDIO_LAYOUT_OVRD;
	uint32_t AFMT_60958_OSF_OVRD;
	uint32_t HDMI_ACR_AUTO_SEND;
	uint32_t HDMI_ACR_SOURCE;
	uint32_t HDMI_ACR_AUDIO_PRIORITY;
	uint32_t HDMI_ACR_CTS_32;
	uint32_t HDMI_ACR_N_32;
	uint32_t HDMI_ACR_CTS_44;
	uint32_t HDMI_ACR_N_44;
	uint32_t HDMI_ACR_CTS_48;
	uint32_t HDMI_ACR_N_48;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_L;
	uint32_t AFMT_60958_CS_CLOCK_ACCURACY;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_R;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_2;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_3;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_4;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_5;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_6;
	uint32_t AFMT_60958_CS_CHANNEL_NUMBER_7;
	uint32_t DP_SEC_AUD_N;
	uint32_t DP_SEC_TIMESTAMP_MODE;
	uint32_t DP_SEC_ASP_ENABLE;
	uint32_t DP_SEC_ATP_ENABLE;
	uint32_t DP_SEC_AIP_ENABLE;
	uint32_t DP_SEC_ACM_ENABLE;
	uint32_t AFMT_AUDIO_SAMPLE_SEND;
	uint32_t AFMT_AUDIO_CLOCK_EN;
	uint32_t TMDS_PIXEL_ENCODING;
	uint32_t DIG_STEREOSYNC_SELECT;
	uint32_t DIG_STEREOSYNC_GATE_EN;
	uint32_t TMDS_COLOR_FORMAT;
	uint32_t DP_DB_DISABLE;
	uint32_t DP_MSA_MISC0;
	uint32_t DP_MSA_HTOTAL;
	uint32_t DP_MSA_VTOTAL;
	uint32_t DP_MSA_HSTART;
	uint32_t DP_MSA_VSTART;
	uint32_t DP_MSA_HSYNCWIDTH;
	uint32_t DP_MSA_HSYNCPOLARITY;
	uint32_t DP_MSA_VSYNCWIDTH;
	uint32_t DP_MSA_VSYNCPOLARITY;
	uint32_t DP_MSA_HWIDTH;
	uint32_t DP_MSA_VHEIGHT;
	uint32_t HDMI_DB_DISABLE;
	uint32_t DP_VID_N_MUL;
	uint32_t DP_VID_M_DOUBLE_VALUE_EN;
	uint32_t DIG_SOURCE_SELECT;
};

struct dce110_stream_enc_registers {
	uint32_t AFMT_CNTL;
	uint32_t AFMT_AVI_INFO0;
	uint32_t AFMT_AVI_INFO1;
	uint32_t AFMT_AVI_INFO2;
	uint32_t AFMT_AVI_INFO3;
	uint32_t AFMT_GENERIC_0;
	uint32_t AFMT_GENERIC_1;
	uint32_t AFMT_GENERIC_2;
	uint32_t AFMT_GENERIC_3;
	uint32_t AFMT_GENERIC_4;
	uint32_t AFMT_GENERIC_5;
	uint32_t AFMT_GENERIC_6;
	uint32_t AFMT_GENERIC_7;
	uint32_t AFMT_GENERIC_HDR;
	uint32_t AFMT_INFOFRAME_CONTROL0;
	uint32_t AFMT_VBI_PACKET_CONTROL;
	uint32_t AFMT_VBI_PACKET_CONTROL1;
	uint32_t AFMT_AUDIO_PACKET_CONTROL;
	uint32_t AFMT_AUDIO_PACKET_CONTROL2;
	uint32_t AFMT_AUDIO_SRC_CONTROL;
	uint32_t AFMT_60958_0;
	uint32_t AFMT_60958_1;
	uint32_t AFMT_60958_2;
	uint32_t DIG_FE_CNTL;
	uint32_t DP_MSE_RATE_CNTL;
	uint32_t DP_MSE_RATE_UPDATE;
	uint32_t DP_PIXEL_FORMAT;
	uint32_t DP_SEC_CNTL;
	uint32_t DP_STEER_FIFO;
	uint32_t DP_VID_M;
	uint32_t DP_VID_N;
	uint32_t DP_VID_STREAM_CNTL;
	uint32_t DP_VID_TIMING;
	uint32_t DP_SEC_AUD_N;
	uint32_t DP_SEC_TIMESTAMP;
	uint32_t HDMI_CONTROL;
	uint32_t HDMI_GC;
	uint32_t HDMI_GENERIC_PACKET_CONTROL0;
	uint32_t HDMI_GENERIC_PACKET_CONTROL1;
	uint32_t HDMI_GENERIC_PACKET_CONTROL2;
	uint32_t HDMI_GENERIC_PACKET_CONTROL3;
	uint32_t HDMI_INFOFRAME_CONTROL0;
	uint32_t HDMI_INFOFRAME_CONTROL1;
	uint32_t HDMI_VBI_PACKET_CONTROL;
	uint32_t HDMI_AUDIO_PACKET_CONTROL;
	uint32_t HDMI_ACR_PACKET_CONTROL;
	uint32_t HDMI_ACR_32_0;
	uint32_t HDMI_ACR_32_1;
	uint32_t HDMI_ACR_44_0;
	uint32_t HDMI_ACR_44_1;
	uint32_t HDMI_ACR_48_0;
	uint32_t HDMI_ACR_48_1;
	uint32_t TMDS_CNTL;
	uint32_t DP_DB_CNTL;
	uint32_t DP_MSA_MISC;
	uint32_t DP_MSA_COLORIMETRY;
	uint32_t DP_MSA_TIMING_PARAM1;
	uint32_t DP_MSA_TIMING_PARAM2;
	uint32_t DP_MSA_TIMING_PARAM3;
	uint32_t DP_MSA_TIMING_PARAM4;
	uint32_t HDMI_DB_CONTROL;
};

struct dce110_stream_encoder {
	struct stream_encoder base;
	const struct dce110_stream_enc_registers *regs;
	const struct dce_stream_encoder_shift *se_shift;
	const struct dce_stream_encoder_mask *se_mask;
};

void dce110_stream_encoder_construct(
	struct dce110_stream_encoder *enc110,
	struct dc_context *ctx,
	struct dc_bios *bp,
	enum engine_id eng_id,
	const struct dce110_stream_enc_registers *regs,
	const struct dce_stream_encoder_shift *se_shift,
	const struct dce_stream_encoder_mask *se_mask);


void dce110_se_audio_mute_control(
	struct stream_encoder *enc, bool mute);

void dce110_se_dp_audio_setup(
	struct stream_encoder *enc,
	unsigned int az_inst,
	struct audio_info *info);

void dce110_se_dp_audio_enable(
		struct stream_encoder *enc);

void dce110_se_dp_audio_disable(
		struct stream_encoder *enc);

void dce110_se_hdmi_audio_setup(
	struct stream_encoder *enc,
	unsigned int az_inst,
	struct audio_info *info,
	struct audio_crtc_info *audio_crtc_info);

void dce110_se_hdmi_audio_disable(
	struct stream_encoder *enc);

#endif /* __DC_STREAM_ENCODER_DCE110_H__ */
