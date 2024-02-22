/*******************************************************************************
* File Name: cy_hpi_master.h
* \version 1.0
*
* Defines APIs for HPI master middleware.
*
********************************************************************************
* \copyright
* (c) 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_HPI_MASTER_H
#define CY_HPI_MASTER_H

#include <stdint.h>
#include "cy_hpi_master_defines.h"

/**
********************************************************************************
* \addtogroup group_hpi_master
* \{
*
* The Host Processor Interface (HPI) master library implements a set of APIs 
* through which the application communicates over the HPI interface to monitor 
* or control the operating condition of other HPI slave devices. The middleware 
* implements an asynchronous interrupt-based event queue handling.
*
* HPI master communicates over an I2C interface (supported clock frequencies are
* 1 MHz, 400 kHz and 100 kHz), with an interrupt line using a GPIO.
*
* <b>Features:</b>
* 1. Firmware version identification.
* 2. Firmware update capability.
* 3. Enquiry of Type-C and USB PD connection status.
* 4. Control of USB PD power profiles.
*
********************************************************************************
* \section section_hpim_general_description General description
********************************************************************************
*
* Includes cy_hpi_master_defines.h and cy_hpi_master.h to
* access all the functions and other declarations in this library. See the
* \ref section_hpim_quick_start to use the HPI library.
*
* See the \ref section_hpim_toolchain section for compatibility
* information.
*
* See the \ref section_hpim_changelog section for change history.
*
********************************************************************************
* \section section_hpim_quick_start Quick Start Guide
********************************************************************************
*
* HPI master middleware is used in ModusToolbox(TM) based development 
* environment. See the \ref section_hpim_toolchain section.
*
* These steps describe the simplest method to enable the HPI master 
* middleware in an application.
*
* 1. Create or open an application to add HPI master functions.
* 
* 2. Add the HPI master middleware to your project. This quick start guide
* assumes that the environment is configured to use the MTB CAT2 peripheral
* driver library (PDL) for development and the PDL is included in the project.
*
* 3. Include cy_hpi_master.h and cy_hpi_master_defines.h to get access to all 
* functions and other declarations in this library.
* \snippet snippet/main.c snippet_configuration_include
*
* 4. Define the following data structures required by the HPI master middleware:
*    * HPI master required buffers and data structures
*    \snippet snippet/main.c snippet_configuration_hpim_data
*    * HPI master context parameters
*    \snippet snippet/main.c snippet_configuration_hpim_context
*    * Register application callback functions
*    \snippet snippet/main.c snippet_configuration_hpim_app_cbk
*   The HPI master library uses these callbacks registered by the application
*   to perform the application specific tasks such as read/write on the I2C bus, handle
*   slave events, handle error conditions and so on.
* 
* 5. Initialize the HPI master middleware. Configure and initialize the 
*    I2C SCB, before calling this function.
*   \snippet snippet/main.c snippet_configuration_hpim_init
*
* 6. Register a slave device. The interrupt GPIO is already configured.
*    
*   \snippet snippet/main.c snippet_configuration_hpim_slave_init
* 
* 7. Invoke the \ref Cy_HPI_Master_InterruptHandler function from the GPIO interrupt
*    service routine for each slave device.
*   \snippet snippet/main.c snippet_configuration_hpim_interrupt
*
* 8. Call \ref Cy_HPI_Master_Task from the main processing loop of the application 
*    to handle the slave device events.
*   \snippet snippet/main.c snippet_configuration_hpim_task
*
********************************************************************************
* \section section_hpim_configuration_considerations Configuration considerations
********************************************************************************
*
*
********************************************************************************
* \section section_hpim_miscellaneous Limitations and restrictions
********************************************************************************
*
*
********************************************************************************
* \section section_hpim_toolchain Supported software and tools
********************************************************************************
*
* This version of the HPI middleware was validated for the compatibility
* with the following software and tools:
*
* <table class="doxtable">
*   <tr>
*     <th>Software and tools</th>
*     <th>Version</th>
*   </tr>
*   <tr>
*     <td>ModusToolbox(TM) software environment</td>
*     <td>3.1</td>
*   </tr>
*   <tr>
*     <td>mtb-pdl-cat2</td>
*     <td>2.8.0</td>
*   </tr>
*   <tr>
*     <td>GCC compiler</td>
*     <td>10.3.1</td>
*   </tr>
*   <tr>
*     <td>IAR compiler</td>
*     <td>8.42.2</td>
*   </tr>
*   <tr>
*     <td>Arm(R) compiler 6</td>
*     <td>6.13</td>
*   </tr>
* </table>
*
********************************************************************************
* \section section_hpim_changelog Changelog
********************************************************************************
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
********************************************************************************
* \section section_hpim_more_information More information
********************************************************************************
*
* For more information, see the following documents:
*
* * <a href=" https://www.infineon.com/modustoolbox">
*      <b>ModusToolbox(TM) software, quick start guide, documentation,
*         and videos</b>
*   </a>
*
* * <a href="https://infineon.github.io/hpi/api_reference_manual/html/index.html">
*   <b>HPI API reference</b></a>
*
* \note
* The links to the other software component documentation (middleware and PDL)
* point to GitHub for the latest available version of the software.
* To get documentation of the specified version, download from GitHub, and unzip
* the component archive. The documentation is available in
* the <i>docs</i> folder.
*
********************************************************************************
*
* \defgroup group_hpim_macros Macros
* \brief
* Describes the HPI master macros.
*
* \defgroup group_hpim_functions Functions
* \brief
* Describes the HPI master function prototypes.
*
* \defgroup group_hpim_data_structures Data Structures
* \brief
* Describes the data structures defined by the HPI master.
*
* \defgroup group_hpim_enums Enumerated Types
* \brief
* Describes the enumeration types defined by the HPI master.
*
* \} */

