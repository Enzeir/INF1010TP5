/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include "Foncteur.h"
#pragma once

// TODO : Créer la classe GestionnaireGenerique
// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/
template<typename T, typename C, typename A, typename S>
class GestionnaireGenerique
{
	public:
		GestionnaireGenerique() {};

		void ajouter(T* objet) 
		{
			A ajoutFoncteur(conteneur_);
			ajoutFoncteur(objet);
		};
		void supprimer(T* objet) 
		{
			S suppFoncteur(conteneur_);
			suppFoncteur(objet);
		};

		C obtenirConteneur()
		{
			return conteneur_;
		};

		/*
		template<typename Predicate>
		void pourChaqueElement(Predicate predicate)
		{
			for_each(conteneur_.begin(), conteneur_.end(), predicate)
		};
		*/
	protected:
		C conteneur_;
};
