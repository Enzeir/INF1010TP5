/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

GestionnaireUsagers::GestionnaireUsagers()
{
}

void GestionnaireUsagers::afficherProfils() const
{
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (montant > produit->obtenirPrix())
	{
		produit->mettreAJourEnchere(client, montant);
	}
}