/*******************************************************************************
*                              Type definitions
*******************************************************************************/
/**
* \addtogroup group_hpim_functions
* \{
*/

/*******************************************************************************
    * Function Name: Cy_HPI_Master_Init
****************************************************************************//**
*
* Initializes the HPI master context members, application callbacks
* pointer, and initialize the slave devices. Call this function before calling any APIs from this library.
* 
* Initializes the following structure members in the \ref cy_hpi_master_context_t
* before calling this function:
* - ptrEventQueue
* - maxSlaveDevices
* - ptrSlaves
* - ptrScbBase
* - ptrI2cContext
* - respBuffLen
* - ptrRespBuff
*
* \param context
* HPI master library context pointer.
*
* \param appCbk
* Requires application callbacks from the HPI master library.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operations are successful.
* CY_HPI_MASTER_FAILURE - if the operations are not successful.
* CY_HPI_MASTER_INVALID_ARGS - if the input parameter validation failed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_Init(cy_hpi_master_context_t *context,
                                          cy_hpi_master_app_cbk_t *appCbk);


/*******************************************************************************
* Function Name: Cy_HPI_Master_DeInit
****************************************************************************//**
*
* De-initializes all the global variables and data structure values.
*
* \param context
* HPI Master library context pointer.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operations are successful.
* CY_HPI_MASTER_INVALID_ARGS - if the input parameter validation failed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_DeInit(cy_hpi_master_context_t *context);

/*******************************************************************************
* Function Name: Cy_HPI_Master_SlaveDeviceInit
****************************************************************************//**
*
* Configures the HPI slave device information to allow the HPI master to communicate.
* Call this function for each slave device on the same I2C bus.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* HPI slave device I2C address (7 bits).
*
* \param intrGpioPort
* HPI interrupt GPIO port number.
*
* \param intrGpioPin
* HPI interrupt GPIO pin number.
*
* \param portCount
* Number of PD ports supported by the slave device.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operations are successful.
* CY_HPI_MASTER_FAILURE - if the slave registration failed.
* CY_HPI_MASTER_INVALID_ARGS - if the input parameter validation failed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_SlaveDeviceInit(cy_hpi_master_context_t *context,
                                                  uint8_t slaveAddr,
                                                  uint8_t intrGpioPort,
                                                  uint8_t intrGpioPin,
                                                  uint8_t portCount);

/*******************************************************************************
* Function Name: Cy_HPI_Master_InterruptHandler
****************************************************************************//**
*
* Sets the interrupt mask bit and the interrupt is handled by the 
* \ref Cy_HPI_Master_Task function. To get the HPI interrupt pin status, call from the GPIO interrupt routine or periodically from the main loop.
*
* \param context
* HPI master library context pointer.
*
* \param gpioPort
* HPI interrupt GPIO port number.
*
* \param gpioPin
* HPI interrupt GPIO pin number.
*
* \return
* None
*
*******************************************************************************/
void Cy_HPI_Master_InterruptHandler(cy_hpi_master_context_t *context,
                                    uint8_t gpioPort, 
                                    uint8_t gpioPin);

