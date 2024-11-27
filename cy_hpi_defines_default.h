/***************************************************************************//**
* \file cy_hpi_defines_default.h
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
#if !defined(CY_HPI_DEFINES_DEFAULT_H)
#define CY_HPI_DEFINES_DEFAULT_H

/** @cond DOXYGEN_HIDE */
#ifndef HPI_CALL_MAP
#define HPI_CALL_MAP
#endif /* HPI_CALL_MAP */

#ifndef ATTRIBUTES_HPISS_HPI
#define ATTRIBUTES_HPISS_HPI
#endif /* ATTRIBUTES_HPISS_HPI */

#ifndef HPI_GLOBAL_VAR
#define HPI_GLOBAL_VAR
#endif /* HPI_GLOBAL_VAR */

#ifndef HPI_CONST
#define HPI_CONST
#endif /* HPI_CONST */

#ifndef CY_HPI_PD_CMD_ENABLE
#define CY_HPI_PD_CMD_ENABLE                       (0U)
#endif /* CY_HPI_PD_CMD_ENABLE */

#ifndef CY_HPI_PD_INTR_STATUS_ENABLE
#define CY_HPI_PD_INTR_STATUS_ENABLE               (0U)
#endif /* CY_HPI_PD_INTR_STATUS_ENABLE */

#ifndef CY_HPI_BB_ENABLE
#define CY_HPI_BB_ENABLE                           (0U)
#endif /* CY_HPI_BB_ENABLE */

#ifndef DFP_ALT_MODE_SUPP
#define DFP_ALT_MODE_SUPP                          (0U)
#endif /* DFP_ALT_MODE_SUPP */

#ifndef UFP_ALT_MODE_SUPP
#define UFP_ALT_MODE_SUPP                          (0U)
#endif /* UFP_ALT_MODE_SUPP */

#ifndef CY_HPI_BOOT_ENABLE
#define CY_HPI_BOOT_ENABLE                         (0U)
#endif /* CY_HPI_BOOT_ENABLE */

#ifndef CY_HPI_FLASH_RW_ENABLE
#define CY_HPI_FLASH_RW_ENABLE                     (0U)
#endif /* CY_HPI_FLASH_RW_ENABLE */

#ifndef TEST_CODE_COVERAGE
#define TEST_CODE_COVERAGE                         (0U)
#endif /* TEST_CODE_COVERAGE */

#ifndef CY_HPI_LITE_ENABLED
#define CY_HPI_LITE_ENABLED                        (0U)
#endif /* CY_HPI_LITE_ENABLED */

#ifndef HPI_DEBUG_COMMAND_EN
#define HPI_DEBUG_COMMAND_EN                       (0U)
#endif /* HPI_DEBUG_COMMAND_EN */

#ifndef ALL_APP_EVT_HANDLERS
#define ALL_APP_EVT_HANDLERS                       (0U)
#endif /* ALL_APP_EVT_HANDLERS */

#ifndef SYS_BLACK_BOX_ENABLE
#define SYS_BLACK_BOX_ENABLE                       (0U)
#endif /* SYS_BLACK_BOX_ENABLE */

#ifndef SROM_CODE_HPISS_HPI
#define SROM_CODE_HPISS_HPI                        (0U)
#endif /* SROM_CODE_HPISS_HPI */

#define CY_HPI_RESPONSE_MASK_SIZE                  (8U)
#define CY_HPI_MASK_WORDSIZE_BITS                  (32U)

/** @endcond */

/**
* \addtogroup group_hpis_macros
* \{
*/
/** Maximum number of PD ports supported. */
#define CY_HPI_NO_OF_PD_PORTS_MAX                  (2U)

/** Size of flash write SROM API parameters in bytes. */
#define CY_SROM_API_PARAM_SIZE                     (8U)

/** Maximum supported flash row size. */
#define CY_HPI_MAX_FLASH_ROW_SIZE                  (256U)

/** I2C slave address used for HPI interface, when the I2C_CFG pin is sensed as LOW. */
#define CY_HPI_ADDR_I2C_CFG_LOW                    (0x40)

/** I2C slave address used for HPI interface, when the I2C_CFG pin is sensed as HIGH. */
#define CY_HPI_ADDR_I2C_CFG_HIGH                   (0x42)

/** I2C slave address used for HPI interface, when the I2C_CFG pin is sensed as FLOATING. */
#define CY_HPI_ADDR_I2C_CFG_FLOAT                  (0x08)

/** Maximum number of Alternate modes for which mode data can be stored. */
#define CY_HPI_MAX_ALTMODE_COUNT                   (8U)

/** Number of reserved device space registers. */
#define CY_HPI_DEVICE_RESERVED_COUNT               (CY_HPI_DEV_REG_RESPONSE - CY_HPI_DEV_REG_DEV_CONTROL - 1)

/** Number of user-defined HPI registers supported. */
#define CY_HPI_USERDEF_REG_COUNT                   (16U)

/** Macro to get the SCB index. */
#define CY_HPI_GET_SCB_IDX(scb_p)                  (uint8_t)(((uint32_t)(scb_p) - (uint32_t)SCB0_BASE) >> 0x10U)

/** UCSI Read Pending status bit in INTERRUPT register.
 * Note: In the AMD TED platform, bit 3 of the INTERRUPT register is used to 
 * indicate that a UCSI read is pending. This is changed to bit 7 in the final 
 * spec that is released to other customers. Change as necessary.
 */
#define CY_HPI_UCSI_READ_PENDING_EVENT             (7U)

/** Mask is applied for UCSI Read Pending Event. */
#define CY_HPI_UCSI_READ_PENDING_MASK              (1u << CY_HPI_UCSI_READ_PENDING_EVENT)

/** Mask to retrieve UCSI register offset. */
#define CY_HPI_UCSI_REG_OFFSET_MASK                (0x0FFFU)

/** UCSI External Supply Changed Event bit. */
#define CY_HPI_UCSI_EVT_EXT_SUPPLY_CHANGED         (0x0002U)

/** UCSI Capability Changed Event bit. */
#define CY_HPI_UCSI_EVT_CAP_CHANGED                (0x0020U)

/** UCSI PD Contract Changed Event bit. */
#define CY_HPI_UCSI_EVT_PD_CONTRACT_CHANGED        (0x0040U)

/** Automatic EPR Enable Mask bits. */
#define CY_HPI_AUTO_EPR_ENABLE_MASK                (0x80U)

/** Valid EPR Mask bits. */
#define CY_HPI_VALID_EPR_MASK                      (0x3FU)

/** \} group_hpis_macros */

/**
* \addtogroup group_hpis_enums
* \{
*/

/**
 * @typedef cy_en_hpi_status_t
 * @brief List of HPI status code.
 *
 * This enumeration lists all the status code returned by HPI APIs.
 */
typedef enum
{
    CY_HPI_STAT_INVALID_ARGS               = -1,   /**< Operation failed due to invalid arguments. */
    CY_HPI_STAT_SUCCESS                    = 0,    /**< Success status. */
    CY_HPI_STAT_INVALID_CMD                = 1,    /**< Return status when command not supported. */
    CY_HPI_STAT_BAD_PARAM                  = 2,    /**< Bad input parameters. */
}cy_en_hpi_status_t;

/**
 * @typedef cy_en_hpi_response_t
 * @brief List of HPI response and event codes.
 */
