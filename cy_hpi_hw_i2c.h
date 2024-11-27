/******************************************************************************
* File Name: cy_hpi_hw_i2c.h
* \version 1.1.0
*
* HPI I2C slave driver header file.
*
********************************************************************************
* \copyright
* (c) 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_HPI_HW_I2C_H)
#define CY_HPI_HW_I2C_H

#include <stdint.h>
#include <cy_pdl.h>
#include "cy_hpi_defines.h"

#ifndef I2C_CALL_MAP
#define I2C_CALL_MAP
#endif /* I2C_CALL_MAP */

#define CY_HPI_HW_I2C_FIFO_SIZE                       (8U)    
/**< Size of FIFO in the SCB block for I2C transfers. */

#define CY_HPI_HW_I2C_RX_FIFO_SIZE                    (CY_HPI_HW_I2C_FIFO_SIZE)
/**< Size of FIFO provided by the SCB block for I2C read (incoming data) transfers. */

#define CY_HPI_HW_I2C_TX_FIFO_SIZE                    (CY_HPI_HW_I2C_FIFO_SIZE)
/**< Size of FIFO provided by the SCB block for I2C write (outgoing data) transfers. */

#define CY_HPI_HW_I2C_SLAVE_ADDR_MASK_DEFAULT         (0xFEU)
/**< I2C slave address mask to be applied on received preamble. */

#define CY_HPI_HW_I2C_SLAVE_TIMER_BASE                CY_PDUTILS_I2C_SLAVE_SCB0_TIMER
/**< Base ID of timers reserved for I2C transfer timeout implementation. */

#define CY_HPI_HW_I2C_SLAVE_TIMER_PERIOD              (500U)
/**< Timeout period for I2C transfers in milliseconds. The I2C block will be reset
     if any transaction is not complete within the time period. */

#ifndef I2C_SLAVE_SINGLE_ADDR
#define I2C_SLAVE_SINGLE_ADDR                         0U
#endif /* I2C_SLAVE_SINGLE_ADDR */
/**
* group_hpi_i2c_state
* \{ List of possible states in I2C slave mode state machine. 
*/
#define CY_HPI_HW_I2C_STATE_DISABLED        0  /**< I2C interface is disabled. */
#define CY_HPI_HW_I2C_STATE_INIT            1  /**< Interface initialized and waiting to be enabled. */
#define CY_HPI_HW_I2C_STATE_IDLE            2  /**< Interface ready and waiting for preamble from the master. */
#define CY_HPI_HW_I2C_STATE_PREAMBLE        3  /**< Preamble phase is in progress. */
#define CY_HPI_HW_I2C_STATE_READ            4  /**< I2C read operation is in progress. */
#define CY_HPI_HW_I2C_STATE_WRITE           5  /**< I2C write operation is in progress. */
#define CY_HPI_HW_I2C_STATE_CLK_STRETCH     6  /**< Drive is stretching I2C clock to delay operation. */
#define CY_HPI_HW_I2C_STATE_ERROR           7  /**< Error state: transaction error detected. */
#define CY_HPI_HW_I2C_NUM_STATES            8  /**< Last state ID: not used. */
/** \} group_hpi_i2c_state */

