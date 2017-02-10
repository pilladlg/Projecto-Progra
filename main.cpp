
/*
Equipo :
 
 Enrique Salvador Rodríguez Jiménez     A01282130
 
 



 PROYECTO PRIMER PARCIAL
 */
#include <iostream>
#include <string>
using namespace std;

/* empezamos poniendo la clase del libro porque es la que se va a manejar como base de impresion
TAMBIEN SE PONDRAN TODOS LOS [ getyear , getauthor , geteditorial ,etc] chequen las instrucciones del proyecto.
*/
class book
{
private:
    
    //inicialisamos las variables que se usaran ( ustedes pondran las que faltan)
    
    string nameautor;
    string middlename;
    int year;
    
public:
    
    // constructor vacio ( siempre se pone )
    book()
    {
        
    }
    
    // constructor para asignar las variables con las que trabajaremos ( agreguen las que faltan )
    
    book (string name , string middle , int iyear)
    {
        nameautor = name;
        middlename = middle;
        year = iyear;
        
    }
    
    //manera de escritura y orden de las referencias
    // ustedes iran agregando las que falten ! NO OLVIDEN PONER EL ORDEN DE UNA REFERENCIA DE UN LIBRO
    // Esto yo lo puse al azar , denle el orden que debe llevar
   
    string toString()
    {
        string tmp = " ";
        tmp = middlename + " , ";
        tmp = tmp + nameautor[0];
        tmp = tmp + ". (" + to_string(year) +") ";
         // hasta ahorita imprimira esto --> [ "apellido", "primera letra del nombre". (año)]
        return tmp ;
        
    }
    // para poder tomar el year siendo private
    int getyear ()
    {
        return year;
        
    }
    
    
    
};

//
class Refmanager
{
    //inicialisamos las variables que se usaran

private:
    int counter;
    // estos elementos son las referencias que guardara , en este momento solo estamos usando 2
    // las que ya tengo yo puestas
    
    book elementos [100];
    
public:
    // constructor vacio ( siempre se pone )

    Refmanager ()
    {
        
    }
    // funcion de agregar libros , tendran que poner las variables que faltan.
    
    void add(string sname , string smiddle , int iyear)
    {
        //poner las variables que faltan
        book milibro(sname , smiddle ,iyear);
        
        // de esta manera guardamos las referencias que vayamos agregando
        elementos[counter++] = milibro;
    
    }
    
    //  imprimir todos : en esta funcion se veran todas las referencias que hemos puesto.
    void imprimirtodos ()
    {
        
        for (int i=0 ; i < counter ; i++)
            {
                // se lee donde esta el libro y se imprime con funcion to String
                cout<<elementos[i].toString()<<endl;
            }
        
    }
    // ya hice la primer variable de año donde busca todos los libros que tengan el año que se escriba
    
    void findyear(int year)
    {
        
        for (int i=0 ; i < counter ; i++)
            
        {
            /* "i" siendo el libro en el cual estoy checando , se pondra un if para ir buscando el
            año que se requiere y se ira escribiendo los que encuentre con el toString*/
            
            // por el hecho de que getyear es una funcion se le ponen  ()
            
            if (elementos[i].getyear() == year)
                {
                    cout<<elementos[i].toString()<<endl;
                
                }
            
        }
        
    }
    
    
    
    
    
    
};

int main ()
{
    // se inicialisa la clase con la que se trabajara
    Refmanager manager;
    
    /* aqui se agregaran las variables para la referencia , recuerden modificar  el toString para poder poner la referencia en el ordeben que debe ir.
     */
    
    manager.add("Jose","Cruz" ,1987);
    manager.add("Manuel", "Salvador" , 1997);
    
    /* void para imprimir todos , si quieren que funcione quiten las "//" y ponganlas a las demas funciones que no quieran checar */
    
    // manager.imprimirtodos();
    
    /* esta es la funcion que llama para encontrar el año , solo se pone el año que deseas encontrar
     */
    manager.findyear(1987);
    
    /*
     NOTAS 
     
     muy bien , faltan poner variables como la editorial , nombre del libro etc ( las que pusimos en el UML) recuerden que si pondran mas tienen que cambiar el orden de poner la referencia en el toString para que se pueda imprimir la referencia con la estructura que debe. y creo que eso seria todo de mi parte , yo tambien lo completare por mi cuenta y cualquier duda preguntenme en whatsapp.
     atte: Enrique Salvador
     */
    
    
    return 0;
}
