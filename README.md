# Gestion d'utilisateur

Pour cet exo, on va créer un programme qui permet la gestion d'utilisateurs fictifs.

Cet exo est un **programme**, sous la forme d'un prompt infini, acceptant des commandes défini plus bas.
Exemple:
```text
./user_management
Welcome in user management system.
Please type a command.
>
```
Le programme attends des commandes.
Voici les consignes générales:
- Le prompt commencera par '> ' (chevron suivi d'un espace).
- **Les fonctions externes autorisées sont malloc, free, read, write**
- Les commandes seront valides avec autant d'espace possible:
```
> create user Paul
>          create      user    Paul
```
Sont toutes les deux des commandes valides qui font la même chose.
- PAS DE FUITE MEMOIRE
- Aucun bug sous aucun pretexte:

Liste non exhaustive de situation qui ne devront pas faire buger le programme:
```
- Une commande incomplète.
- Des espaces.
- Une commande qui n'existe pas.
- Des parametres en plus sur une commandes.
```
**Ne pas bugger ne veux pas dire que c'est valide: on veut de la gestion d'erreur avec des messages d'erreurs, et gros bonus si les messages d'erreurs sont sur la sortie d'erreur**

Les commandes seront les suivantes:
## exit
La commande `exit` permet de quitter le programme
Exemple:

```text
./user_management
Welcome in user management system.
Please type a command.
> exit
Bye!
```

## create
Permet de créer un utilisateur.
La commande create sera sous la forme:

`create <type user> <name>`

où <type user> pourra etre: "user" ou "admin".

Exemple:
```text
> create user Paul
user Paul succefully created!
> create admin Marius
admin Marius succefully created!
```
Un utilisateur devra obligatoirement avoir un nom et un type, sinon une erreur sera affichée et l'utilisateur ne sera pas créé.
  

## list
Permet de lister les utilisateurs créés.
Si list est utilisé seul, alors cela affiche tous les utilisateurs.
Si list est utilisé avec un type, cela affiche tous les utilisateurs de ce type.

Exemple:
```text
> create user Paul
user Paul succefully created!
> create admin Marius
admin Marius succefully created!
> list
user Paul
admin Marius
> list user
Paul
> list admin
Marius
```

## delete
Permet de supprimer un utilisateur grace a son nom.

Exemple:
```text
> create user Paul
user Paul succefully created!
> delete user Paul
user Paul succefully deleted!
```
Si delete est utilisé avec un type, alors cela supprime tous les utilisateurs après avoir demandé confirmation.
Exemple:
```text
> delete user
>> Are you sure you want to delete the 3 users? (y/n): y
All the users are deleted.
```

## history
Cette commande permet d'afficher l'historique des commandes précédentes.
  
Exemple:
```text
> create user Paul
user Paul succefully created!
> create admin Marius
admin Marius succefully created!
> list
user Paul 
admin Marius
> list user
Paul
> list admin
Marius
> history
list admin
list user
list
create admin Marius
create user Paul
```
L'historique est affiché du plus récent au plus ancien.

# Quelques pistes
 
Pour un prompt infini, on a besoin d'une boucle infini. Cependant on veux faire les choses proprements, et on n'utilisera pas la fonction `exit` qui n'est pas autorisées (cf plus haut fonctions autorisées).

Il y a deux approches possibles:
- while(1)/break: on utilise une boucle while(1) et la commande break quand on veux sortir de la boucle.
- while(is_running): on utilise une variable int `is_running` qui vaut 1, qu'on set a 0 quand on veux sortir.
J'ai une préférence pour la deuxième option.

Divise bien la tâche globale en plusieurs "tickets":
- je créé un système qui permet d'afficher mon prompt et qui attend du texte
- je créé une boucle infini
- je code les commandes
- etc

Je te conseille de mettre au propre ton code le plus souvent possible, de bien le documenter etc.
 

Pour la gestion de la mêmoire, tu devra surement utiliser plusieurs liste chainées (donc le nommage de chacune d'elle est important++), mais tu peux aussi utiliser des listes simples.

N'oublie pas l'existance des structures, elles te seront utiles.

Tu as toute la libertée sur la forme (les messages affiché, la manière dont s'est affiché etc) mais passe plus de temps sur le fond que sur la forme.
  
Je te conseil de créer un repo git dont la branche `main` sera toujours fonctionnelle. Ainsi, même si tu as pas fini l'exo, le jour de notre cours, si je clone la branche `main`, le code compile.

