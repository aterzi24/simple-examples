ifact :: Integer -> Integer
ifact n = if n == 0 then 1 else n * ifact (n - 1) -- one line 

ifactChecked :: Integer -> Integer
ifactChecked n = if n < 0 -- broken over multiple lines
                    then error "factorial of a negative value"
                    else ifact n
