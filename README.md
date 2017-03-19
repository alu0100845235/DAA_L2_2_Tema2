# **Comparativa de algoritmos de ordenación: ordenación por selección y Heapsort**
#### ETSII ULL Grado de Informatica
#### Asignatura: [Diseño y Análisis de Algoritmos (Univerdidad de La Laguna)](https://campusvirtual.ull.es/1617/course/view.php?id=1138)


### Descripción

	Realización de un proyecto que analice los algoritmos de ordenación por selección y el Heapsort, así como
	la comparación entre ambos. Se desarrollará el código fuente de dichos algoritmos, para luego crear tablas
	y gráficas de pruebas realizadas con distintos valores.

	Los documentos necesarios son:

		- Informe con una extensión máxima de ocho páginas.
		- Presentación ajustada a un máximo de 10 minutos.
		- Código fuente de los algoritmos desarrollados.


### Repositorio del proyecto:

- [github](https://github.com/alu0100845235/DAA_L2_2_Tema2.git)



### Autores (Grupo L2_2)

<table>
<tr>
<td> Airam Manuel Navas Simón </td>
<td> <a href="https://github.com/AiramNavas">GitHub</a> </td>
<td> <a href="https://airamnavas.github.io/">Página personal</a> </td>
</tr>
<tr>
<td> Jorge Sierra Acosta </td>
<td> <a href="https://github.com/Ediolot">GitHub</a> </td>
<td> <a href="https://ediolot.github.io/">Página personal</a> </td>
</tr>
<tr>
<td> Ruymán Rodríguez Martín </td>
<td> <a href="https://github.com/alu0100845235">GitHub</a> </td>
<td> <a href="https://alu0100845235.github.io/">Página personal</a></td>
</tr>
</table>

### Códigos de ejemplo

En la carpeta *src* podemos encontrar en dos headers la implementación en C++ con templates de los dos algoritmos:

 - `heapsort.h`
 - `selectionsort.h`

Además se han creado dos ejemplos que pueden ser compilados utilizando los comandos dentro de la carpeta *src*:

 - `make timeTest`: Crea el ejecutable *timeTest* que realizará una medición de los tiempos de ejecución.
 - `make example`: Crea el ejecutable *example* que muestra un ejemplo de funcionamiento de los algoritmos.

*timeTest* genera una serie de vectores aleatorios de enteros que después son ordenados por los algoritmos desde
un tamaño inicial hasta uno final predefinidos junto a un número de ejecuciones para cada n:

|Algoritmo|N inicial|N final|Incremento de N|Número de ejecuciones para cada N|Número total de ordenaciones|
|---|---|---|---|---|---|
|Selection Sort|2E+4|2E+5|2E+4|4|36|
|Heap Sort|2E+5|1E+8|2E+5|3|147|

Después, para cada conjunto de ejecuciones de un tamaño se generarán una serie de datos que serán guardados en *selectionSortTime.txt* y *heapSortTime.txt* en el siguiente orden:

 - Tamaño
 - Media
 - Mediana
 - Desviación típica

*example* simeplemente muestra por pantalla dos vectores desordenados y el resultado de aplicarles cada uno de los algoritmos.
