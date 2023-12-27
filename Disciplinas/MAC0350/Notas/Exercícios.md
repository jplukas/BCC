# Exercícios

## Review Questions

1. Define the following terms: data, database, DBMS, database system, database catalog, program-data independence, user view, DBA, end user, canned transaction, deductive database system, persistent object, meta-data, and transaction-processing application.
2. What four main types of actions involve databases? Briefly discuss each.
3. Discuss the main characteristics of the database approach and how it differs from traditional file systems.
4. What are the responsibilities of the DBA and the database designers?
5. What are the different types of database end users? Discuss the main activities of each.
6. Discuss the capabilities that should be provided by a DBMS.
7. Discuss the differences between database systems and information retrieval systems.

## Exercises

8. Identify some informal queries and update operations that you would expect to apply to the database shown in Figure 1.2.
9. What is the difference between controlled and uncontrolled redundancy?
Illustrate with examples.
10. Specify all the relationships among the records of the database shown in Figure 1.2.
11. Give some additional views that may be needed by other user groups for the database shown in Figure 1.2.
12. Cite some examples of integrity constraints that you think can apply to the database shown in Figure 1.2.
13. Give examples of systems in which it may make sense to use traditional file processing instead of a database approach.Selected Bibliography
14. Consider Figure 1.2.
    a. If the name of the ‘CS’ (Computer Science) Department changes to ‘CSSE’ (Computer Science and Software Engineering) Department and the corresponding prefix for the course number also changes, identify the columns in the database that would need to be updated.
    b. Can you restructure the columns in the COURSE , SECTION , and
    PREREQUISITE tables so that only one column will need to be updated?

## Álgebra Relacional

1. Considere as seguintes relações:

    1. Obtenha todos os ID_PACIENTE da relação PACIENTE dos pacientes que realizaram consulta com dentistas com as especialidade "ortodontia" ou "endodontia":

        $$
        \begin{aligned}
        \text{OrtOUEnd} \gets &\pi_{\text{ID_Dentista}}(\sigma_{
        (\text{Especialidade} = \text{"ortodontia"}) \textbf{OU}
        (\text{Especialidade} = \text{"endodontia"})}
        (\text{ESPECIALIDADE})
        )\\
        \text{Cons_OE} \gets &\pi_{\text{ID_Paciente}}(\text{CONSULTA} * \text{OrtOuEnd})\\
        &\pi_{\text{ID_Paciente}}(\text{PACIENTE} * \text{Cons_OE})\\
        \end{aligned}
        $$

    2. Obtenha todos os nomes dos PACIENTEs que realizaram consulta com dentistas que tenham, ao mesmo tempo, as especialidades "endodontia" e "ortodontia":

        $$
        \begin{aligned}
        \text{OrtEEnd} \gets &\pi_{\text{ID_Dentista}}(\sigma_{
        (\text{Especialidade} = \text{"ortodontia"}) \textbf{E}
        (\text{Especialidade} = \text{"endodontia"})}
        (\text{ESPECIALIDADE})
        )\\
        \text{Cons_OE} \gets &\pi_{\text{ID_Paciente}}(\text{CONSULTA} * \text{OrtEEnd})\\
        &\pi_{\text{Nome}}(\text{PACIENTE} * \text{Cons_OE})\\
        \end{aligned}
        $$

    3. Obtenha o nome de todos os dentistas que, na sua carreira, realizaram todos os procedimentos existentes:

        $$
        \begin{aligned}
        \text{ConsDent} \gets &\text{CONSULTA} * \text{DENTISTA}\\
        \text{ConsDentRel} \gets &\text{ConsDent} * \text{REL_PROC_CONSULTA}\\
        \text{ConsDentRelProc} \gets &\text{ConsDent} * \text{PROCEDIMENTO}\\
        \text{Res} \gets &\text{ConsDentRelProc} \div
        \pi_{\text{Cod_Procedimento}}(\text{PROCEDIMENTO})\\
        &\pi_{\text{Nome}}(\text{Res})
        \end{aligned}
        $$

    4. Obtenha o número de consultas de pacientes para cada dentista:

        $$
        \begin{aligned}
        \text{DentPac} \gets &\text{DENTISTA} \times \text{PACIENTE}\\
        \text{DentPacCons} \gets &\text{DentPac} * \text{CONSULTA}\\
        \text{Res} \gets
        & _{\text{ID_Dentista, ID_Paciente}}\mathfrak{I}_{\text{COUNT ID_Consulta}}
        (\text{DentPacCons})\\
        &\pi_{\text{ID_Dentista, ID_Paciente, COUNT_ID_Consulta}}(\text{Res})
        \end{aligned}
        $$

