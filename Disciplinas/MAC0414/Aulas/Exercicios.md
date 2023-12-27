# Exercícios

## Linguagens regulares

1. 
    a. Qual é o estado de início?
   
        $M_{1}$. $q_{1}$

        $M_{2}$. $q_{1}$

    b. Quais são os estados de aceitação?

        $M_{1}$. $\{q_{2}\}$

        $M_{2}$. $\{q_{2}, q_{4}\}$

    c. Qual sequência de estados a máquina percorre pela string $\text{aabb}$?

        $M_{1}$. $q_{1}, q_{2}, q_{3}, q_{1}, q_{1}$

        $M_{2}$. $q_{1}, q_{1}, q_{1}, q_{2}, q_{4}$

    d. A máquina aceita a string $\text{aabb}$?

        $M_{1}$. Não

        $M_{2}$. Sim

    e. A máquina aceita a string $\epsilon$?

        $M_{1}$. Não

        $M_{2}$. Sim

2. Dê a descrição formal das máquinas $M_{1}$ e $M_{2}$ do exercício anterior.

    $M_{1} = (\{q_{1}, q_{2}, q_{3}\}, \{\text{a,b}\}, \delta_{1}, q_{1}, \{q_{2}\})$, onde $\delta_{1}$ é tal que
    $$
    \begin{aligned}
    \delta_{1}(q_{1}, \text{a}) &= q_{2}\\
    \delta_{1}(q_{2}, \text{a}) &= q_{3}\\
    \delta_{1}(q_{3}, \text{a}) &= q_{2}\\
    \delta_{1}(q_{1}, \text{b}) &= q_{1}\\
    \delta_{1}(q_{2}, \text{b}) &= q_{3}\\
    \delta_{1}(q_{3}, \text{b}) &= q_{1}
    \end{aligned}
    $$

    $M_{2} = (\{q_{1}, q_{2}, q_{3}, q_{4}\}, \{\text{a,b}\}, \delta_{2}, q_{1}, \{q_{1}, q_{4}\})$, onde $\delta_{2}$ é tal que
    $$
    \begin{aligned}
    \delta_{2}(q_{1}, \text{a}) &= q_{1}\\
    \delta_{2}(q_{2}, \text{a}) &= q_{3}\\
    \delta_{2}(q_{3}, \text{a}) &= q_{2}\\
    \delta_{2}(q_{4}, \text{a}) &= q_{3}\\
    \delta_{2}(q_{1}, \text{b}) &= q_{2}\\
    \delta_{2}(q_{2}, \text{b}) &= q_{4}\\
    \delta_{2}(q_{3}, \text{b}) &= q_{1}\\
    \delta_{2}(q_{4}, \text{b}) &= q_{4}
    \end{aligned}
    $$

3. TODO

