/*******************************************************************************
* File Name: rempedaal.h  
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

#if !defined(CY_PINS_rempedaal_H) /* Pins rempedaal_H */
#define CY_PINS_rempedaal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "rempedaal_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 rempedaal__PORT == 15 && ((rempedaal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    rempedaal_Write(uint8 value);
void    rempedaal_SetDriveMode(uint8 mode);
uint8   rempedaal_ReadDataReg(void);
uint8   rempedaal_Read(void);
void    rempedaal_SetInterruptMode(uint16 position, uint16 mode);
uint8   rempedaal_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the rempedaal_SetDriveMode() function.
     *  @{
     */
        #define rempedaal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define rempedaal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define rempedaal_DM_RES_UP          PIN_DM_RES_UP
        #define rempedaal_DM_RES_DWN         PIN_DM_RES_DWN
        #define rempedaal_DM_OD_LO           PIN_DM_OD_LO
        #define rempedaal_DM_OD_HI           PIN_DM_OD_HI
        #define rempedaal_DM_STRONG          PIN_DM_STRONG
        #define rempedaal_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define rempedaal_MASK               rempedaal__MASK
#define rempedaal_SHIFT              rempedaal__SHIFT
#define rempedaal_WIDTH              1u

/* Interrupt constants */
#if defined(rempedaal__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in rempedaal_SetInterruptMode() function.
     *  @{
     */
        #define rempedaal_INTR_NONE      (uint16)(0x0000u)
        #define rempedaal_INTR_RISING    (uint16)(0x0001u)
        #define rempedaal_INTR_FALLING   (uint16)(0x0002u)
        #define rempedaal_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define rempedaal_INTR_MASK      (0x01u) 
#endif /* (rempedaal__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define rempedaal_PS                     (* (reg8 *) rempedaal__PS)
/* Data Register */
#define rempedaal_DR                     (* (reg8 *) rempedaal__DR)
/* Port Number */
#define rempedaal_PRT_NUM                (* (reg8 *) rempedaal__PRT) 
/* Connect to Analog Globals */                                                  
#define rempedaal_AG                     (* (reg8 *) rempedaal__AG)                       
/* Analog MUX bux enable */
#define rempedaal_AMUX                   (* (reg8 *) rempedaal__AMUX) 
/* Bidirectional Enable */                                                        
#define rempedaal_BIE                    (* (reg8 *) rempedaal__BIE)
/* Bit-mask for Aliased Register Access */
#define rempedaal_BIT_MASK               (* (reg8 *) rempedaal__BIT_MASK)
/* Bypass Enable */
#define rempedaal_BYP                    (* (reg8 *) rempedaal__BYP)
/* Port wide control signals */                                                   
#define rempedaal_CTL                    (* (reg8 *) rempedaal__CTL)
/* Drive Modes */
#define rempedaal_DM0                    (* (reg8 *) rempedaal__DM0) 
#define rempedaal_DM1                    (* (reg8 *) rempedaal__DM1)
#define rempedaal_DM2                    (* (reg8 *) rempedaal__DM2) 
/* Input Buffer Disable Override */
#define rempedaal_INP_DIS                (* (reg8 *) rempedaal__INP_DIS)
/* LCD Common or Segment Drive */
#define rempedaal_LCD_COM_SEG            (* (reg8 *) rempedaal__LCD_COM_SEG)
/* Enable Segment LCD */
#define rempedaal_LCD_EN                 (* (reg8 *) rempedaal__LCD_EN)
/* Slew Rate Control */
#define rempedaal_SLW                    (* (reg8 *) rempedaal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define rempedaal_PRTDSI__CAPS_SEL       (* (reg8 *) rempedaal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define rempedaal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) rempedaal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define rempedaal_PRTDSI__OE_SEL0        (* (reg8 *) rempedaal__PRTDSI__OE_SEL0) 
#define rempedaal_PRTDSI__OE_SEL1        (* (reg8 *) rempedaal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define rempedaal_PRTDSI__OUT_SEL0       (* (reg8 *) rempedaal__PRTDSI__OUT_SEL0) 
#define rempedaal_PRTDSI__OUT_SEL1       (* (reg8 *) rempedaal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define rempedaal_PRTDSI__SYNC_OUT       (* (reg8 *) rempedaal__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(rempedaal__SIO_CFG)
    #define rempedaal_SIO_HYST_EN        (* (reg8 *) rempedaal__SIO_HYST_EN)
    #define rempedaal_SIO_REG_HIFREQ     (* (reg8 *) rempedaal__SIO_REG_HIFREQ)
    #define rempedaal_SIO_CFG            (* (reg8 *) rempedaal__SIO_CFG)
    #define rempedaal_SIO_DIFF           (* (reg8 *) rempedaal__SIO_DIFF)
#endif /* (rempedaal__SIO_CFG) */

/* Interrupt Registers */
#if defined(rempedaal__INTSTAT)
    #define rempedaal_INTSTAT            (* (reg8 *) rempedaal__INTSTAT)
    #define rempedaal_SNAP               (* (reg8 *) rempedaal__SNAP)
    
	#define rempedaal_0_INTTYPE_REG 		(* (reg8 *) rempedaal__0__INTTYPE)
#endif /* (rempedaal__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_rempedaal_H */


/* [] END OF FILE */
