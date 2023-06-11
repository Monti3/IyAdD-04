#include <stdio.h>
#include "pico/stdlib.h"
#include "ultrasonico.h"

/*
 * @brief Programa principal
 */
int main(void) {
    // Inicializacion del USB
    stdio_init_all();
    // Elegir un GPIO para trigger, echo y buzzer
    #define trig 14
    #define echo 15 
    #define buzz 0
    #define led 25
    // Inicializacion del ultrasonico
    ultrasonico_init(trig, echo);
    // Inicializo buzzer
    gpio_init(0);
    gpio_set_dir(buzz,true);
    // inicializo led
    gpio_init(led);
    gpio_set_dir(led,true);
    

    while(1) {

        // Hago una lectura de distancia
        float d = ultrasonico_get_distance_cm(trig, echo);
        // Muestro por consola
        printf("La distancia es %.2f", d);

        // Verifico distancia
        if (13 < d){
            gpio_put(led,1);
            gpio_put(buzz, 1);
        }
        else {
            gpio_put(led,0);
            gpio_put(buzz, 0);
        }
        // Espero
        sleep_ms(10);
    }
}