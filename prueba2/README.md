# Implementación para el segundo problema - Listado de directorios json.
El programa recibe la ruta a un directorio, en la función main de `listDir.cpp` tomamos ese argumento y creamos una dirección con boost. Tambíen creamos un `property_tree` que es donde guardaremos la estructura que se convertirá en JSON. Posteriormente llamamos a la función `list_files` la cual itera sobre todos los archivos del directorio que le pasamos y le va agregando hijos a nuestro `property_tree`, los cuales contienen el nombre y el tamaño del archivo. Finalmente se llama a la función `write_json` que crea un archivo JSON en `build/` en él podremos ver todos los archivos y sus tamaños.

## Instrucciones para ejecutar
Tenemos la siguiente estructura de nuestros archivos:

```
prueba2/
├── CMakeLists.txt
├── README.md
└── src/
    └── listDir.cpp
├── build/
└── libs/
```

nos posicionamos en `prueba2/build/` y ejecutamos `cmake ../`, posteriormente ejecutamos `make` y finalmente `./findRoots <directorio>` donde `<directorio>` es la ruta absoluta al directorio donde queremos buscar los archivos.

### Nota sobre Boost
Puede que se tenga que descargar boost de nuevo y compilar los binarios en caso de que no corra. Se tendran que colocar en `prueba2/libs`. Los binarios incluidos se compilaron en macos y puede que no corran en otros sistemas operativos.
[Descarga de Boost](https://www.boost.org/users/history/version_1_81_0.html)