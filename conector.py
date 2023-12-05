from ecdb_conector import Ecdb
Conexion1 = Ecdb("miempresa")
# Conexion1.update("clientes","cliente6",'{"nombre":"Luis","edad":"20"}')
# Conexion1.select(input("Que coleccion:"),input("Que documento:"),"")
# Conexion1.insert(input("Que coleccion:"),input("Que documento:"),input("Que contenido:"))
Conexion1.delete(input("Que coleccion:"),input("Que documento:"))