/**
 * @brief Configure one of the I2C blocks as required.
 *
 * API is used to enable and configure one of the I2C blocks for driver operation.
 * Only I2C slave operation is currently supported by the driver.
 * The I2C driver is agnostic of the actual data transfer protocol. It reads all
 * data written by the master into a receive buffer provided by the protocol 
 * layer. A callback function notifies the protocol layer when the write
 * is complete. The receive buffer should be large enough to hold the 
 * maximum amount of data that the master may provide in a write operation. If 
 * the write contains more data than the buffer can hold, the I2C driver will NAK
 * the transaction.
 *
 * Read requests from the I2C master are automatically delayed by clock stretching. A
 * callback function notifies the protocol layer that the master is waiting
 * for data. The i2c_scb_write function can be used by the protocol layer to write data
 * into the transmit FIFO in response to the read request.
 *
 * All the I2C driver events are generated from interrupt context and are expected 
 * to be handled with care. The protocol layer should defer any long operations 
 * to a non-interrupt context.
 *
 * @param context The pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 * @param base Pointer to the I2C instance being configured. 
 * @param slave_addr Device address used in case of slave operation.
 * @param slave_mask Mask to be applied on for slave address matching.
 * @param cb_fun_ptr Callback function to be called for event notification.
 * @param cbk_context Context pointer of the caller module.
 * @param scratch_buffer Receive buffer used to hold written by master.
 * @param scratch_buffer_size Size of the receive buffer in bytes.
 * @param timer_context Pointer to timer_context.
 *
 * @return None
 */
void cy_hpi_hw_i2c_init(cy_stc_hpi_i2c_context_t *context, 
                        CySCB_Type* base,
                        uint8_t slave_addr, 
                        uint8_t slave_mask, 
                        cy_hpi_i2c_cb_fun_t cb_fun_ptr, 
                        void *cbk_context,
                        uint8_t *scratch_buffer, 
                        uint16_t scratch_buffer_size,
                        void *timer_context);
        
/**
 * @brief Deinitialize a previously initialized SCB block.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 *
 * @return None.
 */
void cy_hpi_hw_i2c_deinit(cy_stc_hpi_i2c_context_t *context);

/**
 * @brief Write data into the transmit FIFO associated with the I2C block.
 *
 * This function is used by the protocol layer to write data into the I2C transmit
 * FIFO in response to a master read operation.
 *
 * @param context The pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 * @param source_ptr Pointer to buffer containing the data to be written.
 * @param size Size of the data buffer. Maximum amount of data that may be written.
 * @param count Return parameter through which the actual write size is returned.
 *
 * @return None.
 */
void cy_hpi_hw_i2c_write(cy_stc_hpi_i2c_context_t *context, uint8_t *source_ptr, 
                                        uint8_t  size, uint8_t *count);
                                        
/**
 * @brief Reset the I2C block specified.
 *
 * Function resets the I2C block in response to an error or explicit request
 * from protocol layer.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 *
 * @return None.
 */
void cy_hpi_hw_i2c_reset(cy_stc_hpi_i2c_context_t *context);

/**
 * @brief Enable/disable the I2C slave acknowledgement.
 *
 * Function enables/disables the slave address ACK from the I2C block. The protocol
 * layer disables the address ACK to hold off data transfers when it is not ready to
 * respond to the master.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 * @param enable Whether to enable or disable the auto slave address acknowledgement.
 *
 * @return None.
 */
void cy_hpi_hw_i2c_ack_ctrl(cy_stc_hpi_i2c_context_t *context, bool enable);

/**
 * @brief Check if the I2C block is idle.
 *
 * This function checks whether the specified I2C block is idle. This check
 * should be performed before the device enters into Deep Sleep mode. Deep Sleep entry
 * should be avoided if this function returns false.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 *
 * @return true - If the I2C block is idle, false otherwise.
 */
bool cy_hpi_hw_i2c_is_idle(cy_stc_hpi_i2c_context_t *context);

/**
 * @brief Enable Deep Sleep wakeup due to address match on the specified SCB block.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 *
 * @return None
 */
void cy_hpi_hw_i2c_enable_wakeup(cy_stc_hpi_i2c_context_t *context);


/**
 * @brief Enable Deep Sleep wakeup due to address match on the specified SCB block.
 *
 * @param context Pointer to the context structure \ref cy_stc_hpi_i2c_context_t 
 *                allocated by the user. The structure is used during the I2C 
 *                operation for internal configuration and data retention.
 *
 * @return None
 */
void cy_hpi_hw_i2c_intr_handler(cy_stc_hpi_i2c_context_t *context);

#endif /* CY_HPI_HW_I2C_H */

/* [] END OF FILE */

