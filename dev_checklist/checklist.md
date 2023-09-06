# checklist_user_management

## Environnement de développement :

- [x]  **Initialiser un dépôt git.**
    - [x]  Créer une branche `main`.
    - [x]  Créer une branche `development` pour le développement en cours.

## Structure de base :

- [x]  **Établir un squelette de programme principal (`main.c`).**
- [x]  **Configurer une boucle infinie pour le prompt** (utiliser `while(is_running)`).
- [x]  **Afficher le prompt '> '** à chaque tour de boucle.
- [x]  **Lire les entrées utilisateur.**

## Gestion des commandes :

### Commande "exit" :

- [x]  **Identifier la commande "exit".**
- [x]  **Afficher "Bye!".**
- [x]  **Terminer la boucle et quitter le programme.**

### Commande "create" :

- [x]  **Identifier la commande "create".**
- [x]  **Extraire le type d'utilisateur et le nom.**
- [x]  **Vérifier le type** (doit être "user" ou "admin").
- [x]  **Gérer les erreurs** :
    - [x]  Si le type ou le nom est manquant.
    - [x]  Si le type est invalide.
- [x]  **Si tout est valide, créer l'utilisateur et afficher le message de succès.**

### Commande "list" :

- [x]  **Identifier la commande "list".**
- [x]  **Si un type est spécifié, lister uniquement les utilisateurs de ce type.**
- [x]  **Sinon, lister tous les utilisateurs.**

### Commande "delete" :

- [x]  **Identifier la commande "delete".**
- [x]  **Si un nom est spécifié** :
    - [x]  Rechercher l'utilisateur.
    - [x]  Supprimer l'utilisateur.
    - [x]  Afficher le message de succès.
- [x]  **Si un type est spécifié** :
    - [x]  Demander une confirmation.
    - [x]  Si confirmé, supprimer tous les utilisateurs de ce type.

### Commande "history" :

- [x]  **Identifier la commande "history".**
- [x]  **Afficher l'historique des commandes**, du plus récent au plus ancien.

## Structures et gestion de la mémoire :

- [x]  **Définir une structure pour les utilisateurs.**
- [x]  **Définir une structure pour la liste chaînée des utilisateurs.**
- [x]  **Définir une structure pour la liste chaînée de l'historique des commandes.**
- [x]  **Implémenter des fonctions pour** :
    - [x]  Ajouter un utilisateur.
    - [x]  Supprimer un utilisateur.
    - [x]  Lister les utilisateurs.
    - [x]  Ajouter une commande à l'historique.
- [ ]  **Assurer qu'il n'y a pas de fuites mémoire** :
    - [ ]  Libérer la mémoire après la suppression d'un utilisateur.
    - [ ]  Libérer la mémoire après la fin du programme.

## Autres considérations :

- [x]  **Gérer les espaces superflus dans les commandes.**
- [ ]  **Assurer une bonne documentation du code.**
- [ ]  **Veiller à ce que le code soit propre et bien organisé.**
- [x]  **Tester régulièrement après chaque étape majeure.**