typedef enum
{
    CY_HPI_RESPONSE_NO_RESPONSE            = 0x00, /**< No valid response. */
    CY_HPI_RESPONSE_SUCCESS                = 0x02, /**< Success response. */
    CY_HPI_RESPONSE_FLASH_DATA_AVAILABLE   = 0x03, /**< Flash read data is available in flash data memory. */
    CY_HPI_RESPONSE_INVALID_COMMAND        = 0x05, /**< Invalid command received. */
    CY_HPI_RESPONSE_CMD_FAILED             = 0x06, /**< Load sharing command failed. */
    CY_HPI_RESPONSE_FLASH_UPDATE_FAILED    = 0x07, /**< Flash read/write operation failed. */
    CY_HPI_RESPONSE_INVALID_FW             = 0x08, /**< Firmware binary checked is invalid. */
    CY_HPI_RESPONSE_INVALID_ARGUMENT       = 0x09, /**< Invalid parameter specified for the command. */
    CY_HPI_RESPONSE_NOT_SUPPORTED          = 0x0A, /**< Command received is not supported. */
    CY_HPI_RESPONSE_PD_TRANSACTION_FAILED  = 0x0C, /**< USB PD transaction failed. */
    CY_HPI_RESPONSE_PD_COMMAND_FAILED      = 0x0D, /**< USB PD command failed. */
    CY_HPI_RESPONSE_UNDEFINED_ERROR        = 0x0F, /**< Undefined error occurred. */
    CY_HPI_RESPONSE_PDO_DATA               = 0x10, /**< PDO read data is available in read data memory. */
    CY_HPI_RESPONSE_CMD_ABORTED            = 0x11, /**< HPI initiated PD command is aborted. */
    CY_HPI_RESPONSE_PORT_BUSY              = 0x12, /**< HPI initiated PD command failed due to port busy. */
    CY_HPI_RESPONSE_MIN_MAX_CUR            = 0x13, /**< HPI response provides sink min/max current data. */
    CY_HPI_RESPONSE_EXT_SRC_CAP            = 0x14, /**< HPI response provides external source cap data. */
    CY_HPI_RESPONSE_UCSI_COMMAND_FAILED    = 0x15, /**< UCSI command failed. */
    CY_HPI_RESPONSE_PPS_SINK_CAP_MISMATCH  = 0x16, /**< Capability mismatch for EC request to enter PPS contract. */
    CY_HPI_RESPONSE_DISC_ID_VDM            = 0x18, /**< HPI response provides DISC_ID VDM response. */
    CY_HPI_RESPONSE_DISC_SVID_VDM          = 0x19, /**< HPI response provides DISC_SVID VDM response. */
    CY_HPI_RESPONSE_DISC_MODE_VDM          = 0x1A, /**< HPI response provides DISC_MODE VDM response. */
    CY_HPI_RESPONSE_VCONN_DISABLED         = 0x1B, /**< PD command is not initiated due to VConn being OFF. */
    CY_HPI_RESPONSE_EXT_SNK_CAP            = 0x1C, /**< HPI response provides ext. sink cap data. */
    CY_HPI_RESPONSE_I2C_REG                = 0x1D, /**< HPI response provides I2C device read data. */
    CY_HPI_RESPONSE_PD_RESP_DATA           = 0x1E, /**< HPI response provides PD response data. */
    CY_HPI_RESPONSE_MIN_MAX_CUR_EPR        = 0x1F, /**< HPI response provides EPR sink min/max current data. */

    CY_HPI_RESPONSE_INVALID_ID             = 0x40, /**< Invalid FWCT identity received for signed FW upgrade. >**/
    CY_HPI_RESPONSE_INVALID_GUID           = 0x41, /**< Invalid GUID received for signed FW upgrade. >**/
    CY_HPI_RESPONSE_INVALID_VER            = 0x42, /**< Invalid/older primary FW version received for signed FW upgrade. >**/
    CY_HPI_RESPONSE_OUT_OF_SEQ_CMD         = 0x43, /**< Command sent is not expected in current state during signed FW upgrade. >**/
    CY_HPI_RESPONSE_INVALID_FWCT           = 0x44, /**< Unauthentic FWCT received for signed FW upgrade. >**/
    CY_HPI_RESPONSE_HASH_CMP_FAILED        = 0x45, /**< Hash comparison of FW image and hash in FWCT is not matched during signed FW upgrade. >**/
    CY_HPI_RESPONSE_INVALID_FW_DATA        = 0x46, /**< Invalid FW start address or FW size in FWCT table. */

    CY_HPI_EVENT_RESET_COMPLETE            = 0x80, /**< Reset complete event notification. */
    CY_HPI_EVENT_MSG_OVERFLOW              = 0x81, /**< Event queue overflow. */
    CY_HPI_EVENT_OC_DETECT                 = 0x82, /**< Overcurrent event detected. */
    CY_HPI_EVENT_OV_DETECT                 = 0x83, /**< Overvoltage event detected. */
    CY_HPI_EVENT_CONNECT_DETECT            = 0x84, /**< Type-C connect detected. */
    CY_HPI_EVENT_DISCONNECT_DETECT         = 0x85, /**< Type-C disconnect detected. */
    CY_HPI_EVENT_NEGOTIATION_COMPLETE      = 0x86, /**< PD contract negotiation completed. */
    CY_HPI_EVENT_SWAP_COMPLETE             = 0x87, /**< Swap (DR_SWAP, PR_SWAP, or VCONN_SWAP) completed. */
    CY_HPI_EVENT_PS_RDY_RECEIVED           = 0x8A, /**< PS_RDY message received. */
    CY_HPI_EVENT_GOTO_MIN_RECEIVED         = 0x8B, /**< GOTO_MIN message received. */
    CY_HPI_EVENT_ACCEPT_RECEIVED           = 0x8C, /**< ACCEPT message received. */
    CY_HPI_EVENT_REJECT_RECEIVED           = 0x8D, /**< REJECT message received. */
    CY_HPI_EVENT_WAIT_RECEIVED             = 0x8E, /**< WAIT message received. */
    CY_HPI_EVENT_HARD_RESET_RECEIVED       = 0x8F, /**< HARD RESET received. */
    CY_HPI_EVENT_VDM_RECEIVED              = 0x90, /**< VDM received and the contents are stored in data memory. */
    CY_HPI_EVENT_SOURCE_CAP_RECEIVED       = 0x91, /**< Source capabilities received. PDOs received are stored
                                                     in data memory. */
    CY_HPI_EVENT_SINK_CAP_RECEIVED         = 0x92, /**< Sink capabilities received. PDOs received are stored in
                                                     data memory. */
    CY_HPI_EVENT_DATA_RESET_RECEIVED       = 0x93, /**< Data reset received. No event data. */
    CY_HPI_EVENT_DATA_RESET_COMPLETE       = 0x94, /**< Data reset sequence completed. No event data. */
    CY_HPI_EVENT_USB_ENTRY_COMPLETE        = 0x95, /**< Enter_USB handshake completed successfully. */
    CY_HPI_EVENT_HARD_RESET_SENT           = 0x9A, /**< HARD RESET is sent by CCG device. */
    CY_HPI_EVENT_SOFT_RESET_SENT           = 0x9B, /**< SOFT RESET is sent by CCG device. Event data will indicate
                                                     SOFT RESET packet type (SOP, SOP', or SOP''). */
    CY_HPI_EVENT_CABLE_RESET_SENT          = 0x9C, /**< CABLE RESET is sent by CCG device. */
    CY_HPI_EVENT_SOURCE_DISABLED           = 0x9D, /**< Source disabled state ID entered. */
    CY_HPI_EVENT_SENDER_TIMEOUT            = 0x9E, /**< Sender Response timeout occurred. */
    CY_HPI_EVENT_VDM_NO_RESPONSE           = 0x9F, /**< No response to VDM sent by CCG device. */
    CY_HPI_EVENT_UNEXPECTED_VOLTAGE        = 0xA0, /**< Unexpected VBus voltage detected. */
    CY_HPI_EVENT_ERROR_RECOVERY            = 0xA1, /**< Type-C error recovery started. */
    CY_HPI_EVENT_BAT_STATUS_RECEIVED       = 0xA2, /**< Battery status message received. */
    CY_HPI_EVENT_ALERT_RECEIVED            = 0xA3, /**< Alert message received. */
    CY_HPI_EVENT_NOTSUPP_RECEIVED          = 0xA4, /**< Not supported message received. */
    CY_HPI_EVENT_EMCA_DETECT               = 0xA6, /**< EMCA is detected. */
    CY_HPI_EVENT_EMCA_NOT_DETECT           = 0xA7, /**< No EMCA present in current connection. */
    CY_HPI_EVENT_RP_CHANGE_DETECT          = 0xAA, /**< Change in Rp termination detected. */
    CY_HPI_EVENT_BB_UPDATE                 = 0xAB, /**< Billboard update event. */
    CY_HPI_EVENT_PD_EXTD_MSG_SOP           = 0xAC, /**< PD extended data message (SOP) received. */
    CY_HPI_EVENT_CCG2_RESERVED_AD          = 0xAD, /**< Reserved event. */
    CY_HPI_EVENT_CCG2_RESERVED_AE          = 0xAE, /**< Reserved event. */
    CY_HPI_EVENT_CCG2_RESERVED_AF          = 0xAF, /**< Reserved event. */
    CY_HPI_EVENT_ALT_MODE                  = 0xB0, /**< Alternate mode related event. Event data contains the SVID
                                                     corresponding to the mode and the event type. */
    CY_HPI_EVENT_APP_HW                    = 0xB1, /**< Alternate mode control hardware (MUX, HPD, etc.) related
                                                     event occurred. */
    CY_HPI_EVENT_PD_EXTD_MSG_SOP_PRIME     = 0xB4, /**< PD extended data message (SOP') received. */
    CY_HPI_EVENT_PD_EXTD_MSG_SOP_DPRIME    = 0xB5, /**< PD extended data message (SOP'') received. */
    CY_HPI_EVENT_OT_DETECT                 = 0xB6, /**< Overtemperature condition detected. */
    CY_HPI_EVENT_RESERVED_B7               = 0xB7, /**< Reserved event code. */
    CY_HPI_EVENT_HARDWARE_ERROR            = 0xB8, /**< System hardware (MUX, regulator, etc.) error. */
    CY_HPI_EVENT_VCONN_OC_DETECT           = 0xB9, /**< Overcurrent condition detected on VConn supply. */
    CY_HPI_EVENT_CC_VBUS_SHORT             = 0xBA, /**< Overvoltage condition (possible VBus short) on CC lines. */
    CY_HPI_EVENT_SBU_VBUS_SHORT            = 0xBB, /**< Overvoltage condition (possible VBus short) on SBU lines. */
    CY_HPI_EVENT_SC_DETECT                 = 0xBC, /**< Short-circuit fault condition. */
    CY_HPI_EVENT_RC_DETECT                 = 0xBD, /**< Reverse current fault condition. */
    CY_HPI_EVENT_STANDBY_CURRENT           = 0xBE, /**< Standby current. */
    CY_HPI_EVENT_UV_DETECT                 = 0xBF, /**< VBus undervoltage fault condition. */

    CY_HPI_EVENT_SOC_TIMEOUT               = 0xC0, /**< SoC ACK timeout in Intel host designs. */
    CY_HPI_EVENT_SRC_RP_REMOVED            = 0xC1, /**< Rp termination applied by the source is removed. */
    CY_HPI_EVENT_PR_SWAP_ACCEPTED          = 0xC2, /**< PR-SWAP is accepted by CCGx or the port partner. */
    CY_HPI_EVENT_SNK_POWER_REDUCED         = 0xC3, /**< PD contract re-negotiated to reduce power available. */
    CY_HPI_EVENT_BC_12_EVENTS              = 0xC4, /**< BC12 related notification. */

    CY_HPI_EVENT_CUST_NTF_BEFORE_HR        = 0xD0, /**< Event to notify host before sending HARD_RESET. */
    CY_HPI_EVENT_CUST_UVDM_RCVD            = 0xD1, /**< Customer-defined UVDM Received. */
    CY_HPI_EVENT_CUST_ALT_MODE_CHANGE      = 0xD2, /**< This event is sent for notification of alternate mode specific conditions
                                                    like mode entry and mode exit. */
    CY_HPI_EVENT_CUST_DISCOVERY_COMPLETE   = 0xD3, /**< Customer-defined Discovery Process Completed. */
    CY_HPI_EVENT_COLLECTED_CHUNKED_MSG     = 0xD4, /**< Event containing collected multi-chunk extended message. */
    CY_HPI_EVENT_BIST_STM_ENTRY            = 0xD5, /**< BIST STM Entry Request received. */
    CY_HPI_EVENT_BIST_STM_EXIT             = 0xD6, /**< BIST STM Exit Request received. */
    CY_HPI_EVENT_SRC_INFO_RECEIVED         = 0xD7, /**< Source Info message received. */
    CY_HPI_EVENT_REVISION_RECEIVED         = 0xD8, /**< Revision message received. */
    CY_HPI_EVENT_EPR_MODE_RECEIVED         = 0xD9, /**< EPR Mode Event. */
    CY_HPI_EVENT_PORT_DISABLED             = 0xDA, /**< Port disabled event received. */
    CY_HPI_EVENT_MOISTURE_DETECTED         = 0xDB, /**< Moisture detected event received. */
    CY_HPI_EVENT_MOISTURE_CLEARED          = 0xDC, /**< Moisture cleared event received. */
    CY_HPI_EVENT_HASH_MEASURE_COMPLETE     = 0xDD  /**< Hash measurement complete event. */
} cy_en_hpi_response_t;