4. blabla

    a. $\{w | w \text{ tem ao menos 3 "a"s e ao menos 2 "b"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s8"},"s6":{"b":"s7","a":"s0"},"s8":{"b":"s0","a":"s9"},"s0":{"b":"s1","a":"s2"},"s9":{"b":"s2","a":"s10"},"s2":{"b":"s3","a":"s4"},"s10":{"b":"s4","a":"s10"},"s4":{"b":"s5","a":"s4"},"s7":{"a":"s1","b":"s7"},"s1":{"a":"s3","b":"s1"},"s3":{"a":"s5","b":"s3"},"s5":{"a":"s5","b":"s5"}},"startState":"start","acceptStates":["s5"]},"states":{"start":{},"s8":{"top":354,"left":205,"displayId":"(q1,start)"},"s6":{"top":413,"left":0,"displayId":"(start,r1)"},"s7":{"top":537,"left":0,"displayId":"(start,r2)"},"s0":{"top":414,"left":209,"displayId":"(q1,r1)"},"s9":{"top":355,"left":409,"displayId":"(q2,start)"},"s1":{"top":536,"left":204,"displayId":"(q1,r2)"},"s2":{"top":415,"left":411,"displayId":"(q2,r1)"},"s10":{"top":331,"left":649,"displayId":"(q3,start)"},"s3":{"top":536,"left":410,"displayId":"(q2,r2)"},"s4":{"top":451,"left":649,"displayId":"(q3,r1)"},"s5":{"isAccept":true,"top":531,"left":656,"displayId":"(q3,r2)"}},"transitions":[{"stateA":"start","label":"a","stateB":"s8"},{"stateA":"s6","label":"b","stateB":"s7"},{"stateA":"s6","label":"a","stateB":"s0"},{"stateA":"s8","label":"b","stateB":"s0"},{"stateA":"s8","label":"a","stateB":"s9"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s2"},{"stateA":"s9","label":"b","stateB":"s2"},{"stateA":"s9","label":"a","stateB":"s10"},{"stateA":"s2","label":"b","stateB":"s3"},{"stateA":"s2","label":"a","stateB":"s4"},{"stateA":"s10","label":"b","stateB":"s4"},{"stateA":"s10","label":"a","stateB":"s10"},{"stateA":"s4","label":"b","stateB":"s5"},{"stateA":"s4","label":"a","stateB":"s4"},{"stateA":"s7","label":"a","stateB":"s1"},{"stateA":"s7","label":"b","stateB":"s7"},{"stateA":"s1","label":"a","stateB":"s3"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s3","label":"a","stateB":"s5"},{"stateA":"s3","label":"b","stateB":"s3"},{"stateA":"s5","label":"a","stateB":"s5"},{"stateA":"s5","label":"b","stateB":"s5"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. $\{w | w \text{ tem exatamente 2 "a"s e ao menos 2 "b"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s8"},"s6":{"b":"s7","a":"s0"},"s8":{"b":"s0","a":"s9"},"s0":{"b":"s1","a":"s2"},"s9":{"b":"s2","a":"s10"},"s2":{"b":"s3","a":"s4"},"s10":{"b":"s4","a":"s10"},"s4":{"b":"s5","a":"s4"},"s7":{"a":"s1","b":"s7"},"s1":{"a":"s3","b":"s1"},"s3":{"a":"s5","b":"s3"},"s5":{"a":"s5","b":"s5"}},"startState":"start","acceptStates":["s3"]},"states":{"start":{},"s8":{"top":354,"left":205,"displayId":"(q1,start)"},"s6":{"top":413,"left":0,"displayId":"(start,r1)"},"s7":{"top":537,"left":0,"displayId":"(start,r2)"},"s0":{"top":414,"left":209,"displayId":"(q1,r1)"},"s9":{"top":355,"left":409,"displayId":"(q2,start)"},"s1":{"top":536,"left":204,"displayId":"(q1,r2)"},"s2":{"top":415,"left":411,"displayId":"(q2,r1)"},"s10":{"top":331,"left":649,"displayId":"(q3,start)"},"s3":{"isAccept":true,"top":536,"left":410,"displayId":"(q2,r2)"},"s4":{"top":451,"left":649,"displayId":"(q3,r1)"},"s5":{"top":531,"left":656,"displayId":"(q3,r2)"}},"transitions":[{"stateA":"start","label":"a","stateB":"s8"},{"stateA":"s6","label":"b","stateB":"s7"},{"stateA":"s6","label":"a","stateB":"s0"},{"stateA":"s8","label":"b","stateB":"s0"},{"stateA":"s8","label":"a","stateB":"s9"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s2"},{"stateA":"s9","label":"b","stateB":"s2"},{"stateA":"s9","label":"a","stateB":"s10"},{"stateA":"s2","label":"b","stateB":"s3"},{"stateA":"s2","label":"a","stateB":"s4"},{"stateA":"s10","label":"b","stateB":"s4"},{"stateA":"s10","label":"a","stateB":"s10"},{"stateA":"s4","label":"b","stateB":"s5"},{"stateA":"s4","label":"a","stateB":"s4"},{"stateA":"s7","label":"a","stateB":"s1"},{"stateA":"s7","label":"b","stateB":"s7"},{"stateA":"s1","label":"a","stateB":"s3"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s3","label":"a","stateB":"s5"},{"stateA":"s3","label":"b","stateB":"s3"},{"stateA":"s5","label":"a","stateB":"s5"},{"stateA":"s5","label":"b","stateB":"s5"}],"bulkTests":{"accept":"","reject":""}}
        ```

    c. $\{w | w \text{ tem um numero par de "a"s e 1 ou 2 "b"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"b":"s8","a":"s6"},"s6":{"b":"s0","a":"start"},"s8":{"a":"s0","b":"s11"},"s0":{"a":"s8","b":"s12"},"s11":{"b":"s13","a":"s12"},"s12":{"b":"s14","a":"s11"},"s13":{"a":"s14","b":"s13"},"s14":{"a":"s13","b":"s14"}},"startState":"start","acceptStates":["s8","s11"]},"states":{"start":{},"s8":{"isAccept":true,"top":349,"left":212,"displayId":"(start,r1)"},"s6":{"top":451,"left":0,"displayId":"(q1,start)"},"s0":{"top":456,"left":218,"displayId":"(q1,r1)"},"s11":{"isAccept":true,"top":344,"left":398,"displayId":"(start,r2)"},"s12":{"top":457,"left":401,"displayId":"(q1,r2)"},"s13":{"top":339,"left":591,"displayId":"(start,r3)"},"s14":{"top":456,"left":593,"displayId":"(q1,r3)"}},"transitions":[{"stateA":"start","label":"b","stateB":"s8"},{"stateA":"start","label":"a","stateB":"s6"},{"stateA":"s6","label":"b","stateB":"s0"},{"stateA":"s6","label":"a","stateB":"start"},{"stateA":"s8","label":"a","stateB":"s0"},{"stateA":"s8","label":"b","stateB":"s11"},{"stateA":"s0","label":"a","stateB":"s8"},{"stateA":"s0","label":"b","stateB":"s12"},{"stateA":"s11","label":"b","stateB":"s13"},{"stateA":"s11","label":"a","stateB":"s12"},{"stateA":"s12","label":"b","stateB":"s14"},{"stateA":"s12","label":"a","stateB":"s11"},{"stateA":"s13","label":"a","stateB":"s14"},{"stateA":"s13","label":"b","stateB":"s13"},{"stateA":"s14","label":"a","stateB":"s13"},{"stateA":"s14","label":"b","stateB":"s14"}],"bulkTests":{"accept":"","reject":""}}
        ```

    d. $\{w | w \text{ tem um numero par de "a"s e cada "a" é seguido de ao menos 1 "b"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"start"},"s6":{"a":"s8","b":"s6"},"s8":{"a":"s12","b":"start"},"s0":{"a":"s11","b":"s6"},"s11":{"a":"s12","b":"s11"},"s12":{"a":"s11","b":"s12"}},"startState":"start","acceptStates":["start"]},"states":{"start":{"isAccept":true},"s0":{"top":456,"left":205,"displayId":"(q1,r1)"},"s6":{"top":451,"left":0,"displayId":"(q1,start)"},"s8":{"top":350,"left":202,"displayId":"(start,r1)"},"s12":{"top":459,"left":368,"displayId":"(q1,r2)"},"s11":{"top":346,"left":375,"displayId":"(start,r2)"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"start"},{"stateA":"s6","label":"a","stateB":"s8"},{"stateA":"s6","label":"b","stateB":"s6"},{"stateA":"s8","label":"a","stateB":"s12"},{"stateA":"s8","label":"b","stateB":"start"},{"stateA":"s0","label":"a","stateB":"s11"},{"stateA":"s0","label":"b","stateB":"s6"},{"stateA":"s11","label":"a","stateB":"s12"},{"stateA":"s11","label":"b","stateB":"s11"},{"stateA":"s12","label":"a","stateB":"s11"},{"stateA":"s12","label":"b","stateB":"s12"}],"bulkTests":{"accept":"","reject":""}}
        ```

    e. $\{w | w \text{ começa com um "a" e tem no máximo 1 "b"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s6","b":"s15"},"s6":{"a":"s6","b":"s0"},"s8":{"a":"s0","b":"s16"},"s0":{"a":"s0","b":"s12"},"s11":{"a":"s12","b":"s16"},"s12":{"a":"s12","b":"s12"},"s14":{"a":"s14","b":"s15"},"s15":{"a":"s15","b":"s16"},"s16":{"a":"s16","b":"s16"}},"startState":"start","acceptStates":["s6","s0"]},"states":{"start":{},"s6":{"isAccept":true,"top":451,"left":0,"displayId":"(q1,start)"},"s15":{"top":581,"left":229,"displayId":"(q2,r1)"},"s0":{"isAccept":true,"top":446,"left":249,"displayId":"(q1,r1)"},"s8":{"top":351,"left":196,"displayId":"(start,r1)"},"s16":{"top":578,"left":410,"displayId":"(q2,r2)"},"s12":{"top":457,"left":475,"displayId":"(q1,r2)"},"s11":{"top":350,"left":388,"displayId":"(start,r2)"},"s14":{"top":575,"left":0,"displayId":"(q2,start)"}},"transitions":[{"stateA":"start","label":"a","stateB":"s6"},{"stateA":"start","label":"b","stateB":"s15"},{"stateA":"s6","label":"a","stateB":"s6"},{"stateA":"s6","label":"b","stateB":"s0"},{"stateA":"s8","label":"a","stateB":"s0"},{"stateA":"s8","label":"b","stateB":"s16"},{"stateA":"s0","label":"a","stateB":"s0"},{"stateA":"s0","label":"b","stateB":"s12"},{"stateA":"s11","label":"a","stateB":"s12"},{"stateA":"s11","label":"b","stateB":"s16"},{"stateA":"s12","label":"a","stateB":"s12"},{"stateA":"s12","label":"b","stateB":"s12"},{"stateA":"s14","label":"a","stateB":"s14"},{"stateA":"s14","label":"b","stateB":"s15"},{"stateA":"s15","label":"a","stateB":"s15"},{"stateA":"s15","label":"b","stateB":"s16"},{"stateA":"s16","label":"a","stateB":"s16"},{"stateA":"s16","label":"b","stateB":"s16"}],"bulkTests":{"accept":"","reject":""}}
        ```

    f. $\{w | w \text{ tem um número ímpar de "a"s e termina em "b"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s1","b":"s0"},"s1":{"a":"start","b":"s2"},"s0":{"a":"s1","b":"s0"},"s2":{"a":"start","b":"s2"}},"startState":"start","acceptStates":["s2"]},"states":{"start":{},"s1":{"top":353,"left":410,"displayId":"(start,r1)"},"s0":{"top":508,"left":0,"displayId":"(q1,start)"},"s2":{"isAccept":true,"top":511,"left":416,"displayId":"(q1,r1)"}},"transitions":[{"stateA":"start","label":"a","stateB":"s1"},{"stateA":"start","label":"b","stateB":"s0"},{"stateA":"s1","label":"a","stateB":"start"},{"stateA":"s1","label":"b","stateB":"s2"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s0","label":"b","stateB":"s0"},{"stateA":"s2","label":"a","stateB":"start"},{"stateA":"s2","label":"b","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    g. $\{w | w \text{ tem um comprimento par e um número ímpar de "a"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"b":"s0","a":"s2"},"s1":{"b":"s2","a":"s0"},"s0":{"b":"start","a":"s1"},"s2":{"b":"s1","a":"start"}},"startState":"start","acceptStates":["s1"]},"states":{"start":{},"s0":{"top":508,"left":0,"displayId":"(q1,start)"},"s2":{"top":511,"left":416,"displayId":"(q1,r1)"},"s1":{"isAccept":true,"top":353,"left":410,"displayId":"(start,r1)"}},"transitions":[{"stateA":"start","label":"b","stateB":"s0"},{"stateA":"start","label":"a","stateB":"s2"},{"stateA":"s1","label":"b","stateB":"s2"},{"stateA":"s1","label":"a","stateB":"s0"},{"stateA":"s0","label":"b","stateB":"start"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s2","label":"b","stateB":"s1"},{"stateA":"s2","label":"a","stateB":"start"}],"bulkTests":{"accept":"","reject":""}}
        ```

5. blabla

    a. $\{w | w \text{ não contém a substring "ab"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"start"},"s0":{"b":"s1","a":"s0"},"s1":{"a":"s1","b":"s1"}},"startState":"start","acceptStates":["s0","start"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":356,"left":219,"displayId":"q1"},"s1":{"top":359,"left":456,"displayId":"q2"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"start"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s0"},{"stateA":"s1","label":"a","stateB":"s1"},{"stateA":"s1","label":"b","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. $\{w | w \text{ não contém a substring "baba"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"b":"s0","a":"start"},"s1":{"b":"s2","a":"start"},"s0":{"a":"s1","b":"s0"},"s2":{"a":"s3","b":"s0"},"s3":{"a":"s3","b":"s3"}},"startState":"start","acceptStates":["s2","s1","s0","start"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":351,"left":136,"displayId":"s0"},"s1":{"isAccept":true,"top":352,"left":286,"displayId":"s1"},"s2":{"isAccept":true,"top":353,"left":438,"displayId":"s2"},"s3":{"top":350,"left":591,"displayId":"s3"}},"transitions":[{"stateA":"start","label":"b","stateB":"s0"},{"stateA":"start","label":"a","stateB":"start"},{"stateA":"s1","label":"b","stateB":"s2"},{"stateA":"s1","label":"a","stateB":"start"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s0","label":"b","stateB":"s0"},{"stateA":"s2","label":"a","stateB":"s3"},{"stateA":"s2","label":"b","stateB":"s0"},{"stateA":"s3","label":"a","stateB":"s3"},{"stateA":"s3","label":"b","stateB":"s3"}],"bulkTests":{"accept":"","reject":""}}
        ```

    c. $\{w | w \text{ não contém as substrings "ab" ou "ba"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"s2"},"s0":{"b":"s1","a":"s0"},"s2":{"a":"s3","b":"s2"},"s1":{"a":"s1","b":"s1"},"s3":{"a":"s3","b":"s3"}},"startState":"start","acceptStates":["s2","s0","start"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":296,"left":183,"displayId":"s0"},"s2":{"isAccept":true,"top":447,"left":183,"displayId":"s2"},"s1":{"top":296,"left":368,"displayId":"s1"},"s3":{"top":446,"left":367,"displayId":"s3"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"s2"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s0"},{"stateA":"s2","label":"a","stateB":"s3"},{"stateA":"s2","label":"b","stateB":"s2"},{"stateA":"s1","label":"a","stateB":"s1"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s3","label":"a","stateB":"s3"},{"stateA":"s3","label":"b","stateB":"s3"}],"bulkTests":{"accept":"","reject":""}}
        ```

    d. $\{w | w \text{ é qualquer string que não esteja em "a*b*"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"b":"s0","a":"start"},"s0":{"b":"s0","a":"s1"},"s1":{"b":"s1","a":"s1"}},"startState":"start","acceptStates":["s1"]},"states":{"start":{},"s0":{"top":353,"left":159,"displayId":"s0"},"s1":{"isAccept":true,"top":353,"left":338,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"b","stateB":"s0"},{"stateA":"start","label":"a","stateB":"start"},{"stateA":"s0","label":"b","stateB":"s0"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s1","label":"a","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    e. $\{w | w \text{ é qualquer string que não esteja em "(ab+)*"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"s2"},"s0":{"b":"s1","a":"s2"},"s1":{"b":"s1","a":"s0"},"s2":{"b":"s2","a":"s2"}},"startState":"start","acceptStates":["s0","s2"]},"states":{"start":{},"s0":{"isAccept":true,"top":353,"left":159,"displayId":"s0"},"s2":{"isAccept":true,"top":440,"left":156,"displayId":"s2"},"s1":{"top":353,"left":323,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"s2"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s2"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s1","label":"a","stateB":"s0"},{"stateA":"s2","label":"b","stateB":"s2"},{"stateA":"s2","label":"a","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    f. $\{w | w \text{ é qualquer string que não esteja em "a* } \cup \text{ b*"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"s1"},"s2":{"b":"s2","a":"s2"},"s0":{"a":"s0","b":"s2"},"s1":{"a":"s2","b":"s1"}},"startState":"start","acceptStates":["s2"]},"states":{"start":{},"s0":{"top":255,"left":131,"displayId":"s0"},"s1":{"top":462,"left":123,"displayId":"s1"},"s2":{"isAccept":true,"top":364,"left":298,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"s1"},{"stateA":"s2","label":"b","stateB":"s2"},{"stateA":"s2","label":"a","stateB":"s2"},{"stateA":"s0","label":"a","stateB":"s0"},{"stateA":"s0","label":"b","stateB":"s2"},{"stateA":"s1","label":"a","stateB":"s2"},{"stateA":"s1","label":"b","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    g. $\{w | w \text{ é qualquer string que não contém exatamente 2 "a"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"start"},"s0":{"a":"s1","b":"s0"},"s1":{"a":"s2","b":"s1"},"s2":{"a":"s2","b":"s2"}},"startState":"start","acceptStates":["s2","s0","start"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":355,"left":149,"displayId":"s0"},"s1":{"top":353,"left":299,"displayId":"s1"},"s2":{"isAccept":true,"top":354,"left":484,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"start"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s0","label":"b","stateB":"s0"},{"stateA":"s1","label":"a","stateB":"s2"},{"stateA":"s1","label":"b","stateB":"s1"},{"stateA":"s2","label":"a","stateB":"s2"},{"stateA":"s2","label":"b","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    h. $\{w | w \text{ é qualquer string diferente de "a" e "b"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"a":"s0","b":"s1"},"s0":{"a":"s2","b":"s2"},"s1":{"b":"s2","a":"s2"},"s2":{"a":"s2","b":"s2"}},"startState":"start","acceptStates":["start","s2"]},"states":{"start":{"isAccept":true},"s0":{"top":263,"left":135,"displayId":"s0"},"s1":{"top":473,"left":137,"displayId":"s1"},"s2":{"isAccept":true,"top":362,"left":273,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"s1"},{"stateA":"s0","label":"a","stateB":"s2"},{"stateA":"s0","label":"b","stateB":"s2"},{"stateA":"s1","label":"b","stateB":"s2"},{"stateA":"s1","label":"a","stateB":"s2"},{"stateA":"s2","label":"a","stateB":"s2"},{"stateA":"s2","label":"b","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

6. Crie diagramas de estado de AFDs que reconheçam as seguintes linguagens. Em cada exemplo, o alfabeto é $\{0,1\}$.

    a. $\{w | w \text{ começa com "1" e termina com "0"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s2","1":"s0"},"s0":{"0":"s1","1":"s0"},"s1":{"0":"s1","1":"s0"},"s2":{"0":"s2","1":"s2"}},"startState":"start","acceptStates":["s1"]},"states":{"start":{},"s2":{"top":270,"left":0,"displayId":"s2"},"s0":{"top":355,"left":160,"displayId":"s0"},"s1":{"isAccept":true,"top":355,"left":329,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"0","stateB":"s2"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s0"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s0"},{"stateA":"s2","label":"0","stateB":"s2"},{"stateA":"s2","label":"1","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. $\{w | w \text{ contém ao menos 3 "1"s}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"start","1":"s0"},"s0":{"0":"s0","1":"s1"},"s1":{"0":"s1","1":"s2"},"s2":{"0":"s2","1":"s2"}},"startState":"start","acceptStates":["s2"]},"states":{"start":{},"s0":{"top":353,"left":141,"displayId":"s0"},"s1":{"top":353,"left":283,"displayId":"s1"},"s2":{"isAccept":true,"top":353,"left":430,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"0","stateB":"start"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s0"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s2"},{"stateA":"s2","label":"0","stateB":"s2"},{"stateA":"s2","label":"1","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    c. $\{w | w \text{ contém a substring "0101"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0"},"s0":{"0":"s0","1":"s1"},"s1":{"0":"s2","1":"start"},"s2":{"0":"s0","1":"s3"},"s3":{"0":"s3","1":"s3"}},"startState":"start","acceptStates":["s3"]},"states":{"start":{},"s0":{"top":353,"left":141,"displayId":"s0"},"s1":{"top":354,"left":276,"displayId":"s1"},"s2":{"top":355,"left":432,"displayId":"s2"},"s3":{"isAccept":true,"top":353,"left":586,"displayId":"s3"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s0"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s2"},{"stateA":"s1","label":"1","stateB":"start"},{"stateA":"s2","label":"0","stateB":"s0"},{"stateA":"s2","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s3"},{"stateA":"s3","label":"1","stateB":"s3"}],"bulkTests":{"accept":"","reject":""}}
        ```

    d. $\{w | w \text{ tem comprimento ao menos 3 e o 3º símbolo é "0"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0","1":"s0"},"s0":{"0":"s1","1":"s1"},"s1":{"0":"s2","1":"s3"},"s3":{"0":"s3","1":"s3"},"s2":{"0":"s2","1":"s2"}},"startState":"start","acceptStates":["s2"]},"states":{"start":{},"s0":{"top":354,"left":136,"displayId":"s0"},"s1":{"top":355,"left":292,"displayId":"s1"},"s2":{"isAccept":true,"top":355,"left":435,"displayId":"s2"},"s3":{"top":469,"left":126,"displayId":"s3"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s2"},{"stateA":"s1","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s3"},{"stateA":"s3","label":"1","stateB":"s3"},{"stateA":"s2","label":"0","stateB":"s2"},{"stateA":"s2","label":"1","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    e. $\{w | w \text{ começa com "0" e tem comprimento ímpar ou começa com "1" e tem comprimento par}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0","1":"s1"},"s0":{"0":"s2","1":"s2"},"s2":{"0":"s0","1":"s0"},"s1":{"0":"s3","1":"s3"},"s3":{"0":"s1","1":"s1"}},"startState":"start","acceptStates":["s0","s3"]},"states":{"start":{},"s0":{"isAccept":true,"top":283,"left":139,"displayId":"s0"},"s1":{"top":447,"left":139,"displayId":"s1"},"s2":{"top":284,"left":357,"displayId":"s2"},"s3":{"isAccept":true,"top":446,"left":364,"displayId":"s3"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"s1"},{"stateA":"s0","label":"0","stateB":"s2"},{"stateA":"s0","label":"1","stateB":"s2"},{"stateA":"s2","label":"0","stateB":"s0"},{"stateA":"s2","label":"1","stateB":"s0"},{"stateA":"s1","label":"0","stateB":"s3"},{"stateA":"s1","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s1"},{"stateA":"s3","label":"1","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    f. $\{w | w \text{ não contém a substring "110"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"start","1":"s0"},"s0":{"0":"start","1":"s1"},"s1":{"0":"s2","1":"s1"},"s2":{"0":"s2","1":"s2"}},"startState":"start","acceptStates":["start","s0","s1"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":354,"left":155,"displayId":"s0"},"s1":{"isAccept":true,"top":354,"left":316,"displayId":"s1"},"s2":{"top":355,"left":489,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"0","stateB":"start"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"start"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s2"},{"stateA":"s1","label":"1","stateB":"s1"},{"stateA":"s2","label":"0","stateB":"s2"},{"stateA":"s2","label":"1","stateB":"s2"}],"bulkTests":{"accept":"","reject":""}}
        ```

    g. $\{w | w \text{ tem comprimento de no máximo 5}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0","1":"s0"},"s0":{"0":"s1","1":"s1"},"s1":{"0":"s2","1":"s2"},"s2":{"0":"s3","1":"s3"},"s3":{"0":"s4","1":"s4"},"s4":{"0":"s5","1":"s5"},"s5":{"0":"s5","1":"s5"}},"startState":"start","acceptStates":["start","s0","s1","s2","s3","s4"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":353,"left":149,"displayId":"s0"},"s1":{"isAccept":true,"top":353,"left":311,"displayId":"s1"},"s2":{"isAccept":true,"top":354,"left":485,"displayId":"s2"},"s3":{"isAccept":true,"top":352,"left":648,"displayId":"s3"},"s4":{"isAccept":true,"top":350,"left":815,"displayId":"s4"},"s5":{"top":349,"left":971,"displayId":"s5"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s2"},{"stateA":"s1","label":"1","stateB":"s2"},{"stateA":"s2","label":"0","stateB":"s3"},{"stateA":"s2","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s4"},{"stateA":"s3","label":"1","stateB":"s4"},{"stateA":"s4","label":"0","stateB":"s5"},{"stateA":"s4","label":"1","stateB":"s5"},{"stateA":"s5","label":"0","stateB":"s5"},{"stateA":"s5","label":"1","stateB":"s5"}],"bulkTests":{"accept":"","reject":""}}
        ```

    h. $\{w | w \text{ é qualquer string diferente de "11" e "111"}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s3","1":"s0"},"s0":{"0":"s3","1":"s1"},"s1":{"0":"s3","1":"s2"},"s2":{"0":"s3","1":"s3"},"s3":{"0":"s3","1":"s3"}},"startState":"start","acceptStates":["start","s0","s3"]},"states":{"start":{"isAccept":true},"s3":{"isAccept":true,"top":241,"left":267,"displayId":"s3"},"s0":{"isAccept":true,"top":356,"left":168,"displayId":"s0"},"s1":{"top":353,"left":349,"displayId":"s1"},"s2":{"top":354,"left":540,"displayId":"s2"}},"transitions":[{"stateA":"start","label":"0","stateB":"s3"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s3"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s3"},{"stateA":"s1","label":"1","stateB":"s2"},{"stateA":"s2","label":"0","stateB":"s3"},{"stateA":"s2","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s3"},{"stateA":"s3","label":"1","stateB":"s3"}],"bulkTests":{"accept":"","reject":""}}
        ```

    i. $\{w | \text{ cada posição ímpar de } w \text{ contém "1"}\}$.

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s1","1":"s0"},"s0":{"0":"start","1":"start"},"s1":{"0":"s1","1":"s1"}},"startState":"start","acceptStates":["start","s0"]},"states":{"start":{"isAccept":true},"s1":{"top":262,"left":172,"displayId":"s1"},"s0":{"isAccept":true,"top":352,"left":223,"displayId":"s0"}},"transitions":[{"stateA":"start","label":"0","stateB":"s1"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"start"},{"stateA":"s0","label":"1","stateB":"start"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    j. $\{w | w \text{ contém no mínimo 2 "0"s e no máximo 1 "1"}\}$.

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s1","1":"s0"},"s1":{"0":"s2","1":"s4"},"s2":{"0":"s2","1":"s6"},"s0":{"0":"s4","1":"s3"},"s4":{"0":"s6","1":"s5"},"s6":{"0":"s6","1":"s7"},"s3":{"0":"s5"},"s5":{"0":"s7"},"s7":{"0":"s7","1":"s7"}},"startState":"start","acceptStates":["s2","s6"]},"states":{"start":{},"s1":{"top":355,"left":168,"displayId":"s1"},"s0":{"top":455,"left":0,"displayId":"s0"},"s2":{"isAccept":true,"top":355,"left":350,"displayId":"s2"},"s4":{"top":456,"left":165,"displayId":"s4"},"s6":{"isAccept":true,"top":461,"left":353,"displayId":"s6"},"s3":{"top":562,"left":0,"displayId":"s3"},"s5":{"top":561,"left":169,"displayId":"s5"},"s7":{"top":568,"left":367,"displayId":"s7"}},"transitions":[{"stateA":"start","label":"0","stateB":"s1"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s1","label":"0","stateB":"s2"},{"stateA":"s1","label":"1","stateB":"s4"},{"stateA":"s2","label":"0","stateB":"s2"},{"stateA":"s2","label":"1","stateB":"s6"},{"stateA":"s0","label":"0","stateB":"s4"},{"stateA":"s0","label":"1","stateB":"s3"},{"stateA":"s4","label":"0","stateB":"s6"},{"stateA":"s4","label":"1","stateB":"s5"},{"stateA":"s6","label":"0","stateB":"s6"},{"stateA":"s6","label":"1","stateB":"s7"},{"stateA":"s3","label":"0","stateB":"s5"},{"stateA":"s5","label":"0","stateB":"s7"},{"stateA":"s7","label":"0","stateB":"s7"},{"stateA":"s7","label":"1","stateB":"s7"}],"bulkTests":{"accept":"","reject":""}}
        ```

    k. $\{\epsilon, \text{0}\}$

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0","1":"s1"},"s0":{"0":"s1","1":"s1"},"s1":{"0":"s1","1":"s1"}},"startState":"start","acceptStates":["start","s0"]},"states":{"start":{"isAccept":true},"s0":{"isAccept":true,"top":352,"left":183,"displayId":"s0"},"s1":{"top":247,"left":87,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"s1"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    l. $\{w | w \text{ contém um número par de "0"s ou contém exatamente 2 "1"s}\}$.

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s2","1":"s0"},"s0":{"0":"s3","1":"s1"},"s1":{"0":"s4","1":"s5"},"s2":{"0":"start","1":"s3"},"s3":{"0":"s0","1":"s4"},"s4":{"0":"s1","1":"s6"},"s5":{"0":"s6","1":"s5"},"s6":{"0":"s5","1":"s6"}},"startState":"start","acceptStates":["s1","s4","s0","s5","start"]},"states":{"start":{"isAccept":true},"s2":{"top":453,"left":0,"displayId":"s2"},"s0":{"isAccept":true,"top":354,"left":185,"displayId":"s0"},"s3":{"top":460,"left":188,"displayId":"s3"},"s1":{"isAccept":true,"top":351,"left":382,"displayId":"s1"},"s4":{"isAccept":true,"top":459,"left":383,"displayId":"s4"},"s5":{"isAccept":true,"top":353,"left":562,"displayId":"s5"},"s6":{"top":459,"left":567,"displayId":"s6"}},"transitions":[{"stateA":"start","label":"0","stateB":"s2"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s3"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s4"},{"stateA":"s1","label":"1","stateB":"s5"},{"stateA":"s2","label":"0","stateB":"start"},{"stateA":"s2","label":"1","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s0"},{"stateA":"s3","label":"1","stateB":"s4"},{"stateA":"s4","label":"0","stateB":"s1"},{"stateA":"s4","label":"1","stateB":"s6"},{"stateA":"s5","label":"0","stateB":"s6"},{"stateA":"s5","label":"1","stateB":"s5"},{"stateA":"s6","label":"0","stateB":"s5"},{"stateA":"s6","label":"1","stateB":"s6"}],"bulkTests":{"accept":"","reject":""}}
        ```

    m. $\emptyset$.

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"start","1":"start"}},"startState":"start","acceptStates":[]},"states":{"start":{}},"transitions":[{"stateA":"start","label":"0","stateB":"start"},{"stateA":"start","label":"1","stateB":"start"}],"bulkTests":{"accept":"","reject":""}}
        ```

    n. $\{w | w \text{ é qualquer string exceto a string vazia}\}$.

        ```json
        {"type":"DFA","dfa":{"transitions":{"start":{"0":"s0","1":"s0"},"s0":{"0":"s0","1":"s0"}},"startState":"start","acceptStates":["s0"]},"states":{"start":{},"s0":{"isAccept":true,"top":355,"left":162,"displayId":"s0"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s0"},{"stateA":"s0","label":"1","stateB":"s0"}],"bulkTests":{"accept":"","reject":""}}
        ```

7. Dê os diagramas de estado de cada AFN, com o número de estados especificados, para cada linguagem:

    a. A linguagem $\{w | w \text{ termina com "00"}\}$ com 3 estados.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["s0"],"1":["start"]},"s0":{"0":["s1"],"1":["start"]},"s1":{"0":["s1"],"1":["start"]}},"startState":"start","acceptStates":["s1"]},"states":{"start":{},"s0":{"top":353,"left":172,"displayId":"s0"},"s1":{"isAccept":true,"top":355,"left":338,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"start"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"start"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"start"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. A linguagem do ex. 6.c com 5 estados.

        Como o autômato do exercício 6.c é um AFD com 5 estados, ele também é um AFN com 5 estados.

    c. A linguagem do ex. 6.l com 5 estados.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["s2"],"1":["s0"]},"s2":{"0":["start"],"1":["s3"]},"s0":{"0":["s3"],"1":["s1"]},"s3":{"0":["s0"],"1":["s4"]},"s1":{"0":["s4"]},"s4":{"0":["s1"]}},"startState":"start","acceptStates":["s1","s4","s0","start"]},"states":{"start":{"isAccept":true},"s2":{"top":468,"left":0,"displayId":"s2"},"s0":{"isAccept":true,"top":354,"left":192,"displayId":"s0"},"s3":{"top":465,"left":197,"displayId":"s3"},"s1":{"isAccept":true,"top":354,"left":399,"displayId":"s1"},"s4":{"isAccept":true,"top":465,"left":400,"displayId":"s4"}},"transitions":[{"stateA":"start","label":"0","stateB":"s2"},{"stateA":"start","label":"1","stateB":"s0"},{"stateA":"s2","label":"0","stateB":"start"},{"stateA":"s2","label":"1","stateB":"s3"},{"stateA":"s0","label":"0","stateB":"s3"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s3","label":"0","stateB":"s0"},{"stateA":"s3","label":"1","stateB":"s4"},{"stateA":"s1","label":"0","stateB":"s4"},{"stateA":"s4","label":"0","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    d. A linguagem $\{0\}$ com 2 estados.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["s0"]}},"startState":"start","acceptStates":["s0"]},"states":{"start":{},"s0":{"isAccept":true,"top":354,"left":179,"displayId":"s0"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"}],"bulkTests":{"accept":"","reject":""}}
        ```

    e. A linguagem $\text{0*1*0+}$ com 3 estados.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["s0"],"":["s1"]},"s0":{"0":["s0"],"1":["s1"]},"s1":{"0":["s0"],"1":["s1"]}},"startState":"start","acceptStates":["s0"]},"states":{"start":{},"s0":{"isAccept":true,"top":240,"left":158,"displayId":"s0"},"s1":{"top":354,"left":310,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"ϵ","stateB":"s1"},{"stateA":"s0","label":"0","stateB":"s0"},{"stateA":"s0","label":"1","stateB":"s1"},{"stateA":"s1","label":"0","stateB":"s0"},{"stateA":"s1","label":"1","stateB":"s1"}],"bulkTests":{"accept":"","reject":""}}
        ```

    f. A linguagem $\text{1*(001+)*}$ com 3 estados.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["s0"],"1":["start"],"":["s0"]},"s0":{"0":["s1"]},"s1":{"1":["start"]}},"startState":"start","acceptStates":["start"]},"states":{"start":{"isAccept":true},"s0":{"top":234,"left":131,"displayId":"s0"},"s1":{"top":353,"left":243,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"0","stateB":"s0"},{"stateA":"start","label":"1","stateB":"start"},{"stateA":"start","label":"ϵ","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"start"}],"bulkTests":{"accept":"","reject":""}}
        ```

    g. A linguagem $\{\epsilon\}$ com 1 estado.

        ```json
        {"type":"NFA","nfa":{"transitions":{},"startState":"start","acceptStates":["start"]},"states":{"start":{"isAccept":true}},"transitions":[],"bulkTests":{"accept":"","reject":""}}
        ```

    h. A linguagem $\text{0*}$ com 1 estado.

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"0":["start"],"":["start"]}},"startState":"start","acceptStates":["start"]},"states":{"start":{"isAccept":true}},"transitions":[{"stateA":"start","label":"0","stateB":"start"},{"stateA":"start","label":"ϵ","stateB":"start"}],"bulkTests":{"accept":"","reject":""}}
        ```

8. Dê os diagramas de estado das AFNs que reconhecem a união das linguagens descritas em:

    a. Exercícios 6.a e 6.b

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"":["s4","s0"]},"s0":{"0":["s1"],"1":["s2"]},"s1":{"0":["s1"],"1":["s1"]},"s2":{"0":["s3"]},"s3":{"0":["s3"],"1":["s2"]},"s7":{"0":["s7"],"1":["s7"]},"s4":{"0":["s4"],"1":["s5"]},"s5":{"0":["s5"],"1":["s6"]},"s6":{"0":["s6"],"1":["s7"]}},"startState":"start","acceptStates":["s3","s7"]},"states":{"start":{},"s4":{"top":480,"left":222,"displayId":"s4"},"s0":{"top":274,"left":223,"displayId":"s0"},"s1":{"top":156,"left":222,"displayId":"s1"},"s2":{"top":276,"left":406,"displayId":"s2"},"s3":{"isAccept":true,"top":274,"left":631,"displayId":"s3"},"s7":{"isAccept":true,"top":480,"left":811,"displayId":"s7"},"s5":{"top":480,"left":404,"displayId":"s5"},"s6":{"top":481,"left":609,"displayId":"s6"}},"transitions":[{"stateA":"start","label":"ϵ","stateB":"s4"},{"stateA":"start","label":"ϵ","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s2"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s1"},{"stateA":"s2","label":"0","stateB":"s3"},{"stateA":"s3","label":"0","stateB":"s3"},{"stateA":"s3","label":"1","stateB":"s2"},{"stateA":"s7","label":"0","stateB":"s7"},{"stateA":"s7","label":"1","stateB":"s7"},{"stateA":"s4","label":"0","stateB":"s4"},{"stateA":"s4","label":"1","stateB":"s5"},{"stateA":"s5","label":"0","stateB":"s5"},{"stateA":"s5","label":"1","stateB":"s6"},{"stateA":"s6","label":"0","stateB":"s6"},{"stateA":"s6","label":"1","stateB":"s7"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. Exercícios 6.c e 6.f

        ```json
        {"type":"NFA","nfa":{"transitions":{"start":{"":["s5","s0"]},"s0":{"0":["s1"],"1":["s0"]},"s1":{"0":["s1"],"1":["s2"]},"s2":{"0":["s3"],"1":["s0"]},"s4":{"0":["s4"],"1":["s4"]},"s5":{"0":["s5"],"1":["s6"]},"s6":{"0":["s5"],"1":["s7"]},"s7":{"0":["s8"],"1":["s7"]},"s8":{"0":["s8"],"1":["s8"]},"s3":{"0":["s1"],"1":["s4"]}},"startState":"start","acceptStates":["s5","s6","s7","s4"]},"states":{"start":{},"s5":{"isAccept":true,"top":465,"left":148,"displayId":"s5"},"s0":{"top":244,"left":159,"displayId":"s0"},"s1":{"top":245,"left":319,"displayId":"s1"},"s2":{"top":245,"left":489,"displayId":"s2"},"s3":{"top":245,"left":665,"displayId":"s3"},"s4":{"isAccept":true,"top":245,"left":839,"displayId":"s4"},"s6":{"isAccept":true,"top":467,"left":317,"displayId":"s6"},"s7":{"isAccept":true,"top":467,"left":491,"displayId":"s7"},"s8":{"top":468,"left":656,"displayId":"s8"}},"transitions":[{"stateA":"start","label":"ϵ","stateB":"s5"},{"stateA":"start","label":"ϵ","stateB":"s0"},{"stateA":"s0","label":"0","stateB":"s1"},{"stateA":"s0","label":"1","stateB":"s0"},{"stateA":"s1","label":"0","stateB":"s1"},{"stateA":"s1","label":"1","stateB":"s2"},{"stateA":"s2","label":"0","stateB":"s3"},{"stateA":"s2","label":"1","stateB":"s0"},{"stateA":"s4","label":"0","stateB":"s4"},{"stateA":"s4","label":"1","stateB":"s4"},{"stateA":"s5","label":"0","stateB":"s5"},{"stateA":"s5","label":"1","stateB":"s6"},{"stateA":"s6","label":"0","stateB":"s5"},{"stateA":"s6","label":"1","stateB":"s7"},{"stateA":"s7","label":"0","stateB":"s8"},{"stateA":"s7","label":"1","stateB":"s7"},{"stateA":"s8","label":"0","stateB":"s8"},{"stateA":"s8","label":"1","stateB":"s8"},{"stateA":"s3","label":"0","stateB":"s1"},{"stateA":"s3","label":"1","stateB":"s4"}],"bulkTests":{"accept":"","reject":""}}
        ```

9. Dê os diagramas de estado das AFNs que reconhecem a concatenação das linguagens descritas em:

    a. Exercícios 6.g e 6.i


21. Converta as seguintes AFNs para expressões regulares:

    a. ```json
    {"type":"NFA","nfa":{"transitions":{"start":{"a":["s0"],"b":["s0"]},"s0":{"a":["s0"],"b":["s1"]},"s1":{"a":["start"],"b":["s0"]}},"startState":"start","acceptStates":["s1","start"]},"states":{"start":{"isAccept":true},"s0":{"top":354,"left":224,"displayId":"s0"},"s1":{"isAccept":true,"top":506,"left":115,"displayId":"s1"}},"transitions":[{"stateA":"start","label":"a","stateB":"s0"},{"stateA":"start","label":"b","stateB":"s0"},{"stateA":"s0","label":"a","stateB":"s0"},{"stateA":"s0","label":"b","stateB":"s1"},{"stateA":"s1","label":"a","stateB":"start"},{"stateA":"s1","label":"b","stateB":"s0"}],"bulkTests":{"accept":"","reject":""}}```

        (e(a|b)(b(b|a(a|b))|a)*b(e|ae)|ee)

28. Converta as seguintes expressoes regulares para AFNs

    a. $a(abb)* \cup b$

        ```json
        {"type":"NFA","nfa":{"transitions":{"s0":{"a":["s1"]},"s2":{"b":["s3"]},"s4":{"b":["s5"]},"s1":{"":["s2"]},"s3":{"":["s4"]},"s6":{"":["s0"]},"s5":{"":["s0"]},"s7":{"a":["s8"]},"s8":{"":["s6"]},"s9":{"b":["s10"]},"start":{"":["s9","s7"]}},"startState":"start","acceptStates":["s5","s6","s10"]},"states":{"s0":{"top":103,"left":248,"displayId":"s0"},"s1":{"top":98,"left":423,"displayId":"s1"},"s2":{"top":101,"left":600,"displayId":"s2"},"s3":{"top":97,"left":792,"displayId":"s3"},"s4":{"top":95,"left":957,"displayId":"s4"},"s5":{"isAccept":true,"top":243,"left":1025,"displayId":"s5"},"s6":{"isAccept":true,"top":103,"left":67,"displayId":"s6"},"s7":{"top":247,"left":55,"displayId":"s7"},"s8":{"top":246,"left":238,"displayId":"s8"},"s9":{"top":460,"left":100,"displayId":"s9"},"s10":{"isAccept":true,"top":461,"left":275,"displayId":"s10"},"start":{}},"transitions":[{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s2","label":"b","stateB":"s3"},{"stateA":"s4","label":"b","stateB":"s5"},{"stateA":"s1","label":"ϵ","stateB":"s2"},{"stateA":"s3","label":"ϵ","stateB":"s4"},{"stateA":"s6","label":"ϵ","stateB":"s0"},{"stateA":"s5","label":"ϵ","stateB":"s0"},{"stateA":"s7","label":"a","stateB":"s8"},{"stateA":"s8","label":"ϵ","stateB":"s6"},{"stateA":"s9","label":"b","stateB":"s10"},{"stateA":"start","label":"ϵ","stateB":"s9"},{"stateA":"start","label":"ϵ","stateB":"s7"}],"bulkTests":{"accept":"","reject":""}}
        ```

    b. $a+ \cup (ab)+$

        ```json
        {"type":"NFA","nfa":{"transitions":{"s4":{"":["s3","s2"]},"s1":{"":["s2","s4"]},"s2":{"a":["s3"]},"s0":{"a":["s1"]},"s3":{"":["s4"]},"s5":{"a":["s6"]},"s7":{"b":["s8"]},"s6":{"":["s7"]},"s9":{"a":["s10"]},"s11":{"b":["s12"]},"s10":{"":["s11"]},"s12":{"":["s13"]},"s13":{"":["s9"]},"s8":{"":["s13"]},"start":{"":["s5","s0"]}},"startState":"start","acceptStates":["s4","s3","s12","s13"]},"states":{"s4":{"isAccept":true,"top":130,"left":489,"displayId":"s4"},"s3":{"isAccept":true,"top":103,"left":867,"displayId":"s3"},"s2":{"top":43,"left":591,"displayId":"s2"},"s1":{"top":72,"left":272,"displayId":"s1"},"s0":{"top":74,"left":117,"displayId":"s0"},"s5":{"top":509,"left":96,"displayId":"s5"},"s6":{"top":508,"left":231,"displayId":"s6"},"s7":{"top":507,"left":425,"displayId":"s7"},"s8":{"top":507,"left":564,"displayId":"s8"},"s9":{"top":463,"left":816,"displayId":"s9"},"s10":{"top":464,"left":961,"displayId":"s10"},"s11":{"top":460,"left":1136,"displayId":"s11"},"s12":{"isAccept":true,"top":499,"left":1278,"displayId":"s12"},"s13":{"isAccept":true,"top":556,"left":813,"displayId":"s13"},"start":{}},"transitions":[{"stateA":"s4","label":"ϵ","stateB":"s3"},{"stateA":"s4","label":"ϵ","stateB":"s2"},{"stateA":"s1","label":"ϵ","stateB":"s2"},{"stateA":"s1","label":"ϵ","stateB":"s4"},{"stateA":"s2","label":"a","stateB":"s3"},{"stateA":"s0","label":"a","stateB":"s1"},{"stateA":"s3","label":"ϵ","stateB":"s4"},{"stateA":"s5","label":"a","stateB":"s6"},{"stateA":"s7","label":"b","stateB":"s8"},{"stateA":"s6","label":"ϵ","stateB":"s7"},{"stateA":"s9","label":"a","stateB":"s10"},{"stateA":"s11","label":"b","stateB":"s12"},{"stateA":"s10","label":"ϵ","stateB":"s11"},{"stateA":"s12","label":"ϵ","stateB":"s13"},{"stateA":"s13","label":"ϵ","stateB":"s9"},{"stateA":"s8","label":"ϵ","stateB":"s13"},{"stateA":"start","label":"ϵ","stateB":"s5"},{"stateA":"start","label":"ϵ","stateB":"s0"}],"bulkTests":{"accept":"","reject":""}}```

# Exercícios extra

1. Prove que a linguagem $E = \{1^{k} : k \text{ é primo}\}$ não é regular.

    TODO