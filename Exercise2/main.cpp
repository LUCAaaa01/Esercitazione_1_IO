#include <fstream>
#include <iostream>

double maps(double a,double b,double c,double d,double x){
   return c+((x-a)*(d-c)/(b-a));
}



int main()
{
    std::ifstream file("./data.txt");//accedo al file
    if(file.fail())
    {
    	std::cerr <<"Non è stato possibile aprire il file"<<std::endl;
    	return 1;
    }
    
    
    double val, sum=0.0;
    int count=0;

    std::ofstream result("result.txt");
    if (result.fail())
    {
    	std::cerr<< "Errore nell'apertura del file di output"<<std::endl;
    	return 1;
    }

    result << "# N Mean\n"; //prima riga di codice del file di output

    while (file>>val){ //estrae un numero da data e lo memorizza in val
    	double mapped=maps(1,5,-1,2,val);
    	sum=sum+mapped; //aggiungiamo il valore mappato alla somma totale
    	count++; //all'inizio è 0
    	double mean=sum/count;//calcolo media progressiva

    	result << count << " " << mean << std::endl;
    	std::cout << "N: " << count << " Mean: " << mean << std::endl;
    }

    file.close();
    result.close();

    


    return 0;
}
