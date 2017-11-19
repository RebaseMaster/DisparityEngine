# Normes de programmation de Disparity Engine

Les normes de programmation suivantes ont été créé pour les besoins d'un moteur de jeu. Ce n'est
donc en aucun cas pour l'utilisateur final du SDK. La plupart des conventions sont prévues pour
permettre des *refactoring* rapides ainsi qu'une lecture et une compréhension optimisées du code.
Ce document n'est pas définitif et sera mis à jour.

### Sur cette page : 
   - Introduction
   - Copyright
   - Conventions de nommage
        - Exemples
   - Commentaires et documentation 
       - Exemples
   - Const correctness
   - C++11
   - Formattage du code
       - Accolades
       - If - Else
   - Namespace
   - Mémoire
   
#### Introduction
Pour des raisons de **maintenabilité**, l'accent devra être mis sur la **lisibilité** du code. Cela implique
qu'une documentation interne au moteur doit être mis en place et que **tout code non trivial** doit être
accompagné d'une court paragraphe le décrivant. De plus, un nommage rigoureux et une utilisation
judicieuse des mots clés du langage doivent être de mise. Lorsqu'une solution à un problème est trouvée
sur un site internet, il peut être bon de citer le lien dans la documentation du bloc de code.
    
#### Copyright Notice
Chaque fichier source ou d'en tête doit include la notice suivante :
    
    Copyright (C) 2017-2018 Disparity Engine

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    he Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
        
#### Conventions de nommage
 * Les membres de classe doivent être préfixés par **m_** : m_life
    * Cela permet de rapidement savoir dans un gros bloc de code qui appartient à la classe.
 * Les pointeurs doivent être préfixés par **p** : pPlayer
    * Les pointeurs étant non-sûr, il est préférable de toujours les expliciter clairement.
 * Les tableaux doivent être préfixés par **a** : std::vector < Foo > aFoo;
    * Dû à la grande variété des classes s'utilisant comme un tableau, il est préférable de les expliciter.
 * Toutes les fonctions ou méthodes commencent par une majuscule
 * Toutes les fonctions ou méthodes qui retourne un booléen doivent poser une question : **Is**Invincible ?
 * Les noms explicites sont meilleurs qu'une abréviation sauf si cela est évident
 * Les variables de boucle sont préfixés par un **n**
    * Cela rend plus visible ces variables surtout dans les grandes boucles
 * Les noms de classes abstraites sont préfixées d'un **A**
 * Les noms des interfaces sont préfixées d'un **I**
 * Les noms des templates sont préfixés d'un **T**
 * L'extension des fichiers d'en-tête C est .h
 * L'extension des fichiers d'en-tête C++ est .hpp
 * L'extension des fichiers inline est .inl
    
    #### Exemples
    ```cpp
    class Player
    {
    public:
        
        // Le pointer est préfixé d'un "p"
        explicit Player(const char * pName);     
    
    private:
        
        // Le membre de classe est préfixé par "m_"
        std::string m_playerName;
    };
    ```
    ```cpp
    // L'index de la boucle est préfixé par "n"
    // Le tableau est préfixé par "a"
    for(unsigned nNode = ...; nNode < ...; ++nNode)
    {
        // nNode porte maintenant deux informations visuelles
        // 1 - Il s'agit de l'index de boucle
        // 2 - On sait qu'elle sert principalement à accèder à des Nodes
        Foo(aNodes[nNode]);
    }
    ```
  
#### Commentaires et documentation
* Les commentaires doivent être clairs et utiles
* Les commentaires de code utilise //
* La documentation utilise ///
* Le générateur de documentation est Doxygen
    #### Exemples
    ```cpp
    /// \brief  Default entry point
    /// \param  argc The number of parameters
    /// \param  argv An array of C-String
    int main(int argc, char ** argv)
    {
        // Si on veut compter des arbres
        // Mauvais car illisible
        int c = 0;
        
        // Mauvais car trop générique
        int counter = 0;
       
        // Bon car explicite
        int treeCounter = 0;
        
        return 0;
    }
    ```
    
* Lorsqu'un mot clé tel que *static, virtual ou explicit* est utilisé, un commentaire doit être ajouté
dans l'implémentation pour jouer le rôle d'avertisseur :
    ```cpp
    // Déclaration
    virtual void Foo(void);
    
    // Implémentation
    /* virtual */ void Bar::Foo(void) { ... }
    ```
#### Const correctness
La *const-correctness* est obligatoire puisqu'elle rend le code plus sûr et plus clair.
  
 ```cpp
    // Returns a reference on a const object
    // The method is also marked as const 
    // since it doesn't modify the object
    const Foo & Foo::GetFoo(void) const;
 ``` 
#### C++ 11
Le moteur redéfinis tous les mots clés du C++ avec des macros pour s'assurer de pouvoir toujours
compiler selon le compilateur (Bien que C++11 soit maintenant presque partout). 
Ces macros doivent être utilisées à la place des mots clés bruts du C++.

* **nullptr** : Doit être utilisé à la place de NULL pour éviter l'ambiguité avec le pointeur et l'entier 0
* **auto** : Ne doit jamais être utilisé sauf avec les expressions lambda (PF)
* **override and final** : Utilisation fortement encouragée car cela augmente le nombre de 
  vérifications à la compilation
* **explicit** : Utilisation également conseillée pour les types complexes
* **constexpr** : Conseillé pour faire le plus de traitements possibles à la compilation

#### Formattage du code
- Accolades & If - Else
```cpp 
// Mauvais car en cas de rajout, il faut ajouter les accolades
if(x) Do();

// Mauvais car si on commente le Do(); il faut aussi commenter le if(x)
if(x)
    Do();

// Bon car les commentaires et le refacoring sont aisés
if(x)
{
    Do();
}
else
{
    DoOther();
}
```

#### Namespace
Les *namespaces* sont principalement utilisés pour éviter les conflits de nommage avec le reste du 
programme et les bibliothèques tiers. Le *namespace* du moteur est "disparity" :
```cpp
// Déclaration
namespace disparity
{
class Foo
{
public:
    explicit Foo(void);
};

}

// Usage
disparity::Foo f;
```
 A noter que l'utilisation de **using** est **déconseillée** pour ne pas annuler l'avantage des namespaces.
 
#### Mémoire
La mémoire est une ressource primordiale du moteur. C'est aussi facile d'en faire mauvais usage.
Voici quelques conseilles :
* Tout code qui alloue de la mémoire est responsable de sa libération. 
Si ce n'est pas possible cela doit être écrit **très explicitement** dans la documentation.
* Toujours veiller à ne pas copier les objets lorsque ce n'est pas nécessaire, privilégiez les références, 
ou les pointeurs si besoin.
* Il faut toujours penser à vérifier avec des asserts si les pointeurs ne sont pas nullptr.
* Ne jamais briser l'alignement de la mémoire
* Expliciter le padding des champs de bits
* Utiliser la move semantics (std::move) dès que possible
