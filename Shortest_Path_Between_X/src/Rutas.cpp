#include "Core.hpp"
#include "Ride.hpp"

int usage(std::string exe)
{
	std::cout << "[USAGE]\t\t:./" << exe << " [Entry] [Amount] [Step1] [Step2] ..." << std::endl;
	std::cout << "[Entry]\t\t: name of the metro station from where MHB's journey starts." << std::endl;
	std::cout << "[Amount]\t: number of metro station MHB wants to stop at." << std::endl;
	std::cout << "[Step 1-2-...]\t: name of the metro stations MHB shall stop at." << std::endl
			  << std::endl;
	std::cout << "List of availlable stations : " << std::endl;
	std::cout << "LINEA 1 : San Pablo, Neptuno, Pajaritos, Las Rejas, Ecuador, San Alberto Hurtado, U. de Santiago, Estacion Central, U.L.A, Republica, "
			  << "Los Heroes, La Moneda, U.de Chile, Santa Lucia, U.Catolica, Baquedano, Salvador, Manuel Montt, Pedro de Valdivia, "
			  << "Los Leones, Tobalaba, El Golf, Alcantara, Escuela Militar, Manquehue, Hernando de Magallanes, Los Dominicos." << std::endl
			  << std::endl;

	std::cout << "LINEA 2 : Vespucio Norte, Zaparadores, Dorsal, Einstein, Cementerios, Cerro Blanco, Patronato, Puente Cal y Canto, Santa Ana, Los Heroes, Toesca, "
			  << "Parque O`Higgins, Rondizzoni, Franklin, El Llano, San Miguel, Lo Vial, Departemental, Ciudad del Nino, Lo Ovalle, El Parron, La Cisterna." << std::endl
			  << std::endl;

	std::cout << "LINEA 3 : Los Libertadores, Cardenal Caro, Vivaceta, Conchali, Plaza Chacabuco, Hospitales, Puente Cal y Canto, Plaza de Armas, U.de Chile, "
			  << "Parque Almagro, Matta, Irarrazaval, Monsenor Eyzaguirre, Nunoa, Chile Espana, Villa Frei, Plaza Engana, Fernando Castillo Velasco." << std::endl
			  << std::endl;

	std::cout << "LINEA 4 : Tobalaba, Cristobal Colon, Francisco Bilbao, Principe de Gales, Simon Bolivar, Plaza Engana, Los Orientales, Grecia, Los Presidentes, "
			  << "Quilin, Las Torres, Macul, Vicuna Mackenna, Vicente Valdes, Rojas Magallanes, Trinidad, San Jose de la Estrella, Los Quillayes, Elisa Correa, "
			  << "Hospital Sotero del Rio, Protectora de la Infancia, Las Mercedes, Plaza de Puente Alto." << std::endl
			  << std::endl;

	std::cout << "LINEA 4A : La Cisterna, San Ramon, Santa Rosa, La Granja, Santa Julia, Vinuca Mackenna." << std::endl
			  << std::endl;

	std::cout << "LINEA 5 : Plaza de Maipu, Santiago Bueras, Del Sol, Monte Tabor, Las Parcelas, Laguna Sur, Barrancas, Pudahuel, San Pablo, Lo Prado, Blanqueado, "
			  << "Gruta de Lourdes, Quinta Normal, Cumming, Santa Ana, Plaza de Armas, Bella Artes, Baquedano, Parque Bustamante, Santa Isabel, Irarrazaval, "
			  << "Nuble, Rodrigo de Araya, Carlos Valdovinos, Camino Agricola, San Joaquin, Pedrero, Mirador, Bellavista de la Florida, Vincente Valdes." << std::endl
			  << std::endl;

	std::cout << "LINEA 6 : Cerillos, Lo Valledor, Presidente Pedro Aguirre Cerda, Franklin, Bio Bio, Nuble, Estadio Nacional, Nunoa, Ines de Suarez, Los Loenes" << std::endl
			  << std::endl;

	return 0;
}

int error(int err)
{
	switch (err)
	{
	case 0:
		std::cerr << "Please execute this program with the following arguments : the metro station you're at, the number of stations to visit and their name." << std::endl;
		std::cerr << "For some insight on this program's usage, execute with the flag -h ." << std::endl;
		break;
	case 1:
		std::cerr << "One of the station names was incorrect." << std::endl;
		break;
	case 2:
		std::cerr << "Please enter the correct amount of stations." << std::endl;
		break;
	}
	return 84;
}

int main(int ac, char **av)
{
	Core *core;
	std::vector<std::string> stations;

	if (ac == 2)
		return usage(av[0]);
	if (ac < 3)
		return error(0);
	stations.push_back(av[1]);
	for (int i = 3; i < ac; i += 1)
		stations.push_back(av[i]);
	if (size_t(ac) != stations.size() + 2)
		return error(2);
	core = new Core(stations);
	if (core->start() == 1)
		return error(1);
	delete core;
	return 0;
}
/*
int main(int ac, char **av)
{
	Grapher *arquitect;
	PathFinder *guide;
	if (ac == 2)
		return usage(av[0]);
	if (ac != 3)
		return error(0);
	arquitect = new Grapher(av[1], av[2]);
	guide = new PathFinder();

	arquitect->buildGraph();
	if (arquitect->getWayIn() == nullptr || arquitect->getWayOut() == nullptr)
		return error(1);
	guide->doYouKnowDaWey(arquitect->getWayIn(), arquitect->getWayOut());
}*/