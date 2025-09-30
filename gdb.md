Parfait, on entre dans le **vrai débogage avec GDB** maintenant 🔍🚀
Voici **exactement comment faire** pour **lancer un programme et l’arrêter à certains endroits** (points d’arrêt) avec `gdb`.

---

## ✅ Étapes pour exécuter un programme et l’arrêter à certaines lignes

### 🧱 1. Compile ton programme avec l'option `-g` :

```bash
g++ -g monprogramme.cpp -o monprogramme
```

> `-g` ajoute les **symboles de débogage** (noms des variables, numéros de lignes, etc.)

---

### 🧰 2. Lance GDB sur l’exécutable :

```bash
gdb ./monprogramme
```

---

### 🧭 3. Dans GDB, place des **points d'arrêt** (breakpoints) :

```gdb
(gdb) break main
```

ou :

```gdb
(gdb) break 12          # ← ligne 12 du fichier courant
(gdb) break fichier.cpp:25  # ← ligne 25 dans un fichier précis
(gdb) break nom_de_fonction
```

---

### ▶️ 4. Lance l’exécution :

```gdb
(gdb) run
```

Ton programme s'arrête automatiquement **au premier breakpoint** rencontré.

---

### 🧭 5. Avance **ligne par ligne** :

| Commande GDB      | Effet                                                            |
| ----------------- | ---------------------------------------------------------------- |
| `next` ou `n`     | Exécute la prochaine ligne sans entrer dans les fonctions        |
| `step` ou `s`     | Exécute la prochaine ligne **et entre dans la fonction appelée** |
| `continue` ou `c` | Continue l'exécution jusqu'au **prochain breakpoint**            |
| `print var`       | Affiche la valeur de la variable `var`                           |
| `list`            | Affiche le code source autour de la ligne actuelle               |
| `info locals`     | Affiche les variables locales dans la fonction actuelle          |
| `delete`          | Supprime tous les breakpoints                                    |
| `quit`            | Quitte GDB                                                       |

---

### 🧪 Exemple complet (pas à pas) :

```bash
g++ -g test.cpp -o test
gdb ./test
```

```gdb
(gdb) break main         # arrêter au début du programme
(gdb) break 12           # s’arrêter à la ligne 12
(gdb) run                # commence l’exécution
(gdb) next               # exécute la ligne suivante
(gdb) print a            # affiche la valeur de a
(gdb) continue           # continue jusqu’au prochain point d’arrêt
(gdb) quit               # quitter
```

---

## 💡 Bonus : GDB scriptable

Tu peux créer un fichier `debug.gdb` avec tes commandes GDB :

```gdb
break main
break 12
run
next
print a
quit
```

Et tu peux lancer :

```bash
gdb -x debug.gdb ./test
```

---