/**
 * @typedef cy_en_hpi_dev_reg_address_t
 * @brief List of HPI device information register addresses.
 *
 * This enumeration lists the addresses for the HPI device information registers supported by CCGx devices.
 * These registers are used to retrieve firmware mode and version information, and doing firmware and
 * configuration table updates.
 */
typedef enum
{
    CY_HPI_DEV_REG_DEVICE_MODE             = 0x00, /**< Device mode register: Specifies FW mode, PD port count
                                                        and flash row size. */
    CY_HPI_DEV_REG_BOOT_MODE_REASON        = 0x01, /**< Boot mode reason register: Specifies validity of each
                                                        firmware image. Also, reports reason for device staying
                                                        in Boot mode. */
    CY_HPI_DEV_REG_SI_ID                   = 0x02, /**< Silicon ID: MS byte. */
    CY_HPI_DEV_REG_SI_ID_LSB               = 0x03, /**< Silicon ID: LS byte. */
    CY_HPI_DEV_REG_BL_LAST_ROW             = 0x04, /**< Bootloader last row: LS byte. This is actually the
                                                        last flash row before the start of the firmware. */
    CY_HPI_DEV_REG_BL_LAST_ROW_MSB         = 0x05, /**< Bootloader last row: MS byte. */
    CY_HPI_DEV_REG_INTR_ADDR               = 0x06, /**< Interrupt status register. */
    CY_HPI_DEV_REG_JUMP_TO_BOOT            = 0x07, /**< Jump to boot (or alt firmware) request register. */
    CY_HPI_DEV_REG_RESET_ADDR              = 0x08, /**< Reset request signature register. */
    CY_HPI_DEV_REG_RESET_CMD               = 0x09, /**< Reset command register: I2C or device reset. */
    CY_HPI_DEV_REG_ENTER_FLASH_MODE        = 0x0A, /**< Enter flashing mode request register. */
    CY_HPI_DEV_REG_VALIDATE_FW_ADDR        = 0x0B, /**< Validate firmware request register. */
    CY_HPI_DEV_REG_FLASH_READ_WRITE        = 0x0C, /**< Flash read/write signature register. */
    CY_HPI_DEV_REG_FLASH_READ_WRITE_CMD    = 0x0D, /**< Flash read/write command register: 0 = read, 1 = write. */
    CY_HPI_DEV_REG_FLASH_ROW_LSB           = 0x0E, /**< Flash row to read/write: LSB. */
    CY_HPI_DEV_REG_FLASH_ROW_MSB           = 0x0F, /**< Flash row to read/write: MSB. */
    CY_HPI_DEV_REG_ALL_VERSION             = 0x10, /**< Bootloader version: LSB of build number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_1      = 0x11, /**< Bootloader version: MSB of build number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_2      = 0x12, /**< Bootloader version: Patch level. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_3      = 0x13, /**< Bootloader version: Major and minor number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_4      = 0x14, /**< Bootloader version: LSB of application type. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_5      = 0x15, /**< Bootloader version: MSB of application type. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_6      = 0x16, /**< Bootloader version: Hardware circuit version. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_7      = 0x17, /**< Bootloader version: App major and minor number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_8      = 0x18, /**< FW1 version: LSB of build number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_9      = 0x19, /**< FW1 version: MSB of build number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_10     = 0x1A, /**< FW1 version: Patch level. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_11     = 0x1B, /**< FW1 version: Major and minor number. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_12     = 0x1C, /**< FW1 version: LSB of application type. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_13     = 0x1D, /**< FW1 version: MSB of application type. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_14     = 0x1E, /**< FW1 version: Hardware circuit version. */
    CY_HPI_DEV_REG_ALL_VERSION_BYTE_15     = 0x1F, /**< FW1 version: App major and minor number. */
    CY_HPI_DEV_REG_FW_2_VERSION            = 0x20, /**< FW2 version: LSB of build number. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_1     = 0x21, /**< FW2 version: MSB of build number. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_2     = 0x22, /**< FW2 version: Patch level. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_3     = 0x23, /**< FW2 version: major and minor number. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_4     = 0x24, /**< FW2 version: LSB of application type. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_5     = 0x25, /**< FW2 version: MSB of application type. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_6     = 0x26, /**< FW2 version: Hardware circuit version. */
    CY_HPI_DEV_REG_FW_2_VERSION_BYTE_7     = 0x27, /**< FW2 version: App major and minor number. */
    CY_HPI_DEV_REG_FW_1_BIN_LOC_LSB        = 0x28, /**< FW1 binary location: LSB. */
    CY_HPI_DEV_REG_FW_1_BIN_LOC_MSB        = 0x29, /**< FW1 binary location: MSB. */
    CY_HPI_DEV_REG_FW_2_BIN_LOC_LSB        = 0x2A  /**< FW2 binary location: LSB. */,
    CY_HPI_DEV_REG_FW_2_BIN_LOC_MSB        = 0x2B  /**< FW2 binary location: MSB. */,
    CY_HPI_DEV_REG_PORT_ENABLE             = 0x2C, /**< Port enable command/status register. */
    CY_HPI_DEV_REG_SLEEP_CTRL              = 0x2D, /**< Deep Sleep control register. */
    CY_HPI_DEV_REG_POWER_STAT              = 0x2E, /**< Power Status register used to update status message. */
    CY_HPI_DEV_REG_SET_APP_PRIORITY        = 0x2F, /**< Set APP Priority. */
    CY_HPI_DEV_REG_READ_CUSTOMER_INFO      = 0x30, /**< Read 32 bytes of customer info. */
    CY_HPI_DEV_REG_BATTERY_STAT            = 0x31, /**< Register showing the current battery status. */
    CY_HPI_DEV_REG_WD_RESET_COUNT          = 0x32, /**< Watchdog reset count register. */
    CY_HPI_DEV_REG_READ_DIE_INFO           = 0x33, /**< Read 32 byte device Die Information. */
    CY_HPI_DEV_REG_HPI_VERSION_EXT         = 0x34, /**< HPI version ext register: Byte 0. */
    CY_HPI_DEV_REG_HPI_VERSION_EXT_B1      = 0x35, /**< HPI version ext register: Byte 1. */
    CY_HPI_DEV_REG_HPI_VERSION_EXT_B2      = 0x36, /**< HPI version ext register: Byte 2. */
    CY_HPI_DEV_REG_HPI_VERSION_EXT_B3      = 0x37, /**< HPI version ext register: Byte 3. */

    CY_HPI_DEV_REG_UCSI_STATUS             = 0x38, /**< UCSI status register. */
    CY_HPI_DEV_REG_UCSI_CONTROL            = 0x39, /**< UCSI control register. */

    CY_HPI_DEV_REG_CFGTAB_VERSION          = 0x3A, /**< Config table version register. */
    CY_HPI_DEV_REG_SYS_PWR_STATE           = 0x3B, /**< System Power State register. */
    CY_HPI_DEV_REG_HPI_VERSION             = 0x3C, /**< HPI version register: Byte 0. */
    CY_HPI_DEV_REG_HPI_VERSION_B1          = 0x3D, /**< HPI version register: Byte 1. */
    CY_HPI_DEV_REG_HPI_VERSION_B2          = 0x3E, /**< HPI version register: Byte 2. */
    CY_HPI_DEV_REG_HPI_VERSION_B3          = 0x3F, /**< HPI version register: Byte 3. */

    CY_HPI_DEV_REG_USERDEF_00              = 0x40, /**< User-defined register number 0. */
    CY_HPI_DEV_REG_USERDEF_01              = 0x41, /**< User-defined register number 1. */
    CY_HPI_DEV_REG_USERDEF_02              = 0x42, /**< User-defined register number 2. */
    CY_HPI_DEV_REG_USERDEF_03              = 0x43, /**< User-defined register number 3. */
    CY_HPI_DEV_REG_USERDEF_04              = 0x44, /**< User-defined register number 4. */
    CY_HPI_DEV_REG_USERDEF_05              = 0x45, /**< User-defined register number 5. */
    CY_HPI_DEV_REG_USERDEF_06              = 0x46, /**< User-defined register number 6. */
    CY_HPI_DEV_REG_USERDEF_07              = 0x47, /**< User-defined register number 7. */
    CY_HPI_DEV_REG_USERDEF_08              = 0x48, /**< User-defined register number 8. */
    CY_HPI_DEV_REG_USERDEF_09              = 0x49, /**< User-defined register number 9. */
    CY_HPI_DEV_REG_USERDEF_0A              = 0x4A, /**< User-defined register number 10. */
    CY_HPI_DEV_REG_USERDEF_0B              = 0x4B, /**< User-defined register number 11. */
    CY_HPI_DEV_REG_USERDEF_0C              = 0x4C, /**< User-defined register number 12. */
    CY_HPI_DEV_REG_USERDEF_0D              = 0x4D, /**< User-defined register number 13. */
    CY_HPI_DEV_REG_USERDEF_0E              = 0x4E, /**< User-defined register number 14. */
    CY_HPI_DEV_REG_USERDEF_0F              = 0x4F, /**< User-defined register number 15. */

    CY_HPI_DEV_BB_DISABLE_RESET            = 0x50, /**< Disable Billboard reset request register. */
    CY_HPI_DEV_BB_ALT_MODE_STATUS          = 0x52, /**< Alt. mode status for use by Billboard device. */
    CY_HPI_DEV_BB_ALT_MODE_STAT_B1         = 0x53, /**< Alt. mode status for use by Billboard device. */
    CY_HPI_DEV_BB_OPER_MODEL               = 0x54, /**< Billboard operating mode configuration. */
    CY_HPI_DEV_BB_ADDL_FAILURE_INFO        = 0x55, /**< Used to provide bAdditionalFailureInfo value for Billboard device. */
    CY_HPI_DEV_BB_CMD_REG                  = 0x56, /**< Billboard command register. */
    CY_HPI_DEV_BB_MISC_INFO                = 0x57, /**< Billboard misc info such as self-powered and so on. */
    CY_HPI_DEV_REG_BB_BL_VER_B0            = 0x58, /**< Billboard bootloader version: Byte 0. */
    CY_HPI_DEV_REG_BB_BL_VER_B1            = 0x59, /**< Billboard bootloader version: Byte 1. */
    CY_HPI_DEV_REG_BB_BL_VER_B2            = 0x5A, /**< Billboard bootloader version: Byte 2. */
    CY_HPI_DEV_REG_BB_BL_VER_B3            = 0x5B, /**< Billboard bootloader version: Byte 3. */
    CY_HPI_DEV_REG_BB_BL_VER_B4            = 0x5C, /**< Billboard bootloader version: Byte 4. */
    CY_HPI_DEV_REG_BB_BL_VER_B5            = 0x5D, /**< Billboard bootloader version: Byte 5. */
    CY_HPI_DEV_REG_BB_BL_VER_B6            = 0x5E, /**< Billboard bootloader version: Byte 6. */
    CY_HPI_DEV_REG_BB_BL_VER_B7            = 0x5F, /**< Billboard bootloader version: Byte 7. */
    CY_HPI_DEV_REG_BB_FW_VER_B0            = 0x60, /**< Billboard firmware version: Byte 0. */
    CY_HPI_DEV_REG_BB_FW_VER_B1            = 0x61, /**< Billboard firmware version: Byte 1. */
    CY_HPI_DEV_REG_BB_FW_VER_B2            = 0x62, /**< Billboard firmware version: Byte 2. */
    CY_HPI_DEV_REG_BB_FW_VER_B3            = 0x63, /**< Billboard firmware version: Byte 3. */
    CY_HPI_DEV_REG_BB_FW_VER_B4            = 0x64, /**< Billboard firmware version: Byte 4 .*/
    CY_HPI_DEV_REG_BB_FW_VER_B5            = 0x65, /**< Billboard firmware version: Byte 5. */
    CY_HPI_DEV_REG_BB_FW_VER_B6            = 0x66, /**< Billboard firmware version: Byte 6. */
    CY_HPI_DEV_REG_BB_FW_VER_B7            = 0x67, /**< Billboard firmware version: Byte 7. */
    CY_HPI_DEV_REG_RESERVED_68H            = 0x68, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_69H            = 0x69, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6AH            = 0x6A, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6BH            = 0x6B, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6CH            = 0x6C, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6DH            = 0x6D, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6EH            = 0x6E, /**< Reserved register. */
    CY_HPI_DEV_REG_RESERVED_6FH            = 0x6F, /**< Reserved register. */
    CY_HPI_DEV_REG_PPS_DESIGN_VOLT_LSB     = 0x70, /**< HPI PPS Design Voltage Register: Byte 0. */
    CY_HPI_DEV_REG_PPS_DESIGN_VOLT_MSB     = 0x71, /**< HPI PPS Design Voltage Register: Byte 1. */
    CY_HPI_DEV_REG_FW_UPDATE_LOCK          = 0x72, /**< FW update lock register. */
    CY_HPI_DEV_REG_DEV_CONTROL             = 0x73, /**< Device Control register used for device-specific commands. */
    CY_HPI_DEV_REG_BYTE_74_RESERVED        = 0x74, /**< Reserved register. */

    CY_HPI_DEV_REG_RESPONSE                = 0x7E, /**< Response type register. */
    CY_HPI_DEV_REG_RESPONSE_LEN            = 0x7F, /**< Response length register. */
    CY_HPI_DEV_REG_BYTE_A0_RESERVED        = 0xA0, /**< Reserved register. */
    CY_HPI_DEV_REG_BYTE_A4_RESERVED        = 0xA4, /**< Reserved register. */

} cy_en_hpi_dev_reg_address_t;

