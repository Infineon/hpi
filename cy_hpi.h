/***************************************************************************//**
* \file cy_hpi.h
* \version 1.1.0
*
* Defines the APIs for the HPI middleware.
*
********************************************************************************
* \copyright
* (c) 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_HPI_H)
#define CY_HPI_H

#include "cy_hpi_defines.h"

/**
********************************************************************************
* \addtogroup group_hpi_slave
* \{
* The Host Processor Interface (HPI) library implements the HPI transport,
* protocol, register, and PD message handling. It allow the host processor or EC
* to monitor the status of the USB PD ports, change configuration, perform
* firmware updates, and transparently interact with other USB PD devices
* connected.
*
* HPI communicates over an I2C interface (supported clock frequencies are 1 MHz,
* 400 kHz, and 100 kHz) with an interrupt line using a GPIO.
*
* <b>Features:</b>
* * Firmware version identification
* * Firmware update capability
* * Reporting of Type-C and USB PD connection status
* * Interrupt-based event reporting when connection status changes
* * Control of USB PD power profiles

*
********************************************************************************
* \section section_hpis_general_description General description
********************************************************************************
*
* Include cy_hpi_defines.h, cy_hpi.h to
* get access to all functions and other declarations in this library. See the
* \ref section_hpis_quick_start to start using the HPI Library.
*
* See the \ref section_toolchain section for compatibility
* information.
*
* See the \ref section_changelog section for change history.
*
********************************************************************************
* \section section_hpis_quick_start Quick start guide
********************************************************************************
*
* HPI middleware is used in ModusToolbox(TM) based development 
* environment. See the \ref section_toolchain section.
*
* These steps describe the simplest method to enable the HPI interface in a 
* ModusToolbox(TM) based application.
*
* 1. Create or open an application to add HPI functions.
* 
* 2. Add the HPI middleware to your project. This quick start guide
* assumes that the environment is configured to use the MTB CAT2 Peripheral
* Driver Library (PDL) for development and the PDL is included in the project.<br>
* Add the PDStack and PDUtils middleware along with the PmgAppCommon middleware
* libraries if the Type-C and Power Delivery functionality is needed in the application.
*
* 3. Include cy_hpi.h to get access to all functions and other declarations in 
*    this library.
* \snippet snippet/hpis_sut.c snippet_configuration_hpis_include
*
* 4. Define the following data structures required by the HPI middleware:
*    * SCB I2C and interrupt GPIO configuration structure.
*    \snippet snippet/hpis_sut.c snippet_configuration_hpis_data
*    * HPI slave context parameters
*    \snippet snippet/hpis_sut.c snippet_configuration_hpis_context
*    * Register application callback functions
*    \snippet snippet/hpis_sut.c snippet_configuration_hpis_app_cbk
*   The HPI library uses these callbacks registered by the application
*   to perform the application-specific tasks such as flash read/write, interrupt
*   GPIO control, VBus control, validate firmware image, and so on.
* 
* 5. Invoke the \ref Cy_Hpi_PdEventHandler function from the solution event handler. 
*   \snippet snippet/hpis_sut.c snippet_configuration_hpis_event
*
* 6. Invoke the \ref Cy_Hpi_I2cInterruptHandler function from the SCB I2C
*    interrupt service function. 
*   \snippet snippet/hpis_sut.c snippet_configuration_hpis_interrupt
*
* 7. Initialize the HPI middleware. Configure and initialize the I2C SCB in 
*    slave mode, before calling this function.
*   \snippet snippet/hpis_sut.c snippet_configuration_hpis_init
* 
* 8. Initialize common features such as HPI version, application versions, flash
*    locations, and device mode based on the application design and current status.
*   \snippet snippet/hpis_sut.c snippet_configuration_hpis_app_info
*
* 9. Call \ref Cy_Hpi_Task from the main processing loop of the application 
*    to handle the command and data received from the HPI master device.
*   \snippet snippet/hpis_sut.c snippet_configuration_hpis_task
*
********************************************************************************
* \section section_hpis_configuration_considerations Configuration considerations
********************************************************************************
*
*
********************************************************************************
* \section section_hpis_miscellaneous Limitations and restrictions
********************************************************************************
*
*
********************************************************************************
*
* \defgroup group_hpis_macros Macros
* \brief
* This section describes the HPI macros.
*
* \defgroup group_hpis_functions Functions
* \brief
* This section describes the HPI function prototypes.
*
* \defgroup group_hpis_data_structures Data structures
* \brief
* This section describes the data structures defined by the HPI.
*
* \defgroup group_hpis_enums Enumerated types
* \brief
* This section describes the enumeration types defined by the HPI.
*
* \} */

