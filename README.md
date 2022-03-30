-project TrafficJam-

TrafficJam este o aplicatie care reproduce, generat aleator, diferite variante ale unei intersectii. Dupa aceasta urmeaza implementarea unei anumite oridini de catre utilizator pentru a si verifica cunostintele de legislatie. Daca raspunsul este corect, aplicatia genereaza inca o intersecetie si scorul creste, in caz contrar va aparea un ecran "GAME OVER" care ii va permite persoanei sa reincerce;


Tehnologii
C++
SFML

- Aplicatia este realizata strict in C++, utilizand Visual Studio
- Fiecare nivel este generat random, logica jocului fiind formata dintr-un algoritm ce poate genera situatii aleatorii de trafic, respectand toate regulile de circulatie
- Atat masinile cat si destinatia acestora este stocata in noduri pe un arbore orientat, ordinea prioritatii fiind generata de catre calculator prin algoritmi clasici de grafuri
- Programul are optinunea de a oferi prioritate unei strazi (unei muchii pe arbore), aceasta decizie fiind luata aleatoriu de catre program la generarea nivelului
- Pe harta pot fi generate intre 2 si 3 masini, tehnica de aplicare a algoritmului find una buttom-up, generand destinatia masinilor (ce reprezinta radacina arborelui), 
dupa care calculand ordinea prioritatii, atat in cazul lipsei dirijarii intersectiei (regula prioritatii de dreapta), cat si in cazul drumurilor cu prioritate.

- Pentru optimizare este implementat un sistem de preload al texturilor, fiind stocate intr-un std::map si apelate de fiecare clasa pentru generarea unui sprite
- Libraria Sfml a facut posibila generarea texturilor cat si a interfatei in sine.

