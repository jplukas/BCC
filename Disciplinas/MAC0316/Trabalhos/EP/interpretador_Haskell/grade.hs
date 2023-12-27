{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module Grade where

import Interpreter (interp0)
import Types
import Control.Exception

displayErr :: SomeException -> String
displayErr = head . lines . displayException

test :: String -> String -> Maybe Value -> IO ()
test description code value = do
  result <- try $ evaluate (interp0 code) :: IO (Either SomeException Value)
  case (value, result) of
    (Just value, Right result) ->
      if result == value
        then putStrLn $
          "OK " ++ description
        else putStrLn $
          "FAILED " ++ description ++ ". " ++
          "Expected " ++ show value ++ ", " ++
          "got " ++ show (interp0 code)
    (Nothing, Left err) ->
      putStrLn $ "OK " ++ description ++ ", got exception " ++ displayErr err
    (Just _, Left err) ->
      putStrLn $ "FAILED " ++ description ++ ", got exception " ++ displayErr err
    (Nothing, Right result) ->
      putStrLn $ "FAILED " ++ description ++ ", expected exception, got result " ++ show result 

main :: IO ()
main = do
  putStrLn "Part 1:"
  test "Test 1" "(+ 10 (call (lambda x (head x)) (cons 15 16)))" (Just (NumV 25))
  test "Test 2" "(call (lambda x (+ x 5)) 8)" (Just (NumV 13))
  test "Test 3" "(call (lambda f (call f (~ 32))) (lambda x (- 200 x)))" (Just (NumV 232))
  test "Fatorial" "(letrec fatorial (lambda x (if x (* x (call fatorial (- x 1))) 1)) (call fatorial 5))" (Just (NumV 120))
  test "1-01" "(let x 1 x)" (Just (NumV 1))
  test "1-02" "(let x1 1 x1)" (Just (NumV 1))
  test "1-03" "(let 1x 1 1x)" Nothing
  test "1-04" "(let 1x 1 1)" Nothing
  test "1-05" "(let 1 1 1)" Nothing
  test "1-06" "(letrec x (lambda y (+ y 1)) 2)" (Just (NumV 2))
  test "1-07" "(letrec x (lambda 1y (+ 1 1)) 2)" Nothing
  test "1-08" "(letrec 1x (lambda y (+ y 1)) 2)" Nothing
  test "1-09" "(letrec 1 (lambda y (+ y 1)) 2)" Nothing
  test "1-10" "(letrec fatorial (lambda x (if x (* x (call fatorial (- x 1))) 1)) (call fatorial (let x 5 x)))" (Just (NumV 120))
  test "1-11" "(letrec fatorial (lambda x (if x (* x (call fatorial (- x 1))) 1)) (call fatorial (let x1 5 x1)))" (Just (NumV 120))
  test "1-12" "(letrec fatorial (lambda x (if x (* x (call fatorial (- x 1))) 1)) (call fatorial (let 123mksamdk 5 123mksamdk)))" Nothing
  test "1-13" "(letrec fatorial (lambda x (if x (* x (call fatorial (- x 1))) 1)) (call fatorial (let 1 5 1)))" Nothing
  test "1-14" "(let let 1 let)" Nothing
  test "1-15" "(let lambda 1 lambda)" Nothing
  test "1-16" "(let letrec 1 1)" Nothing
  test "1-17" "(let if 1 let)" Nothing
  test "1-18" "(let + 1 1)" Nothing
  test "1-19" "(let - 1 1)" Nothing
  test "1-20" "(let ~ 1 1)" Nothing
  test "1-21" "(let cons 1 1)" Nothing
  test "1-22" "(let head 1 1)" Nothing
  test "1-23" "(let tail 1 1)" Nothing
  test "1-24" "(let call 1 1)" Nothing
  test "1-25" "(let quote 1 1)" Nothing
  test "1-26" "(letrec let 1 let)" Nothing
  test "1-27" "(letrec if 1 1)" Nothing
  test "1-28" "(lambda if 1)" Nothing
  test "1-29" "(let case 1 1)" Nothing
  putStrLn ""

  putStrLn "Part 2:"
  test "2-01" "(case (+ 6 4) of (cons (* 5 2) 8) (cons (* (+ 1 3) (- 10 20)) (if 0 (+ 1 2) (+ 10 20))))" (Just (NumV (-40)))
  test "2-02" "(case 1 of (cons 1 2) (cons 3 4))" (Just (NumV 3))
  test "2-03" "(case 2 of (cons 1 2) (cons 3 4))" (Just (NumV 4))
  test "2-04" "(case 1 of (cons 1 (cons 2 3)) (cons 10 (cons 20 30)))" (Just (NumV 10))
  test "2-05" "(case 2 of (cons 1 (cons 2 3)) (cons 10 (cons 20 30)))" (Just (NumV 20))
  test "2-06" "(case 3 of (cons 1 (cons 2 3)) (cons 10 (cons 20 30)))" (Just (NumV 30))
  test "2-07" "(case 4 of (cons 1 (cons 2 (cons 3 4))) (cons 10 (cons 20 (cons 30 40))))" (Just (NumV 40))
  test "2-08" "(case 1 of (cons 1 2) (cons (let x 1 x) 4))" (Just (NumV 1))
  test "2-09" "(case 1 of (cons 1 2) (cons (let 1x 1 1x) 4))" Nothing
  test "2-10" "(case 1 of (cons 1 2) (cons (case 1 of (cons 1 2) (cons 5 6)) 4))" (Just (NumV 5))
  test "2-11" "(case 1 of (cons 1 2) (cons (case 2 of (cons 1 2) (cons 5 6)) 4))" (Just (NumV 6))
