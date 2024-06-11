# Benchmarks
## Descripción
Se implementa un script de python principal para la toma de tiempos de un ejemplo contratizado con la biblioteca propuesta. Se incluyen dos códigos auxiliares relevantes:
- makefile: Archivo Make para compilar el ejemplo con las diferentes implementaciones que ofrece la biblioteca.
- script.sh: Script en bash que es llamado desde el script de python para lanzar los procesos de ejecución y tomas de tiempo cíclicamente. Admite parámetros que indiquen la optimización a utilizar y la cantidad de veces que debe realizarse la toma de tiempos.

Por último, el script de python es con el que el usuario debe interactuar, deberá pasar el número de veces que se realizará la toma de tiempos para promediar y si quiere que se muestren las gráficas o se almacenen.

```bash
usage: benchmarks.py [-h] [-silence] [-optimization [OPTIMIZATION]] [num_repetitions]

Script para realizar benchmarks de ejemplos contratizados. Especifique el ejemplo a utilizar en makefile

positional arguments:
  num_repetitions       Número de veces que se ejecutará el ejemplo.

options:
  -h, --help            show this help message and exit
  -silence              Silencia salida de gráficas y las guarda en ./data/plot.png
  -optimization [OPTIMIZATION]
                        Type of optimization.
```


## Uso
Para ejecución de toma de tiempos:

1. Reemplazar en SRC del makefile con sus archivos .cpp del ejemplo a medir.
	```bash
	nano makefile
	```
2. Asegurarse que script.sh tenga permisos de ejecucion
	```bash
	chmod +x script.sh
	```

3. Correr benchmarks.py
	```bash
	python3 benchmarks.py
	```

Por defecto se realizará una sola repetición de la ejecución del ejemplo y se mostrarán las gráficas. Pueden verse las opciones ejecutando:
```bash
python3 benchmarks.py -h
```

Podrá ver que puede tomar parámetros para la compilación siguiendo reglas de optimización.


