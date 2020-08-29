## DataManager hints.

DataManager is a global unique object.  
If you want to keep ptr on it in your object you need to keep it like `general` ptr - without clean up or just copy it.