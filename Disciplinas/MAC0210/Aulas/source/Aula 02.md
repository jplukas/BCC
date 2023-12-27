# Algoritmos numéricos e erros

Todo cálculo de interesse terá algum erro. Nosso objetivo é nos certificar que esse erro será pequeno.

## Erros absolutos e relativos

Podemos classificar os erros em medições em dois tipos básicos: erros absolutos e erros relativos.
Seja $u$ uma quantidade escalar de interesse, e seja $v$ uma aproximação de $u$:

- O ***erro absoluto*** em $v$ é dado por $|u-v|$
- O ***erro relativo*** (assumindo que $u \neq 0$) em $v$ é dado por $\frac{|u-v|}{|u|}$
O erro relativo geralmente é uma medida mais apropriada da qualidade de uma aproximação do que o erro absoluto.

## Erros de aproximação

Quando utilizamos uma aproximação de uma função ao invés da função de fato, nos deparamos com erros de aproximação. Podemos classificá-los em dois tipos:

- **Erros de discretização**: Aparecem quando truncamos, ou discretizamos processos contínuos, como diferenciação, integração e interpolação.
- **Erros de convergência**: Muitos métodos que utilizamos são métodos iterativos, que a partir de uma aproximação inicial, refinam essa aproximação iterativamente até chegar em uma estimativa *próxima* do valor real, porque precisamos parar o nosso método iterativo em algum ponto.

## Erros de arredondamento

Qualquer computação com números reais está sujeita a erros de arredondamento, devido a precisão finita da representação de números reais no computador. Erros de discretização e convergência podem ser mitigados por meio da análise dos métodos utilizados, porém erros de arredondamento dependem da plataforma onde os nossos programas rodarão. Nossa hipótese básica é que erros de aproximação dominam erros de arredondamento em magnitude em geral.

## Condicionamento de problemas e estabilidade de algoritmos

### Acumulação de erros
