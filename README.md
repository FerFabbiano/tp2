# Taller de Programación - TP2

**Alumno**: Fernando Fabbiano

**Padrón**: 102464

**URL**: https://github.com/FerFabbiano/tp2

**Versionado Semántico**: https://semver.org/lang/es/

1. **Descripción del trabajo**

	Para la resolución del trabajo, resolví utilizar una cola bloqueante por cada tipo de recolector, y un único inventario general. 

	Para este útlimo, utilicé el objeto map de la Standard Library, con claves de tipo char, y valores de tipo int, simbolizando cada par el tipo de recurso y la cantidad disponible del mismo. 
	
	En el caso de los colas bloqueantes, tuve que analizar dos casos a la hora de quitar un elemento: la cola esta vacía, pero no cerrada, en cuyo caso debo esperar hasta que se le agregue un elemento a la cola; la cola esta vacía y cerrada, es decir, no se van a colocar mas elementos en la cola y no hay mas nada por quitar. Cuando la cola está cerrada, es decir, los recolectores ya no van a poder sacar mas nada de ella (dado que no hay mas recursos por repartir desde el mapa de recursos), cada uno debe encargarse de notificar al inventario que no va a proporcionarle mas materiales. En el momento en que todos los threads de recolectores dieron ese aviso, quiere decir que se cerro el inventario, es decir, ningun recolector va a depositar mas recursos en él. 
	
	Análogamente a lo que pasa con las colas bloqueantes, cuando un productor debe consumir los materiales del inventario general, me encuentro ante dos escenarios posibles: el inventario no posee los recursos que necesito como productor para trabajar, pero el inventario no está cerrado, en cuyo caso el productor debe quedar a la espera de una nueva notificación que indique que hay nuevos recursos disponibles; el inventario no posee los recursos necesarios y además se encuentra en un estado cerrado, luego lo único que le queda a los productores es consumir lo que esta disponible en ese momento en el inventario, y si no hay recursos necesarios para generar los puntos de beneficio, no deben volver más a un estado de espera.
	
	Para resolver el item anterior, en un principio, quisé cerrar el inventario al mismo tiempo que cerraba las colas bloqueantes luego de terminar de repartir los recursos. Es decir, el inventario se cerraba cuando las tres colas estaban cerradas. Esto es un error, ya que es posible que cuando cierro las colas bloqueantes, aun exista algun recolector que este añadiendo el material que quitó de dicha cola al inventario, y si cierro este último, ese recurso se perdería y no sería tenido en cuenta para generar los puntos de beneficio. Es por eso que resolví que la forma de solucionar esto era teniendo en cuenta que, para considerar al inventario cerrado, debía tener el "ok" de todos los threads recolectores. 
	
	Para simplificar, cuando un recolector saca un recurso de alguna de las colas bloqueantes, y lo añade al inventario, notificó a todos los productores que estén a la espera de consumirlos para generar los puntos de beneficio. De esta forma, cumpló la indicación de que los productores deben ser notificados tan pronto como haya recursos disponibles para consumir. 

	Me gustaría destacar que en el Recurso Compartido Inventory, la critical section que encontré fue cuando un productor quiere transformar los recursos en puntos. Para conseguir esto, debe consultar el stock, y en caso de existir los materiales solicitados, removerlos del inventario para luego sumar los puntos de beneficio correspondientes. Todo esto, debe suceder con el mutex tomado, ya que sino podría ocurrir que consulte el stock, reciba el "ok" para retirar los recursos y transformarlos en puntos, pero que cuando vaya a descontar los materiales, resulte que otro productor, que necesitaba también esos materiales, ya los quitó y por ende el inventario podría quedar en negativo y se estarían consumiendo mas recursos de los que realmente hay. 

	Del mismo modo funciona el Recurso Compartido resultProtected, el que posee una función que va incrementando un contador de puntos cada vez que es invocado por algún productor. Esto debe suceder también con el mutex de dicho recurso tomado, para evitar que dos productores quieran sumar a la vez, y que el resultado final de puntos se vea afectado por alguna race condition que haya provocado un resultado erróneo. 

<p align="center">
<img src="https://user-images.githubusercontent.com/38590805/82076622-83ef5000-96b4-11ea-8939-a6c5d10534b5.png" 			width=900 height=300>