/*******************************************************************************
*                              Type definitions
*******************************************************************************/
/**
* \addtogroup group_hpis_functions
* \{
*/

/*******************************************************************************
* Function name: Cy_Hpi_IsEcReady
****************************************************************************//**
*
* Checks for EC initialization complete event is received. This
* function is used by the application to check the EC has sent the EC
* initialization complete event notification.
*
* \param context
* HPI library context pointer.
*
* \return
* Returns true if EC init is received, false otherwise.
*
*******************************************************************************/
bool Cy_Hpi_IsEcReady(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_SetEvent
****************************************************************************//**
*
* Updates the Interrupt Status register and assert the EC_INT pin.
*
* \param context
* HPI library context pointer.
*
* \param evtCode
* Set the event code.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetEvent (cy_stc_hpi_context_t *context, uint8_t evtCode);

/*******************************************************************************
* Function name: Cy_Hpi_ClearEvent
****************************************************************************//**
*
* Clears the Interrupt Status register and deassert the EC_INT pin.
*
* \param context
* HPI library context pointer.
*
* \param evtCode
* Clears the event code.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_ClearEvent (cy_stc_hpi_context_t *context, uint8_t evtCode);

/*******************************************************************************
* Function name: Cy_Hpi_UcsiRegReset
****************************************************************************//**
*
* Clears the Status and Control register.
*
* \param context
* HPI library context pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UcsiRegReset(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_ClearStatusBit
****************************************************************************//**
*
* Clears the appropriate bit_idx to '0' in the Status register.
*
* \param context
* HPI library context pointer.
*
* \param bitIdx
* Clears the bit index.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UcsiClearStatusBit(cy_stc_hpi_context_t *context, uint8_t bitIdx);

/*******************************************************************************
* Function name: Cy_Hpi_UcsiSetStatusBit
****************************************************************************//**
*
* Sets appropriate bit index to '1' in the Status register.
*
* \param context
* HPI library context pointer.
*
* \param bitIdx
* Sets the bit index.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UcsiSetStatusBit(cy_stc_hpi_context_t *context, uint8_t bitIdx);

/*******************************************************************************
* Function name: Cy_Hpi_GetUcsiControl
****************************************************************************//**
*
* Gets the UCSI Control register value.
*
* \param context
* HPI library context pointer.
*
* \return
* UCSI control HPI register value.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetUcsiControl(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_GetStatusBit
****************************************************************************//**
*
* Gets the UCSI Status bit.
*
* \param context
* HPI library context pointer.
*
* \param bitIdx
* Status bit index.
*
* \return
* UCSI status bit value.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetStatusBit(cy_stc_hpi_context_t *context, uint8_t bitIdx);

/*******************************************************************************
* Function name: Cy_Hpi_UcsiGetStatusRegAddr
****************************************************************************//**
*
* Gets the UCSI Status register address.
*
* \param context
* HPI library context pointer.
*
* \return
* Address of the UCSI Status register.
*
*******************************************************************************/
uint8_t * Cy_Hpi_UcsiGetStatusRegAddr (cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_UcsiGetControlRegAddr
****************************************************************************//**
*
* Gets the UCSI Control register address.
*
* \param context
* HPI library context pointer.
*
* \return
* Address of the UCSI Control register.
*
*******************************************************************************/
uint8_t * Cy_Hpi_UcsiGetControlRegAddr (cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_IsVdmEcCtrlEnabled
****************************************************************************//**
*
* Checks if the EC control of VDMs is enabled.
*
* \param context
* HPI library context pointer.
*
* \param port
* USB PD port to check the configuration.
*
* \return
* true - If EC control is enabled, false otherwise.
*
*******************************************************************************/
bool Cy_Hpi_IsVdmEcCtrlEnabled(cy_stc_hpi_context_t *context, uint8_t port);

/*******************************************************************************
* Function name: Cy_Hpi_IsExtdMsgEcCtrlEnabled
****************************************************************************//**
*
* Checks whether the handling of extended messages by EC is enabled. If not,
* the CCG firmware will automatically responds with a NOT_SUPPORTED messages.
*
* \param context
* HPI library context pointer.
*
* \param port
* USB PD port to check the configuration.
*
* \return
* true - If EC control is enabled, false otherwise.
*
*******************************************************************************/
bool Cy_Hpi_IsExtdMsgEcCtrlEnabled(cy_stc_hpi_context_t *context, uint8_t port);

/*******************************************************************************
* Function name: Cy_Hpi_GetEcActiveModes
****************************************************************************//**
*
* Gets the active EC alternate modes value.
*
* \param context
* HPI library context pointer.
*
* \param port
* USB PD to check the configuration.
*
* \return
* The active EC modes setting programmed by EC.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetEcActiveModes(cy_stc_hpi_context_t *context, uint8_t port);

/*******************************************************************************
* Function name: Cy_Hpi_QueuePdMsg
****************************************************************************//**
*
* PDStack and application layers sends event and
* extended message notifications to the EC through the HPI registers.
*
* Note that only responses without associated data is sent through
* the Response register for the HPI_REG_SECTION_DEV section. If any additional
* response data is required, use the user-defined registers or the
* response register associated with CY_HPI_REG_SECTION_PORT_0 or
* CY_HPI_REG_SECTION_PORT_1.
*
* \param context
* HPI library context pointer.
*
* \param section
* Reports the event through the register section.
*
* \param status
* The event code to be stored into the Response register.
*
* \param len1
* Length of the data associated with the event.
*
* \param data1
* Pointer to buffer containing data associated with the event.
*
* \param len2
* PD message data length in bytes.
*
* \param data2
* Pointer to buffer containing PD message data.
*
* \return
* true - If the event queue has space for the event.
* false - If there is an overflow.
*
*******************************************************************************/
bool Cy_Hpi_QueuePdMsg(cy_stc_hpi_context_t *context,
                       cy_en_hpi_reg_section_t section,
                       uint8_t status,
                       uint16_t len1, uint8_t *data1,
                       uint16_t len2, uint8_t *data2);

/*******************************************************************************
* Function name: Cy_Hpi_PdEventHandler
****************************************************************************//**
*
* Receives PD events from the stack and to update the HPI registers.
*
* \param context
* HPI library context pointer.
*
* \param port
* PD port corresponding to the event.
*
* \param evt
* Event is notified.
*
* \param data
* Data associated with the event. This is an opaque pointer that needs to be
* de-referenced based on event type.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_PdEventHandler(cy_stc_hpi_context_t *context, uint8_t port,
                           uint8_t evt,
                           const void *data);

/*******************************************************************************
* Function name: Cy_Hpi_SendHwErrorEvent
****************************************************************************//**
*
* Notifies the EC for a system hardware access error.
*
* \param context
* HPI library context pointer.
*
* \param port
* PD port index.
*
* \param errType
* Detects the type of error.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SendHwErrorEvent(cy_stc_hpi_context_t *context,
                             uint8_t port,
                             uint8_t errType);

/*******************************************************************************
* Function name: Cy_Hpi_SetHpiVersion
****************************************************************************//**
*
* Sets the HPI version info.
*
* \param context
* HPI library context pointer.
*
* \param hpiVers
* HPI version information.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetHpiVersion(cy_stc_hpi_context_t *context, uint32_t hpiVers);

/*******************************************************************************
* Function name: Cy_Hpi_SetHpiVersionExt
****************************************************************************//**
*
* This function sets the HPI version extended information.
*
* \param context
* HPI Library context pointer.
*
* \param hpiVers
* HPI version information.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetHpiVersionExt(cy_stc_hpi_context_t *context, uint32_t hpiVers);

/*******************************************************************************
* Function name: Cy_Hpi_SetModeRegs
****************************************************************************//**
*
* Updates the Device and Boot modes reason in HPI registers.
* 
*
* \param context
* HPI library context pointer.
*
* \param devMode
* Sets the value into the Device mode register.
*
* \param modeReason
* Sets the value into the Boot mode reason register.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetModeRegs(cy_stc_hpi_context_t *context,
                        uint8_t devMode,
                        uint8_t modeReason);

/*******************************************************************************
* Function name: Cy_Hpi_UpdateVersions
****************************************************************************//**
*
* Updates the firmware version information in the HPI registers.
* 
*
* \param context
* HPI library context pointer.
*
* \param blVersion
* Buffer contains the Bootloader version information.
*
* \param fw1Version
* Buffer contains the firmware-1 version information.
*
* \param fw2Version
* Buffer contains the firmware-2 version information.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UpdateVersions(cy_stc_hpi_context_t *context,
                           uint8_t *blVersion,
                           uint8_t *fw1Version,
                           uint8_t *fw2Version);

/*******************************************************************************
* Function name: Cy_Hpi_UpdateRegs
****************************************************************************//**
*
* Updates the information in the HPI registers.
*
* \param context
* HPI library context pointer.
*
* \param section
* HPI register section (DEV/PORT-0/PORT-1).
*
* \param offset
* HPI Device register offset.
*
* \param data
* Buffer contains the data to be written.
*
* \param size
* Write the number of bytes of data.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UpdateRegs(cy_stc_hpi_context_t *context,
                        uint8_t section,
                        uint8_t offset,
                        uint8_t *data,
                        uint8_t size);

/*******************************************************************************
* Function name: Cy_Hpi_GetDevAddr
****************************************************************************//**
*
* API to fetch the base address of the HPI Device register space.
*
* \param context
* HPI library context pointer.
*
* \return
* Pointer of the device register base address.
*
*******************************************************************************/
void *Cy_Hpi_GetDevAddr(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_UpdateFwLocations
****************************************************************************//**
*
* Updates the firmware location HPI registers.
*
* \param context
* HPI library context pointer.
*
* \param fw1Location
* Flash row where FW1 is located.
*
* \param fw2Location
* Flash row where FW2 is located.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UpdateFwLocations(cy_stc_hpi_context_t *context,
                              uint16_t fw1Location,
                              uint16_t fw2Location);

/*******************************************************************************
* Function name: Cy_Hpi_RegEnqueueEvent
****************************************************************************//**
*
* PDStack and application layers send event
* notifications to the EC through the HPI registers.
*
* Note that only responses without associated data can be sent through
* the Response register for the HPI_REG_SECTION_DEV section. If any additional
* response data is required, use the user-defined registers or the
* response register associated with CY_HPI_REG_SECTION_PORT_0 or
* CY_HPI_REG_SECTION_PORT_1.
*
* \param context
* HPI library context pointer.
*
* \param section
* Reports the event through the register section.
*
* \param status
* Stores the event code into the response register.
*
* \param length
* Length of the data associated with the event.
*
* \param data
* Pointer to buffer containing data associated with the event.
*
* \return
* true - If the event queue has space for the event.
* false - If there is an overflow.
*
*******************************************************************************/
bool Cy_Hpi_RegEnqueueEvent(cy_stc_hpi_context_t *context,
                            cy_en_hpi_reg_section_t section,
                            uint8_t status,
                            uint16_t length,
                            uint8_t *data);

/*******************************************************************************
* Function name: Cy_Hpi_GetConsFetStatus
****************************************************************************//**
*
* Retrieves the current value of consumer FET Status register.
*
* \param context
* HPI library context pointer.
*
* \param port
* Port for which consumer FET status is to be retrieved.
*
* \return
* Current value of the consumer FET Status register.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetConsFetStatus(cy_stc_hpi_context_t *context, uint8_t port);

/*******************************************************************************
* Function name: Cy_Hpi_UpdateConsFetStatus
****************************************************************************//**
*
* Updates the consumer FET status associated with a port.
*
* \param context
* HPI library context pointer.
*
* \param port
* Port on which FET status has to be updated.
*
* \param status
* Stores the new value in the register.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UpdateConsFetStatus(cy_stc_hpi_context_t *context,
                                uint8_t port,
                                uint8_t status);

/*******************************************************************************
* Function name: Cy_Hpi_GetPortEnable
****************************************************************************//**
*
* Gets the Port Enable register value.
*
* \param context
* HPI library context pointer.
*
* \return
* The Port Enable HPI register value.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetPortEnable(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_GetSysPwrState
****************************************************************************//**
*
* Gets the content of the HPI System power State register.
*
* \param context
* HPI library context pointer.
*
* \return
* The 8-bit unsigned content of the HPI syspwr_state register.
*
*******************************************************************************/
uint8_t Cy_Hpi_GetSysPwrState(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_BbGetVersion
****************************************************************************//**
*
* Gets the Billboard firmware version.
*
* \param context
* HPI library context pointer.
*
* \return
* Pointer to firmware version buffer.
*
*******************************************************************************/
uint8_t *Cy_Hpi_BbGetVersion(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_BbRegUpdate
****************************************************************************//**
*
* Updates the content of the Billboard Control register.
*
* \param context
* HPI library context pointer.
*
* \param bbRegAddr
* Billboard related register address.
*
* \param data
* Register write data pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_BbRegUpdate(cy_stc_hpi_context_t *context,
                        uint8_t bbRegAddr,
                        void *data);

/*******************************************************************************
* Function name: Cy_Hpi_BbGetReg
****************************************************************************//**
*
* Gets the current content of the Billboard Control register.
*
* \param context
* HPI library context pointer.
*
* \param bbRegAddr
* Billboard related register address.
*
* \return
* Data of selected Billboard related register.
*
*******************************************************************************/
uint32_t Cy_Hpi_BbGetReg(cy_stc_hpi_context_t *context, uint8_t bbRegAddr);

/*******************************************************************************
* Function name: Cy_Hpi_SetUserdefWriteHandler
****************************************************************************//**
*
* Enables handling of EC writes to the user-defined HPI
* register region in the application code.
*
* \param context
* HPI library context pointer.
*
* \param wrHandler
* Pointer to function that handles the received HPI writes.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetUserdefWriteHandler(cy_stc_hpi_context_t *context,
                                   cy_hpi_write_cbk_t wrHandler);

/*******************************************************************************
* Function name: Cy_Hpi_InitUserdefRegs
****************************************************************************//**
*
* Initializes the contents of the user-defined 
* registers that are part of the HPI register space.
*
* \param context
* HPI library context pointer.
*
* \param regAddr
* Updates the base address of registers and stores it in the user-defined
* address region.
*
* \param size
* Number of registers to be updated. The upper limit should not exceed the user-
* defined address region.
*
* \param data
* Buffer contains the data to be copied into HPI registers.
*
* \return
* Returns true if the operation is successful, otherwise
* false if the input parameters are not valid.
*
*******************************************************************************/
bool Cy_Hpi_InitUserdefRegs(cy_stc_hpi_context_t *context,
                                                uint16_t regAddr,
                                                uint8_t size,
                                                uint8_t *data);

/*******************************************************************************
* Function name: Cy_Hpi_Task
****************************************************************************//**
*
* Handles the commands from the EC through the HPI registers. HPI
* writes from the EC are handled in interrupt context and any associated work
* is queued to be handled by this function. The Cy_Hpi_Task is expected to be
* called periodically from the main task loop of the firmware application.
*
* \param context
* HPI library context pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_Task(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_SetEcInterrupt
****************************************************************************//**
*
* Configures HPI to use the EC_INT pin for interrupt mode.
*
* \param context
* HPI library context pointer.
*
* \param enable
* Checks to enable or disable interrupt mode.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetEcInterrupt(cy_stc_hpi_context_t *context, bool enable);

/*******************************************************************************
* Function name: Cy_Hpi_SendFwReadyEvent
****************************************************************************//**
*
* Sends a firmware-ready notification through HPI to the EC. This event is sent to the
* EC to indicate that the device is out of reset and has a loaded firmware.
*
* \param context
* HPI library context pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SendFwReadyEvent(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_SetPortEventMask
****************************************************************************//**
*
* Updates the event mask value for the specified PD port.
*
* \param context
* HPI library context pointer.
*
* \param port
* PD port index.
*
* \param mask
* Event mask value to be set.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetPortEventMask(cy_stc_hpi_context_t *context,
                            uint8_t port,
                            uint32_t mask);

/*******************************************************************************
* Function name: Cy_Hpi_SetPortBcStatus
****************************************************************************//**
*
* Updates the BC 1.2 connection status to the HPI interface.
*
* \param context
* HPI Library Context pointer.
*
* \param port
* PD port index.
*
* \param bcStatus
* BC 1.2 status.
*
* \return
* None.
*
*******************************************************************************/
ATTRIBUTES_HPISS_HPI void Cy_Hpi_SetPortBcStatus(cy_stc_hpi_context_t *context, 
                                             uint8_t port, uint8_t bcStatus);

/*******************************************************************************
* Function name: Cy_Hpi_SetFlashParams
****************************************************************************//**
*
* Sets the CCG device flash parameters. These values are used for the device
* status reporting and firmware update implementation.
*
* \param context
* HPI library context pointer.
*
* \param flashSize
* Total device flash size in bytes.
*
* \param rowSize
* Size of each flash row in bytes.
*
* \param rowCnt
* Number of flash rows on the device.
*
* \param blLastRow
* Last flash row assigned to Bootloader.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetFlashParams(cy_stc_hpi_context_t *context,
                            uint32_t flashSize,
                            uint16_t rowSize,
                            uint16_t rowCnt,
                            uint16_t blLastRow);

/*******************************************************************************
* Function name: Cy_Hpi_IsAccessed
****************************************************************************//**
*
* Checks for any recent HPI accesses since start up.
*
* \param context
* HPI library context pointer.
*
* \return
* Returns true if any HPI read/write access has occurred. Otherwise,
* false if HPI is not accessed.
*
*******************************************************************************/
bool Cy_Hpi_IsAccessed (cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_UpdatePdoChange
****************************************************************************//**
*
* Enables/disables PDO update through HPI.
*
* \param context
* HPI library context pointer.
*
* \param disable
* Checks if the PDO update is disabled.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_UpdatePdoChange(cy_stc_hpi_context_t *context, bool disable);

/*******************************************************************************
* Function name: Cy_Hpi_Init
****************************************************************************//**
*
* Initializes the HPI library variables and registers to their
* default values, registers the context reference pointers, and enables the I2C
* interface.
*
* \param context
* HPI library context pointer.
*
* \param ptrHwConfig
* HPI hardware configuration pointer.
*
* \param ptrAppCbk
* HPI application-specific callback structure pointer.
*
* \param pdPort0Ctx
* Pointer to the PDStack port0 context structure.
*
* \param pdPort1Ctx
* Pointer to the PDStack port1 context structure.
*
* \param numPorts
* Number of PD ports supported by DUT.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_Init(cy_stc_hpi_context_t *context,
                 cy_stc_hpi_hw_config_t *ptrHwConfig,
                 cy_stc_hpi_app_cbk_t *ptrAppCbk,
                 void *pdPort0Ctx,
                 void *pdPort1Ctx,
                 uint8_t numPorts);

/*******************************************************************************
* Function name: Cy_Hpi_Deinit
****************************************************************************//**
*
* Deinitializes the HPI interface. This is used
* in applications where the HPI master (Billboard controller) in the system can
* be powered off under control of the CCG device.
*
* \param context
* HPI library context pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_Deinit(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_SleepAllowed
****************************************************************************//**
*
* Checks if the CCG device enters Deep Sleep mode.
*
* \param context
* HPI library context pointer.
*
* \return
* true - If switches to Deep Sleep.
* false- If the operation failed.
*
*******************************************************************************/
bool Cy_Hpi_SleepAllowed(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_Sleep
****************************************************************************//**
*
* Checks whether the I2C interface is idle so that the CCG device
* can enter into Deep Sleep mode. It also enables an I2C address match as a wake up
* trigger from Deep Sleep mode. Call the Cy_Hpi_SleepAllowed before 
* calling this function.
*
* \param context
* HPI library context pointer.
*
* \return
* true - If the HPI interface is ready for Sleep.
* false - If operation failed.
*
*******************************************************************************/
bool Cy_Hpi_Sleep(cy_stc_hpi_context_t *context);

/*******************************************************************************
* Function name: Cy_Hpi_UcsiInitContext
****************************************************************************//**
*
* Registers the UCSI context pointer to the HPI context.
*
* \param ptrHpiContext
* HPI library context pointer.
*
* \param ptrUcsiContext
* A void pointer of UCSI context pointer.
*
* \return
* true - If the arguments are valid.
* false - If the arguments are not valid.
*
*******************************************************************************/
bool Cy_Hpi_UcsiInitContext (cy_stc_hpi_context_t *ptrHpiContext, void *ptrUcsiContext);

/*******************************************************************************
* Function name: Cy_Hpi_I2cInterruptHandler
****************************************************************************//**
*
* Handles I2C hardware interrupts. It must be called by the 
* interrupt handler.
*
* \param ptrHpiContext
* HPI library context pointer.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_I2cInterruptHandler(cy_stc_hpi_context_t *ptrHpiContext);

/*******************************************************************************
* Function name: Cy_Hpi_SetResetCount
****************************************************************************//**
*
* Writes the WDT reset count value to a device-specific register.
*
* \param context
* HPI library context pointer.

* \param count
* WDT reset count value.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SetResetCount(cy_stc_hpi_context_t *context, uint32_t count);

/*******************************************************************************
* Function name: Cy_Hpi_SendPfEvent
****************************************************************************//**
*
* Notifies EC about platform-specific events, if mask is enabled.
*
* \param ptrHpiContext
* HPI library context pointer.
*
* \param port
* PD port index.
*
* \param evtType
* Event type.
*
* \return
* None.
*
*******************************************************************************/
void Cy_Hpi_SendPfEvent(cy_stc_hpi_context_t *ptrHpiContext, uint8_t port, uint8_t evtType);

/*******************************************************************************
* Function name: Cy_Hpi_EnqueuePdPktMsgEvent
****************************************************************************//**
*
* Enqueues HPI events or PD msgs from PDStack.
*
* \param context
* HPI library context pointer.
*
* \param port
* PD port index.
*
* \param ptrPdPkt
* Pointer to the PD Pkt.
*
* \param eventType
* Event type.
*
* \param maskBit
* Mask bit controls the reporting of HPI events.
*
* \return
* None.
*
*******************************************************************************/
void  Cy_Hpi_EnqueuePdPktMsgEvent(cy_stc_hpi_context_t *context, uint8_t port,
        cy_stc_pd_packet_extd_t *ptrPdPkt, cy_en_hpi_response_t eventType, uint32_t maskBit);

/*******************************************************************************
* Function name: Cy_Hpi_InitSromParams
****************************************************************************//**
*
* Initializes the HPI parameters required for HPI lib variant support.
*
* \param pdEn
* true - If PD is enabled otherwise false.
*
* \param pdCmdEn
* true - If PD commands are enabled otherwise false.
*
* \param ucsiEn
* true - If UCSI is enabled otherwise false.
*
* \param dualAppEn
* true - If dual-app mode is enabled, otherwise false.
*
* \param ptrHpiDevMask
* HPI device register map to identify if the access is enabled or disabled for register/cmd.
*
* \param ptrHpiPortMask
* HPI Port register map to identify if the access is enabled or disabled for register/cmd.
* 
* \return
* None.
*
* \note This function is applicable for ROM-based code examples.
*
*******************************************************************************/
void Cy_Hpi_InitSromParams(bool pdEn, bool pdCmdEn, bool ucsiEn, bool dualAppEn,
                           const uint32_t *ptrHpiDevMask, const uint32_t *ptrHpiPortMask);

/*******************************************************************************
* Function name: Cy_Hpi_GetDevRegRespMskPtr
****************************************************************************//**
*
* This function returns the address of the HPI Device register response mask array
* which defines whether the register/cmd access is enabled or disabled.
*
* \return
* Address of the HPI Device register response mask array.
*
* \note This function is applicable only for ROM-based code examples.
*
*******************************************************************************/
const uint32_t *Cy_Hpi_GetDevRegRespMskPtr(void);

/*******************************************************************************
* Function name: Cy_Hpi_GetPortRegRespMskPtr
****************************************************************************//**
*
* This function returns the address of the HPI Port register response mask array
* which defines whether the register/cmd access is enabled or disabled.
*
* \return
* Address of the HPI Port register response mask array.
*
* \note This function is applicable only for ROM-based code examples.
*
*******************************************************************************/
const uint32_t *Cy_Hpi_GetPortRegRespMskPtr(void);

/** \} group_hpis_functions */
#endif /* CY_HPI_H */

/* [] END OF FILE */
