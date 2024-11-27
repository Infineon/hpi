/*******************************************************************************
* File Name: cy_hpi_master_defines.h
* \version 1.1.0
*
* Defines the macros and data structures for HPI master middleware.
*
********************************************************************************
* \copyright
* (c) 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_HPI_MASTER_DEFINES_H
#define CY_HPI_MASTER_DEFINES_H

#include <stdint.h>
#include <stdbool.h>
#include "cy_pdl.h"

/**
* \addtogroup group_hpim_macros
* \{
*/

/** Mask to set/clear all HPI interrupt status bits. */
#define CY_HPI_MASTER_INTR_REG_CLEAR_DEV_INT          (0x01U)

/** Mask to set/clear all HPI interrupt status bits. */
#define CY_HPI_MASTER_INTR_REG_CLEAR_PORT0_INT        (0x02U)

/** Mask to set/clear all HPI interrupt status bits. */
#define CY_HPI_MASTER_INTR_REG_CLEAR_PORT1_INT        (0x04U)

/** HPI master Port 0 number. */
#define CY_HPI_MASTER_PORT_NUMBER_0                   (0U)

/** HPI master Port 1 number. */
#define CY_HPI_MASTER_PORT_NUMBER_1                   (1U)

/** Signature to request a JUMP_TO_BOOT operation. */
#define CY_HPI_MASTER_JUMP_TO_BOOT_CMD_SIG            ('J')

/** Signature to request a JUMP_TO_ALT_FW operation. */
#define CY_HPI_MASTER_JUMP_TO_ALT_FW_SIG              ('A')

/** Signature to request entry to flash update mode. */
#define CY_HPI_MASTER_ENTER_FLASHING_CMD_SIG          ('P')

/** Signature for valid flash read/write requests. */
#define CY_HPI_MASTER_FLASH_READ_WRITE_CMD_SIG        ('F')

/** Command code to read a flash row. */
#define CY_HPI_MASTER_FLASH_ROW_READ_CMD              (0x00U)

/** Command code to write a flash row. */
#define CY_HPI_MASTER_FLASH_ROW_WRITE_CMD             (0x01U)

/** Size of the firmware binary version. */
#define CY_HPI_MASTER_FW_VERSION_SIZE                 (8U)

/** All HPI version register size in bytes. */
#define CY_HPI_MASTER_DEV_REG_ALL_VERSION_BYTES       (CY_HPI_MASTER_FW_VERSION_SIZE * 3)

/** Signature to request an I2C interface or device reset. */
#define CY_HPI_MASTER_RESET_CMD_SIG                   ('R')

/** Command code for a device reset request. */
#define CY_HPI_MASTER_RESET_DEVICE_RESET_CMD          (0x01u)

/** HPI slave invalid index number. */
#define CY_HPI_MASTER_UNKNOWN_SLAVE_IDX               (0xFFU)

/** \} group_hpim_macros */

/**
* \addtogroup group_hpim_enums
* \{
*/

/**
 * @typedef cy_hpi_master_status_t
 * @brief HPI master return status.
 *
 * Return status of HPI master.
 */
typedef enum
{
    CY_HPI_MASTER_SUCCESS                  = 0U,            /**< Success return code. */
    CY_HPI_MASTER_FAILURE                  = 1U,            /**< Generic failure return code. */
    CY_HPI_MASTER_INVALID_ARGS             = 2U,            /**< Invalid argument passed. */
    CY_HPI_MASTER_QUEUE_OVERFLOW           = 3U,            /**< HPI master event queue overflow error. */
    CY_HPI_MASTER_I2C_FAILURE              = 4U,            /**< HPI master read/write to slave device failure. */
} cy_hpi_master_status_t;

/**
 * @typedef cy_hpi_master_evt_mask_t
 * @brief HPI event mask definitions.
 *
 * Mask values that control the reporting of HPI events.
 */