/**
 * @typedef cy_en_hpi_port_reg_address_t
 * @brief List of USB PD port specified register addresses.
 *
 * This enumeration lists the registers used to control one USB PD port on the CCG device. The addresses listed are
 * offsets on top of the base register for the port. Separate sets of these registers will exist for each port.
 */
typedef enum
{
    CY_HPI_PORT_REG_VDM_CTRL               = 0x00, /**< VDM Control register. */
    CY_HPI_PORT_REG_VDM_CTRL_LEN           = 0x01, /**< VDM Length register. */
    CY_HPI_PORT_REG_EFF_SRC_PDO_MASK       = 0x02, /**< Effective Source PDO Mask register: Read-only. */
    CY_HPI_PORT_REG_EFF_SINK_PDO_MASK      = 0x03, /**< Effective Sink PDO Mask register: Read-only. */
    CY_HPI_PORT_REG_SOURCE_PDO_ADDR        = 0x04, /**< Source PDO Mask Selection register. */
    CY_HPI_PORT_REG_SINK_PDO_ADDR          = 0x05, /**< Sink PDO Mask Selection register. */
    CY_HPI_PORT_REG_PD_CTRL                = 0x06, /**< PD Control register. */
    CY_HPI_PORT_REG_BYTE_7_RESERVED        = 0x07, /**< Reserved register. */
    CY_HPI_PORT_REG_PD_STATUS              = 0x08, /**< PD Status register: LS byte. */
    CY_HPI_PORT_REG_PD_STATUS_BYTE_1       = 0x09, /**< PD Status register: Byte 1. */
    CY_HPI_PORT_REG_PD_STATUS_BYTE_2       = 0x0A, /**< PD Status register: Byte 2. */
    CY_HPI_PORT_REG_PD_STATUS_BYTE_3       = 0x0B, /**< PD Status register: MS byte. */
    CY_HPI_PORT_REG_TYPE_C_STATUS          = 0x0C, /**< Type-C Status register. */
    CY_HPI_PORT_REG_BUS_VOLTAGE            = 0x0D, /**< VBus voltage in 100 mV units. */
    CY_HPI_PORT_REG_BYTE_14_RESERVED       = 0x0E, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_15_RESERVED       = 0x0F, /**< Reserved register. */
    CY_HPI_PORT_REG_CUR_PDO                = 0x10, /**< Current PDO register: LS byte. */
    CY_HPI_PORT_REG_CUR_PDO_BYTE_1         = 0x11, /**< Current PDO register: Byte 1. */
    CY_HPI_PORT_REG_CUR_PDO_BYTE_2         = 0x12, /**< Current PDO register: Byte 2. */
    CY_HPI_PORT_REG_CUR_PDO_BYTE_3         = 0x13, /**< Current PDO register: MS byte. */
    CY_HPI_PORT_REG_CUR_RDO                = 0x14, /**< Current RDO register: LS byte. */
    CY_HPI_PORT_REG_CUR_RDO_BYTE_1         = 0x15, /**< Current RDO register: Byte 1. */
    CY_HPI_PORT_REG_CUR_RDO_BYTE_2         = 0x16, /**< Current RDO register: Byte 2. */
    CY_HPI_PORT_REG_CUR_RDO_BYTE_3         = 0x17, /**< Current RDO register: MS byte. */
    CY_HPI_PORT_REG_CABLE_VDO              = 0x18, /**< Cable VDO register: LS byte. */
    CY_HPI_PORT_REG_CABLE_VDO_BYTE_1       = 0x19, /**< Cable VDO register: Byte 1. */
    CY_HPI_PORT_REG_CABLE_VDO_BYTE_2       = 0x1A, /**< Cable VDO register: Byte 2. */
    CY_HPI_PORT_REG_CABLE_VDO_BYTE_3       = 0x1B, /**< Cable VDO register: MS byte. */

    CY_HPI_PORT_REG_ALT_MODE_CMD           = 0x1C, /**< ALT MODE command register: LS byte. */
    CY_HPI_PORT_REG_ALT_MODE_CMD_BYTE_1    = 0x1D, /**< ALT MODE command register: Byte 1. */
    CY_HPI_PORT_REG_ALT_MODE_CMD_BYTE_2    = 0x1E, /**< ALT MODE command register: Byte 2. */
    CY_HPI_PORT_REG_ALT_MODE_CMD_BYTE_3    = 0x1F, /**< ALT MODE command register: MS byte. */
    CY_HPI_PORT_REG_APP_HW_CMD             = 0x20, /**< HW Control command register: LS byte. */
    CY_HPI_PORT_REG_APP_HW_CMD_BYTE_1      = 0x21, /**< HW Control command register: Byte 1. */
    CY_HPI_PORT_REG_APP_HW_CMD_BYTE_2      = 0x22, /**< HW Control command register: Byte 2. */
    CY_HPI_PORT_REG_APP_HW_CMD_BYTE_3      = 0x23, /**< HW Control command register: MS byte. */

    CY_HPI_PORT_REG_EVENT_MASK             = 0x24, /**< Event Mask register: LS byte. */
    CY_HPI_PORT_REG_EVENT_MASK_BYTE_1      = 0x25, /**< Event Mask register: Byte 1. */
    CY_HPI_PORT_REG_EVENT_MASK_BYTE_2      = 0x26, /**< Event Mask register: Byte 2. */
    CY_HPI_PORT_REG_EVENT_MASK_BYTE_3      = 0x27, /**< Event Mask register: MS byte. */
    CY_HPI_PORT_REG_SWAP_RESPONSE          = 0x28, /**< Swap Response register. */
    CY_HPI_PORT_REG_ACTIVE_EC_MODES        = 0x29, /**< EC ALT MODES active register. */
    CY_HPI_PORT_REG_VDM_EC_CTRL            = 0x2A, /**< VDM control by EC Enable register. */
    CY_HPI_PORT_REG_ALT_MODE_STATUS        = 0x2B, /**< Alternate Mode Status register. */
    CY_HPI_PORT_REG_BC_1_2_CONTROL         = 0x2C, /**< BC 1.2 support enable/disable control. */

    CY_HPI_PORT_REG_BYTE_45_RESERVED       = 0x2D, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_46_RESERVED       = 0x2E, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_47_RESERVED       = 0x2F, /**< Reserved register. */
    CY_HPI_PORT_REG_CMD_TIMEOUT            = 0x30, /**< Timeout associated with VDM and PD commands (ms). */

    CY_HPI_PORT_REG_FRS_ENABLE             = 0x31, /**< Fast Role Swap enable register. */
    CY_HPI_PORT_REG_CONSUMER_FET_CTRL      = 0x32, /**< VBUS Consumer FET Control register. */
    CY_HPI_PORT_REG_BYTE_51_RESERVED       = 0x33, /**< Reserved register. */
    CY_HPI_PORT_REG_INTERRUPT_STATUS       = 0x34, /**< Interrupt status register: LSB. */
    CY_HPI_PORT_REG_INT_STAT_BYTE_1        = 0x35, /**< Interrupt status register: Byte 1. */
    CY_HPI_PORT_REG_INT_STAT_BYTE_2        = 0x36, /**< Interrupt status register: Byte 2. */
    CY_HPI_PORT_REG_INT_STAT_BYTE_3        = 0x37, /**< Interrupt status register: MSB. */

    CY_HPI_PORT_REG_USERDEF_00             = 0x38, /**< User-defined register number 00. */
    CY_HPI_PORT_REG_USERDEF_01             = 0x39, /**< User-defined register number 01. */
    CY_HPI_PORT_REG_USERDEF_02             = 0x3A, /**< User-defined register number 02. */
    CY_HPI_PORT_REG_USERDEF_03             = 0x3B, /**< User-defined register number 03. */
    CY_HPI_PORT_REG_USERDEF_04             = 0x3C, /**< User-defined register number 04. */
    CY_HPI_PORT_REG_USERDEF_05             = 0x3D, /**< User-defined register number 05. */
    CY_HPI_PORT_REG_USERDEF_06             = 0x3E, /**< User-defined register number 06. */
    CY_HPI_PORT_REG_USERDEF_07             = 0x3F, /**< User-defined register number 07. */
    CY_HPI_PORT_REG_USERDEF_08             = 0x40, /**< User-defined register number 08. */
    CY_HPI_PORT_REG_USERDEF_09             = 0x41, /**< User-defined register number 09. */
    CY_HPI_PORT_REG_USERDEF_0A             = 0x42, /**< User-defined register number 0A. */
    CY_HPI_PORT_REG_USERDEF_0B             = 0x43, /**< User-defined register number 0B. */
    CY_HPI_PORT_REG_USERDEF_0C             = 0x44, /**< User-defined register number 0C. */
    CY_HPI_PORT_REG_USERDEF_0D             = 0x45, /**< User-defined register number 0D. */
    CY_HPI_PORT_REG_USERDEF_0E             = 0x46, /**< User-defined register number 0E. */
    CY_HPI_PORT_REG_USERDEF_0F             = 0x47, /**< User-defined register number 0F. */
    CY_HPI_PORT_REG_USERDEF_10             = 0x48, /**< User-defined register number 10. */
    CY_HPI_PORT_REG_USERDEF_11             = 0x49, /**< User-defined register number 11. */
    CY_HPI_PORT_REG_USERDEF_12             = 0x4A, /**< User-defined register number 12. */
    CY_HPI_PORT_REG_USERDEF_13             = 0x4B, /**< User-defined register number 13. */
    CY_HPI_PORT_REG_USERDEF_14             = 0x4C, /**< User-defined register number 14. */
    CY_HPI_PORT_REG_USERDEF_15             = 0x4D, /**< User-defined register number 15. */
    CY_HPI_PORT_REG_USERDEF_16             = 0x4E, /**< User-defined register number 16. */
    CY_HPI_PORT_REG_USERDEF_17             = 0x4F, /**< User-defined register number 17. */

    CY_HPI_PORT_REG_ACT_CBL_VDO_2          = 0x50, /**< Active cable VDO 2 byte 0 (LSB). */
    CY_HPI_PORT_REG_ACT_CBL_VDO_2_B1       = 0x51, /**< Active cable VDO 2 byte 1. */
    CY_HPI_PORT_REG_ACT_CBL_VDO_2_B2       = 0x52, /**< Active cable VDO 2 byte 2. */
    CY_HPI_PORT_REG_ACT_CBL_VDO_2_B3       = 0x53, /**< Active cable VDO 2 byte 3 (MSB). */

    CY_HPI_PORT_REG_SINK_RDO_REQUEST       = 0x54, /**< Send RDO from EC. */
    CY_HPI_PORT_REG_BUS_CURRENT            = 0x58, /**< VBus current in 50 mA units. */

    CY_HPI_PORT_REG_HOST_CAP_CTRL          = 0x5C, /**< Host Capabilities Control register. */

    CY_HPI_PORT_REG_ALT_MODE_MASK          = 0x60, /**< Alt Mode Mask register. */
    CY_HPI_PORT_REG_ALT_MODE_SVID          = 0x62, /**< Alt Mode SVID register byte 0. */
    CY_HPI_PORT_REG_ALT_MODE_SVID_BYTE_1   = 0x63, /**< Alt Mode SVID register byte 1. */

    CY_HPI_PORT_REG_SOURCE_PDO_EPR_MASK    = 0x64, /**< Current EPR Source PDO mask. */
    CY_HPI_PORT_REG_SINK_PDO_EPR_MASK      = 0x65, /**< Current EPR Sink PDO mask. */
    CY_HPI_PORT_REG_BYTE_66_RESERVED       = 0x66, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_67_RESERVED       = 0x67, /**< Reserved register. */
    CY_HPI_PORT_REG_SINK_PPS_AVS_CTRL      = 0x68, /**< PPS & AVS control register. */

    CY_HPI_PORT_REG_BYTE_80_RESERVED       = 0x80, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_84_RESERVED       = 0x84, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_85_RESERVED       = 0x85, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_86_RESERVED       = 0x86, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_88_RESERVED       = 0x88, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_8C_RESERVED       = 0x8C, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_90_RESERVED       = 0x90, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_94_RESERVED       = 0x94, /**< Reserved register. */
    CY_HPI_PORT_REG_BYTE_95_RESERVED       = 0x95, /**< Reserved register. */

    CY_HPI_PORT_REG_BYTE_A0_RESERVED       = 0xA0, /**< Reserved register.  */
    CY_HPI_PORT_REG_BYTE_A4_RESERVED       = 0xA4, /**< Reserved register.  */
    CY_HPI_PORT_REG_BYTE_A6_RESERVED       = 0xA6, /**< Reserved register.  */
} cy_en_hpi_port_reg_address_t;

