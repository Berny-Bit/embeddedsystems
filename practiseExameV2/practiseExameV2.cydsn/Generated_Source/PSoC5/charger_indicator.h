/*******************************************************************************
* File Name: charger_indicator.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_charger_indicator_H) /* Pins charger_indicator_H */
#define CY_PINS_charger_indicator_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "charger_indicator_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 charger_indicator__PORT == 15 && ((charger_indicator__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    charger_indicator_Write(uint8 value);
void    charger_indicator_SetDriveMode(uint8 mode);
uint8   charger_indicator_ReadDataReg(void);
uint8   charger_indicator_Read(void);
void    charger_indicator_SetInterruptMode(uint16 position, uint16 mode);
uint8   charger_indicator_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the charger_indicator_SetDriveMode() function.
     *  @{
     */
        #define charger_indicator_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define charger_indicator_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define charger_indicator_DM_RES_UP          PIN_DM_RES_UP
        #define charger_indicator_DM_RES_DWN         PIN_DM_RES_DWN
        #define charger_indicator_DM_OD_LO           PIN_DM_OD_LO
        #define charger_indicator_DM_OD_HI           PIN_DM_OD_HI
        #define charger_indicator_DM_STRONG          PIN_DM_STRONG
        #define charger_indicator_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define charger_indicator_MASK               charger_indicator__MASK
#define charger_indicator_SHIFT              charger_indicator__SHIFT
#define charger_indicator_WIDTH              1u

/* Interrupt constants */
#if defined(charger_indicator__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in charger_indicator_SetInterruptMode() function.
     *  @{
     */
        #define charger_indicator_INTR_NONE      (uint16)(0x0000u)
        #define charger_indicator_INTR_RISING    (uint16)(0x0001u)
        #define charger_indicator_INTR_FALLING   (uint16)(0x0002u)
        #define charger_indicator_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define charger_indicator_INTR_MASK      (0x01u) 
#endif /* (charger_indicator__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define charger_indicator_PS                     (* (reg8 *) charger_indicator__PS)
/* Data Register */
#define charger_indicator_DR                     (* (reg8 *) charger_indicator__DR)
/* Port Number */
#define charger_indicator_PRT_NUM                (* (reg8 *) charger_indicator__PRT) 
/* Connect to Analog Globals */                                                  
#define charger_indicator_AG                     (* (reg8 *) charger_indicator__AG)                       
/* Analog MUX bux enable */
#define charger_indicator_AMUX                   (* (reg8 *) charger_indicator__AMUX) 
/* Bidirectional Enable */                                                        
#define charger_indicator_BIE                    (* (reg8 *) charger_indicator__BIE)
/* Bit-mask for Aliased Register Access */
#define charger_indicator_BIT_MASK               (* (reg8 *) charger_indicator__BIT_MASK)
/* Bypass Enable */
#define charger_indicator_BYP                    (* (reg8 *) charger_indicator__BYP)
/* Port wide control signals */                                                   
#define charger_indicator_CTL                    (* (reg8 *) charger_indicator__CTL)
/* Drive Modes */
#define charger_indicator_DM0                    (* (reg8 *) charger_indicator__DM0) 
#define charger_indicator_DM1                    (* (reg8 *) charger_indicator__DM1)
#define charger_indicator_DM2                    (* (reg8 *) charger_indicator__DM2) 
/* Input Buffer Disable Override */
#define charger_indicator_INP_DIS                (* (reg8 *) charger_indicator__INP_DIS)
/* LCD Common or Segment Drive */
#define charger_indicator_LCD_COM_SEG            (* (reg8 *) charger_indicator__LCD_COM_SEG)
/* Enable Segment LCD */
#define charger_indicator_LCD_EN                 (* (reg8 *) charger_indicator__LCD_EN)
/* Slew Rate Control */
#define charger_indicator_SLW                    (* (reg8 *) charger_indicator__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define charger_indicator_PRTDSI__CAPS_SEL       (* (reg8 *) charger_indicator__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define charger_indicator_PRTDSI__DBL_SYNC_IN    (* (reg8 *) charger_indicator__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define charger_indicator_PRTDSI__OE_SEL0        (* (reg8 *) charger_indicator__PRTDSI__OE_SEL0) 
#define charger_indicator_PRTDSI__OE_SEL1        (* (reg8 *) charger_indicator__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define charger_indicator_PRTDSI__OUT_SEL0       (* (reg8 *) charger_indicator__PRTDSI__OUT_SEL0) 
#define charger_indicator_PRTDSI__OUT_SEL1       (* (reg8 *) charger_indicator__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define charger_indicator_PRTDSI__SYNC_OUT       (* (reg8 *) charger_indicator__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(charger_indicator__SIO_CFG)
    #define charger_indicator_SIO_HYST_EN        (* (reg8 *) charger_indicator__SIO_HYST_EN)
    #define charger_indicator_SIO_REG_HIFREQ     (* (reg8 *) charger_indicator__SIO_REG_HIFREQ)
    #define charger_indicator_SIO_CFG            (* (reg8 *) charger_indicator__SIO_CFG)
    #define charger_indicator_SIO_DIFF           (* (reg8 *) charger_indicator__SIO_DIFF)
#endif /* (charger_indicator__SIO_CFG) */

/* Interrupt Registers */
#if defined(charger_indicator__INTSTAT)
    #define charger_indicator_INTSTAT            (* (reg8 *) charger_indicator__INTSTAT)
    #define charger_indicator_SNAP               (* (reg8 *) charger_indicator__SNAP)
    
	#define charger_indicator_0_INTTYPE_REG 		(* (reg8 *) charger_indicator__0__INTTYPE)
#endif /* (charger_indicator__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_charger_indicator_H */


/* [] END OF FILE */