typedef enum 
{
    CY_HPI_MASTER_EVT_MASK_DISABLED        = 0x00000000U,   /**< Mask value disabled. */
    CY_HPI_MASTER_EVT_MASK_RSRVD           = 0x00000001U,   /**< Mask value reserved. */
    CY_HPI_MASTER_EVT_MASK_OCP             = 0x00000002U,   /**< Mask to enable/disable overcurrent event. */
    CY_HPI_MASTER_EVT_MASK_OVP             = 0x00000004U,   /**< Mask to enable/disable overvoltage event. */
    CY_HPI_MASTER_EVT_MASK_CC_CONNECT      = 0x00000008U,   /**< Mask to enable/disable Type-C connect event. */
    CY_HPI_MASTER_EVT_MASK_CC_DISCON       = 0x00000010U,   /**< Mask to enable/disable Type-C disconnect event. */
    CY_HPI_MASTER_EVT_MASK_CONTRACT        = 0x00000020U,   /**< Mask to enable/disable PD contract complete event. */
    CY_HPI_MASTER_EVT_MASK_CTRL_MSG        = 0x00000040U,   /**< Mask to enable/disable PD control message events. */
    CY_HPI_MASTER_EVT_MASK_VDM_RCVD        = 0x00000080U,   /**< Mask to enable/disable VDM received event. */
    CY_HPI_MASTER_EVT_MASK_SRC_CAP         = 0x00000100U,   /**< Mask to enable/disable source capabilities event received. */
    CY_HPI_MASTER_EVT_MASK_SNK_CAP         = 0x00000200U,   /**< Mask to enable/disable sink capabilities event received. */
    CY_HPI_MASTER_EVT_MASK_ALT_MODE        = 0x00000400U,   /**< Mask to enable/disable alternate mode related events. */
    CY_HPI_MASTER_EVT_MASK_ERROR           = 0x00000800U,   /**< Mask to enable/disable error events. */
    CY_HPI_MASTER_EVT_MASK_EMCA            = 0x00001000U,   /**< Mask to enable/disable EMCA connection related events. */
    CY_HPI_MASTER_EVT_MASK_MISC            = 0x00002000U,   /**< Mask to enable/disable miscellaneous events like Rp change. */
    CY_HPI_MASTER_EVT_MASK_BB              = 0x00004000U,   /**< Mask to enable/disable Billboard events. */
    CY_HPI_MASTER_EVT_MASK_OTP             = 0x00010000U,   /**< Mask to enable/disable overtemperature event. */
    CY_HPI_MASTER_EVT_MASK_DATA_MSG        = 0x00020000U,   /**< Mask to enable/disable data message event. */
    CY_HPI_MASTER_EVT_MASK_SYS_ERROR       = 0x00040000U,   /**< Mask to enable/disable system error notifications. */
} cy_hpi_master_evt_mask_t;

/**
 * @typedef cy_hpi_master_response_t
 * @brief List of HPI response and event codes.
 */