#if (CCG_UCSI_ENABLE)
/**
 * @typedef cy_hpi_en_ucsi_status_reg_t
 * @brief HPI UCSI Status register values.
 *
 * Status values for the UCSI Status register defined in the HPI register
 * space.
 */
typedef enum
{
    CY_HPI_UCSI_STATUS_STARTED             = 0x00, /**< Status value to indicate UCSI is started. */
    CY_HPI_UCSI_STATUS_CMD_IN_PROGRESS     = 0x01, /**< Status value to indicate UCSI command is in progress. */
    CY_HPI_UCSI_STATUS_EVENT_PENDING       = 0x02, /**< Status value to indicate UCSI event pending. */
} cy_hpi_en_ucsi_status_reg_t;

/**
 * @typedef cy_hpi_en_ucsi_control_cmds_t
 * @brief HPI UCSI Control commands.
 *
 * Commands to control the UCSI interface.
 */
typedef enum
{
    CY_HPI_UCSI_START_CMD                  = 0x01, /**< This command starts the UCSI interface. */
    CY_HPI_UCSI_STOP_CMD,                          /**< This command stops the UCSI interface. */
    CY_HPI_UCSI_SILENCE_CMD,                       /**< This command silences the UCSI port. */
    CY_HPI_UCSI_SIG_CONNECT_EVT_CMD,               /**< EC sends this command to request CCG to send connect
                                                      event information to OS. */
} cy_hpi_en_ucsi_control_cmds_t;

#endif /* (CCG_UCSI_ENABLE) */


/**
 * @typedef cy_en_hpi_reg_section_t
 * @brief HPI register section definitions.
 *
 * HPI registers are grouped into sections corresponding to the functions that are supported.
 */
typedef enum
{
    CY_HPI_REG_SECTION_DEV                 = 0x00, /**< Device Information registers. */
    CY_HPI_REG_SECTION_PORT_0              = 0x01, /**< USB PD Port 0 related registers. */
    CY_HPI_REG_SECTION_PORT_1              = 0x02, /**< USB PD Port 1 related registers. */
    CY_HPI_REG_SECTION_DEV_AUTO            = 0x06, /**< HPI auto related registers */
    CY_HPI_REG_SECTION_UCSI                = 0x0F, /**< UCSI related registers. */
    CY_HPI_REG_SECTION_ALL                         /**< Special definition to select all register spaces. */
} cy_en_hpi_reg_section_t;

/**
 * @typedef cy_en_hpi_reg_part_t
 * @brief Types of HPI register/memory regions.
 */
typedef enum
{
    CY_HPI_REG_PART_REG                    = 0,    /**< Register region. */
    CY_HPI_REG_PART_DATA                   = 1,    /**< Data memory for device section. */
    CY_HPI_REG_PART_FLASH                  = 2,    /**< Flash memory. */
    CY_HPI_REG_PART_PDDATA_READ            = 4,    /**< Read data memory for port section. */
    CY_HPI_REG_PART_PDDATA_READ_H          = 5,    /**< Upper fraction of read data memory for port section. */
    CY_HPI_REG_PART_PDDATA_WRITE           = 8,    /**< Write data memory for port section. */
    CY_HPI_REG_PART_PDDATA_WRITE_H         = 9     /**< Upper fraction of write data memory for port section. */
} cy_en_hpi_reg_part_t;

/**
 * @typedef cy_en_hpi_boot_prio_conf_t
 * @brief Enumeration showing possible boot priority configurations for the firmware application.
 */
typedef enum
{
    CY_HPI_BOOT_PRIO_LAST_FLASHED         = 0,     /**< Last flashed firmware is prioritized. */
    CY_HPI_BOOT_PRIO_FW1,                          /**< FW1 is prioritized. */
    CY_HPI_BOOT_PRIO_FW2                           /**< FW2 is prioritized. */
} cy_en_hpi_boot_prio_conf_t;


/**
 * @typedef cy_en_hpi_sys_hw_error_t
 * @brief List of possible hardware errors defined for the system.
 */
typedef enum {
    CY_HPI_SYS_HW_ERROR_NONE               = 0x00, /**< No error. */
    CY_HPI_SYS_HW_ERROR_MUX_ACCESS         = 0x01, /**< Error while accessing data MUX. */
    CY_HPI_SYS_HW_ERROR_REG_ACCESS         = 0x02, /**< Error while accessing regulator. */
    CY_HPI_SYS_HW_ERROR_BAD_VOLTAGE        = 0x04  /**< Unexpected voltage generated by source regulator. */
} cy_en_hpi_sys_hw_error_t;

/**
 * @typedef cy_en_hpi_i2c_owner_t
 * @brief List of possible owners for the I2C slave interface. The interface can be used for one of HPI or UCSI
 * functionality at a time.
 */
