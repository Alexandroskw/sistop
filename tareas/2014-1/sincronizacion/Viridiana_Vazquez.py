from threading import Semaphore, Thread
pasolibre = Semaphore(1)
se�al =semaphore(0)
torniquete = semaphore(1)
obstaculos = 0



def controlpuerta():
	se�al.acquire()
	abreOcierra()
	se�al.release()

def personas():

	torniquete.acquire()
	torniquete.release()
	pasolibre.acquire()
	obstaculos= obstaculos + 1
	cruzancalle()
	print "Personas atravesando la calle"
	
	obstaculos= obstaculos - 1

	if obstaculos == 0:
		se�al.release()
		pasolibre.release()

	
def carro():
	torniquete.acquire()
	pasolibre.acquire()
	entraOsale()
			
	pasolibre.release
	se�al.release
	
	
	torniquete.release()	