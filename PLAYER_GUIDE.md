# ToME 2 Player Guide

Tales of Middle-earth (ToME) is a roguelike RPG set in Tolkien's world of Arda. You explore
procedurally generated dungeons, fight monsters, collect items, gain experience, and develop
your character through a flexible skill system. Death is permanent — choose carefully.

## Getting Started

### Building and Running

```sh
cmake -B build
cmake --build build
```

Run from the **repository root** (the game must find `./lib`):

```sh
./build/tome-gcu    # terminal/curses frontend
./build/tome-x11    # X11 graphical frontend
```

### Character Creation

When you start a new game you will:

1. Choose a **module** (ToME is the standard campaign)
2. Select a **race** — each has stat bonuses and restrictions (Human, Elf, Dwarf, Hobbit, Orc, Troll, and many more)
3. Select a **race modifier** — a sub-race that further specialises your character
4. Select a **class** — determines your starting skills and playstyle
5. Choose a **god** (optional) — grants prayers and divine powers
6. Name your character

Your character has six primary stats: **STR, INT, WIS, DEX, CON, CHR**. Stats range from 3
to 18/220 ("18/***" is the cap). Secondary attributes (height, weight, social class) provide
flavour and minor effects.

---

## The World

### The Town

You begin in town. Shops sell supplies, weapons, armour, and magical items in exchange for
gold. Key shops:

| Symbol | Shop |
|--------|------|
| `1` | General Store |
| `2` | Armoury |
| `3` | Weapon Smith |
| `4` | Temple |
| `5` | Alchemy Shop |
| `6` | Magic Shop |
| `7` | Black Market |
| `8` | Your Home (stores items between sessions) |
| `9` | Bookstore |

There are several towns across the wilderness. Your starting town will eventually become too
small. Read the *Adventurer's Guide to Middle-earth* parchment (given at the start) to find
other towns.

### The Wilderness and Dungeons

Outside town walls lies the wilderness. Dungeon entrances (`v>`) lead to randomly generated
levels. Descend with `>` (go down) and ascend with `<` (go up). Deeper levels hold stronger
monsters and better loot.

---

## Map Symbols

### Terrain

| Symbol | Meaning |
|--------|---------|
| `.` | Floor |
| `#` | Wall |
| `<` | Staircase up |
| `>` | Staircase down |
| `+` | Closed/locked door |
| `'` | Open door |
| `^` | Known trap |
| `_` | Fountain |
| `%` | Mineral vein |
| `~` | Water (shallow) |
| `@` | Your character |

### Objects