typedef enum {
    CY_HPI_I2C_OWNER_UCSI                  = 0,    /**< I2C interface used for UCSI commands. */
    CY_HPI_I2C_OWNER_HPI                           /**< I2C interface used for HPI commands. */
} cy_en_hpi_i2c_owner_t;

/**
 * @typedef cy_en_hpi_i2c_cb_cmd_t
 * @brief Type of I2C operation being notified through a callback function.
 */
typedef enum
{
    CY_HPI_I2C_CB_CMD_READ                 = 0,    /**< Read command from master. */
    CY_HPI_I2C_CB_CMD_WRITE,                       /**< Write command from master. */
    CY_HPI_I2C_CB_CMD_XFER_END,                    /**< End of read transfer: STOP condition signalled by master. */
    CY_HPI_I2C_CB_CMD_TIMEOUT,                     /**< Timeout on I2C operation. */
    CY_HPI_I2C_CB_SLAVE_ADDR_MATCH                 /**< I2C slave address match detected. */
} cy_en_hpi_i2c_cb_cmd_t;

/**
 * @typedef cy_en_hpi_pps_avs_ctrl_en_t
 * @brief List of possible values for the Sink PPS AVS Enable Field.
 */
typedef enum {
    CY_HPI_PPS_AVS_CTRL_EN_NONE             = 0,   /**< Sink PPS AVS Control Enable None. */
    CY_HPI_PPS_AVS_CTRL_EN_PPS,                    /**< Sink PPS AVS Control Enable PPS. */
    CY_HPI_PPS_AVS_CTRL_EN_AVS                     /**< Sink PPS AVS Control Enable AVS. */
} cy_en_hpi_pps_avs_ctrl_en_t;

/** \} group_hpis_enums */

/**
* \addtogroup group_hpis_data_structures
* \{
*/


/**
 * @brief Parameters associated with a VDM_CTRL command.
 */
typedef union
{
    uint16_t    val;                               /**< VDM control parameter 2-byte value. */
    /** @brief VDM_CTRL parameters broken down into component fields. */
    struct PARAM_T
    {
        uint16_t sopType              : 2;         /**< VDM command SOP type. */
        uint16_t pd3Support           : 1;         /**< PD Specification Rev3 supported. */
        uint16_t extended             : 1;         /**< Extended message type. */
        uint16_t timeoutDisable       : 1;         /**< Timeout disable. */
        uint16_t rsrvd1               : 1;         /**< Reserve bit. */
        uint16_t lenMsb               : 2;         /**< VDM command length MSB bits. */
        uint16_t lenLsb               : 8;         /**< VDM command length LSB bits. */
    } param;                                       /**< VDM control command parameters. */
} cy_hpi_vdm_ctrl_param_t;

/**
 * @brief Sink PPS AVS PDO bit field.
 */
typedef union
{
    uint32_t    val;                               /**< PPS AVS control 32-bit value. */
    /** @brief PPS AVS control bit values. */
    struct 
    {
        uint32_t rqstd_current      : 7;           /**< PPS requested current. */
        uint32_t reserved_1         : 2;           /**< Reserve bit. */
        uint32_t rqstd_voltage      : 12;          /**< PPS requested voltage. */
        uint32_t reserved_2         : 3;           /**< Reserve bit. */
        uint32_t pps_rqst_intrvl    : 4;           /**< PPS request interval. */
        uint32_t reserved_3         : 2;           /**< Reserve bit. */
        uint32_t pps_avs_en         : 2;           /**< PPD AVS enable flag. */
    };
} cy_hpi_snk_pps_avs_ctrl_t;

/* Forward declarations of structures. */
struct cy_stc_hpi_context;

/**
 * @typedef cy_hpi_write_cbk_t
 * @brief Handler for HPI register writes.
 * @return Type of response to be sent to the EC. Only a single byte response
 * can be sent from here. Use cy_hpi_reg_enqueue_event to send longer responses.
 */
typedef uint8_t (*cy_hpi_write_cbk_t)(
        struct cy_stc_hpi_context *context,        /**< HPI data context. */
        uint16_t  reg_addr,                        /**< Address of register that is written. */
        uint8_t   wr_size,                         /**< Size of write operation. */
        uint8_t  *wr_data                          /**< Buffer containing data written. */
        );

#if SYS_BLACK_BOX_ENABLE
/**
 * @typedef cy_hpi_black_box_cbk_t
 * @brief Handler for black box access HPI command.
 * @return Address of black box.
 */
typedef uint32_t (*cy_hpi_black_box_cbk_t)(
        struct cy_stc_hpi_context *context         /**< HPI data context. */
        );
#endif /* SYS_BLACK_BOX_ENABLE */

/**
 * @typedef cy_hpi_i2c_cb_fun_t
 * @brief I2C callback function for interrupt notifications.
 * @return true - If the operation is success.
 *         false - If the operation is not success.
 */
typedef bool (*cy_hpi_i2c_cb_fun_t)(
                            void *context,               /**< Stack context pointer. */
                            cy_en_hpi_i2c_cb_cmd_t cmd,  /**< Type of I2C event notified. */
                            uint8_t state,               /**< Current I2C block state. */
                            uint16_t count               /**< Transaction size. */
                            );
                            
/**
* @brief Structure to hold the UCSI related status.
*/
typedef struct
{
    /** If UCSI read is pending from the EC, the state is tracked. */
    bool readPending;

    /** Check if the bus is already busy. */
    bool isI2cBusy;

    /** Track who owns the I2C bus. */
    volatile cy_en_hpi_i2c_owner_t i2cOwner;
}cy_stc_hpi_ucsi_status_t;

/**
* @brief Defines the solution-specific application callback.
*/
typedef struct
{
    void (*ec_intr_write)(
            bool value                                      /**< EC Interrupt status. */
            );                                              /**< Handler to control the HPI EC interrupt pin. */
    
    uint32_t (*sys_get_custom_info_addr)(void);             /**< Handler to get the alt mode status. */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE))
    bool (*hpi_is_event_enabled)(
            uint8_t port,                                   /**< PD port index. */
            uint8_t evCode,                                 /**< HPI event code.*/
            uint32_t evMask                                 /**< HPI event mask value.*/
            );                                              /**< Function to check the HPI event enabled status. */

    cy_en_pdstack_status_t (*app_disable_pd_port)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            cy_pdstack_dpm_typec_cmd_cbk_t cbk              /**< PD port disable app callback pointer. */
            );                                              /**< Wrapper function for PD port disable. */    
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (DFP_ALT_MODE_SUPP || UFP_ALT_MODE_SUPP))
    uint8_t (*alt_mode_get_status)(
            cy_stc_pdstack_context_t *context               /**< PD port index. */
            );                                              /**< Handler to get the alt mode status. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (DFP_ALT_MODE_SUPP || UFP_ALT_MODE_SUPP)) */

    void (*app_update_sys_pwr_state)(
            uint8_t state                                   /**< System power state. */
            );                                              /**< Function updates the system power state. */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_CMD_ENABLE))
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || ((DFP_ALT_MODE_SUPP) || (UFP_ALT_MODE_SUPP)))
    bool (*set_custom_svid)(
            cy_stc_pdstack_context_t *context,              /**< PD port index. */
            uint16_t svid                                   /**< Custom SVID value. */
            );                                              /**< Function sets the custom SVID value from HPI library. */

    void (*set_alt_mode_mask)(
            cy_stc_pdstack_context_t *context,              /**< PD port index. */
            uint16_t mask                                   /**< Alt mode mask value. */
            );                                              /**< Function sets the alt mode mask from HPI library. */
    bool (*app_vdm_layer_reset)(
            cy_stc_pdstack_context_t *ptrPdStackContext     /**< PD port index. */
            );                                              /**< Restarts the alternate mode layer. */
            
    bool (*eval_app_alt_mode_cmd)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            uint8_t *cmd,                                   /**< Pointer to received alt mode APP command. */
            uint8_t *data                                   /**< Pointer to received alt mode APP command additional data. */
            );                                              /**< Function analyzes, parses, and run the alternate mode analysis function if the received command is a specific alt mode command. */

    bool (*eval_app_alt_hw_cmd)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            uint8_t *cmd_param                              /**< Pointer to received application HW command data. */
            );                                              /**< Function evaluates received application HW command. */
            
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || ((DFP_ALT_MODE_SUPP) || (UFP_ALT_MODE_SUPP))) */

    bool (*set_custom_host_cap_control)(
            cy_stc_pdstack_context_t *context,              /**< PD port index. */
            uint8_t host_config                             /**< Host CAP configuration. */
            );                                              /**< Handler to update the custom host capability. */
            
    bool (*app_set_custom_pid)(
            cy_stc_pdstack_context_t *context,              /**< PD port index. */
            uint16_t usb_pid                                /**< UPB PID value. */
            );                                              /**< Stores the custom PID value in application status. */

    bool (*i2cm_gen_i2c_tunnel_cmd)(
            uint8_t *write_req_data,                        /**< Write data pointer. */
            uint8_t *read_req_data                          /**< Read data pointer. */
            );                                              /**< Handler for I2C read and write tunneling. */

    bool (*switch_vddd_supply)(
            cy_stc_pdstack_context_t *context,              /**< PD port index. */
            bool useVsys                                    /**< Switch VSYS or VDDD status. */
            );                                              /**< Function switches the supply from VDDD to VSYS and vice versa. */   
            
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_VDM_QUERY_SUPPORTED))
    uint8_t *(*vdm_get_disc_id_resp)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            uint8_t *resp_len_p                             /**< Length of response in PD data objects. */
            );                                              /**< Obtain the last DISC_ID response received by the CCG device from a port partner. */
    
    uint8_t *(*vdm_get_disc_svid_resp)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            uint8_t *resp_len_p                             /**< Length of response in PD data objects. */
            );                                              /**< Obtain the collective DISC_SVID response received by the CCG device from a port partner.*/
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_VDM_QUERY_SUPPORTED)) */

    void (*app_update_bc_src_support)(
            uint8_t port,                                   /**< PD port index. */
            uint8_t enable                                  /**< BC 1.2 support is enabled or disabled. */
            );                                              /**< Function updates the BC 1.2 source support. */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_VBUS_C_CTRL_ENABLE))
    bool (*psnk_set_vbus_cfet_on_ctrl)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< PD port index. */
            uint8_t *ctrl_p                                 /**< Pointer to command value. */
            );                                              /**< Function to handle Consumer FET control commands.*/
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_VBUS_C_CTRL_ENABLE)) */

    bool (*hpi_vconn_enable)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< Port index the function is performed. */
            uint8_t channel                                 /**< Selected CC line. */
            );                                              /**< Function enables VCONN power. */

    void (*hpi_vconn_disable)(
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< Port index the function is performed for. */
            uint8_t channel                                 /**< Selected CC line. */
            );                                              /**< This function disables VCONN power. */
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_RW_PD_RESP_MSG_DATA))
    cy_en_pdstack_status_t (*hpi_rw_pd_resp_data)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            cy_stc_pdstack_context_t *ptrPdStackContext,    /**< Pointer to the PD context. */
            uint8_t *data                                   /**< Pointer to received RW PD response data command. */
            );                                              /**< This function handles the RW PD response data command. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_RW_PD_RESP_MSG_DATA)) */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_CMD_ENABLE)) */

    uint16_t (*vbus_get_live_current)(
            cy_stc_pdstack_context_t *ptrPdStackContext     /**< PDStack context pointer. */
            );                                              /**< Function measures the live VBUS current. */

