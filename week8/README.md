# Задача

## Използвайки вашата имплементация на класа `Vector` от седмица 5, заместете следните методи с предефинирани оператори:

- **`at(int index)`** - `operator []`, като при подаване на отрицателен индекс трябва да се върне съответният елемент, спрямо последния - при подаване на -1 се връща последният, при -2 този преди него и т.н. Ако подаденият индекс е невалиден (излиза извън размера на вектора), програмата трябва да хвърля грешка

- **`concat(const Vector& other)`** - `operator +=`

## Добавете имплементация за предефинирането на следните оператори:

- **`operator==(const Vector& other)`** - проверява дали два вектора са равни(имат еднаква дължина и елементите им на всяка позиция съвпадат)

- **`operator!=(const Vector& other)`** - проверява дали два вектора са различни

- **`operator<(const Vector& other)`** - проверява дали всеки един от елементите на вектора от лявата страна на израза е по-малък от всеки един от елементите на вектора от дясната страна

- **`operator>(const Vector& other)`** - проверява дали всеки един от елементите на вектора от лявата страна на израза е по-голям от всеки един от елементите на вектора от дясната страна


## Предефинирайте следните оператори на класовете `std::ostream` и `std::istream`

- **`std::ostream & operator<<(std::ostream &, Vector const &`** - извежда елементите на вектора, разделени със запетая.

- **`std::istream & operator>>(std::istream &, Vector const &`** - чете цели числа, разделени със запетая, и ги записва във вектора.


## Приятелски функции

- Дефинирайте приятелска ф-я за класа Vector - **`scalar(const Vector& v1, const Vector& v2)`**, която връща число, което представлява скаларното произведение на двата вектора.



