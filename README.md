# Projeto de Criptografia em C
## Sobre

Este projeto foi projetado em C, como uma atividade acadêmica de criação de um sistema de criptografia.

O programa recebe uma palavra de até 15 caracteres, um valor de SHIFT, e parâmetros de uma Progressão Geométrica (PG). A palavra passa por duas etapas de criptografia e, no final, o programa gera um arquivo `.txt` com o registro da execução.

## Objetivo

O objetivo do projeto é aplicar conceitos básicos de programação em C, como:

- Variáveis e tipos de dados;
- Estruturas de repetição;
- Estruturas condicionais;
- Funções;
- Vetores de `char`;
- Manipulação de strings;
- Operações matemáticas;
- Manipulação de arquivos `.txt`.

## Funcionamento

O programa utiliza um alfabeto completo com 62 caracteres, contendo maiúscula, minúsculas e númerico.: "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

A posição de cada caractere dentro desse conjunto é utilizada durante as etapas de criptografia.

### SHIFT

Na primeira parte, utilizamos o método de César, aplicando um valor fixo de SHIFT sobre cada caractere. Então o programa localiza o caractere dentro do alfabeto, obtém sua posição, soma o valor do SHIFT, utiliza o operador `% 62` para manter a posição dentro do alfabeto, substitui o caractere original pelo novo caractere.

### Progressão Geométrica

Após a aplicação do SHIFT, a palavra passa pela segunda parte.

Agora, o usuário informa o primeiro termo da PG e a razão da PG, fazendo com que cada caractere recebe um valor diferente da sequência. Por exemplo, utilizando:

Primeiro termo = 1
Razão = 2

A sequência começa no 1 e se multiplica por 2, então a sequência gerada sera: 1, 2, 4, 8, 16...

Para cada caractere, o valor atual da PG é somado à sua posição no alfabeto utilizando: nova posição = posição atual + valor da PG. O resultado também utiliza `% 62` para permanecer dentro das 62 posições disponíveis.

Após cada caractere, o próximo termo da PG é calculado através de: próximo termo = termo atual × razão

## Registro da execução

Ao finalizar ambas as partes, o programa cria automaticamente um arquivo de log na pasta (a pasta já vem com um de exemplo para referencia)
O arquivo registra as seguintes informações:Palavra original, Palavra codificada, Quantidade de caracteres, Valor do SHIFT, Primeiro termo da PG, Razao da PG.

OBS: O log é criando na mesma parte onde o main.exe está.

## Tecnologias utilizadas

- Linguagem: C
- Biblioteca: `stdio.h`
- Programas/Sites: Visual Studio Code, OneCompiler

OBS: O código foi escrito majoritariamente no OneCompiler, e em seguida o transcrevemos para o VS Code.

## Considerações finais

O projeto nos permitiu aplicar conceitos básicos de programação em C na criação de um sistema de criptografia básico, enquanto a utilização de duas etapas, SHIFT e Progressão Geométrica, permitiu trabalhar com operações matemáticas, vetores, funções e manipulação de arquivos em um único programa.