typedef enum
{
    CY_HPI_MASTER_RESPONSE_NO_RESPONSE            = 0x00,   /**< No valid response. */
    CY_HPI_MASTER_RESPONSE_SUCCESS                = 0x02,   /**< Success response. */
    CY_HPI_MASTER_RESPONSE_FLASH_DATA_AVAILABLE   = 0x03,   /**< Flash read data available in flash data memory. */
    CY_HPI_MASTER_RESPONSE_INVALID_COMMAND        = 0x05,   /**< Invalid command received. */
    CY_HPI_MASTER_RESPONSE_FLASH_UPDATE_FAILED    = 0x07,   /**< Flash read/write operation failed. */
    CY_HPI_MASTER_RESPONSE_INVALID_FW             = 0x08,   /**< Invalid firmware binary. */
    CY_HPI_MASTER_RESPONSE_INVALID_ARGUMENT       = 0x09,   /**< Invalid parameter for the command. */
    CY_HPI_MASTER_RESPONSE_NOT_SUPPORTED          = 0x0A,   /**< Command received is not supported. */
    CY_HPI_MASTER_RESPONSE_PD_TRANSACTION_FAILED  = 0x0C,   /**< USB PD transaction failed. */
    CY_HPI_MASTER_RESPONSE_PD_COMMAND_FAILED      = 0x0D,   /**< USB PD command failed. */
    CY_HPI_MASTER_RESPONSE_UNDEFINED_ERROR        = 0x0F,   /**< Undefined error. */
    CY_HPI_MASTER_RESPONSE_PDO_DATA               = 0x10,   /**< PDO read data is available in read data memory. */
    CY_HPI_MASTER_RESPONSE_CMD_ABORTED            = 0x11,   /**< HPI initiated PD command aborted. */
    CY_HPI_MASTER_RESPONSE_PORT_BUSY              = 0x12,   /**< HPI initiated PD command due to busy port. */
    CY_HPI_MASTER_RESPONSE_MIN_MAX_CUR            = 0x13,   /**< HPI response for sink Min/Max current data. */
    CY_HPI_MASTER_RESPONSE_EXT_SRC_CAP            = 0x14,   /**< HPI response for external source cap data. */
    
    CY_HPI_MASTER_EVENT_RESET_COMPLETE            = 0x80,   /**< Resets complete event notification. */
    CY_HPI_MASTER_EVENT_MSG_OVERFLOW              = 0x81,   /**< Event message queue overflow. */
    CY_HPI_MASTER_EVENT_OC_DETECT                 = 0x82,   /**< Overcurrent event detected. */
    CY_HPI_MASTER_EVENT_OV_DETECT                 = 0x83,   /**< Overvoltage event detected. */
    CY_HPI_MASTER_EVENT_CONNECT_DETECT            = 0x84,   /**< Type-C connect detected. */
    CY_HPI_MASTER_EVENT_DISCONNECT_DETECT         = 0x85,   /**< Type-C disconnect detected. */
    CY_HPI_MASTER_EVENT_NEGOTIATION_COMPLETE      = 0x86,   /**< PD contract negotiation complete. */
    CY_HPI_MASTER_EVENT_SWAP_COMPLETE             = 0x87,   /**< Swap (DR_SWAP, PR_SWAP or VCONN_SWAP) complete. */
    CY_HPI_MASTER_EVENT_PS_RDY_RECEIVED           = 0x8A,   /**< PS_RDY message received. */
    CY_HPI_MASTER_EVENT_GOTO_MIN_RECEIVED         = 0x8B,   /**< GOTO_MIN message received. */
    CY_HPI_MASTER_EVENT_ACCEPT_RECEIVED           = 0x8C,   /**< ACCEPT message received. */
    CY_HPI_MASTER_EVENT_REJECT_RECEIVED           = 0x8D,   /**< REJECT message received. */
    CY_HPI_MASTER_EVENT_WAIT_RECEIVED             = 0x8E,   /**< WAIT message received. */
    CY_HPI_MASTER_EVENT_HARD_RESET_RECEIVED       = 0x8F,   /**< HARD RESET received. */
    CY_HPI_MASTER_EVENT_VDM_RECEIVED              = 0x90,   /**< VDM received and stored in data memory. */
    CY_HPI_MASTER_EVENT_SOURCE_CAP_RECEIVED       = 0x91,   /**< Source capabilities received and the PDOs received are stored
                                                                 in data memory. */
    CY_HPI_MASTER_EVENT_SINK_CAP_RECEIVED         = 0x92,   /**< Sink capabilities received and the PDOs received are stored in
                                                                 data memory. */
    CY_HPI_MASTER_EVENT_HARD_RESET_SENT           = 0x9A,   /**< HARD RESET is sent by CCG device. */
    CY_HPI_MASTER_EVENT_SOFT_RESET_SENT           = 0x9B,   /**< SOFT RESET is sent by CCG device. Event data indicates the
                                                                 SOFT RESET packet type (SOP, SOP', or SOP''). */
    CY_HPI_MASTER_EVENT_CABLE_RESET_SENT          = 0x9C,   /**< CABLE RESET is sent by CCG device. */
    CY_HPI_MASTER_EVENT_SOURCE_DISABLED           = 0x9D,   /**< Enters Source disabled state. */
    CY_HPI_MASTER_EVENT_SENDER_TIMEOUT            = 0x9E,   /**< Sender Response timeout occurred. */
    CY_HPI_MASTER_EVENT_VDM_NO_RESPONSE           = 0x9F,   /**< No response to VDM sent by CCG device. */
    CY_HPI_MASTER_EVENT_UNEXPECTED_VOLTAGE        = 0xA0,   /**< Unexpected VBus voltage detected. */
    CY_HPI_MASTER_EVENT_ERROR_RECOVERY            = 0xA1,   /**< Initiates Type-C error recovery. */
    CY_HPI_MASTER_EVENT_BAT_STATUS_RECEIVED       = 0xA2,   /**< Battery status message received. */
    CY_HPI_MASTER_EVENT_ALERT_RECEIVED            = 0xA3,   /**< Alert message received. */
    CY_HPI_MASTER_EVENT_NOTSUPP_RECEIVED          = 0xA4,   /**< Not supported message received. */
    CY_HPI_MASTER_EVENT_EMCA_DETECT               = 0xA6,   /**< EMCA detected. */
    CY_HPI_MASTER_EVENT_EMCA_NOT_DETECT           = 0xA7,   /**< No EMCA present in current connection. */
    CY_HPI_MASTER_EVENT_RP_CHANGE_DETECT          = 0xAA,   /**< Change in Rp termination detected. */
    CY_HPI_MASTER_EVENT_BB_UPDATE                 = 0xAB,   /**< Billboard update event. */
    CY_HPI_MASTER_EVENT_PD_EXTD_MSG_SOP           = 0xAC,   /**< PD extended data message (SOP) received. */
    CY_HPI_MASTER_EVENT_ALT_MODE                  = 0xB0,   /**< Alternate mode related event. Event data contains the SVID
                                                                 corresponding to the mode as well as the event type. */
    CY_HPI_MASTER_EVENT_APP_HW                    = 0xB1,   /**< Alternate mode control hardware (MUX, HPD, etc.) related
                                                                 event occurred. */
    CY_HPI_MASTER_EVENT_PD_EXTD_MSG_SOP_PRIME     = 0xB4,   /**< PD extended data message (SOP') received. */
    CY_HPI_MASTER_EVENT_PD_EXTD_MSG_SOP_DPRIME    = 0xB5,   /**< PD extended data message (SOP'') received. */
    CY_HPI_MASTER_EVENT_OT_DETECT                 = 0xB6,   /**< Overtemperature condition detected. */
} cy_hpi_master_response_t;

