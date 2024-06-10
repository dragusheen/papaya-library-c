# Papaya Library 🍉📚

Welcome to Papaya Library, a lightweight C library designed for managing and manipulating structured data in your projects. Below is a detailed guide to help you understand the features and usage of Papaya Library.

<br>
<br>

## 🌟 Summary

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)
  - [Structures](#structures)
  - [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)
- [Authors](#authors)

<br>
<br>

## 🌈 Features

- Add, remove, and save data entries to a papaya object.
- Create, load, and destroy papaya objects.
- Simple and efficient data management with key-value pairs.

<br>
<br>

## 🚀 Installation

To integrate Papaya Library into your project, follow the steps below:

1. Clone the repository:
```bash
git clone https://github.com/yourusername/papaya-library.git
```

```bash
cd papaya-library
```

<br>

2. Include the header file in your project:
```c
#include "papaya.h"
```

<br>
<br>

## 💻 Usage

### Example

```c
#include "papaya.h"
#include <stdio.h>

int main() {
    // Create a papaya object with keys
    char *keys[] = {"id", "name", "value", NULL};
    papaya_t *papaya = papaya_create("path/to", "example", keys);

    // Add data
    char *data[] = {"1", "Apple", "100", NULL};
    papaya_add(papaya, data);

    // Remove data
    papaya_remove(papaya, "id", "1");

    // Save papaya to file
    papaya_save(papaya);

    // Destroy papaya object
    papaya_destroy(papaya);

    return 0;
}
```

<br>
<br>

## 📖 Documentation

### Structures

#### Papaya Structure

- **Description:** Represents a papaya object containing data and keys.
- **Attributes:**
  - `path`: The path to the papaya file.
  - `name`: The name of the papaya.
  - `keys`: Doubly linked list of keys.
  - `datas`: Doubly linked list of data entries.

#### Mini Map Structure

- **Description:** Represents a key-value pair used in data entries.
- **Attributes:**
  - `key`: The key of the data entry.
  - `value`: The value associated with the key.

<br>

### Functions

#### `papaya_add(papaya_t *papaya, char **data)`

- **Description:** Add data to a papaya object.
- **Parameters:**
  - `papaya`: Pointer to the papaya object.
  - `data`: Array of strings representing the data to add.
- **Example:**
  ```c
  char *data[] = {"1", "Apple", "100", NULL};
  papaya_add(papaya, data);
  ```

#### `papaya_create(char *path, char *name, char **keys)`

- **Description:** Create a new papaya object.
- **Parameters:**
  - `path`: The path to the papaya file.
  - `name`: The name of the papaya.
  - `keys`: Array of strings representing the keys.
- **Returns:** Pointer to the created papaya object.
- **Example:**
  ```c
  char *keys[] = {"id", "name", "value", NULL};
  papaya_t *papaya = papaya_create("path/to", "example", keys);
  ```

#### `papaya_destroy(papaya_t *papaya)`

- **Description:** Destroy a papaya object and free memory.
- **Parameters:**
  - `papaya`: Pointer to the papaya object to destroy.
- **Example:**
  ```c
  papaya_destroy(papaya);
  ```

#### `papaya_load(char *path, char *name)`

- **Description:** Load an existing papaya object from file.
- **Parameters:**
  - `path`: The path to the papaya file.
  - `name`: The name of the papaya.
- **Returns:** Pointer to the loaded papaya object.
- **Example:**
  ```c
  papaya_t *papaya = papaya_load("path/to", "example");
  ```

#### `papaya_remove(papaya_t *papaya, char *key, char *value)`

- **Description:** Remove data from a papaya object.
- **Parameters:**
  - `papaya`: Pointer to the papaya object.
  - `key`: The key of the data entry to remove.
  - `value`: The value of the data entry to remove.
- **Example:**
  ```c
  papaya_remove(papaya, "id", "1");
  ```

#### `papaya_save(papaya_t *papaya)`

- **Description:** Save a papaya object to file.
- **Parameters:**
  - `papaya`: Pointer to the papaya object to save.
- **Example:**
  ```c
  papaya_save(papaya);
  ```

<br>

## 🎉 Contributing

Contributions to Papaya Library are welcome! Please feel free to submit pull requests for enhancements or bug fixes.

<br>
<br>

## 📄 License

This library is free to use, modify, and distribute. The only requirement is to give credit to the original author in any commercial or public use.

The author is not responsible for any issues or problems that may arise from using this library. As a small developer, errors may occur. If you find any errors or problems, please inform me so I can address them.

<br>
<br>

## 🌟 Authors

- [dragusheen](https://github.com/dragusheen) - Initial work
