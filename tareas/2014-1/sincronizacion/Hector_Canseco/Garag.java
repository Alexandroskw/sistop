/* Bonilla Pastor Jos� Abraham y Canseco Hector
Sistemas operativos grupo:7  12/09/13
FI-UNAM

Programa que resuelve el problema:
Implementa hilos que controlen el siguiente sistema:

La cochera de casa es de port�n de apertura autom�tica
Una vez que la puerta comienza a abrir, tarda x tiempo en quedar abierta
Una vez que la puerta comienza a cerrar, tarda x tiempo en quedar cerrada
El coche toma cierto tiempo en entrar y salir. Particularmente si hay peatones o veh�culos cruzando frente a la puerta, tienes que esperar a que terminen de pasar.
La bater�a del control est� muy d�bil, por lo que cuando llegas tienes que pedirle a otro actor que abra y cierre por t�. Cuando te vas tambi�n necesitas esta ayuda.
Si el coche es golpeado por la puerta, se abolla y hay que llevarlo al taller. No quieres que eso ocurra.
Implementa un sistema que tome en cuenta las restricciones en cuesti�n.
*/


package garage1;



public class Garag {

	 public static void main(String[] args){
		 new Ayudante().start();
		 new Conductor().start();
		 
	 }
}
