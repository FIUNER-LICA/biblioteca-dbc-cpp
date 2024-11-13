<div align="center">

# Biblioteca para DbC en C++

## Garcia Justo - Insfrán Jordán F. - Diaz Zamboni Javier E.

![DOI](https://doi.org/10.5281/zenodo.14139843)

[Descripción](#descripción) • [Documentación](#documentación) • [Estructura de directorios](#estructura-de-directorios) •[Instalación](#instalación) • [Uso](#uso)

</div>

## Descripción

Este repositorio contiene una biblioteca que permite implementar Diseño por Contratos en C++, proponiendo precondiciones, postcondiciones e invariantes para la declaración de los componentes del software.

Además, se incluyen benchmarks para evaluar el rendimiento de la biblioteca bajo diferentes condiciones y escenarios.

## Documentación

Se recomienda el acceso a la documentación a través de una forma más interactiva en el [sitio web](https://fiuner-lica.github.io/biblioteca-dbc-cpp/)

## Estructura de directorios

- Benchmarks: scripts que permiten ejecutar benchmarks y la salida de los mismos.
- Casos: casos implementados utilizando la biblioteca.
- contract-lib: archivo header y cpp de la biblioteca.
- docs: carpeta correspondiente a la documentación en doxygen y los archivos utilizados para generear el [sitio web](https://fiuner-lica.github.io/biblioteca-dbc-cpp/)

## Instalación

Para utilizar la biblioteca simplemente clona este repositorio y realiza la inclusión del archivo de header *contract-lib/contract.h*.

## Uso

<!-- TODO: agregar un ejemplo -->

Para ejecutar los benchmarks se recomienda leer la documentación específica presente en su carpeta [*Benchmarks/README.md*](https://github.com/FIUNER-LICA/biblioteca-dbc-cpp/blob/main/Benchmarks/README.md)