#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)) */


    void (*set_bootloader_run_type)(
            uint32_t runType                                /**< Firmware run type signature. */
            );                                              /**< Function updates the current firmware run type status. */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (!CY_HPI_BOOT_ENABLE))
    int8_t (*hpi_boot_validate_fw)(
            void *fw_addr                                   /**< Flash address of the firmware. */
            );                                              /**< API validate the firmware and return the status. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (!CY_HPI_BOOT_ENABLE)) */
    
    int8_t (*hpi_boot_validate_fw_cmd)(
            uint8_t fw_mode                                 /**< Firmware which needs to be validated. */
            );                                              /**< Function is used to validate the firmware image. */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (!CY_HPI_BOOT_ENABLE))
    uint8_t (*hpi_sys_get_device_mode)(void);               /**< This function gets the current device mode. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (!CY_HPI_BOOT_ENABLE)) */

#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_FLASH_RW_ENABLE))
    int8_t (*hpi_flash_row_write)(
            uint16_t row_num,                               /**< Flash row to be updated. */
            uint8_t *data,                                  /**< Buffer containing data to be written to the flash row. */
            void *cbk                                       /**< Callback function is called at the end of non-blocking flash write. */
            );                                              /**< Writes the given data to the specified flash row. */

    int8_t (*hpi_flash_row_read)(
            uint16_t row_num,                               /**< Reads the flash row. */
            uint8_t* data                                   /**< Buffer to read the flash row content into. */
            );                                              /**< Read the contents of the specified flash row. */
    
    bool (*hpi_flash_access_get_status)(
            uint8_t modes                                   /**< Bitmap containing flashing interfaces to be checked. */
            );                                              /**< Check whether flashing mode has been entered. */

    void (*hpi_flash_enter_mode)(
            bool is_enable,                                 /**< Enable/disable Flashing mode. */
            uint8_t mode,                                   /**< Flash update interface to be used. */
            bool data_in_place                              /**< Specifies whether the flash write data buffer can be used in place as SROM API parameter buffer. */
            );                                              /**< Handle ENTER_FLASHING_MODE command. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_FLASH_RW_ENABLE)) */
    
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CCG_UCSI_ENABLE))
    void (*ucsi_notify)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint8_t port,                                   /**< Port index the function is performed. */
            uint16_t notification                           /**< Notification ID. */
            );                                              /**< Function updates the UCSI notifications. */

    void (*ucsi_reg_space_write_handler)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint8_t *hpi_buffer,                            /**< HPI I2C buffer. */
            uint16_t hpi_wr_count                           /**< Write data count in bytes. */
            );                                              /**< Function handles the writes to the UCSI register space. */

    uint8_t (*ucsi_handle_hpi_commands)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint8_t *cmd_param                              /**< Command parameters. */
            );                                              /**< Function handles the UCSI HPI commands. */

    void (*hpi_update_ucsi_reg_space)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint16_t offset                                 /**< UCSI command offset. */
            );                                              /**< This function updates the UCSI reg space. */
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CCG_UCSI_ENABLE)) */

    bool (*hpi_dev_wr_handler_ext)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint8_t  cmdOpcode,                             /**< Offset address of the HPI device-specific register.*/
            uint8_t *cmdParam,                              /**< Pointer to HPI command buffer. */
            uint8_t  cmdLength,                             /**< Write data count in bytes. */
            cy_en_hpi_status_t *stat,                       /**< Parameter to store HPI status code. */
            cy_en_hpi_response_t *code                      /**< Parameter to store HPI response and event codes. */
            );                                              /**< Function handles the writes to the HPI Device register space. */

    bool (*hpi_port_wr_handler_ext)(
            struct cy_stc_hpi_context *context,             /**< HPI context pointer. */
            uint8_t  port,                                  /**< Port Index. */
            uint8_t  cmdOpcode,                             /**< Offset address of the HPI Port register.*/
            uint8_t *cmdParam,                              /**< Pointer to HPI command buffer. */
            uint8_t  cmdLength,                             /**< Write data count in bytes. */
            cy_en_hpi_status_t *stat,                       /**< Parameter to store HPI status code. */
            cy_en_hpi_response_t *code                      /**< Parameter to store HPI response and event codes. */
            );                                              /**< Function handles the writes to the HPI Port register space. */
}cy_stc_hpi_app_cbk_t;

/**
 * @brief HPI middleware context information.
 */
typedef struct
{
    /** SCB module base address. */
    CySCB_Type *scbBase;

    /** Slave address is valid in slave modes. */
    uint8_t  slave_address;

    /** Slave address mask is valid in slave modes. */
    uint8_t  slave_mask;

    /** Slave ACK disable for I2C slave blocks. */
    volatile bool i2c_ack_disable;

    /** Indicates whether there is a pending slave ACK. */
    volatile bool i2c_ack_pending;
    
    /** Current state of the I2C block. */
    uint8_t i2c_state;   
    
    /** Buffer is used to receive data. */
    uint8_t *buffer;   
    
    /** Size of receive buffer. */
    uint16_t buf_size;   
    
    /** Current index into receive buffer. */
    volatile uint16_t i2c_write_count;
    
    /** Callback function pointer. */
    cy_hpi_i2c_cb_fun_t cb_fun_ptr;     
    
    /** Callback context pointer. */
    void  *ptr_cbk_context;

    /** Pointer to the timer context. */
    void *ptrTimerContext;
}cy_stc_hpi_i2c_context_t;

/**
* @brief Defines the HPI flash configurations.
*/
typedef struct
{
    /** Device flash size. */
    uint32_t flashSize;
    
    /** Device flash row size. */
    uint16_t flashRowSize;

    /** Flash row count. */
    uint16_t flashRowCnt;

    /** Last flash row assigned to bootloader. */
    uint16_t blLastRow;
}cy_stc_hpi_flash_config_t;


#if (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)
/**
 * @brief Structure to hold the HPI DOs list information.
 */
typedef struct
{
    /** PD data object count. */ 
    uint8_t  doCnt;
    
    /** PD data object list. */
    uint32_t doList[CY_PD_MAX_NO_OF_DO];
}cy_stc_hpi_disc_mode_resp_t;
#endif /* (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE) */

/**
 * @brief Structure to define the HPI device-specific register details.
 */
typedef struct __attribute__((packed))
{
    uint8_t  device_mode;                                   /**< 00h    - Device Operation mode. */
    uint8_t  boot_mode_reason;                              /**< 01h    - Reason for Boot mode operation. */
    uint16_t silicon_id;                                    /**< 03:02h - Device Silicon ID.*/
    uint16_t bl_last_row;                                   /**< 05:04h - Number of last flash row occupied by Bootloader. */
    uint8_t  intr_stat;                                     /**< 06h    - Interrupt GPIO status. */
    uint8_t  jump_to_boot;                                  /**< 07h    - Jump to boot or alternate firmware. */
    uint16_t reset_rqt;                                     /**< 09:08h - Device/I2C reset. */
    uint8_t  enter_flash;                                   /**< 0Ah    - Enter Flashing mode. */
    uint8_t  validate_fw;                                   /**< 0Bh    - Validate firmware image. */
    uint32_t flash_read_write;                              /**< 0F:0Ch - Flash read/write. */
    uint8_t  dev_version[16];                               /**< 1F:10h - Bootloader and FW version. */
    uint8_t  fw_2_version[8];                               /**< 27:20h - Firmware2 version. */
    uint16_t fw_bin_loc[2];                                 /**< 2B:28h - Firmware binary location. */
    uint8_t  port_enable;                                   /**< 2Ch    - PD port enable bit mask. */
    uint8_t  sleep_ctrl;                                    /**< 2Dh    - Deep Sleep enable/disable register. */
    uint8_t  power_stat;                                    /**< 2Eh    - System Power Status register. */
    uint8_t  set_app_priority;                              /**< 2Fh    - Set application boot priority. */
    uint8_t  read_customer_info;                            /**< 30h    - Read customer-specific information. */
    uint8_t  battery_stat;                                  /**< 31h    - Current Battery Status register. */
    uint8_t  wd_reset_count;                                /**< 32h    - Watchdog reset count since startup. */
    uint8_t  read_die_info;                                 /**< 33h    - Read DIA and Silicon ID. */
    uint32_t hpi_vers_ext;                                  /**< 37:34h - HPI library and feature support information. */
    uint8_t  ucsi_status;                                   /**< 38h    - UCSI Status register. */
    uint8_t  ucsi_control;                                  /**< 39h    - UCSI Control register. */
    uint8_t  cfgtab_vers;                                   /**< 3Ah    - Config table version supported by firmware. */
    uint8_t  syspwr_state;                                  /**< 3Bh    - System power state (received from EC). */
    uint32_t hpi_vers;                                      /**< 3F:3Ch - HPI version and feature support information. */
    uint8_t  userdef_regs[CY_HPI_USERDEF_REG_COUNT];        /**< 4F:40h - User-specific register space. */
    uint8_t  bb_disable_reset;                              /**< 50h    - Control register used by Billboard controller to prevent reset. */
    uint8_t  byte_81_reserved;                              /**< 51h    - Reserved for future implementation. */
    uint16_t bb_altmode_status;                             /**< 53:52h - Alternate mode status to be reported during Billboard enumeration. */
    uint8_t  bb_oper_model;                                 /**< 54h    - Billboard operating model configuration. */
    uint8_t  bb_addl_fail_info;                             /**< 55h    - Billboard failure information during enumeration. */
    uint8_t  bb_cmd_reg;                                    /**< 56h    - Reserved register to support Billboard commands. */
    uint8_t  bb_misc_info;                                  /**< 57h    - Reserved register to report PD contract status. */
    uint8_t  bb_bl_version[8];                              /**< 5F:58h - Reserved Register to expand Billboard communication. */
    uint8_t  bb_fw_version[8];                              /**< 67:60h - Reserved Register to expand Billboard communication. */
    uint8_t  reg_6F_68h[8];                                 /**< 6F:68h - Reserved Register for future use. */
    uint16_t pps_design_voltage;                            /**< 71:70h - PPD design voltage. */
    uint8_t  fw_update_lock;                                /**< 72h    - FW Update lock state. */          
    uint8_t  dev_control;                                   /**< 73h    - Device Control register. */
    uint8_t  userdef_rsvd[CY_HPI_DEVICE_RESERVED_COUNT];    /**< 7D:74h - Reserved register for future implementation. */
    uint8_t  response;                                      /**< 7Eh    - Response ID/Code. */
    uint8_t  response_length;                               /**< 7Fh    - Response data length. */
} cy_stc_hpi_dev_reg_t;