/**
 * @typedef cy_hpi_master_dev_reg_t
 * @brief List of HPI device information register addresses.
 *
 * This enumeration lists the addresses for the HPI device information registers
 * supported by CCGx devices. These registers are used to retrieve firmware mode
 * and version information, and doing firmware and configuration table updates.
 */
typedef enum
{
    CY_HPI_MASTER_DEV_REG_DEVICE_MODE             = 0x00,   /**< Device Mode register: Specifies FW mode, PD port count,
                                                                 and flash row size. */
    CY_HPI_MASTER_DEV_REG_BOOT_MODE_REASON        = 0x01,   /**< Boot Mode Reason register: Specifies validity of each
                                                                 firmware image. Also, reports reason for device staying
                                                                 in the Boot mode. */
    CY_HPI_MASTER_DEV_REG_SI_ID                   = 0x02,   /**< Silicon ID: MS byte. */
    CY_HPI_MASTER_DEV_REG_BL_LAST_ROW             = 0x04,   /**< Bootloader last row: LS byte. This is actually the
                                                                 last flash row before the start of the firmware. */
    CY_HPI_MASTER_DEV_REG_INTR_ADDR               = 0x06,   /**< Interrupt Status register. */
    CY_HPI_MASTER_DEV_REG_JUMP_TO_BOOT            = 0x07,   /**< Jumps to boot (or alt firmware) request register. */
    CY_HPI_MASTER_DEV_REG_RESET_ADDR              = 0x08,   /**< Resets request signature register. */
    CY_HPI_MASTER_DEV_REG_ENTER_FLASH_MODE        = 0x0A,   /**< Enters flashing mode request register. */
    CY_HPI_MASTER_DEV_REG_VALIDATE_FW_ADDR        = 0x0B,   /**< Validate firmware request register. */
    CY_HPI_MASTER_DEV_REG_FLASH_READ_WRITE        = 0x0C,   /**< Flash read/write signature register. */
    CY_HPI_MASTER_DEV_REG_ALL_VERSION_BYTE        = 0x10,   /**< Bootloader version: MSB of build number. */
    CY_HPI_MASTER_DEV_REG_FW_2_VERSION            = 0x20,   /**< FW2 version: LSB of build number. */
    CY_HPI_MASTER_DEV_REG_FW_BIN_LOC              = 0x28,   /**< FW1 binary location: LSB. */
    CY_HPI_MASTER_DEV_REG_PORT_ENABLE             = 0x2C,   /**< Port enable command/status register. */
    CY_HPI_MASTER_DEV_REG_SLEEP_CTRL              = 0x2D,   /**< Deep Sleep Control register. */
    CY_HPI_MASTER_DEV_REG_POWER_STAT              = 0x2E,   /**< Power Status register updates status message. */
    CY_HPI_MASTER_DEV_REG_SET_APP_PRIORITY        = 0x2F,   /**< Sets APP priority. */
    CY_HPI_MASTER_DEV_REG_READ_CUSTOMER_INFO      = 0x30,   /**< Reads 32 bytes of customer info. */
    CY_HPI_MASTER_DEV_REG_BATTERY_STAT            = 0x31,   /**< Register showing the current battery status. */
    CY_HPI_MASTER_DEV_REG_WD_RESET_COUNT          = 0x32,   /**< Watchdog Reset Count register. */
    CY_HPI_MASTER_DEV_REG_CREATE_ERROR            = 0x33,   /**< Command register creates lock-up error. */
    CY_HPI_MASTER_DEV_REG_RESERVED_34H            = 0x34,   /**< Reserved address: 0x0034. */
    CY_HPI_MASTER_DEV_REG_RESERVED_35H            = 0x35,   /**< Reserved address: 0x0035. */
    CY_HPI_MASTER_DEV_REG_RESERVED_36H            = 0x36,   /**< Reserved address: 0x0036. */
    CY_HPI_MASTER_DEV_REG_RESERVED_37H            = 0x37,   /**< Reserved address: 0x0037. */
    CY_HPI_MASTER_DEV_REG_UCSI_STATUS             = 0x38,   /**< UCSI Status register. */
    CY_HPI_MASTER_DEV_REG_UCSI_CONTROL            = 0x39,   /**< UCSI Control register. */
    CY_HPI_MASTER_DEV_REG_CFGTAB_VERSION          = 0x3A,   /**< Config Table Version register. */
    CY_HPI_MASTER_DEV_REG_SYS_PWR_STATE           = 0x3B,   /**< System Power State register. */
    CY_HPI_MASTER_DEV_REG_HPI_VERSION             = 0x3C,   /**< HPI Version register: LSB */
    CY_HPI_MASTER_DEV_REG_RESPONSE                = 0x7E,   /**< Response Type register. */
} cy_hpi_master_dev_reg_t;


