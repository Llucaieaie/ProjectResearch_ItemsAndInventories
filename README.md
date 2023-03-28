# Research Project: Items and Inventories

This repository was made for the Project II class at the university CITM - UPC and the goal is to explain how to implement an inventory on a RPG game made with C++.
The repository contains a handout to try and make a basic inventory with simple UI, all with TODOs to help with the process. It also contains a proposed solution for it.

## How to store items
The inventory to store items will be basically an array of items (from an Item class), so all the item data is accesible from the inventory. It can have a pre-assigned
capacity and it uses a variable to register the number of items on the inventory, to know in which position of the array will be added the next item you get.

## Design of the GUI
There are plenty of different inventories with diferent graphical user interfaces. These are some of them that I found more remarkable.
The pokemon games use a simple inventory which consists of a list of items which you can use while checking the inventory or in certain situations.

![pkmn-inventory](https://user-images.githubusercontent.com/99950000/228314799-e4e7c5eb-4e0d-4c1d-ae14-e0b9ce383016.jpg)



Minecraft and the Dark Souls games use an inventory which, a part from a list of items, in the inventory you can equip some items like armor or weapons, and also you can
have some items in quick access slots

![mc-inventory](https://user-images.githubusercontent.com/99950000/228313980-5b96322b-3968-407e-8070-2c3f5f84f65a.png)
![ds-inventory](https://user-images.githubusercontent.com/99950000/228314043-44d0be92-c376-4881-9c47-e816046a8449.jpg)



Resident Evil 4's inventory is much loved by the community due to the inventory managing system, where every item has a size and you have to try and optimize it to make
all the items fit inside. Escape from Tarkov also uses this type of inventory and the inventory management conforms an important part of the game because there is a
player inventory which is conserved after dying in the game, which have a limited capacity.

![re4-inventory](https://user-images.githubusercontent.com/99950000/228320595-6dad1505-b413-4360-9b5b-8f3a5cfe7f4b.jpg)
![tarkov-inventory](https://user-images.githubusercontent.com/99950000/228320607-529f3b52-a667-4ea1-8e29-eb2ec493f3dd.png)

## How to implement an inventory
This repository contains a handout to learn to implement inventories with the steps to make it. There is also a proposed solution made by me.

## Functions
The inventory will contain the basic functions to work, which are one to add more items and one to remove them, apart from the display of the inventory.

## More information
If you have trouble in understanding the process of making an inventory, I recommend watching this video, and the following ones from the series.

https://www.youtube.com/watch?v=STpke4FGnZk&list=PL6xSOsbVA1eY06RyJuIVWc6tP8hIDiId8&index=31&ab_channel=SurajSharma 
