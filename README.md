# pkg – A dpkg-Inspired Package Manager [![License: GPL-3.0+](https://img.shields.io/badge/license-GPL--3.0+-blue.svg)](LICENSE)

### **Author:** Hunter Bergman [hunterbergman125@gmail.com](mailto:hunterbergman125@gmail.com)

`pkg` is a lightweight, Python-based package manager inspired by Debian’s `dpkg`. It allows users to create, install, extract, and manage `.pkg` packages on Linux systems. Its companion tools (`pkg-get`, `pkg-repo-gen`, `deb2pkg`) enable repository management and easy conversion from Debian `.deb` packages.

---
## Warning

* Packages are **not safety-checked**. Install `.pkg` files only from sources you trust.
* If a package or its contents causes damage, the creator of the package is solely responsible.
### Please act responsibly before sharing packages.
---

## Quick Demo
```bash
git clone --depth 1 https://github.com/hbergman223/pkg.git
cd pkg

# pkg-utils contains pkg, pkg-get, pkg-repo-gen, and deb2pkg
sudo ./pkg -i pkgs/pkg-utils_1.1.1.pkg

pkg -l

# try gnu-hello (make sure it isn't installed by any other source)
sudo pkg -i pkgs/gnu-hello.pkg
hello
```

---
## Features

* Install, remove, and query packages (`.pkg` files)
* Build `.pkg` files from directory structures
* Extract `.pkg` files for inspection
* Track installed packages in a database (`/var/lib/pkg/installed`)
* Manage repositories with `pkg-get`
* Convert `.deb` packages to `.pkg` with `deb2pkg`
* Generate repository indexes with `pkg-repo-gen`

---

## Installed Packages Examples

| Package        | Version | License          | Description                                 |
| -------------- | ------- | ---------------- | ------------------------------------------- |
| bacsh          | 0.1.0   | MIT              | Minimal Bourne-style shell                  |
| bones          | 1.0     | MIT              | Ranger-like file explorer with ncurses      |
| gnu-hello      | 2.12    | GPL-3.0+ | GNU Hello program                           |
| libsyscalls    | 1.0.0   | MIT              | System call library                         |
| miniscript     | 1.3     | MIT              | MiniScript interpreter                      |
| neofetch       | 7.4.1   | MIT              | System information tool                     |
| pkg-utils      | 1.1.1   | GPL-3.0+         | Utilities: `pkg`, `pkg-get`, `pkg-repo-gen` |
| syscalls-hello | 1.0.0   | none             | Example program using libsyscalls           |

### This table is for demonstration purposes and may not reflect actual installed packages.

---

## Installation

Clone the repository and use the executable file `pkg` to install `pkgs/pkg-utils_1.1.1.pkg` (See [Quick Demo](#quick-demo) for more help).

```bash
git clone https://github.com/hbergman223/pkg.git
cd pkg
sudo ./pkg -i pkgs/pkg-utils_1.1.1.pkg
```

---

## Usage

### `pkg`

```bash
pkg -h
```

Common operations:

* Build: `pkg -b <dir> -o <package.pkg>`
* Extract: `pkg -x <package.pkg> -d <dest_dir>`
* Install: `pkg -i <package.pkg>`
* Remove: `pkg -r <package_name>`
* List installed: `pkg -l`
* Show package info: `pkg -s <package_name>`

### `pkg-get`

Repository client:

> Note: Please note there is no official public repo running as of now, so you'll have to make your own.

```bash
pkg-get update
pkg-get search <query>
pkg-get install <package_name>
pkg-get info <package_name>
pkg-get repo list
pkg-get repo add <url>
pkg-get repo remove <url>
```

### `pkg-repo-gen`

Generate repository index for `.pkg` files:

> Note: For now, this is the only way to make `pkg-get` work.

```bash
pkg-repo-gen <repo_dir> -o index.json
```

> Note: To run on your machine (WHICH IS REQUIRED FOR `pkg-get`):
```bash
cd path/to/pkgs
python -m http.server 8000 # this sets up the repo's server
pkg-get repo add http://localhost:8000 # this adds the repo to pkg-get 
```

### `deb2pkg`

Convert Debian `.deb` packages to `.pkg`:

```bash
deb2pkg <package.deb> -d pkg-dirs -b
```

---

## Package Structure

Each `.pkg` file contains:

```
metadata/
    name
    version
    author
    license
    history
    depends
data/
    <installed file hierarchy>
```

---

## Examples

```bash
# Install gnu-hello
pkg -i pkg-dirs/gnu-hello.pkg

# Run hello
hello
# Output: Hello, world!

# List installed packages
pkg -l

# Show package info
pkg -s neofetch
```

---

## Converting Debian Packages

```bash
deb2pkg downloads/cowsay_3.03+deb.deb -b
pkg -i pkgs/cowsay.pkg
```

---

## Repository Management

```bash
# Generate index for your local repository
pkg-repo-gen pkgs -o index.json

# Add repository
pkg-get repo add https://example.com/pkg-repo

# Install package from repository
pkg-get install cowsay
```
---

## Limitations
* No official repositories; you have to make your own.
* No dependency resolution (but `pkg` does tell you what you need).
* Again, no safety checks, so no package signatures or verification system.
* Designed for personal/experimental use.

---

## Contributing

1. Fork the repository
2. Make your changes in a branch
3. Test using `pkg -b`, `pkg -i`, and `pkg-get`
4. Submit a pull request

---

## License

This project is licensed under the **GPL-3.0+** license. See [LICENSE](LICENSE) for details.

