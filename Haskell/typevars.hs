identity :: someType -> someType
identity x = x -- returns its argument

-- we let GHC infer the type of this function
itsgonnabeq x = 'q' -- returns 'q' no matter the argument 
