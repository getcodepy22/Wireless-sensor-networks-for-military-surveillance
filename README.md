
# Topologie d'un Réseau de Capteurs Sans Fil pour Surveillance Militaire

## Description du Projet
Ce projet simule un réseau de capteurs sans fil (WSN – Wireless Sensor Network) destiné à la **surveillance militaire**. Chaque nœud du réseau collecte des informations environnementales, chiffre ces données pour garantir la **sécurité**, puis les transmet aux autres nœuds pour assurer une communication sécurisée dans le réseau.

### Objectifs
1. Collecter des informations de l'environnement (température, mouvement, présence, etc.).
2. Crypter les données collectées pour assurer la confidentialité.
3. Assurer la communication sécurisée entre les nœuds du réseau afin de transmettre les données cryptées à la station de base.

## Technologies Utilisées
- **OMNeT++** : simulateur de réseaux pour modéliser la topologie et les échanges entre nœuds.
- **C++** : pour le codage des fonctionnalités des nœuds (capteurs, cryptage et communication).
- **Bibliothèques de cryptographie** (optionnel) : pour sécuriser les données (ex. OpenSSL ou Crypto++).

## Architecture et Topologie
Le réseau est composé de plusieurs nœuds de capteurs disposés de manière stratégique sur le terrain militaire. Chaque nœud contient :

- **Module Capteur** : collecte les données environnementales.
- **Module de Cryptage** : chiffre les données avant transmission.
- **Module de Communication** : envoie et reçoit les données cryptées aux autres nœuds ou à la station de base.

**Topologie simulée** :
- Maillage complet (Mesh) pour la redondance et fiabilité.
- Possibilité de configurer d'autres topologies : en étoile (Star), en arbre (Tree), ou en cluster.

## Installation

### Prérequis
- OMNeT++ installé (version recommandée : 6.x ou supérieure)
- Compilateur C++ compatible
- Bibliothèque de cryptographie (OpenSSL ou Crypto++)

### Étapes
1. Cloner le dépôt :
   ```bash
   git clone https://github.com/getcodepy22/Wireless-sensor-networks-for-military-surveillance.git
   cd Wireless-sensor-networks-for-military-surveillance

2. Ouvrir le projet dans OMNeT++.

3. Compiler le projet :
    ```bash
       make
4. Lancer la simulation dans OMNeT++.

### Utilisation

1. Configurer les paramètres de simulation dans le fichier omnetpp.ini :

   - Nombre de nœuds
   - Topologie du réseau
   - Paramètres de cryptage

2.Exécuter la simulation.

3. Observer les échanges de données sécurisées entre les nœuds et la station de base via le ### visualiseur d’OMNeT++.

