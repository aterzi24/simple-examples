-- import everything in the module
-- call like any other, e.g. sort [1, 5, 2]
import Data.List 

-- import only certain functions
import Data.List (sort, intercalate)

-- import everything except some functions
import Data.List hiding (sort)

-- import with the module name as prefix
-- e.g. Data.List.sort [1, 5, 2]
import qualified Data.List

-- import with whatever name you like
-- e.g. L.sort [1, 5, 2]
import qualified Data.List as L

-- can add (sort), hiding etc. in front
import qualified Data.List as L (sort, intercalate)
