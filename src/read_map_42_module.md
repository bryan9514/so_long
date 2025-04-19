
# 🗺️ Módulo `read_map` - Proyecto So_long (42)

Este módulo se encarga de abrir un archivo `.ber`, leer el contenido línea por línea, almacenarlo en una lista enlazada, convertir esa lista a un array de strings y verificar que el mapa no esté vacío.

---

## 📁 Archivos involucrados

- `read_maps.c`  
- `so_long.h`

---

## 🔍 Funciones implementadas

### `int open_map_file(char *filename)`
- Abre el archivo recibido.
- Si falla, muestra error y termina el programa.
```c
fd = open(filename, O_RDONLY);
if (fd < 0)
    free_map_print_error(NULL, NULL, NULL, "File does not exist");
```

---

### `t_list *read_lines_into_list(int fd)`
- Usa `get_next_line()` para leer cada línea.
- Aplica `ft_strtrim(line, "
")` y libera `line`.
- Guarda las líneas limpias en una lista enlazada.
- Si falla alguna parte, libera memoria y muestra error.

---

### `char **convert_list_to_array(t_list *lines)`
- Calcula el tamaño con `ft_lstsize`.
- Reserva memoria para un array `char **map`.
- Copia los punteros `content` de la lista al array.
- Libera solo los nodos de la lista (`free_list(lines)`).

---

### `int validate_map_not_empty(char **map)`
- Retorna 0 si el mapa es nulo o la primera línea está vacía.

---

### `char **read_map(char *av)`
- Función principal que llama a las anteriores:
    1. Abre el archivo.
    2. Lee las líneas en una lista.
    3. Convierte la lista a array.
    4. Verifica que el mapa no esté vacío.

---

## ✅ Memoria verificada

Con `valgrind --leak-check=full --show-leak-kinds=all`, el módulo no presenta fugas:

```
== ALL heap blocks were freed -- no leaks are possible
== ERROR SUMMARY: 0 errors from 0 contexts
```

---

## 🧠 Buenas prácticas aplicadas

- Separación clara de responsabilidades.
- Control de errores con función centralizada (`free_map_print_error`).
- Liberación de memoria en todos los caminos posibles.
- Mensajes de error útiles para debugging.

---

## 🟡 Nota importante

Actualmente, `map[i] = tmp->content;` copia directamente los punteros del contenido de la lista.  
Esto **funciona perfectamente** si solo se libera uno de los dos (la lista o el mapa).  
Para independencia total, puede usarse `ft_strdup(tmp->content)`.

---

## 🧽 Recomendación

Usar `--track-origins=yes` con Valgrind en desarrollo para detectar valores no inicializados:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/test.ber
```
