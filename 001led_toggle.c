#include <stdint.h>
#include "stm32f302xx.h"

void delay(void){
	for(uint32_t i = 0;i<500000;i++){

	}
}
int main(void)
{
    GPIO_Handle_t GpioLed, GpioBtn;

    GpioLed.pGPIOx=GPIOB;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOB,ENABLE);

    GPIO_Init(&GpioLed);

    while(1){
		delay();
		GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_13);
    }
    return 0;
}
