/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include <algorithm>
#include "Produit.h"
#include "Usager.h"
#include <utility>
#include <map>
#include <set>

using namespace std;
#pragma once

// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) : t_(t)
	{
	};

	bool operator()(pair<int, T*> objet)
	{
		return objet.second == t_;
	};
	
	bool operator()(Usager* objet)
	{
		return objet == t_;
	};
private:
	T* t_;
};


// TODO : Cr�er le FoncteurGenerateurId
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId() : id_(0)
	{};

	int operator()( void )
	{
		id_++;
		return id_;
	};

private:
	int id_;
};
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
*/

// TODO : Cr�er le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage)
	{};

	void operator()(pair<int, Produit*> t)
	{	
		double nouveauPrix;
		nouveauPrix = t.second->obtenirPrix() * pourcentage_ / 100;
		t.second->modifierPrix(nouveauPrix);
	};

private:
	int pourcentage_;
};
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/

// TODO : Cr�er le FoncteurIntervalle
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup)
	{};

	bool operator()(pair<int, Produit*> t)
	{
		bool intervalle = false;
		double prix = t.second->obtenirPrix();
		if (prix > borneInf_ && prix < borneSup_)
		{
			intervalle = true;
		}
		return intervalle;
	};


private:
	double borneInf_;
	double borneSup_;
};
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/

// TODO : Cr�er le Foncteur AjouterProduit
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*> &multimap) : multimap_(multimap)
	{};

	multimap<int, Produit*>& operator()(Produit* t)
	{
		multimap_.insert(make_pair(t->obtenirReference(), t));
		return multimap_;
	};

private:
	multimap<int, Produit*> &multimap_;
};
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/

// TODO : Cr�er le Foncteur SupprimerProduit
class SupprimerProduit
{
	SupprimerProduit(multimap<int, Produit*> multimap) : multimap_(multimap)
	{};

	multimap<int, Produit*>& operator()(Produit* produit)
	{
		multimap<int, Produit*>::iterator it = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(produit));
		multimap_.erase(it);
	};

private: 
	multimap<int, Produit*> &multimap_;

};
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/

//TODO : Cr�er le Foncteur AjouterUsager
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*> &set) : set_(set)
	{};

	set<Usager*> operator()(Usager* usager)
	{
		set_.insert(usager);
		return set_;
	};

private:
	set<Usager*> &set_;

};
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/


class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*> &set) : set_(set)
	{};
	
	set<Usager*> operator()(Usager* usager)
	{
		set<Usager*>::iterator it = find_if(set_.begin(), set_.end(), FoncteurEgal<Usager>(usager));
		set_.erase(it);
	};

private:
	set<Usager*>&set_;

};
