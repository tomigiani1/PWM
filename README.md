# PWM
1) Forkear el repositorio y abrir el proyecto en STM32CubeIDE
2) Analizar en el IOC las configuraciones del TIM3 y del RCC, sin modificarlas
3) En PA6 colocar un cable Dupont hembra macho y dejarlo al aire. En GND colocar un cable Dupont macho macho y dejarlo al aire.
3) Enchufar la placa NUCLEO-F103RB

## Test 1
4) Volver al código y configurar el primer test, verificando el #define TEST_NUMBER (línea 18 de app.c), es decir que diga #define TEST_NUMBER TEST_1
5) Compilar y debuggear.
6) Colocar la punta del osciloscopio entre PA6 y GND y analizar la forma de onda mostrada. ¿Cuál es el período de la señal? ¿Se modifica? ¿Cómo se define duty cycle? Se modifica?
7) Colocar un led entre PA6 y GND (no olvidar R de polarización) y observar la intensidad del brillo.

## Test 2
8) Volver al código y configurar el segundo test, mediante la directiva #define TEST_NUMBER TEST_2
9) Compilar y debuggear.
10) Colocar la punta del osciloscopio entre PA6 y GND y analizar la forma de onda mostrada. ¿Qué ocurre con el período de la señal? ¿Qué ocurre con el duty cycle?
11) Colocar un led entre PA6 y GND (no olvidar R de polarización) y observar la intensidad del brillo.
12) Comparar resultados

Nota: Los comentarios deberán registrarse en los archivo pwm.txt, test_1.txt y test_2.txt, en el root de la carpeta app de su repositorio. Asimismo, en esa misma ubicación se debe incorporar todo material de soporte o argumentación, tal como capturas de pantalla de computadora, capturas de pantalla de osciloscopio, fotografías, etcétera.