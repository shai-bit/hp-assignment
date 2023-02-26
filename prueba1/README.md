# Implementación para el primer problema - Buscador de raíces. 

El programa recibe tres argumentos, __a__, __b__, __c__ y __d__ que corresponden a los coeficientes y la constante de un polinomio cúbico.
La función main llama a la función __cardano__ con  __a__, __b__, __c__ y __d__. Lo primero que ésta hace es calcular los valores __p__ y __q__ como se describe en la fórmula de Cardano, que después se utilizan para calcular el discriminante __delta__, que nos dirá el comportamiento de las raíces.

- Si __delta__ es positivo, el polinomio tiene una raíz y dos raíces conjugadas.
- Si __delta__ es cero el polinomio tiene una raíz con multiplicidad de 3.
- Si __delta__ es negativo entonces el polinomio tiene tres raíces reales.

La función checa en cuál de estos tres casos caemos y calcula las raíces de acuerdo a como se especifica en la fórmula de Cardano.

## Instrucciones para ejecutar
Tenemos la siguiente estructura de nuestros archivos:

```
prueba1/
├── CMakeLists.txt
├── README.md
└── src/
    └── findRoots.cpp
└── build/
```

nos posicionamos en `prueba1/build/` y ejecutamos `cmake ../`, posteriormente ejecutamos `make` y finalmente `./findRoots <a> <b> <c> <d>` donde a, b, c y d son los coeficientes del polinomio que queremos calcular sus raíces.