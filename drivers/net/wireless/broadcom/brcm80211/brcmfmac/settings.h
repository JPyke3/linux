// SPDX-License-Identifier: ISC
/*
 * Copyright (c) 2014 Broadcom Corporation
 */

#ifndef BRCMFMAC_SETTINGS_H
#define BRCMFMAC_SETTINGS_H

#include <linux/platform_data/brcmfmac.h>

/* Definition for the device specific settings are defined here. One struct
 * is used called brcmf_mp_device. The device specific settings is part of
 * the drvr struct and should be initialized on every brcmf_attach.
 */

/**
 * struct brcmf_mp_device - Device module paramaters.
 *
 * @p2p_enable: Legacy P2P0 enable (old wpa_supplicant).
 * @feature_disable: Feature_disable bitmask.
 * @fcmode: FWS flow control.
 * @roamoff: Firmware roaming off?
 * @ignore_probe_fail: Ignore probe failure.
 * @country_codes: If available, pointer to struct for translating country codes
 * @bus: Bus specific platform data. Only SDIO at the mmoment.
 * @rambase_addr: Manually specified FW shared rambase address.
 */
struct brcmf_mp_device {
	bool		p2p_enable;
	unsigned int	feature_disable;
	int		fcmode;
	bool		roamoff;
	bool		iapp;
	bool		ignore_probe_fail;
	struct brcmfmac_pd_cc *country_codes;
	const char	*board_type;
	union {
		struct brcmfmac_sdio_pd sdio;
	} bus;
	u32		rambase_addr;
};

#endif /* BRCMFMAC_SETTINGS_H */
