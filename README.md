# 🎲 MonteCarlo

<div align="center">

<h2>Simulação de Monte Carlo para Dados de Mercado</h2>

<p>
Simulação estocástica desenvolvida em <strong>C++</strong> utilizando
<strong>CMake</strong>.
</p>

<p>
  <details>
    <summary>🌐 <strong>Idioma / Language</strong></summary>
    <br>
    <a href="README.md">🇧🇷 Português</a>
    <br><br>
    <a href="README.en.md">🇺🇸 English</a>
  </details>
</p>

<p>
<img src="https://img.shields.io/badge/C%2B%2B-17%2B-blue?style=for-the-badge&logo=cplusplus">
<img src="https://img.shields.io/badge/CMake-Build-064F8C?style=for-the-badge&logo=cmake">
<img src="https://img.shields.io/badge/Monte%20Carlo-Simulation-purple?style=for-the-badge">
</p>

</div>

---

## 📌 Sobre o projeto

O **MonteCarlo** é um projeto experimental desenvolvido em C++ para estudar
simulações estocásticas aplicadas a dados financeiros.

O objetivo é gerar possíveis trajetórias de preços utilizando números
aleatórios e analisar os resultados através de dados **OHLC**.

### OHLC

|     Campo    | Significado   |
| :----------: | ------------- |
|  🟢 **Open** | Preço inicial |
|  🔵 **High** | Maior preço   |
|  🔴 **Low**  | Menor preço   |
| 🟡 **Close** | Preço final   |

---

## 🧮 Monte Carlo

O método de Monte Carlo utiliza amostragem aleatória para gerar possíveis
cenários.

```text
              ┌──────────────────┐
              │    Parâmetros    │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │  Random Number   │
              │    Generator     │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │  Monte Carlo     │
              │   Simulation     │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │  Price Scenarios │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │   OHLC Candle    │
              └──────────────────┘
```

> A simulação não representa uma previsão garantida do mercado. Ela gera
> possíveis cenários de acordo com as premissas definidas no modelo.

---

## 📊 Exemplo de saída

O programa gera dados no formato:

```text
OPEN | HIGH | LOW | CLOSE
```

Exemplo:

```text
99.950600|100.078000|99.816000|100.027000
100.130000|100.174000|99.827600|99.916400
99.908600|100.059000|99.867400|99.931900
```

Visualmente:

```text
┌──────────┬──────────┬──────────┬──────────┐
│   OPEN   │   HIGH   │    LOW   │   CLOSE  │
├──────────┼──────────┼──────────┼──────────┤
│ 99.9506  │ 100.078  │ 99.816   │ 100.027  │
└──────────┴──────────┴──────────┴──────────┘
```

---

## 🛠️ Tecnologias

| Tecnologia    | Utilização                    |
| ------------- | ----------------------------- |
| 🟦 C++        | Implementação da simulação    |
| 🔵 CMake      | Sistema de build              |
| 🎲 `<random>` | Geração de números aleatórios |
| ⚛️ `<atomic>` | Operações atômicas            |
| 🔒 `<mutex>`  | Sincronização                 |
| 📦 STL        | Estruturas e algoritmos       |
| 🌱 Git        | Controle de versão            |

---

## 📁 Estrutura do projeto

```text
MonteCarlo/
│
├── CMakeLists.txt
│
├── include/
│   └── MarketData.hpp
│
├── src/
│   └── MarketData.cpp
│
├── build/
│   └── ...
│
├── .gitignore
│
├── README.md
└── README.en.md
```

A pasta `build/` é gerada pelo CMake e deve ser ignorada pelo Git.

Exemplo de `.gitignore`:

```gitignore
/build/
```

---

# 🚀 Instalação

## 📋 Requisitos

* C++17 ou superior
* CMake
* Git
* Compilador compatível com C++

No Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

---

## 📥 Clone

```bash
git clone <URL_DO_REPOSITORIO>
cd MonteCarlo
```

---

## 🔨 Build

Crie o diretório de build:

```bash
mkdir -p build
```

Entre no diretório:

```bash
cd build
```

Configure o CMake:

```bash
cmake ..
```

Compile:

```bash
cmake --build .
```

---

## ▶️ Executando

Depois da compilação:

```bash
./MonteCarlo
```

> O nome do executável depende da configuração do `CMakeLists.txt`.

---

# ⚙️ Configuração

O valor inicial utilizado atualmente é:

```cpp
constexpr double totalAssets{100.0};
```

A distribuição aleatória pode ser configurada através de:

```cpp
std::uniform_real_distribution<double>
    distribuir(-0.100, 0.100);
```

Por exemplo, para aumentar a faixa de variação:

```cpp
std::uniform_real_distribution<double>
    distribuir(-1.0, 1.0);
```

---

# 🔬 Como funciona

A simulação atualmente gera duas variações aleatórias:

```text
d
│
├──────────────┐
│              │
▼              ▼
d1         totalAssets
│              │
└──────┬───────┘
       │
       ▼
 totalAssets + (d - d1)
       │
       ▼
   Novo preço
```

O projeto está sendo desenvolvido para evoluir de uma simples geração de
variações para uma simulação de trajetórias de preços.

---

# 🚧 Status

<div align="center">

### 🟡 Em desenvolvimento

</div>

O projeto ainda está em fase experimental.

## 🗺️ Roadmap

* [x] Gerar números aleatórios
* [x] Gerar valores de preço
* [x] Gerar dados OHLC
* [x] Configurar build com CMake
* [ ] Melhorar o modelo estatístico
* [ ] Criar trajetórias dependentes do preço anterior
* [ ] Implementar volatilidade configurável
* [ ] Executar múltiplas simulações
* [ ] Calcular média
* [ ] Calcular variância
* [ ] Calcular desvio padrão
* [ ] Calcular intervalo de confiança
* [ ] Exportar para CSV
* [ ] Criar gráficos
* [ ] Criar visualização de candles
* [ ] Adicionar testes unitários
* [ ] Melhorar paralelização

---

# 🤝 Contribuição

Contribuições são bem-vindas.

Faça um fork do projeto e crie uma branch:

```bash
git checkout -b minha-feature
```

Faça suas alterações:

```bash
git add .
git commit -m "Add minha feature"
```

Envie:

```bash
git push origin minha-feature
```

Depois abra um **Pull Request**.

---

# 📜 Licença

Este projeto ainda não possui uma licença definida.

---

<div align="center">

## 🎲 MonteCarlo

**Simulate · Analyze · Learn**

<br>

🇧🇷 Português   |   🇺🇸 English

</div>
