 Simulador de Propagação de Incêndio em Floresta

Trabalho acadêmico desenvolvido em C++ para simular a propagação de incêndios em uma floresta e o deslocamento de um animal que tenta sobreviver.

Objetivo do Projeto

    Simular a propagação de um incêndio em uma floresta representada por uma matriz.

    Simular o movimento de um animal tentando escapar do fogo.

    Registrar todos os passos e transformações no ambiente a cada iteração.
---

## 🧱 Estrutura do Projeto

fire_simulation_final/ 
├── src/
│ ├── config.hpp # Constantes globais
│ ├── forest.hpp/cpp # Lógica da floresta e propagação do fogo 
│ ├── animal.hpp/cpp # Comportamento do animal 
│ ├── main.cpp # Função principal 
├── input.dat # Arquivo de entrada da matriz 
├── output.dat # Arquivo de saída com o log da simulação 
├── Makefile # Comandos de compilação 
├── README.md # Documentação


---

## 🧾 Representação da Matriz

| Valor | Significado         |
|-------|----------------------|
| `0`   | Área vazia           |
| `1`   | Árvore saudável      |
| `2`   | Árvore em chamas     |
| `3`   | Árvore queimada      |
| `4`   | Água                 |
| `9`   | Animal               |

---
Descrição das Classes

1. config.hpp

Contém definições de constantes usadas em toda a simulação:

const int VAZIO = 0;
const int ARVORE = 1;
const int FOGO = 2;
const int QUEIMADA = 3;
const int AGUA = 4;
const int ANIMAL = 9;

2. Forest

Responsável por:

    Armazenar a matriz (grid).

    Carregar a matriz inicial do arquivo input.dat.

    Salvar o estado da matriz no output.dat.

    Propagar o fogo de acordo com as regras.

Principais métodos: 

std::vector:usado para representar a matriz grid:

    Declaração:

    std::vector<std::vector<int>> grid;

ifstream para carregar a matriz:

declaração:

std::ifstream file(filename);

ofstream para salvar o estado da matriz:

Declaração:

std::ofstream out("output.dat");

Responsável pela propagação do fogo no método propagate_fire().

Declaração:

Regras da Propagação:

    O fogo (2) se propaga para árvores (1) vizinhas (cima, baixo, esquerda, direita).

    Após propagar, o local em chamas vira árvore queimada (3).


3. Animal

Responsável por:

    Representar o animal na floresta.

    Definir sua posição (x, y).

    Mover o animal de forma aleatória a cada iteração.

    Controlar se o animal está vivo ou morto.

Principais métodos:

std::random_device + std::mt19937

 usados para garantir movimentação aleatória:

std::random_device rd;
std::mt19937 rng(rd());

std::shuffle

 misturando direções de movimento:

std::shuffle(dirs.begin(), dirs.end(), rng);

Movimenta o animal de forma randômica e segura em cada iteração.

ofstream também usado para logar no output.dat eventos do animal:

out << "Animal na posição: (" << x << "," << y << ")\n";

Detalhes:

    Se o animal entrar em água (4), é registrado no log.

    Se ficar cercado sem movimentos possíveis ou cair em fogo, morre.


4. main.cpp

Responsável por:

    Inicializar o programa.

    Controlar o fluxo da simulação:

        Carregar a floresta.

        Posicionar o animal.

        Rodar as iterações de movimento + propagação de fogo.

        Salvar a cada passo o estado atual no output.dat.

 5. Makefile

    Define a compilação moderna usando C++17:

    CXXFLAGS = -Wall -Wextra -std=c++17

    Automatiza:

        Compilação de todos .cpp.

        Linkagem em um executável chamado simulador.

        Comando make clean para apagar os .o e o binário simulador.



Regras da Simulação

    O fogo propaga para árvores adjacentes a cada iteração.

    Uma árvore em chamas se torna cinza após uma rodada.

    O animal tenta sobreviver se movendo aleatoriamente para áreas seguras.

    Se encurralado ou atingido pelo fogo, o animal morre.

    Se encontrar água, o animal sobrevive temporariamente (mas a célula de água vira área vazia).




## ⚙️ Como compilar

Abra o terminal na pasta raiz do projeto e execute:

```bash
make

▶️ Como executar

Após compilar:

./simulador

📥 Arquivo de entrada: input.dat

A primeira linha contém as dimensões da matriz (linhas e colunas). As linhas seguintes contêm os valores da matriz.

Exemplo:

5 5
1 1 1 1 4
1 2 1 1 1
1 1 1 1 4
0 0 1 1 1
1 4 1 0 4

📤 Arquivo de saída: output.dat

Gera um log completo da simulação:

    Iteração atual

    Posição do animal

    Ações do animal: movimento, morte, entrada na água

    Estado completo da matriz após cada passo

    Exemplo de saída:

Iteração 0:
Animal na posição: (0,0)
Animal moveu para (1,0)
Estado da floresta:
[matriz após a propagação]

Iteração 1:
Animal na posição: (1,0)
Animal cercado. Animal morreu!
[matriz após a propagação]


🐾 Lógica do Animal

    O animal começa na posição (0, 0) por padrão.

    Tenta se mover aleatoriamente para uma posição segura (0, 1, ou 4).

    Se não encontrar saída, é considerado morto.

    Se cair na água (4), isso é registrado no log e a célula se torna 0.


🔥 Lógica de Propagação do Fogo

    O fogo se propaga para árvores adjacentes (cima, baixo, esquerda, direita).

    Uma árvore queima (2) por 1 rodada e depois vira cinzas (3).

    Fogo não se propaga para áreas vazias, água, queimadas ou o animal.

✅ Dependências, onde aparece(:) e explicação(|)

C++17:No compilador via Makefile|-std=c++17 força a compilação moderna, permitindo usar std::vector, std::random_device, std::shuffle, etc.

Makefile:Arquivo Makefile|Automatiza a compilação (make para build e make clean para apagar binários).

std::vector:forest.hpp e forest.cpp|Matriz dinâmica é implementada usando std::vector<std::vector<int>>. Representa a floresta.

std::random_device + std::mt19937:animal.cpp|Controla a movimentação aleatória do animal usando geração de números aleatórios seguros.

std::shuffle:animal.cpp|Mistura as direções (cima, baixo, esquerda, direita) antes de escolher uma movimentação aleatória.

ifstream / ofstream:forest.cpp, main.cpp, animal.cpp|Manipulação de arquivos: leitura do input.dat e escrita detalhada no output.dat.


🧹 Limpar a compilação

make clean

Pontos fortes deste projeto

    Movimentação aleatória real do animal a cada execução.

    Propagação realista do incêndio para vizinhos adjacentes.

    Logs detalhados de cada iteração.

    Código modularizado e de fácil manutenção.

    Makefile profissional para automação de build e limpeza.

📎 Conclusão

O projeto atende aos requisitos propostos, sendo modular, eficiente e extensível. O uso de C++ permite explorar conceitos de orientação a objetos e estruturas avançadas de forma clara e didática


AUTOR

Projeto desenvolvido por: Thallys Eduardo Dias Lamounier
Disciplina: Algoritmos e Estruturas de Dados
Ano: 2025

Desenvolvido como parte do trabalho prático de Engenharia de Computação - CEFET-MG.

---

