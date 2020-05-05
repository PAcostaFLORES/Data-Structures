//define un nodo
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
	} *Lista;
	
//Crea una lista vacia
Lista vacia(){
	return NULL;
	}

//construye una lista, con un elemnto e y una lista l
Lista cons(Elem e, Lista l){
	Lista t=(Lista)malloc(sizeof(struct Nodo));
	t->dato=e;
	t->sig=l;
	return t;
	}

//verifica que una lista sea vacia
int esvacia(Lista l){
	return l==NULL;
	}

//Regresa la cabeza de la lista
Elem cabeza(Lista l){
	return l->dato;
	}

//Regresa el resto de la lista
Lista resto(Lista(l)){
	return l->sig;
	}

//Numero de elementos de la lista
int NumElemLista(Lista l){
	if(esvacia(l)) 
		return 0;
	else
		return 1+NumElemLista(resto(l));
	}

//Imprime la lista
void ImpLista(Lista l){
	if(!esvacia(l)){
		ImpElem(cabeza(l));
		ImpLista(resto(l));
		}
	}

//Pega l1 en l2
Lista PegaListas(Lista l1,Lista l2){
	if (esvacia (l1))	
		return l2;
	else 
		return cons(cabeza(l1), PegaListas(resto(l1),l2));
	}

//Invierte una lista
Lista InvLista(Lista(l)){
	if (esvacia(l))
		return l;
	else {
		InvLista(resto(l));
		return PegaListas(InvLista(resto(l)),cons(cabeza(l),vacia()));
		}
	}

//Insertar un elemento en una lista ordenada
Lista InsOrd(Elem e, Lista l){
	if(esvacia(l))
		return cons(e,l);
	else if (EsMenor(e,cabeza(l)))
		return cons(e,l);
		else 
			return cons(cabeza(l),InsOrd(e,resto(l)));
	}

//Ordena una lista
Lista OrdenaLista(Lista l){
	if (esvacia(l))
		return l;
	else
		return InsOrd(cabeza(l), OrdenaLista(resto(l)));
	}

//Verifica que se repíta un elemento
int ExistElem(Elem e, Lista l) {
	if(esvacia(l))
		return 0;
	else if (EsIgual(e,cabeza(l)))
		return 1;
	else 
		return ExistElem(e, resto(l));	
	}

//Verifica que dos listas sean iguales 
int SonIguales(Lista l1, Lista l2){
	if (esvacia(l1)&&esvacia(l2)){
		return 1;
	}
	else if (esvacia(l1)||esvacia(l2))
		return 0;

	else if(EsIgual(cabeza(l1),cabeza(l2))){
		return SonIguales(resto(l1),resto(l2));
	}
	else 
		return 0;
	}

//Verifica que una lista sea palindroma
int EsPalindroma(Lista l){ 
	return SonIguales(l, InvLista(l));
	}
	
//Crea una lista con la mitad inferior de una lista
Lista MitadInferior(Lista l){
	Lista li = vacia();
	int n, tope = NumElemLista(l)/2;
	
	for(n = 0; n<tope; n+=1){
		li = cons(cabeza(l), li);
		l = resto(l);
	}
	return InvLista(li);
}

//Crea una lista con la mitad superior de una lista
Lista MitadSuperior(Lista l){
	int n, tope = NumElemLista(l)/2;
	
	for(n = 0; n<tope; n+=1){
		l = resto(l);
	}
	return l;
}
	
//Mezcla y ordena dos listas ya ordenadas
Lista Mezclar(Lista li, Lista ls){
	int n;
	Lista lo = vacia();
	while(!esvacia(li) || !esvacia(ls)){
		if(li==NULL){
			lo = cons(cabeza(ls), lo);
			ls = resto(ls);
		}
		else if(ls==NULL){
			lo =cons(cabeza(li), lo);
			li = resto(li);
		}
		else if(EsMenor(cabeza(li), cabeza(ls))){
			lo = cons(cabeza(li), lo);
			li = resto(li);
		}else {
			lo = cons(cabeza(ls), lo);
			ls = resto(ls);
		}
	}
	return InvLista(lo);
}
//Regresa una lista de la mezcla de dos
Lista OrdenaListaMezcla(Lista l){
	return Mezclar(OrdenaLista(MitadInferior(l)), OrdenaLista(MitadSuperior(l)));
}

	
	
	
	