/**
 * @typedef cy_hpi_master_port_reg_t
 * @brief List of HPI port information register addresses.
 *
 * This enumeration lists the addresses for the HPI port information registers
 * supported by CCGx devices.
 */
typedef enum
{
    CY_HPI_MASTER_PORT_REG_VDM_CTRL               = 0x00,   /**< VDM Control register. */
    CY_HPI_MASTER_PORT_REG_EFF_SRC_PDO_MASK       = 0x02,   /**< Effective Source PDO Mask register: Read-only. */
    CY_HPI_MASTER_PORT_REG_EFF_SINK_PDO_MASK      = 0x03,   /**< Effective Sink PDO Mask register: Read-only. */
    CY_HPI_MASTER_PORT_REG_PD_CTRL                = 0x06,   /**< PD Control register. */
    CY_HPI_MASTER_PORT_REG_PD_STATUS              = 0x08,   /**< PD Status register: LS byte. */
    CY_HPI_MASTER_PORT_REG_TYPE_C_STATUS          = 0x0C,   /**< Type-C Status register. */
    CY_HPI_MASTER_PORT_REG_CURRENT_PDO            = 0x10,   /**< Current PDO register. */
    CY_HPI_MASTER_PORT_REG_CURRENT_RDO            = 0x14,   /**< Current RDO register. */
    CY_HPI_MASTER_PORT_REG_EVENT_MASK             = 0x24,   /**< Event Mask register: LS byte. */
    CY_HPI_MASTER_PORT_REG_SWAP_RESPONSE          = 0x28,   /**< PD Control register. */
} cy_hpi_master_port_reg_t;

/** \} group_hpim_enums */

/**
* \addtogroup group_hpim_data_structures
* \{
*/

/** Forward declaration of structures. */
struct cy_hpi_master_context;

/**
 * @brief Structure to hold the HPI slave device information.
 */
typedef struct cy_hpi_master_slave_dev
{
    /** Slave I2C address (7 bits) */
    uint8_t slaveAddr;

    /** INTR GPIO number. */
    uint8_t intrGpioPort;

    /** INTR GPIO number. */
    uint8_t intrGpioPin;

    /** Number of supported ports. */
    uint8_t portCount;

    /** Variable to hold the status of the Interrupt register. */
    uint8_t intrReg;
    
    /** Failure count. */
    uint8_t failCount;
}cy_hpi_master_slave_dev_t;