## Formas normais

1. Considere a relação $R = \{A, B, C, D, E, F, G, H, I, J\}$ e o conjunto de dependências funcionais $F = \{AB \to C, A \to DE, B \to F, F \to GH, D \to IJ\}$.

    1. Em qual forma normal está a relação $R$? Justifique.

        $$
        \begin{aligned}
        AB \to C\\
        A \to D\\
        A \to E\\
        A \to I\\
        A \to J\\
        B \to F\\
        B \to G\\
        B \to H\\
        F \to G\\
        F \to H\\
        D \to I\\
        D \to J\\
        \end{aligned}
        $$
        Note que $AB$ é a única chave candidata da relação.  
        Note que $D$ é um atributo não primo de $R$ e depende parcialmente de $AB$, que é uma chave de $R$. Portanto $R$ não está na segunda forma normal.  
        Como $I$ depende de $D$, e $D$ não é uma superchave de $R$, e $I$ é não primo em $R$, então $R$ não está na terceira forma normal, nem na forma normal de Boyce-Codd.  
        Então, podemos afirmar que a relação $R$ está somente na primeira forma normal.

    2. Considerando apenas as formas normais 1NF, 2NF, 3NF e BCNF, normalize a relação $R$ até a mais alta forma normal possível.

        1NF -> 2NF  
        Precisamos eliminar toda dependência parcial das chaves de $R$. Assim, as dependências funcionais $A \to D$, $A \to E$, $A \to I$, $A \to J$ precisam estar em uma relação e as dependências $B \to F$, $B \to G$ e $B \to H$ em outra. Assim, podemos ter:
        $$
        \begin{aligned}
        R_{1} = \{A, D, E, I, J\}
        \end{aligned}
        $$
        Com as dependências
        $$
        \begin{aligned}
        F_{R_{1}} = \{A \to \{DEIJ\}, D \to \{IJ\}\}
        \end{aligned}
        $$
        e
        $$
        \begin{aligned}
        R_{2} = \{B, F, G, H\}
        \end{aligned}
        $$
        Com as dependências
        $$
        \begin{aligned}
        F_{R_{2}} = \{B \to \{FGH\}, F \to \{GH\}\}
        \end{aligned}
        $$
        e
        $$
        \begin{aligned}
        R_{3} = \{A, B, C\}
        \end{aligned}
        $$
        Com uma única dependência, $AB \to C$.

        2NF -> 3NF
        Precisamos eliminar toda dependência transitiva de atributos não primos a subconjuntos que não sejam superchaves de $\{R_{1}, R_{2}, R_{3}\}$.

        Assim, para $R_{1}$, as dependências $A \to D$ e $D \to IJ$ precisam estar em relações diferentes. Então vamos decompor $R_{1}$ em $R_{1a}$ e $R_{1b}$:
        $$
        \begin{aligned}
        R_{1a} = \{A, D, E\}
        \end{aligned}
        $$
        Com uma única dependência, $A \to DE$, e
        $$
        \begin{aligned}
        R_{1b} = \{D, I, J\}
        \end{aligned}
        $$
        Com uma única dependência, $D \to IJ$.

        Para $R_{2}$, temos que as dependências $B \to F$ e $F \to GH$ precisam estar em relações diferentes. Então vamos decompor $R_{2}$ em $R_{2a}$ e $R_{2b}$:
        $$
        \begin{aligned}
        R_{2a} = \{B, F\}
        \end{aligned}
        $$
        Com uma única dependência, $B \to F$, e
        $$
        \begin{aligned}
        R_{2b} = \{F, G, H\}
        \end{aligned}
        $$
        Com uma única dependência, $F \to GH$.

        Note que $R_{3}$ já está na 3NF.  
        Assim, $\{R_{1a}, R_{1b}, R_{2a}, R_{2b}, R_{3}\}$ é uma decomposição de $R$ que está na 3NF. Além disso, note que não temos nenhuma dependência não-trivial $S \to X$, onde $X$ seja um atributo primo de alguma relação. Portanto essa decomposição está na BCNF.
