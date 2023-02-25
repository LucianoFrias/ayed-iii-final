#include <iostream>
#include <queue>


class Paciente
{
    private:
    std::string name;
    int dni;

    public:
    Paciente(std::string name, int dni)
    {
        this->name = name;
        this->dni = dni;
    }

    std::string getNombre()
    {
        return name;
    }

    int getDni()
    {
        return dni;
    }
};


class Atencion
{
    private:
    std::string fecha;
    std::string especialidad;
    std::string doctor;
    std::string diagnostico;

    public:
    Atencion(std::string fecha, 
    std::string especialidad, 
    std::string doctor, 
    std::string diagnostico)
    {
        this->fecha = fecha;
        this->especialidad = especialidad;
        this->doctor = doctor;
        this->diagnostico = diagnostico;
    }

    std::string getFecha(){
            return this->fecha;
        }

    std::string getEspecialidad(){
            return this->especialidad;
        }

    std::string getDoctor(){
            return this->doctor;
        }

    std::string getDiagnostico(){
            return this->diagnostico;
        }


};


class Ficha
{
    private:
    Paciente* paciente;
    std::queue<Atencion*> atenciones;

    public:
    Ficha(Paciente* paciente)
    {
        this->paciente = paciente;
    }

    Paciente* getPaciente()
    {
        return paciente;
    }

    std::queue<Atencion*> getAtenciones()
    {
        return atenciones;
    }

    void addAtencion(Atencion* atencion)
    {
        this->atenciones.push(atencion);
    }

    void toString(){
            std::cout << "Ficha de: " << paciente->getNombre() << " (D.N.I: " << paciente->getDni() << ")" << std::endl;
            std::cout <<  "Lista de atenciones:" << std::endl;
            
            std::queue<Atencion*> g = this->atenciones;
            while (!g.empty()) {
                std::cout << "Fecha: " << g.front()->getFecha() << " || Especialidad: " << g.front()->getEspecialidad() << " || Doctor: " << g.front()->getDoctor() << " || Diagnostico: " << g.front()->getDiagnostico() << std::endl;
                g.pop();
            }

            std::cout << std::endl;
        }




};

class GestorFichas
{
    private:
    std::queue<Ficha*> fichas;

    public:
    GestorFichas()
    {

    }

    std::queue<Ficha*> getFichas()
    {
        return fichas;
    }

    void atender(){
            if (fichas.empty())
            {
                std::cout << "La lista de fichas esta vacia!" << std::endl;
                return;
            }


            std::cout << "Atendiendo paciente:" << std::endl;
            fichas.front()->toString();
            fichas.pop();
        }

    Ficha* createFicha(Paciente* paciente)
    {
        Ficha* ficha = new Ficha(paciente);
        fichas.push(ficha);

        return ficha;
    }

    Ficha* findFicha(int dni)
    {
        Ficha* ficha = NULL;

        std::queue<Ficha*> fichasAux = fichas;

        while(!fichasAux.empty())
        {
           if (fichasAux.front()->getPaciente()->getDni() == dni)
            {
                ficha = fichasAux.front();
                return ficha;
            }

            fichasAux.pop();
        }
        
        return ficha;
    }

    void cargarFicha(){
            // selecciono el paciente a cargar ficha
            // lee de la base de datos los datos de la ficha
        }

    void mostrarListado(){
            std::queue<Ficha*> fichasAux = fichas;

            while (!fichasAux.empty())
            {
                fichasAux.front()->toString();
                fichasAux.pop();
            }
        }
};    
    

int main()
{

    Paciente* paciente1 = new Paciente("Luciano", 22446688);
    Paciente* paciente2 = new Paciente("Homero", 12364400);

    Atencion* atencion1 = new Atencion("1", "2", "3", "4");
    Atencion* atencion2 = new Atencion("5", "6", "7", "8");

    GestorFichas* gf = new GestorFichas();

    gf->createFicha(paciente1);
    gf->createFicha(paciente2);

    gf->findFicha(22446688)->addAtencion(atencion1);
    gf->findFicha(22446688)->addAtencion(atencion2);
    gf->findFicha(12364400)->addAtencion(atencion2);


    gf->mostrarListado();
    
    gf->atender();

    gf->atender();

    gf->atender();

    gf->mostrarListado();



    return 0;
}