/*******************************************************************************
* Function Name: Cy_HPI_Master_Task
****************************************************************************//**
*
* Handle the events from the slave devices. This function handles the HPI port events
* from the slave in the interrupt context, and the associated data
* in queue and is called periodically from the main loop of the application firmware.
*
*
* \param context
* HPI master library context pointer.
*
* \return 
* None.
*
*******************************************************************************/
void Cy_HPI_Master_Task(cy_hpi_master_context_t *context);

/*******************************************************************************
* Function Name: Cy_HPI_Master_GetSlaveIndexByAddr
****************************************************************************//**
*
* Function return the index of slave devices for the given slave address.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* I2C address of the slave device.
*
* \return
* Slave device registered index if found.
* \ref CY_HPI_MASTER_UNKNOWN_SLAVE_IDX if not found.
*
*******************************************************************************/
uint8_t Cy_HPI_Master_GetSlaveIndexByAddr(cy_hpi_master_context_t *context,
                                          uint8_t slaveAddr);
    
/******************************************************************************* 
* Function Name: Cy_HPI_Master_RegisterRead
****************************************************************************//**
*
* Performs the register read operation using a 16-bit register address.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param regAddress
* HPI register address (16 bits).
*
* \param readBuff
* Reads the data buffer pointer.
*
* \param readLen
* Read the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/    
cy_hpi_master_status_t Cy_HPI_Master_RegisterRead (cy_hpi_master_context_t *context,
                                                  uint8_t slaveAddr,
                                                  uint16_t regAddress,
                                                  uint8_t *readBuff,
                                                  uint16_t readLen);
     
/*******************************************************************************
* Function Name: Cy_HPI_Master_RegisterWrite
****************************************************************************//**
*
* Performs the register write operation using a 16-bit register address.
*
* \param context
* Pointer of the HPI master context structure.
*
* \param slaveAddr
* I2C address (7 bits) of the slave device.
*
* \param regAddress
* HPI register address (16 bits).
*
* \param writeBuff
* Writes the data buffer pointer.
*
* \param writeLen
* Write the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/     
cy_hpi_master_status_t Cy_HPI_Master_RegisterWrite(cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 uint16_t regAddress,
                                                 void *writeBuff,
                                                 uint16_t writeLen);
                                                 
/******************************************************************************* 
* Function Name: Cy_HPI_Master_DevRegRead
****************************************************************************//**
*
* Read data from device-specific registers.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param deviceReg
* HPI device-specific register address.
*
* \param readBuff
* Reads the data buffer pointer.
*
* \param readLen
* Read the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_DevRegRead (cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 uint8_t deviceReg,
                                                 uint8_t *readBuff,
                                                 uint16_t readLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_DevRegWrite
****************************************************************************//**
*
* Write data to the device-specific registers.
*
* \param context
* Pointer of the HPI master context structure.
*
* \param slaveAddr
* I2C address (7 bits) of the slave device.
*
* \param deviceReg
* HPI device-specific register address.
*
* \param writeBuff
* Writes the data buffer pointer.
*
* \param writeLen
*  Write the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_DevRegWrite(cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 uint8_t deviceReg,
                                                 void *writeBuff,
                                                 uint16_t writeLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_FlashMemoryRead
****************************************************************************//**
*
* Reads data from the HPI flash memory region.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param readBuff
* Read the data buffer pointer.
*
* \param readLen
* Read the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_FlashMemoryRead (cy_hpi_master_context_t *context,
                                                     uint8_t slaveAddr,
                                                     uint8_t *readBuff,
                                                     uint16_t readLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_FlashMemoryWrite
****************************************************************************//**
*
* Writes data to the HPI flash memory region.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param writeBuff
* Write the data buffer pointer.
*
* \param writeLen
* Writes the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_FlashMemoryWrite(cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 void *writeBuff,
                                                 uint16_t writeLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_PortRegRead
****************************************************************************//**
*
* Port register reads the API will be used to read all port-specific registers.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param port
* Reads the slave port number associated with the register.
*
* \param portReg
* Port register address.
*
* \param readBuff
* Reads the data buffer pointer.
*
* \param readLen
* Read the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_PortRegRead(cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 uint8_t port,
                                                 uint8_t portReg,
                                                 void *readBuff,
                                                 uint16_t readLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_PortRegWrite
****************************************************************************//**
*
* Port Register write API to all the port-specific registers.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param port
* Writes the Slave port number associated with the register.
*
* \param portReg
* Port register address.
*
* \param writeBuff
* Writes the data buffer pointer.
*
* \param writeLen
* Write the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_PortRegWrite(cy_hpi_master_context_t *context,
                                                    uint8_t slaveAddr,
                                                    uint8_t port,
                                                    uint8_t portReg,
                                                    void *writeBuff,
                                                    uint16_t writeLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_PdResponseRegRead
***************************************************************************//**
*
* PD Response register read API is used for response register read operations.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param port
* Slave device port number.
*
* \param offset
* Offset from the response register base address.
*
* \param readData
* Reads the data buffer pointer.
*
* \param readLen
* Read the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_PdResponseRegRead(cy_hpi_master_context_t *context,
                                                 uint8_t slaveAddr,
                                                 uint8_t port,
                                                 uint16_t offset,
                                                 void *readData,
                                                 uint16_t readLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_PdResponseRegWrite
****************************************************************************//**
*
* PD Response register write API is used for response register write operations.
*
* \param context
* HPI master library context pointer.
*
* \param slaveAddr
* Slave device I2C address (7 bits).
*
* \param port
* Slave device port number.
*
* \param offset
* Offset from the response register base address.
*
* \param writeBuff
* Writes the data buffer pointer.
*
* \param writeLen
* Write the number of bytes.
*
* \return
* CY_HPI_MASTER_SUCCESS - if the operation is successful.
* CY_HPI_MASTER_I2C_FAILURE - if the operation failed.
* CY_HPI_MASTER_INVALID_ARGS - invalid arguments passed.
*
*******************************************************************************/
cy_hpi_master_status_t Cy_HPI_Master_PdResponseRegWrite(cy_hpi_master_context_t *context,
                                                    uint8_t slaveAddr,
                                                    uint8_t port,
                                                    uint16_t offset,
                                                    void *writeBuff,
                                                    uint16_t writeLen);

/*******************************************************************************
* Function Name: Cy_HPI_Master_SleepAllowed
****************************************************************************//**
*
* Checks if the device enters to Deep Sleep.
*
* \param context
* HPI Master library context pointer.
*
* \return
* true - if switches to Deep Sleep .
* false - if the operation failed.
*
*******************************************************************************/
bool Cy_HPI_Master_SleepAllowed(cy_hpi_master_context_t *context);

/** \} group_hpim_functions */

#endif  /* CY_HPI_MASTER_H */

/* [END OF FILE] */
