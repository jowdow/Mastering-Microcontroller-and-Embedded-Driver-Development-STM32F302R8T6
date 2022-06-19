#include <stdint.h>


#define RCC_BASE_ADDR 			0x40021000UL
#define RCC_CFGR_REG_OFFSET 	0x04UL  	// This is the offset for the Clock Config register

#define RCC_CFGR_REG_ADDR (RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)

#define GPIOA_BASE_ADDR 			0x48000000UL


int main(void)
{

	uint32_t *pRccCfgrReg= (uint32_t*)RCC_CFGR_REG_ADDR;

	// 1. Configure the RCC_CRGR MCO bit fields to select HSI as clock source
	*pRccCfgrReg &= ~(0x5<<24); // Clear 26 through 24 bit positions

	// Configure MCO1 prescaler
	*pRccCfgrReg |= (1<<29); // The prescaler register is different than the one discussed

	// 2. Configure PA8 to AF0 mode to behave as MCO signal
		// a) Enable the peripheral clock for GPIOA peripheral

	uint32_t *pRccAhbEnr= (uint32_t*)(RCC_BASE_ADDR + 0x14UL); // This is the address for AHB peripheral clock enable register
	*pRccAhbEnr |= (0x1<<17); // This bit shift enables the clock for Port A

		//b ) Configure the mode of GPIOA pin 8 as alternate function mode
	uint32_t *pGPIOAModeReg= (uint32_t*)(GPIOA_BASE_ADDR);
	*pGPIOAModeReg &= ~(0x2<<0); // Clear the first two bits (Best Practice)
	*pGPIOAModeReg |= (0x2<<0); // This bit shift enables Alternate function mode

		//c ) Configure the alternation function register to set the mode 0 for PA8

	uint32_t *pGPIOAAltFunHighReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x20);
	*pGPIOAAltFunHighReg &= ~( 0xf << 0);

    /* Loop forever */
	for(;;);
}
