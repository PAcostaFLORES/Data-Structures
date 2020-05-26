typedef struct NodoListaGen{
	int EsAtomo;
	union {
		Elem Atomo;
		struct NodoListaGen *ListaGenElem ;
	} dato;
	struct NodoListaGen *sig;
}*ListaGen;

ListaGen vaciag(){
	return NULL;
}

ListaGen consElem(Elem e, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	temp->EsAtomo = 1;
	temp->dato.Atomo = e;
	temp->sig = lg;
	return temp;
}


ListaGen consLista(ListaGen e, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	temp->EsAtomo = 0;
	temp->dato.ListaGenElem = e;
	temp->sig = lg;
	return temp;
}

int esvaciag(ListaGen lg){
	return lg==NULL;
}

Elem cabezaElem(ListaGen lg){
	return lg->dato.Atomo;
}

ListaGen cabezaLista(ListaGen lg){
	return lg->dato.ListaGenElem;
}

ListaGen restog(ListaGen lg){
	return lg->sig;
}

int EsAtomo(ListaGen lg){
	return lg->EsAtomo;
}

int NumElemListaGen(ListaGen lg){
	if(esvaciag(lg)){
		return 0;
	}else{
	return NumElemListaGen(restog(lg))+1;
	}
}

void ImpListaGen(ListaGen lg){
	if(!esvaciag(lg)){
		if(!EsAtomo(lg)){
			printf("[");
			ImpListaGen(cabezaLista(lg));
			printf("], ");
		} else {
			ImpElem(cabezaElem(lg));
			if(lg->sig != NULL)
				printf(", ");
		}
		ImpListaGen(restog(lg));	
	}
}
























