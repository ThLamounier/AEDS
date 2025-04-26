 🔥 Simulador de Incêndio em Floresta (C++)

Este projeto simula a propagação de incêndio em uma floresta representada por uma matriz, além do deslocamento de um animal que tenta sobreviver ao fogo.

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

🐾 Lógica do Animal

    O animal começa na posição (0, 0) por padrão.

    Tenta se mover aleatoriamente para uma posição segura (0, 1, ou 4).

    Se não encontrar saída, é considerado morto.

    Se cair na água (4), isso é registrado no log e a célula se torna 0.

🔥 Lógica de Propagação do Fogo

    O fogo se propaga para árvores adjacentes (cima, baixo, esquerda, direita).

    Uma árvore queima (2) por 1 rodada e depois vira cinzas (3).

    Fogo não se propaga para áreas vazias, água, queimadas ou o animal.

✅ Dependências

    Compilador g++

    C++17 ou superior

🧹 Limpar a compilação

make clean

✍️ Autor

Projeto criado para fins acadêmicos. Adaptado por [Seu Nome Aqui].


---

