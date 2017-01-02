# os_process_management



PROCESSUS
|__nom
|__duree
|__priorite
|__sequence d'exécutions


Gantt
|__qt widget pour tableau
|__donnees


Ordonnanceur
|__nom (méthode)
|__gantt
|__qt widget pour dessiner
|__processus

-- Ordonnanceur::init() : affiche les données reçues en arguments
(quel processus, temps d'exécution)

-- Ordonnanceur::showGantt()

-- Ordonnanceur::execute()

-- Ordonnanceur::showProcessStats()

-- Ordonnanceur::doFIFO()
-- Ordonnanceur::doTourniquet()
-- Ordonnanceur::doPriorTourniquet()
-- Ordonnanceur::doPCTE()
-- Ordonnanceur::doPCTER()


main : 
	Process a = new Process(...with properties.p..)
	Process b = new Process(...with properties...)
	Process c = new Process(...with properties...)
	Process d = new Process(...with properties...)
	Ordonnanceur ord = new Ordonnanceur("FIFO");
	ord.addProcess(t0, a);
	ord.addProcess(t1, b);
	ord.addProcess(t2, c);
	ord.addProcess(t3, d);
	...
	ord.init()	// affiche les détails reçus en paramètres
	ord.execute() // fait l'ordonnancement en tant que tel
	ord.showGantt()
	ord.showProcessStats()


## Run Example explained
- Demander à l'utilisateur de creer un Ordonnanceur
- Ajouter des processus à l'ordonnanceur
|__ soit à partir d'un fichier texte préciser à partir d'un file chooser
|__ soit en entrant les détails des processus un à un
- Choisir la méthode d'ordonnancement
- Lancer l'exécution
Ce dernier va générer un premier tableau résumant les informations reçues
en paramètre par le programme.
- Simuler un temps d'exécution avec la fonction sleep
- Option avancer jusqu'à la fin
- Affichage du diagramme de Gantt
- Affichage du sommaire d'exécution (statistiques) dans un tabwidget: 
	* un graphe montrant l'activité du processus
	* un graphe complet montrant tous les processus avec leurs trois états
Ces points (*) représentent des tabs (onglets).


## Run example source
Le reste de l'exécution est laissé aux volonté de l'utilisateur

PROCESSUS
|__nom
|__duree
|__priorite
|__sequence d'exécutions


Gantt
|__qt widget pour tableau
|__donnees


Ordonnanceur
|__nom (méthode)
|__gantt
|__qt widget pour dessiner
|__processus

-- Ordonnanceur::init() : affiche les données reçues en arguments
(quel processus, temps d'exécution)

-- Ordonnanceur::showGantt()

-- Ordonnanceur::execute()

-- Ordonnanceur::showProcessStats()

-- Ordonnanceur::doFIFO()
-- Ordonnanceur::doTourniquet()
-- Ordonnanceur::doPriorTourniquet()
-- Ordonnanceur::doPCTE()
-- Ordonnanceur::doPCTER()


main : 
	Process a = new Process(...with properties.p..)
	Process b = new Process(...with properties...)
	Process c = new Process(...with properties...)
	Process d = new Process(...with properties...)
	Ordonnanceur ord = new Ordonnanceur("FIFO");
	ord.addProcess(t0, a);
	ord.addProcess(t1, b);
	ord.addProcess(t2, c);
	ord.addProcess(t3, d);
	...
	ord.init()	// affiche les détails reçus en paramètres
	ord.execute() // fait l'ordonnancement en tant que tel
	ord.showGantt()
	ord.showProcessStats()



