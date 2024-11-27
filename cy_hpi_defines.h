/***************************************************************************//**
* \file cy_hpi_defines.h
* \version 1.1.0
*
* Defines the macros and data structures for HPI middleware.
*
********************************************************************************
* \copyright
* (c) 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_HPI_DEFINES_H)
#define CY_HPI_DEFINES_H

#include <stdint.h>
#include <stdbool.h>
#include <cy_pdl.h>
#if (CY_HPI_PD_ENABLE)
#include "cy_pdstack_common.h"
#endif /* (CY_HPI_PD_ENABLE) */

#if defined(CY_DEVICE_CCG6DF_CFP)
#include "cy_hpi_defines_ccg6df_cfp.h"
#else
#include "cy_hpi_defines_default.h"
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#endif /* CY_HPI_DEFINES_H */
