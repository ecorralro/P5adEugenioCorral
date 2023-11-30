#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
    FILE *archivo;
    char *operacion = argv[1];
    char *basededatos = argv[2];
    char *coleccion = argv[3];
    /*
        Uso:
        jvdb.exe [operacion] [basededatos] [coleccion] [documento] [contenido]
    */
    if(strcmp(operacion,"select") == 0){
        char *documento = argv[4];
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");
        archivo = fopen(ruta,"r");
        printf("te doy datos:\n");
        char linea[1024];
        while(fgets(linea,sizeof(linea),archivo) != NULL){
            printf("Linea: %s",linea);
        }
        
    }else if(strcmp(operacion,"insert") == 0){
        char *documento = argv[4];
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");
        archivo = fopen(ruta,"w");
        char *texto = argv[5];
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
        
        printf("la ruta es: %s",ruta);
        
    }else if(strcmp(operacion,"create_collection") == 0){
        char rutacoleccion[100];
        strcpy(rutacoleccion,"db/");
        strcat(rutacoleccion,basededatos);
        strcat(rutacoleccion,"/");
        strcat(rutacoleccion,coleccion);
        printf(rutacoleccion);
        if(mkdir(rutacoleccion,0777) == 0){
            printf("ok");
        }else{
            printf("ko");
        }
    }else if(strcmp(operacion,"delete") == 0){
        char *documento = argv[4];
        char ruta[100];
        strcpy(ruta, "db/");
        strcat(ruta, basededatos);
        strcat(ruta, "/");
        strcat(ruta, coleccion);
        strcat(ruta, "/");
        strcat(ruta, documento);
        strcat(ruta, ".json");
        
        if(remove(ruta) == 0){
            printf("%s borrado con éxito",ruta);
        }else{
            printf("%s no se ha podido borrar",ruta);
        }
        
    }else if(strcmp(operacion,"update") == 0){
        char *documento_original = argv[4];
        char *documento_nuevo = argv[5];
        char ruta_original[100];
        char ruta_nuevo[100];
        strcpy(ruta_original, "db/");
        strcat(ruta_original, basededatos);
        strcat(ruta_original, "/");
        strcat(ruta_original, coleccion);
        strcat(ruta_original, "/");
        strcat(ruta_original, documento_original);
        strcat(ruta_original, ".json");
        
        strcpy(ruta_nuevo, "db/");
        strcat(ruta_nuevo, basededatos);
        strcat(ruta_nuevo, "/");
        strcat(ruta_nuevo, coleccion);
        strcat(ruta_nuevo, "/");
        strcat(ruta_nuevo, documento_nuevo);
        strcat(ruta_nuevo, ".json");
        
        if(rename(ruta_original,ruta_nuevo) == 0){
            printf("ok");
        }
        
    }else if(strcmp(operacion,"update_text") == 0){
        char *documento = argv[4];
        char ruta[100];
        strcpy(ruta, "db/");
        strcat(ruta, basededatos);
        strcat(ruta, "/");
        strcat(ruta, coleccion);
        strcat(ruta, "/");
        strcat(ruta, documento);
        strcat(ruta, ".json");
        
        archivo = fopen(ruta,"w");
        char *contenido_nuevo= argv[5];
        fputs(contenido_nuevo, archivo);
        
        fclose(archivo);
        
    }
    
    else{
        printf("operación no válida");
    }
    
    
    
    return 0;
}