#if (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)
/**
 * @brief Structure to define the HPI PD port-specific register details.
 */
typedef struct __attribute__((packed))
{
    uint16_t vdm_ctrl;                                      /**< 00h */
    uint8_t  eff_src_pdo_mask;                              /**< 02h */
    uint8_t  eff_sink_pdo_mask;                             /**< 03h */
    uint8_t  src_pdo_select;                                /**< 04h */
    uint8_t  sink_pdo_select;                               /**< 05h */
    uint8_t  pd_ctrl;                                       /**< 06h */
    uint8_t  byte_7_reserved;                               /**< 07h */
    uint32_t pd_status;                                     /**< 08h */
    uint8_t  type_c_status;                                 /**< 0Ch */
    uint16_t bus_voltage;                                   /**< 0Dh */
    uint8_t  byte_14_reserved;                              /**< 0Fh */
    uint32_t cur_pdo;                                       /**< 10h */
    uint32_t cur_rdo;                                       /**< 14h */
    uint32_t cable_vdo;                                     /**< 18h */
    uint32_t alt_mode;                                      /**< 1Ch */
    uint32_t app_hw;                                        /**< 20h */
    uint32_t event_mask;                                    /**< 24h */
    uint8_t  swap_response;                                 /**< 28h */
    uint8_t  active_ec_modes;                               /**< 29h */
    uint8_t  vdm_ec_ctrl;                                   /**< 2Ah */
    uint8_t  alt_mode_status;                               /**< 2Bh */
    uint8_t  bc12_control;                                  /**< 2Ch */
    uint8_t  byte_45_reserved[3];                           /**< 2Dh */
    uint8_t  pd_cmd_timeout;                                /**< 30h */
    uint8_t  frs_enable;                                    /**< 31h */
    uint8_t  vbus_cfet_ctrl;                                /**< 32h */
    uint8_t  bc12_status;                                   /**< 33h */
    uint32_t intr_status;                                   /**< 34h */
    uint8_t  port_user_reg[24];                             /**< 38h */
    uint32_t act_cbl_vdo_2;                                 /**< 50h */
    uint32_t sink_rdo_request;                              /**< 54h */
    uint8_t  bus_current;                                   /**< 58h */
    uint8_t  byte_89_reserved[3];                           /**< 59h */
    uint8_t  host_cap_control;                              /**< 5Ch */
    uint8_t  byte_93_reserved[3];                           /**< 5Dh */
    uint8_t  dfp_alt_mode_mask;                             /**< 60h */
    uint8_t  ufp_alt_mode_mask;                             /**< 61h */
    uint16_t custom_alt_mode_svid;                          /**< 62h */
    uint8_t  epr_src_pdo_select;                            /**< 64h */
    uint8_t  epr_snk_pdo_select;                            /**< 65h */
    uint8_t  byte_102_reserved[2];                          /**< 66h */
    uint32_t sink_pps_avs_ctrl;                             /**< 68h */
    uint8_t  moisture_status;                               /**< 6Ch */
}cy_stc_hpi_port_reg_t;
#endif /* (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE) */

/**
 * @brief Structure to hold the HPI Device and PD register information.
 */
typedef struct
{
    /** Variable to store the device-specific register information. */
    cy_stc_hpi_dev_reg_t dev;

    /** Buffer to store device level interrupt response data. */
    uint8_t sromApiArg[CY_SROM_API_PARAM_SIZE];

    /** Flash read/write memory scratch buffer. */
    uint8_t flashMem[CY_HPI_MAX_FLASH_ROW_SIZE];

    /** Space reserved or padding. */
    uint8_t padSpace[16];
    
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE))
    /** Variable to store the port-specific register information. */
    cy_stc_hpi_port_reg_t port[CY_HPI_NO_OF_PD_PORTS_MAX];

    /** Pointer to hold the port-specific write memory buffer address. */
    uint8_t *writeMem[CY_HPI_NO_OF_PD_PORTS_MAX];
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)) */
} cy_stc_hpi_reg_space_t;

/**
 * @brief Structure to hold the queue information used by HPI.
 */
typedef struct
{
    /** Pointer to start of the buffer. */
    uint8_t  *startPtr;

    /** Size of the buffer. */
    uint16_t  bufSize;

    /** Offset to store the next message. */
    volatile uint16_t queueLoc;

    /** Offset where the first message in the queue ends. */
    volatile uint16_t msgEndLoc;
}cy_stc_hpi_event_queue_t;

/**
 * @brief Structure to configure the HPI communication bus and interrupt pin.
 */
typedef struct
{
    /** SCB Type address. */
    CySCB_Type *scbBase;
    
    /** SCB GPIO port base address.*/
    GPIO_PRT_Type* scbPort;

    /** HPI slave address. */
    volatile uint8_t slaveAddr;

    /** HPI interrupt port base address. */
    GPIO_PRT_Type* ecIntPort;

    /** HPI interrupt pin number. */
    uint32_t ecIntPin;
}cy_stc_hpi_hw_config_t;

#if (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)
/**
 * @brief Structure to hold the PD status and configurations.
 */
typedef struct
{
    /** Array holds the DISC_MODE responses received for various alternate modes. */
    cy_stc_hpi_disc_mode_resp_t amDiscResp[CY_HPI_MAX_ALTMODE_COUNT];

    /** Number of alternate modes for which response data is stored. */
    uint8_t  amDiscCount;

    /** Check if the DPM command retry is pending. */
    bool pdRetryPending;

    /** Active DPM command for each PD port. */
    cy_en_pdstack_dpm_pd_cmd_t dpmCmd;

    /** Active Type-C command for each PD port. */
    cy_en_pdstack_dpm_typec_cmd_t typecCmd;

    /** DPM command parameters for each port. */
    cy_stc_pdstack_dpm_pd_cmd_buf_t dpmCmdParam;

    /** Variable to track GO_TO_MIN status. */
    volatile bool snkMinStat;

    /** Variable to track GO_TO_MIN received status. */
    volatile bool gotoMinRcvd;
} cy_stc_hpi_pd_status_t;
#endif /* (SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE) */
/**
 * @brief Data structure to hold the HPI interrupt and command operation status
 * variable.
 */
typedef struct
{
    /** Check if any PD port disable operations are pending. */
    volatile uint8_t portStopPending;

    /** Check for the HPI accesses since startup. */
    bool accessed;

    /** Check if the HPI-based PDO updates are allowed. */
    bool pdoUpdateDisable;

    /** Check if the EC interrupt is enabled/disabled. */
    uint8_t ecInt;

    /** Check if the EC init complete event is received. */
    bool ecReady;

    /** Check if the HPI command handling is pending. */
    volatile bool cmdPending;

    /** Size of data in HPI command buffer. */
    volatile uint16_t wrCount;

    /** Variable uses to implement debug features. */
    volatile bool freezeStack;

    /** Current pointer to HPI register space. */
    uint8_t *regPtr;

    /** Limit on valid address space so that the EC does not keep reading. */
    uint8_t *regLimit;

    /** If an EC_INT write is pending, this variable is set. */
    bool ecIntPending;

    /** Current cursor position of the log message. */
    volatile uint16_t logAddr;

    /** HPI soft reset time delay. */
    uint16_t softResetDelay;

    /** HPI soft reset timer ID. */
    uint16_t softResetTimerId;

    /** EPR exit flag */
    bool eprExit[CY_HPI_NO_OF_PD_PORTS_MAX];
} cy_stc_hpi_status_t;

/**
 * @brief Data structure to HPI middleware context information.
 */
typedef struct cy_stc_hpi_context
{
    
    /** I2C context structure. */
    cy_stc_hpi_i2c_context_t i2cContext;

    /** HPI status variable. */
    cy_stc_hpi_status_t hpiStat;

    /** Flash configurations. */
    cy_stc_hpi_flash_config_t flashConfig;

    /** Handler for user-defined register writes. */
    cy_hpi_write_cbk_t userdefCb;

    /** HPI app callback. */
    cy_stc_hpi_app_cbk_t *ptrAppCbk;

    /** RAM copy of all HPI registers. */
    cy_stc_hpi_reg_space_t regSpace;
    
#if ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE))
    /** HPI PD status for each port.*/
    cy_stc_hpi_pd_status_t pdStatus[CY_HPI_NO_OF_PD_PORTS_MAX];

    /** PDStack context pointer for each port. */
    cy_stc_pdstack_context_t *ptrPdContext[CY_HPI_NO_OF_PD_PORTS_MAX];
#endif /* ((SROM_CODE_HPISS_HPI == MODULE_IN_ROM) || (CY_HPI_PD_ENABLE)) */
    /** Queue for storing events. */
    cy_stc_hpi_event_queue_t eventQueue[CY_HPI_NO_OF_PD_PORTS_MAX + 1];

    /** Pointer to store the UCSI context structure. */
    void *ptrUcsiContext;

    /** Variable to store the UCSI status. */
    cy_stc_hpi_ucsi_status_t hpiUcsiStat;

}cy_stc_hpi_context_t;


/** \} group_hpis_data_structures */

#endif /* CY_HPI_DEFINES_DEFAULT_H */
