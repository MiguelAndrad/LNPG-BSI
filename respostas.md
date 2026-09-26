# Para pensar

## 1. Item 2: `/` em vez de `//`

Em Python, `//` é divisão inteira e `/` é sempre divisão real. Com a entrada `17 5`:

- `17 // 5` → `3`
- `17 / 5` → `3.4`

Ou seja, se usarmos `/` no Python, o "quociente" sai `3.4` em vez de `3`.

Em C não existe `//` como operador (`//` inicia um comentário). O resultado de `/` depende
dos tipos dos operandos:

- `int / int` → divisão inteira (a parte fracionária é descartada): `17 / 5` → `3`
- se ao menos um operando for real → divisão real: `17 / 5.0` ou `(float) 17 / 5` → `3.4`

Como `a` e `b` são `int` no programa, `a / b` já dá `3`, exatamente o comportamento do `//` do Python.

## 2. Item 4: `c * (9/5)`

Trocando a fórmula por `f = c * (9/5) + 32;` e digitando `100`, a saída foi:

```
Celsius: 100
Fahrenheit: 132.0
```

O resultado correto seria `212.0`. Os parênteses fazem `9/5` ser calculado primeiro, e como
`9` e `5` são dois `int`, a divisão é inteira: `9/5` → `1`. A conta vira `c * 1 + 32 = 132`.

Na versão `c * 9 / 5 + 32`, a avaliação é da esquerda para a direita: primeiro `c * 9`
(float, pois `c` é float), e depois esse float é dividido por 5, então a divisão é real.
Também funcionaria escrever `c * (9.0 / 5)` ou `c * 9.0f / 5`.

## 3. Item 9: `1` em vez de `True`

Em Python existe um tipo booleano próprio (`bool`), com os valores `True` e `False`, e o
`print` mostra esses nomes.

Em C (sem `<stdbool.h>`) não há um tipo booleano separado: operadores relacionais (`==`, `>`, ...)
e lógicos (`&&`, `||`, `!`) produzem um `int`, valendo `1` para verdadeiro e `0` para falso.
Por isso imprimimos com `%d` e aparece `1`.

Isso revela que, para o C, "verdadeiro" e "falso" são apenas números: `0` é falso e
**qualquer valor diferente de 0** é considerado verdadeiro numa condição. Testes feitos:
`4` → `1`, `0` → `0`, `-4` → `0`.

## 4. `gcc -S` no item 1

Comando:

```
gcc -std=c11 -S 01-idade.c
```

Isso gera o arquivo `01-idade.s` (incluído no repositório). Foi compilado num Mac com
processador Apple Silicon, então o assembly é **ARM64** (no macOS o `gcc` é, na verdade, o clang).

A subtração `ANO_ATUAL - ano` aparece aqui, logo depois da chamada ao `scanf`:

```asm
	bl	_scanf                  ; le o ano digitado
	ldur	w9, [x29, #-8]      ; carrega a variavel "ano" da memoria para o registrador w9
	mov	w8, #2026           ; coloca a constante ANO_ATUAL (2026) em w8
	subs	w10, w8, w9         ; w10 = 2026 - ano  <-- a subtracao
	...
	bl	_printf                 ; imprime "Idade: %d\n" com o valor de w10
```

Observações:

- O `#define ANO_ATUAL 2026` não existe no assembly: o pré-processador troca o nome pelo
  valor antes da compilação, e ele aparece como o número imediato `#2026`.
- As strings do programa (`"Ano de nascimento: "`, `"%d"`, `"Idade: %d\n"`) ficam na seção
  `__cstring`, no fim do arquivo.
