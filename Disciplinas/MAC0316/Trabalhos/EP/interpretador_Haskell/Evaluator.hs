module Evaluator where

import Types (Env, Binding (Binding), ExprC (..), Value (..))
import Env (extendEnv, lookupEnv)

-- | Avaliador.
--
-- Esta é a etapa do interpretador que executa o código desejado.
-- Uma vez que o código foi transformado em uma árvore com marcações
-- semânticas e os açúcares sintáticos foram removidos, podemos finalmente
-- realizar uma última travessia na árvore para interpretar o programa.
--
-- O resultado da avaliação será do tipo `Value`, que representa os
-- valores primitivos da linguagem. Veja a documentação de `Value`
-- no arquivos "Types.hs" para verificar quais são os valores primitivos.
--
-- A função `eval` também pede um _ambiente_ do tipo `Env`. O ambiente
-- é onde o interpretador irá buscar os valores utilizados no programa.
-- Por exemplo, caso o usuário de uma linguagem crie uma função através
-- do recurso `lambda`, a função `eval` irá buscar pelo valor do parâmetro
-- da função no ambiente. Para entender mais sobre o ambiente, veja o
-- módulo `Env.hs`.
--
-- >>> env = [Binding "x" (NumV 1)]
-- >>> code = (PlusC (IdC "x") (NumC 2)) 
-- >>> eval code env
-- NumV {numV = 3.0}
--
-- Para adicionar funcionalidade à linguagem, é necessário acrescentar
-- código a esta função (a não ser que a funcionalidade possa ser descrita
-- a partir de açúcares sintáticos).
eval :: ExprC -> Env -> Value
eval exp env = case exp of
  NumC  num   -> NumV num
  IdC   sym   -> lookupEnv sym env
  PlusC e1 e2 ->
    case (eval e1 env, eval e2 env) of 
      (NumV left, NumV right) -> NumV (left + right)
      (_, _)                  -> error "ERRO eval PlusC: um dos argumentos não é um número"
  MultC e1 e2 ->
    case (eval e1 env, eval e2 env) of
      (NumV left, NumV right) -> NumV (left * right)
      (_, _)                  -> error "ERRO eval MultC: um dos argumentos não é um número"
  LamC argName body -> ClosV argName body env
  AppC fun arg ->
    case closure of
      ClosV param body env ->
        eval body (extendEnv (Binding param argvalue) env)
      _ -> error ("ERRO eval AppC: AppC aplicado a algo que não é um fechamento: " ++ show closure)
    where
      closure  = eval fun env
      argvalue = eval arg env
  IfC cond b1 b2 ->
    case eval cond env of
      NumV num ->
        if num /= 0
          then eval b1 env
          else eval b2 env
      _ -> error "ERRO eval IfC: condição não é um número"
  ConsC e1 e2    -> ConsV (eval e1 env) (eval e2 env)
  HeadC e        ->
    case eval e env of
      ConsV e1 e2 -> e1
      _ -> error "ERRO eval HeadC: head aplicado a algo que não é ConsV"
  TailC e        ->
    case eval e env of
      ConsV e1 e2 -> e2
      _ -> error "ERRO eval TailC: tail aplicado a algo que não é ConsV"
  LetrecC name val body ->
    case closure of
      ClosV param oldBody oldEnv ->
        -- estamos colocando o fechamento em seu próprio ambiente!
        -- note que estamos usando o `let` recursivo do próprio Haskell para
        -- fazer esta implementação...
        -- uma implementação mais baixo-nível seria mais trabalhosa em Haskell
        let newClos = ClosV param oldBody (extendEnv (Binding name newClos) oldEnv)
         in eval body (Types.env newClos)
      _ -> error "ERRO eval LetrecC: valor declarado não é função"
    where
      closure = eval val env
  QuoteC sym -> SymV sym
  CaseC arithExp intList codeList -> 
    case (eval arithExp env, eval intList env, eval codeList env) of
      (NumV num, ConsV i1 i2, ConsV l1 l2) ->
        auxEval num i1 i2 l1 l2
      _ -> error "ERRO eval CaseC"


auxEval :: Double -> Value -> Value -> Value -> Value -> Value
auxEval num i1 i2 l1 l2 = 
  case i1 of
    NumV caso ->
      if num == caso
        then l1
        else case (i2, l2) of
          (NumV ultimoCaso, _) -> 
            if num == ultimoCaso
              then l2
              else error "ERRO eval CaseC: no match 1"
          (ConsV int1 int2, ConsV code1 code2) ->
            auxEval num int1 int2 code1 code2
          _ -> error "ERRO eval CaseC: no match 2"
    _ -> error "ERRO eval CaseC: no match 3"