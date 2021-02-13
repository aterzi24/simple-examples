initials :: String -> String
initials fullName = let nameList = words fullName -- splits on spaces
                        firstName = head nameList
                        lastName = last nameList
                     in [head firstName, '.', head lastName, '.']
