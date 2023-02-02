# push_swap

#### Introdution
Ce projet vous demande de trier des données dans une pile par ordre croissant, en utilisant un set d’instructions limité, et avec le moins d’opérations possibles. Pour le réussir, vous devrez manipuler différents algorithmes de tri et choisir la ou les solutions les plus appropriées pour un classement optimisé des données.
----
<details><summary> 

#### Règles du projets

</summary>
Écrire un programme en C nommé `push_swap` qui trie les données et affiche sur la sortie standard le plus petit programme, fait d’instructions du langage Push swap, permettant de trier les entiers passés en paramètres.

Le jeu est constitué de 2 piles nommées a et b.

- Au départ la pile a contient une quantité aléatoire de négatif et/ou des nombres positifs qui ne peuvent pas être dupliqués. **La pile b est vide.**
- **Le but du jeu est de trier les nombres de la pile a par ordre croissant**. Pour ce faire, vous disposez des instructions suivantes :
- `sa` (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
- `sb` (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
- `ss` : `sa` et `sb` en même temps.
- `pa` (push a) : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
- `pb` (push b) : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
- `ra` (rotate a) : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
- `rb` (rotate b) : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
- `rr` : `ra` et `rb` en même temps.
- `rra` (reverse rotate a) : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
- `rrb` (reverse rotate b) : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
- `rrr` : rra et rrb en même temps.</details>

---

<details><summary> 


## PLAN DE REFLEXION:

<details><summary> 

#### 1. Acceptation d'arguments

</summary> 

Les arguments peuvent être donné par deux manière:

1) Plusieurs chaînes de caractères:
```c
./push_swap 1 2 3
```
2) Une chaîne de caractère:

```c
./push_swap "1 2 3"
```

</details>

---


<details><summary> 

#### 2. Cas d'erreurs:

</summary> 

- Si l'argument n'est pas un `int`, c'est-à-dire si l'argument est plus grand que INT_MAX ou plus petit que INT_MIN;
- Si l'argument n'est pas un `int`, c'est-à-dire que c'est un `char` (p.ex.  `zero` n'est pas un `int` mais une chaîne de caractères);
- S'il y a des doublons dans les arguments.
- S'il y a un seul argument.

Par exemple les cas suivants doivent afficher le message d'erreur:

```c
./push_swap 1 2 3 -2147483648562244
./push_swap 1 2 3 214748364754123
./push_swap 1 2 3 four
./push_swap 1 2 3 3
./push_swap 1
```

##### Le message d'erreur est affiché à l'aide de la fonction 'write' ou `ft_putchar_fd` de la libtf afin de pouvoir indiquer un message d'erreur dans stderr.

```c
void error_msg_stop(void)
{
     write(2, "Error\n", 6);
     exit(1);
}
```

or

```c
void error_msg_stop(void)
{
     ft_putchar_fd("Error\n", 2);
     exit(1);
}

##### Problème: `atoi()` ne permet pas de gérer le dépassement de `INT_MIN` et `INT_MAX` de manière fiable. Une valeur qui dépassera les limites de `int` sera transformé en une valeur qui entre dans les limites. 

P.ex.
```
Input:

int a = 99999999999999999999999999999999999999;
printf("%d", a);

Output:
-1
```


#### Si aucun argument n’est spécifié, le programme ne doit rien afficher.

</details>

---
<details><summary> 

#### 3. Definition de structures

</summary> 

```c
typedef struct s_stack
{
     int              content;
     int              index;
     int              position;
     struct s_stack    *next;
}                     t_stack;
```

</details>

---

<details><summary> 

#### 4. Triage selon les cas

</summary> 

<details><summary> 

##### Cas 3 arguments

</summary> 

dsgdgsdg
dadqw

</details>

<details><summary> 

##### Cas 5 argument

</summary>

dasfasf

</details>

