join :: String -> [String] -> String
join _ [] = "" -- empty list case, an empty string
join _ [str] = str -- single string case, only that string
join joinStr (firstStr:rest) = firstStr ++ joinStr ++ join joinStr rest
