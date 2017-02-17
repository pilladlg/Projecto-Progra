
/*
   Equipo :
   Enrique Salvador Rodríguez Jiménez     A01282130
   Jorge de la Garza Limpabandhu          A01192919
   Rodolfo Ramírez Cedillo                A00820906
   Maria Fernanda Montemayor Agredano     A01282083
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
string title;
string place;
string editorial;
int year;

public:

// constructor vacio ( siempre se pone )
book()
{
        nameautor = "";
        middlename="";
        title="";
        place="";
        editorial="";
        year=0;
}

// constructor para asignar las variables con las que trabajaremos ( agreguen las que faltan )

book (string sname, string smiddle, int iyear, string stitle, string splace, string seditorial)
{
        nameautor = sname;
        middlename = smiddle;
        year = iyear;
        title = stitle;
        editorial = seditorial;
        place = splace;

}

//manera de escritura y orden de las referencias
// ustedes iran agregando las que falten ! NO OLVIDEN PONER EL ORDEN DE UNA REFERENCIA DE UN LIBRO
// Esto yo lo puse al azar , denle el orden que debe llevar

string toString()
{
        string tmp = " ";
        tmp = middlename + " , ";
        tmp = tmp + nameautor[0];
        tmp = tmp + ". (" + to_string(year) +"). " + title + ". " + place + ": " + editorial;
        // hasta ahorita imprimira esto --> [ "apellido", "primera letra del nombre". (año)]
        return tmp;

}
// para poder tomar el year siendo private
int getyear ()
{
        return year;

}

string getauthor()
{
        string fullname;
        fullname = nameautor + middlename;
        return fullname;

}

string gettitle() 
{
        return title;
}

string geteditorial()
{
        return editorial;
}

string getplace()
{
        return place;

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

void add(string sname, string smiddle, int iyear, string stitle, string splace, string seditorial)
{
        //poner las variables que faltan
        book milibro(sname, smiddle,iyear, stitle, splace, seditorial);

        // de esta manera guardamos las referencias que vayamos agregando
        elementos[counter++] = milibro;

}

//  imprimir todos : en esta funcion se veran todas las referencias que hemos puesto.
void imprimirtodos ()
{

        for (int i=0; i < counter; i++)
        {
                // se lee donde esta el libro y se imprime con funcion to String
                cout<<elementos[i].toString()<<endl;
        }

}
// ya hice la primer variable de año donde busca todos los libros que tengan el año que se escriba

void findyear(int year)
{

        for (int i=0; i < counter; i++)

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


void findauthor(string author, string middlename){

        string fullname;
        fullname = author + middlename;

        for (int i = 0; i < counter; i++) {

                if (elementos[i].getauthor() == fullname) {

                        cout << elementos[i].toString() << endl;

                }

        }


}

void printAll(){
        for (int i=0; i < counter; i++) {

                cout << elementos[i].toString() << endl;


        }
}



};

int main ()
{
        // se inicialisa la clase con la que se trabajara
        Refmanager manager;

        /* aqui se agregaran las variables para la referencia , recuerden modificar  el toString para poder poner la referencia en el ordeben que debe ir.
         */

        manager.add("George","Martin", 2015, "El caballero de los siete reinos", "Inglaterra", "George Allen & Unwin");
        manager.add("John", "Tolkien", 1954, "El señor de los anillos: La comunidad del anillo", "Inglaterra", "George Allen & Unwin");
        manager.add("John", "Tolkien", 1957, "El señor de los anillos: Las dos torres", "Inglaterra", "George Allen & Unwin");
        manager.add("Ayn", "Rand", 1957, "Atlas Shrugged", "Estados Unidos", "Random House");
        manager.add("Aldous", "Huxley", 1954, "The Doors of Perception", "Inglaterra", "Chatto & Windus");
        manager.add("Ta-Nehisi", "Coates", 2015, "Between the World and Me", "Estados Unidos", "Spiegel & Grau");
        manager.add("Markus", "Zusak", 2005, "The Book Thief", "Australia", "Picador");
        manager.add("David", "Foster Wallace", 1996, "Infinite Jest", "Estados Unidos", "Little, Brown");
        manager.add("Ed", "Catmull" , 2015, "Creatividad S.A", "Barcelona", "Penguin Random House");
        manager.add("J.K", "Rowling", 2016, "Harry Potter and the Cursed Child", "Virginia", "RR Donnelley & Sons");


        /* void para imprimir todos , si quieren que funcione quiten las "//" y ponganlas a las demas funciones que no quieran checar */
        
        cout << "Estas son todas las referencias que tenemos:" << endl;
        
        manager.imprimirtodos();

        /* esta es la funcion que llama para encontrar el año , solo se pone el año que deseas encontrar
         */
        cout << "Todos los libros de el 2015" << endl;
        
        manager.findyear(2015);
        
        cout << "Todos los libros de John Tolkien" << endl;
        
        manager.findauthor("John", "Tolkien");
        
        cout << "Impresion de todos los libros" << endl;
        
        manager.printAll();

        /*
           NOTAS
           muy bien , faltan poner variables como la editorial , nombre del libro etc ( las que pusimos en el UML) recuerden que si pondran mas tienen que cambiar el orden de poner la referencia en el toString para que se pueda imprimir la referencia con la estructura que debe. y creo que eso seria todo de mi parte , yo tambien lo completare por mi cuenta y cualquier duda preguntenme en whatsapp.
           atte: Enrique Salvador
         */


        return 0;
}