| Symbol | Meaning |
|--------|---------|
| `!` | Potion |
| `?` | Scroll / book / parchment |
| `-` | Wand or rod |
| `_` | Staff |
| `=` | Ring |
| `"` | Amulet |
| `$` | Gold or gems |
| `\|` | Edged weapon |
| `\` | Hafted weapon or digger |
| `/` | Pole-arm |
| `}` | Bow / crossbow / sling |
| `{` | Ammunition |
| `[` | Hard armour |
| `(` | Soft armour / cloak |
| `)` | Shield |
| `,` | Food / mushroom |
| `~` | Torch, lantern, chest, tool |

### Monsters (selected)

| Symbol | Monster type |
|--------|-------------|
| `d` | Dragon |
| `D` | Ancient Dragon |
| `o` | Orc |
| `O` | Ogre |
| `T` | Troll |
| `V` | Vampire |
| `W` | Wight / Wraith |
| `L` | Lich |
| `U` | Major demon |
| `z` | Zombie / Mummy |
| `p` | Human |
| `s` | Skeleton |
| `@` | Unique named enemy |

Use `/` to identify any symbol you do not recognise.

---

## Skills

ToME uses a **skill point system** rather than automatic class progression. Each time you
gain a level you receive **6 skill points** to spend however you like.

Open the skills menu with **`G`** (both keysets). Skills include:

- **Combat** — melee fighting ability
- **Weaponmastery** sub-skills (Sword, Axe, Hafted, Polearm)
- **Archery** — ranged attacks
- **Sneakiness** — stealth and trap disarming
- **Magic** — spellcasting; sub-skills per school of magic
- **Spirituality** — prayer and divine powers
- **Monster-lore** — knowledge of enemies

The cost to raise a skill varies by class. A warrior can learn some magic, but it costs more
skill points than it would for a mage. Some skills automatically raise related sub-skills when
you invest in the parent.

Skill points can also be spent on one-off **Abilities** — passive bonuses and special powers.

---

## Commands

ToME supports two keysets. Choose at startup or via options (`=`).

### Movement

| Original | Roguelike | Direction |
|----------|-----------|-----------|
| `7` | `y` | North-west |
| `8` | `k` | North |
| `9` | `u` | North-east |
| `4` | `h` | West |
| `6` | `l` | East |
| `1` | `b` | South-west |
| `2` | `j` | South |
| `3` | `n` | South-east |
| `5` | `5` | Stand still |

**Running:** Original keyset — `.` then direction. Roguelike — `,` or hold Shift + direction key.

**Tunnelling:** Original keyset — `T` then direction. Roguelike — hold Ctrl + direction key.

### Original Keyset — Full Command List

| Key | Command |
|-----|---------|
| `a` | Aim a wand |
| `A` | Activate an artifact |
| `b` | Browse a book |
| `B` | Bash a door |
| `c` | Close a door |
| `C` | Character description |
| `d` | Drop an item |
| `e` | Equipment list |
| `E` | Eat some food |
| `f` | Fire (shoot) an item |
| `F` | Fuel your lantern/torch |
| `g` | Stay still (flip pickup) |
| `G` | Gain new skills |
| `h` | Hack up a corpse |
| `H` | Drink from a fountain |
| `i` | Inventory list |
| `I` | Inspect (closely examine) an item |
| `j` | Jam a door |
| `k` | Destroy an item |
| `K` | Cure meat |
| `l` | Look around |
| `L` | Look around dungeon by sector |
| `m` | Cast a spell / use mental power |
| `M` | Full dungeon map |
| `n` | Repeat last command |
| `N` | Abilities screen |
| `o` | Open a door or chest |
| `O` | Sacrifice at an altar |
| `p` | Pray to your god |
| `P` | Pet commands |
| `q` | Quaff a potion |
| `Q` | Quit (commit suicide) |
| `r` | Read a scroll |
| `R` | Rest for a period |
| `s` | Search for traps/doors |
| `S` | Toggle search mode |
| `t` | Take off equipment |
| `T` | Dig a tunnel |
| `u` | Use a staff |
| `U` | Use bonus power |
| `v` | Throw an item |
| `V` | Version info |
| `w` | Wear/wield equipment |
| `x` | Engrave the floor |
| `y` | Give item to monster |
| `Y` | Chat with a monster |
| `z` | Zap a rod |
| `Z` | Steal |
| `<` | Go up staircase |
| `>` | Go down staircase |
| `.` | Run |
| `;` | Walk (with pickup) |
| `-` | Walk (flip pickup) |
| `,` | Stay still (with pickup) |
| `+` | Alter grid |
| `=` | Set options |
| `*` | Target monster or location |
| `{` | Inscribe an object |
| `}` | Uninscribe an object |
| `/` | Identify symbol |
| `?` | Help |
| `~` | Display current knowledge |
| `@` | Interact with macros |
| `!` | Interact with system |
| `"` | Enter a user pref command |
| `&` | Interact with colors |
| `%` | Interact with visuals |
| `#` | Begin extended command |
| `:` | Take notes |
| `\` | Bypass keymap (use underlying command directly) |
| `^E` | Toggle choice window |
| `^F` | Repeat level feeling |
| `^P` | Show previous messages |
| `^R` | Redraw the screen |
| `^S` | Save (don't quit) |
| `^T` | Time of day |
| `^X` | Save and quit |

### Roguelike Keyset — Differences

| Key | Command |
|-----|---------|
| `a` | Zap a rod |
| `f` | Bash a door |
| `t` | Fire an item |
| `T` | Take off equipment |
| `x` | Look around |
| `z` | Aim a wand |
| `Z` | Use a staff |
| `P` | Browse a book |
| `W` | Locate player on map |
| `X` | Pet commands |
| `S` | Record macros |
| `,` | Run |
| `.` | Stay still (with pickup) |
| `^T` | Dig a tunnel |
| `^D` | Destroy item |
| `^G` | Sacrifice at an altar |
| `^O` | Cure meat |

Movement in roguelike mode uses `hjklyubn`. Shift + direction runs. Ctrl + direction tunnels.

---

## Items and Inventory

- **Pick up:** walk over an item; press `g` to toggle auto-pickup
- **Drop:** `d`
- **Wear/wield:** `w`
- **Take off:** `t`
- **Inspect:** `I` — shows full item details
- **Inscribe:** `{` — add notes (e.g. `@1` to quick-use with `m1`; `!d` to confirm before dropping)
- **Destroy:** `k`

Items with `{...}` suffixes are **ego items** with extra powers. Items with `{cursed}` cannot
be removed without magic. Items labelled `{special}` or `{randart}` are unique artifacts.

### Identification

Most items start **unidentified**. Methods to identify:

- Use a *Scroll of Identify*
- Use the Alchemy Shop
- Cast the *Identify* spell (if you have it)
- Some classes gain automatic identification over time

---

## Combat

Attacking is automatic — move into an enemy to strike. Your attack speed, number of blows,
and damage depend on your weapon, STR, DEX, and relevant weapon skill.

- **Ranged:** equip a bow/crossbow and ammunition, then `f` + direction or target
- **Throwing:** `v` — any item can be thrown
- **Magic:** `m` to open your spell list
- **Prayers:** `p` to pray (requires worshipping a god)

### Status Effects

Various monsters inflict status ailments (poison, blindness, confusion, paralysis). Carry
potions or scrolls to cure them. The `R` (rest) command restores HP and MP over time when
not in danger.

---

## Gods

You may choose to worship one of the gods of Arda (Eru, Manwë, Tulkas, Yavanna, Melkor, and
others). Praying (`p`) builds piety. High piety grants divine powers and spells. Sinning
against your god reduces piety and may bring divine wrath.

---

## Tips for New Players

- **Read your starting parchment** — it contains quest information and maps.
- **Save often** — use `^S`. The game auto-saves on exit.
- **Descend carefully** — deeper levels scale quickly. Don't rush.
- **Identify before using** — unidentified potions and scrolls can be harmful.
- **Invest in a primary combat skill early** — skill points spent on your main attack style pay off throughout the game.
- **Keep a Scroll of Teleportation** — escaping a dangerous fight is better than dying.
- **Check the `~` knowledge screen** — tracks monsters you've encountered and items you've identified.
- **Use inscriptions** — `{@m1}` on a frequently cast spell book lets you open it with `m1` instantly.
- **Death is permanent** — there is no coming back. When in doubt, retreat.
