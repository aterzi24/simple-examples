data Adress = Info { -- fields are clarified with record syntax
    name :: String,
    addressLine :: String,
    city :: String,
    county :: String,
    zipCode :: String,
    email :: String,
    mobilePhone :: String
    } deriving Show
