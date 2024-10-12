# FdF
Este es un proyecto para empezar en la programación gráfica.
## Descripción
Leyendo las coordenadas de un archivo .fdf que tiene el siguiente formato:

```
  $>cat 42.fdf
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
  0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
  0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
  0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
  0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
  0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
  0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  $>
```

Cada número representa un punto en el espacio:
- La posición horizontal corresponde con su eje de abscisas.
- La posición vertical corresponde con su eje de ordenadas.
- El valor corresponde con su altitud.

<br>

Con este formato el programa utiliza los puntos facilitados para construir una figura en "3D".
La imagen se encuentra en proyección isométrica. Se pueden hacer desde figuras muy sencillas hasta campos suficientemente complejos.

<img width="505" alt="Screen Shot 2021-12-24 at 2 06 22 PM" src="https://user-images.githubusercontent.com/72702214/147354952-68637cc3-4419-4661-b112-c9551e623a28.png">
<img width="885" alt="Screen Shot 2021-12-24 at 2 06 55 PM" src="https://user-images.githubusercontent.com/72702214/147354960-4dccb491-fbd5-4add-beb1-a6dc0a846cd0.png">

<img width="967" alt="Screen Shot 2021-12-24 at 2 09 35 PM" src="https://user-images.githubusercontent.com/72702214/147355034-8b285a4b-7c64-43b3-828b-e0f95ffa5798.png">


## Uso

`make`

`./fdf "archivo .fdf"`
