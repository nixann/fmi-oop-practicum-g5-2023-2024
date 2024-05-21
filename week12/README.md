### Имплементирайте йерархия, състояща се от следните класове


1. **LibraryItem (абстрактен базов клас)**
   - **Полета:** `int identifier`, `title` (низ с максимален размер 127), `bool available`.
   - **Методи:** Чисто виртуален `printDetails()`, чисто виртуален `clone()`

2. **Book (Наследява LibraryItem)**
   - **Допълнителни полета:** `author` (низ с максимален размер 127), `unsigned pages` (брой страници).
   - **Имплементира:** `printDetails()` извежда `Book title: <title>, Author: <author>, Number of pages: <pages>`, `clone()` - клонира текущия обект.

3. **Vinyl (Наследява LibraryItem)**
   - **Допълнителни полета:** `singer` (низ с максимален размер 127), `unsigned length` (дължина на записа в секунди).
   - **Имплементира:** `printDetails()` извежда `Record title: <title>, Singer: <singer>, Length in seconds: <length>`, `clone()` - клонира текущия обект.

4. **Collectible (Клас)**
   - **Поле:** `unsigned rarity` (описва рядкостта на артикула).

5. **SpecialEditionBook (Наследява Book и Collectible)**
   - **Имплементира:** `printDetails()` извежда `Book title: <title>, Author: <author>, Number of pages: <pages>. This is a special edition book with rarity: <rarity>`, `clone()` - клонира текущия обект.

6. **SpecialEditionVinyl (Наследява Vinyl и Collectible)**
   - **Имплементира:** `printDetails()` извежда `Record title: <title>, Singer: <singer>, Length in seconds: <length>. This is a special edition record with rarity: <rarity>`, `clone()` - клонира текущия обект.

7. **Library (Клас)**
   - **Колекция:** Управлява списък от `LibraryItem*`.
   - **Методи:**
     - `add(LibraryItem* item)`: Добавя нов артикул в колекцията.
     - `find(int identifier)`: Намира артикул по идентификатор.
     - `remove(int identifier)`: Премахва артикул от колекцията.
     - `checkout(int identifier)`: Маркира артикул като неналичен.
     - `returnItem(int identifier)`: Маркира артикул като наличен.
     - `printAll()` - отпечатва детайлите за всички артикули,
     - `printAvailable()` - отпечатва детайлите за всички налични артикули
