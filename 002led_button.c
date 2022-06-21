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
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;	// This value is different from in the course. This board needs push pull
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOB,ENABLE);

    GPIO_Init(&GpioLed);


    GpioBtn.pGPIOx=GPIOC;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

        GPIO_PeriClockControl(GPIOC,ENABLE);

        GPIO_Init(&GpioBtn);

    while(1){
    	if(!GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13)){	// Since our board is pulled high we have to use negative logic
    		delay();
    		GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_13);
    	}
    }
    return 0;
}
