import subprocess

class Ecdb:
    def __init__(self,basededatos):
        self.basededatos = basededatos
    def insert(self,coleccion,documento,contenido):
        self.operacion = "insert"
        self.coleccion = coleccion
        self.documento = documento
        self.contenido = contenido
        comando = '"C:\\Users\\PC-Nacho\\Documents\\GitHub\\Acceso a datos\\P5adEugenioCorral\\P3ecdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+' "'+self.contenido+'"'
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        if resultado.returncode == 0:
            return("ok")
        else:
            return("ko")
    def select(self,coleccion, documento, contenido):
        self.operacion = "select"
        self.coleccion = coleccion
        self.documento = documento
        self.contenido = contenido
        comando = '"C:\\Users\\PC-Nacho\\Documents\\GitHub\\Acceso a datos\\P5adEugenioCorral\\P3ecdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+' "'+self.contenido+'"'
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        print(resultado.stdout)
    def update(self,coleccion,documento_nuevo,contenido):
        self.operacion = "update"
        self.coleccion = coleccion
        self.documento_nuevo = documento_nuevo
        self.contenido = contenido
        comando = '"C:\\Users\\PC-Nacho\\Documents\\GitHub\\Acceso a datos\\P5adEugenioCorral\\P3ecdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento_nuevo+' "'+self.contenido+'"'
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        return(resultado)
    def delete(self,coleccion,documento):
        self.operacion = "delete"
        self.coleccion = coleccion
        self.documento = documento
        comando = '"C:\\Users\\PC-Nacho\\Documents\\GitHub\\Acceso a datos\\P5adEugenioCorral\\P3ecdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+''
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        return(resultado)