/**
* @brief Data structure to store the current event/response information.
*/
typedef struct cy_hpi_master_event
{
    /** Pointer to the slave device data. */
    cy_hpi_master_slave_dev_t *slaveDev;
    
    /** Slave device port number. */
    uint8_t port;
    
    /** HPI response/event/failure code. */
    uint8_t eventCode;
    
    /** Event data buffer pointer. */
    uint8_t *eventData;
    
    /** Event data length. */
    uint16_t dataLen;
}cy_hpi_master_event_t;

/**
* @brief Defines the solution-specific application callback.
*/
typedef struct cy_hpi_master_app_cbk
{
    bool (*i2c_master_read)(CySCB_Type *scbBase,                    /**< I2C module base address. */
                            uint8_t slaveAddr,                      /**< I2C slave address. */
                            uint8_t *buffer,                        /**< Read data buffer pointer. */
                            uint32_t count,                         /**< Read data length (bytes). */
                            uint8_t *reg_addr,                      /**< Read data register address. */
                            uint8_t reg_size,                       /**< Read data register length (bytes). */
                            cy_stc_scb_i2c_context_t *i2cContext    /**< I2C driver context pointer. */
                            );                                      /**< Function reads data from specified register location. */
                                                
    bool (*i2c_master_write)(CySCB_Type *scbBase,                   /**< I2C module base address. */
                            uint8_t slaveAddr,                      /**< I2C slave address. */
                            uint8_t *buffer,                        /**< Read data buffer pointer. */
                            uint32_t count,                         /**< Read data length (bytes). */
                            uint8_t *reg_addr,                      /**< Read data register address. */
                            uint8_t reg_size,                       /**< Read data register length (bytes). */
                            cy_stc_scb_i2c_context_t *i2cContext    /**< I2C driver context pointer. */
                            );                                      /**< Function reads data from a specified register location. */

    bool (*event_handler)(struct cy_hpi_master_context *context,    /**< HPI master context structure pointer. */
                          cy_hpi_master_event_t *event              /**< Pointer to the event/response data. */
                          );                                        /**< Function for handling HPI events/responses received from the slave device. */
                          
    bool (*error_handler)(struct cy_hpi_master_context *context,    /**< HPI master context structure pointer. */
                          cy_hpi_master_event_t *event              /**< Pointer to the event/response data. */
                          );                                        /**< Function for handling error conditions. */                          
}cy_hpi_master_app_cbk_t;

/**
* @brief HPI master queue data structure.
*/
typedef struct cy_hpi_master_event_queue
{
    /** Start address of the buffer. */
    uint8_t *startAddress;

    /** Size of the queue buffer. */
    uint16_t bufferSize;

    /** Message start index. */
    uint16_t headIdx;

    /** Message end index. */
    uint16_t tailIdx;
}cy_hpi_master_event_queue_t;

/**
* @brief HPI master library data structure.
*/
typedef struct cy_hpi_master_context
{
    /** Variable to store the slave interrupt status bit. */
    uint8_t intrMask;

    /** Number of slave devices registered. */
    uint8_t slaveCount;
    
    /** Pointer to the application callback structure. */
    cy_hpi_master_app_cbk_t *ptrAppCbk;

    /** Pointer to the queue data structure. */
    cy_hpi_master_event_queue_t *ptrEventQueue;

    /** Supports maximum number of slave devices. */
    const uint8_t maxSlaveDevices;
    
    /** Pointer to the array of slave devices. */
    cy_hpi_master_slave_dev_t *ptrSlaves;

    /** SCB module base address pointer. */
    CySCB_Type *ptrScbBase;

    /** The instance-specific context structure. It is used by the driver for 
        internal configuration and data keeping for the I2C. */
    cy_stc_scb_i2c_context_t *ptrI2cContext;
    
    /** Response buffer size in bytes. Buffer size should be min of 64-bytes. */
    const uint16_t respBuffLen;

    /** Pointer to the PD response buffer. This buffer is used for handling the
        PD response message read/write operation. */
    uint8_t *ptrRespBuff;
    
}cy_hpi_master_context_t;

/** \} group_hpim_data_structures */

#endif  /* CY_HPI_MASTER_DEFINES_H */

/* [] END OF FILE */
