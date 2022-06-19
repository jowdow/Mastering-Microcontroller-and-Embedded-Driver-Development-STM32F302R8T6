#include <stdint.h>

#define ADC_BASE_ADDR 0x50000000UL
#define ADC_CR1_REG_OFFSET 0x08UL

#define ADC_CR1_REG_ADDR (ADC_CR1_REG_OFFSET+ADC_BASE_ADDR)

#define RCC_BASE_ADDR 0x40021000UL
#define RCC_AHB_ENR_OFF 0x14UL   // AHB is the bus used for the ADC in the F302

#define RCC_AHB_ENR_ADDR (RCC_BASE_ADDR + RCC_AHB_ENR_OFF)

int main(void)
{
	uint32_t *pAdcCrlReg = (uint32_t*)ADC_CR1_REG_ADDR;
	uint32_t *pRccAhbEnr = (uint32_t*)RCC_AHB_ENR_ADDR;

	// 1. Enable Peripheral Clock for ADC1
	*pRccAhbEnr |= (1<<28);
	// 2. Modify the ADC cr1(ADEN) register
	*pAdcCrlReg |= (1 << 0);
    /* Loop forever */
	for(;;);
}
