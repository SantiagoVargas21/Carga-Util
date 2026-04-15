# Carga Util

Este es el apartado de la Carga Util del cohete de Stellaris

# ESP-WROOM-32 (Módulo SoC Dual-Core)
Es la Unidad de Procesamiento Principal (MPU), encargada de ejecutar el firmware del vuelo, gestionar los algoritmos de navegación, el control de la misión, y la lectura/registro de datos obtenidos de telemetría. Tiene una frecuencia de reloj ajustable de entre 80 y 240 Mhz. Una memoria estática (SRAM) de 520Kb, y una memoria flash de 4MB. Necesita una alimentación de 3.3V, y tiene opción de comunicación I2C, SPI y UART con otros dispositivos. Con estas prestaciones es mas que suficiente para las exigencias de la misión, y por su bajo costo y reconocido rendimiento, es una opción segura.

# Ra-02 Sx1278 (Transceptor de RF 433 MHz)
Módulo de Telemetría de Largo Alcance (LRT). Establece el enlace de datos (downlink) con la estación terrestre, esencial para el seguimiento durante el vuelo y la localización post-terrizaje. Opera en la banda ISM de 433 Khz mediante la modulación LoRa, un método que permite una comunicación de largo alcance y de muy bajo consumo. Eso lo convierte en una opción fiable para las exigencias presentes, puesto que solo sería inconveniente si quisiéramos incluir un componente que mande gran cantidad de datos, como una cámara de vídeo. Al no ser el caso, procedemos con este método.

# Neo-7M GY-NEO7MV2 (Receptor GNSS)
Sistema Global de Navegación por Satélite (GNSS). Proporciona la Solución de Posición, Navegación y Tiempo (PNT) precisa (latitud, longitud, altitud geodésica y sincronización horaria). Es un receptor GNSS de alta sensibilidad.

# Módulo Lector de Tarjetas Micro SD (DFL)
Unidad de Almacenamiento de Datos de Vuelo (DFL). Permite el registro secuencial y persistente (data logging) de todos los parámetros de vuelo para el análisis post-misión. Tiene una interfaz de comunicación SPI/SDIO.

# 3x Sensor de Presión BMP280 (Triple Barómetro)
Triple Redundancia Barométrica. Del fabricante Bosch Sensortec, mide la presión estática absoluta y la temperatura, crítico para el cálculo de la altitud barométrica y la detección del apogeo. Tiene un rango de 300 a 1100 hPa, que equivale a una altura de 9000m a -500m respecto al nivel del mar, con precisión de ±0.12 hPa, es decir ±1m. 

# Giroscopio-Acelerómetro MPU-6050 (IMU 6-DOF):
Es una Unidad de Medición Inercial (IMU) de 6 Grados de Libertad, del fabricante InvenSense. Proporciona datos de aceleración y velocidad angular, esenciales para la estimación de la Actitud (orientación) del vehículo. Es un dispositivo de 6 ejes, 3 de acelerómetro, y 3 de giroscopio. Tiene rangos programables de hasta ±2000°/seg para el giroscopio, y de hasta ±16 Gs para el acelerómetro. 

# Transistores MOSFET
Estos componentes son fundamentales, pues actuarán como Interruptores de Potencia de Estado Sólido. Permiten a la MPU activar o desactivar las cargas de alta corriente, como los iniciadores pirotécnicos del sistema de recuperación. Necesita lograr la conmutación de la línea de 28VDC (Bus de Alta Tensión).

# Modulo cargador Tp4056 para Batería de Litio 18650 (Celdas Li-ion)
Fuente de Potencia Primaria. Suministro energético de alta densidad para la operación autónoma de la aviónica. Se usará un módulo de carga y descarga, el TP4056 hecho para el Litio 18650. Tendrán una tensión nominal de 3.7V por bateria. Se pondrán dos en serie, dando una tension nominal de 7,4V.

# Step-Down LM2596
Estabilizador del Bus de Baja Tensión. Genera un bus de alimentación estable de 3.3VDC, requerido por la MPU y los sensores digitales. En nuestro caso va a cumplir la función de Regulador Reductor/Buck.

# Step-Up MT3608
Generador del Bus de Alta Tensión. Eleva el voltaje de la batería hasta 28VDC, destinado a la ignición pirotécnica o actuadores.

