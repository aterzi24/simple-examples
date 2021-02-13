initials :: String -> String
initials fullName = [head firstName, '.', head lastName, '.']
  where nameList = words fullName -- splits on spaces
        firstName = head nameList
        lastName = last nameList
