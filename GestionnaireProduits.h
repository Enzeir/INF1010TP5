/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"

// TODO : Cr�er la classe GestionnaireProduits
class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap<int,Produit*>, AjouterProduit, SupprimerProduit>
{
	public:
		GestionnaireProduits();

		double obtenirTotalAPayer();



};
// TODO : M�thodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/