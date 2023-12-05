from ecdb_conector import Ecdb
Conexion1 = Ecdb("miempresa")
while True:
    print("\nMenu:")
    print("1. Update")
    print("2. Select")
    print("3. Insert")
    print("4. Delete")
    print("0. Salir")

    opcion = input("Seleccione una opción (0-4): ")

    if opcion == "0":
        break
    elif opcion == "1":
        Conexion1.update(input("Que coleccion:"), input("Que documento:"), input("Que documento nuevo:"))
    elif opcion == "2":
        Conexion1.select(input("Que coleccion:"), input("Que documento:"), "")
    elif opcion == "3":
        Conexion1.insert(input("Que coleccion:"), input("Que documento:"), input("Que contenido:"))
    elif opcion == "4":
        Conexion1.delete(input("Que coleccion:"), input("Que documento:"))
    else:
        print("Opción no válida. Intente nuevamente.")